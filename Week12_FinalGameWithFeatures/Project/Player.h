#pragma once
#include "PlacableActor.h"
#include "Potion.h"

class Key;
class Potion;

class Player : public PlacableActor
{
public:
	Player();

	//inventory interface or composition
	bool HasKey();
	bool HasKey(ActorColor color);
	bool HasPotion();
	bool HasPotion(ActorColor color);
	void PickupKey(Key* key);
	void PickUpPotion(Potion* potion);
	void UseKey();
	void DropKey();
	Key* GetKey() { return m_pCurrentKey; }
	Potion* GetPotion() { return m_pPotion; }

	void AddMoney(int money) { m_money += money; }
	int GetMoney() { return m_money; }

	void SendToRandomLocation();

	//ILiveable
	//create a function OnLoseLive or ColllideWithEnemy
	int GetLives() { return m_lives; }
	void DecrementLives() { m_lives--; }

	virtual ActorType GetType() override { return ActorType::Player; }
	virtual void Draw() override;
private:
	Potion* m_pPotion;
	Key* m_pCurrentKey;
	int m_money;
	int m_lives;
};
