#pragma once
#include "PlacableActor.h"
class Portal : public PlacableActor
{
public:
	Portal(int x, int y, ActorColor color)
		: PlacableActor(x, y, color)
	{

	}

	virtual ActorType GetType() override { return ActorType::Portal; }
	virtual void Draw() override;
};

