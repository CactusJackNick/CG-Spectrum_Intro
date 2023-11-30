#include <iostream>

#include "Player.h"
#include "Key.h"
#include "Potion.h"


using namespace std;

constexpr int kStartingNumberOfLives = 3;

Player::Player()
	: PlacableActor(0,0)
	, m_pCurrentKey(nullptr)
	, m_money(0)
	, m_lives(kStartingNumberOfLives)
{

}

bool Player::HasKey()
{
	return m_pCurrentKey != nullptr;
}

bool Player::HasKey(ActorColor color)
{
	if (m_pCurrentKey != nullptr)
	{
		if (m_pCurrentKey->GetColor() == color)
		{
			return true;
		}
	}
	return false;
}
bool Player::HasPotion()
{
	return m_pPotion != nullptr;
}

bool Player::HasPotion(ActorColor color)
{
	return true;
}

void Player::PickUpPotion(Potion* potion)
{
	m_pPotion = potion;
}
void Player::SendToRandomLocation()
{
	SetPosition(40, 13);
}

void Player::PickupKey(Key* key)
{
	m_pCurrentKey = key;
}

void Player::UseKey()
{
	if (m_pCurrentKey)
	{
		m_pCurrentKey->Remove();
		m_pCurrentKey = nullptr;
	}
}

void Player::DropKey()
{
	if (m_pCurrentKey)
	{
		m_pCurrentKey->Place(m_pPosition->x, m_pPosition->y);
		m_pCurrentKey = nullptr;
	}
}

void Player::Draw()
{
	cout << "@";
}
