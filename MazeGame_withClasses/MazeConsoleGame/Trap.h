#pragma once
#include "Player.h"
#include "Point.h"

class Trap
{
	Point m_TrapPos;
	Player m_player;
	bool m_isTrapped;

public:
	Trap();
	~Trap();

	int GetXPosition() { return m_TrapPos.x; }
	int GetYPosition() { return m_TrapPos.y; }

	int* GetXPositionPointer() { return &(m_TrapPos.x); }
	int* GetYPositionPointer() { return &(m_TrapPos.y); }

	bool trapIsUsed();

	void SetPosition(int x, int y);
};