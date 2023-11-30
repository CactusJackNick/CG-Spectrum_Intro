#pragma once

#include "PlacableActor.h"

class Trap : public PlacableActor
{
public:
	Trap(int x, int y);
	~Trap();

	void Draw();

	void Disable();

	void Enable();

	void SwitchColor();

	virtual ActorType GetType() override { return ActorType::Trap; }

	int damage;

	int color;
};