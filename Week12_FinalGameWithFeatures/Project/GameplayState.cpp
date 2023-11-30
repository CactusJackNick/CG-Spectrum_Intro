#include "GameplayState.h"

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <assert.h>
#include <thread>


#include "Level.h"
#include "Enemy.h"
#include "Door.h"
#include "Key.h"
#include "Goal.h"
#include "Money.h"
#include "Potion.h"
#include "Portal.h"


#include "Utility.h"

using namespace std;

constexpr int kArrowInput = 224;
constexpr int kLeftArrow = 75;
constexpr int kRightArrow = 77;
constexpr int kUpArrow = 72;
constexpr int kDownArrow = 80;
constexpr int kEscapeKey = 27;

constexpr unsigned int SleepTime = 101;

GameplayState::GameplayState()
	: m_didBeatLevel(false)
	, m_skipFrameCount(0)
	, m_currentLevel(0)
	, m_pLevel(nullptr)
	, m_trap(1,1)
	, m_Ppot(nullptr)
{
	m_LevelNames.push_back("Level1.txt");
	m_LevelNames.push_back("Level2.txt");
	m_LevelNames.push_back("Level3.txt");

	m_shouldProcessInput = true;

	
	Load();
}

GameplayState::~GameplayState()
{
	delete m_pLevel;
	m_pLevel = nullptr;
}

void GameplayState::Load()
{
	if (m_pLevel)
	{
		delete m_pLevel;
		m_pLevel = nullptr;
	}

	m_pLevel = new Level();

	m_pLevel->Load(m_LevelNames.at(m_currentLevel), m_player.GetXPositionPointer(), m_player.GetYPositionPointer());

}

void GameplayState::ProcessInput()
{
	int input = _getch();
	int arrowInput = 0;
	int newPlayerX = m_player.GetXPosition();
	int newPlayerY = m_player.GetYPosition();
	SHORT keyState = GetKeyState(VK_SHIFT);

	// One of the arrow keys were pressed
	if (input == kArrowInput)
	{
		arrowInput = _getch();
	}

	if ((input == kArrowInput && arrowInput == kLeftArrow) ||
		(char)input == 'A' || (char)input == 'a')
	{
		newPlayerX--;
		if (m_player.HasPotion() && keyState & 0x8000)
		{
			newPlayerX--;
		}
	}
	else if ((input == kArrowInput && arrowInput == kRightArrow) ||
		(char)input == 'D' || (char)input == 'd')
	{
		newPlayerX++;
		if (m_player.HasPotion() && keyState & 0x8000)
		{
			newPlayerX++;
		}
	}
	else if ((input == kArrowInput && arrowInput == kUpArrow) ||
		(char)input == 'W' || (char)input == 'w')
	{
		newPlayerY--;
		if (m_player.HasPotion() && keyState & 0x8000)
		{
			newPlayerY--;
		}
	}
	else if ((input == kArrowInput && arrowInput == kDownArrow) ||
		(char)input == 'S' || (char)input == 's')
	{
		newPlayerY++;
		if (m_player.HasPotion() && keyState & 0x8000)
		{
			newPlayerY++;
		}
	}

	// If position changed
	if (newPlayerX != m_player.GetXPosition() || newPlayerY != m_player.GetYPosition())
	{
		HandleCollision(newPlayerX, newPlayerY);
	}

	if ((char)input == 'U' || (char)input == 'u')
	{
		m_pLevel->OpenAllDoors();
	}
}

void GameplayState::CheckBeatLevel()
{
	if (m_didBeatLevel)
	{
		++m_skipFrameCount;
		if (m_skipFrameCount > kFramesToSkip)
		{
			m_didBeatLevel = false;
			m_skipFrameCount = 0;
			++m_currentLevel;
			if (m_currentLevel < m_LevelNames.size())
			{
				// On to the next level
				Load();
			}
		}
	}
}

//TODO: Refactor
bool GameplayState::Update()
{
	ProcessInput();
	
	m_pLevel->UpdateActors();

	HandleCollision(m_player.GetXPosition(), m_player.GetYPosition());
	CheckBeatLevel();
	return false;
}

