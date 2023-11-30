#pragma once
#include "PlacableActor.h"
#include <vector>
#include <string>
#include "Player.h"

class Potion : public PlacableActor
{
public:
	Potion(int x, int y, ActorColor color)
		: PlacableActor(x, y, color)
	{

	}

	virtual ActorType GetType() override { return ActorType::Potion; }
	virtual void Draw() override;

	void BoostPlayer();

};
