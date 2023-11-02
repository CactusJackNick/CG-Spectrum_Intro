#pragma once
#include "Player.h"
#include "Level.h"
#include "Trap.h"


class Game
{
	Trap m_trap;
	Player m_player;
	Level m_level;
	bool m_isGameOver;

public:
	Game();
	~Game();

	bool Load();
	void Run();

	bool isGameOver();

private:
	bool Update();
	void Draw();
};