//TODO: Refactor
void GameplayState::HandleCollision(int newPlayerX, int newPlayerY)
{
	//UpdateActors also does a collision check based on the X,Y passed in
	PlacableActor* collidedActor = m_pLevel->CheckForCollision(newPlayerX, newPlayerY);
	if (collidedActor != nullptr)
	{
		switch (collidedActor->GetType())
		{
		case ActorType::Enemy:
		{
			Enemy* collidedEnemy = dynamic_cast<Enemy*>(collidedActor);
			assert(collidedEnemy);
			collidedEnemy->Remove();
			m_player.SetPosition(newPlayerX, newPlayerY);

			m_player.DecrementLives();
			if (m_player.GetLives() <= 0)
			{
				cout << "You have died" << endl;
				system("pause");
				m_shouldProcessInput = false;
				_putch(1);
			}
			break;
		}
		case ActorType::Money:
		{
			Money* collidedMoney = dynamic_cast<Money*>(collidedActor);
			assert(collidedMoney);
			collidedMoney->Remove();
			m_player.AddMoney(collidedMoney->GetWorth());
			m_player.SetPosition(newPlayerX, newPlayerY);
			break;
		}
		case ActorType::Key:
		{
			Key* collidedKey = dynamic_cast<Key*>(collidedActor);
			assert(collidedKey);
			if (!m_player.HasKey())
			{
				m_player.PickupKey(collidedKey);
				collidedKey->Remove();
				m_player.SetPosition(newPlayerX, newPlayerY);
			}
			break;
		}
		case ActorType::Door:
		{
			Door* collidedDoor = dynamic_cast<Door*>(collidedActor);
			assert(collidedDoor);
			if (!collidedDoor->IsOpen())
			{
				if (m_player.HasKey(collidedDoor->GetColor()))
				{
					collidedDoor->Open();
					collidedDoor->Remove();
					m_player.UseKey();
					m_player.SetPosition(newPlayerX, newPlayerY);
				}
				
			}
			else
			{
				m_player.SetPosition(newPlayerX, newPlayerY);
			}
			break;
		}
		case ActorType::Goal:
		{
			Goal* collidedGoal = dynamic_cast<Goal*>(collidedActor);
			assert(collidedGoal);
			collidedGoal->Remove();
			m_player.SetPosition(newPlayerX, newPlayerY);
			m_didBeatLevel = true;
			m_shouldProcessInput = false;
			_putch(1);
			break;
		}
		case ActorType::Trap:
		{
			Trap* collidedTrap = dynamic_cast<Trap*>(collidedActor);
			SwitchTrap(collidedTrap);
			
			break;
		}
		case ActorType::Potion:
		{
			Potion* collidedPotion = dynamic_cast<Potion*>(collidedActor);
			assert(collidedPotion);
			if (!m_player.HasPotion())
			{
				m_player.PickUpPotion(collidedPotion);
				collidedPotion->Remove();
				m_player.SetPosition(newPlayerX, newPlayerY);
				m_player.HasPotion();
			}
			break;
		}
		case ActorType::Portal:
		{
			Portal* collidedPortal = dynamic_cast<Portal*>(collidedActor);
			m_player.SendToRandomLocation();
			break;
		}
		
		default:
			break;
		}
	}
	else if (m_pLevel->IsSpace(newPlayerX, newPlayerY)) // no collision
	{
		m_player.SetPosition(newPlayerX, newPlayerY);
	}
	else if (m_pLevel->IsWall(newPlayerX, newPlayerY))
	{
		// wall collision, do nothing
	}
}

void GameplayState::SwitchTrap(Trap* trap)
{
	trap->SwitchColor();
}

void GameplayState::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");

	m_pLevel->Draw();

	// Set cursor position for player 
	COORD actorCursorPosition;
	actorCursorPosition.X = m_player.GetXPosition();
	actorCursorPosition.Y = m_player.GetYPosition();
	SetConsoleCursorPosition(console, actorCursorPosition);
	m_player.Draw();

	// Set the cursor to the end of the level
	COORD currentCursorPosition;
	currentCursorPosition.X = 0;
	currentCursorPosition.Y = m_pLevel->GetHeight();
	SetConsoleCursorPosition(console, currentCursorPosition);

}
