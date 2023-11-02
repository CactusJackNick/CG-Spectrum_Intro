#include "Game.h"
#include "Trap.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

constexpr int kOpenDoorColor = 10;
constexpr int kClosedDoorColor = 12;
constexpr int kRegularColor = 7;

Game::Game()
	: m_isGameOver(false)
{

}
Game::~Game()
{
}

bool Game::Load()
{
    return m_level.Load("Level3.txt", m_player.GetXPositionPointer(), m_player.GetYPositionPointer());
}
void Game::Run()
{
	Draw();

	m_isGameOver = Update();

	if (m_isGameOver)
	{
		Draw();
	}
}

bool Game::isGameOver()
{
	return m_isGameOver;
}

bool Game::Update()
{
    char input = (char)_getch();

    int newPlayerX = m_player.GetXPosition();
    int newPlayerY = m_player.GetYPosition();

    switch (input)
    {
    case 'w':
    case 'W':
    {
        newPlayerY--;
        break;
    }
    case 's':
    case 'S':
    {
        newPlayerY++;
        break;
    }
    case 'a':
    case 'A':
    {
        newPlayerX--;
        break;
    }
    case 'd':
    case 'D':
    {
        newPlayerX++;
        break;
    }
    default:
        break;
    }

    if (m_level.IsSpace(newPlayerX, newPlayerY))
    {
        m_player.SetPosition(newPlayerX, newPlayerY);
    }
    else if (m_level.IsKey(newPlayerX, newPlayerY))
    {
        m_level.PickupKey(newPlayerX, newPlayerY);
        m_player.PickupKey();
        m_player.SetPosition(newPlayerX, newPlayerY);
        //PlayKeyPickupSound();
    }
    else if (m_level.IsDoor(newPlayerX, newPlayerY) && m_player.hasKey())
    {
        m_level.OpenDoor(newPlayerX, newPlayerY);
        m_player.UseKey();
        m_player.SetPosition(newPlayerX, newPlayerY);
        //PlayDoorOpenSound();
    }
    else if (m_level.IsDoor(newPlayerX, newPlayerY) && !m_player.hasKey())
    {
        //PlayDoorClosedSound();
    }
    else if (m_level.IsGoal(newPlayerX, newPlayerY))
    {
        m_player.SetPosition(newPlayerX, newPlayerY);
        return true;
    }
    else if (m_level.IsTrap(newPlayerX, newPlayerY)) 
    {
        m_player.SetPosition(newPlayerX, newPlayerY);

        m_trap.trapIsUsed();
        system("pause");
        return m_isGameOver;
    }
    return false;
}
void Game::Draw()
{
    system("cls");
    for (int y = 0; y < m_level.GetHeight(); y++)
    {
        for (int x = 0; x < m_level.GetWidth(); x++)
        {
            if (m_player.GetXPosition() == x && m_player.GetYPosition() == y)
            {
                m_player.Draw();
            }
            else
            {
                HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
                if (m_level.IsDoor(x,y))
                {
                    if (m_player.hasKey())
                    {
                        SetConsoleTextAttribute(console, kOpenDoorColor);
                    }
                    else
                    {
                        SetConsoleTextAttribute(console, kClosedDoorColor);
                    }
                }
                else
                {
                    SetConsoleTextAttribute(console, kRegularColor);
                }

                m_level.Draw(x, y);
            }
        }
        cout << endl;
    }
}