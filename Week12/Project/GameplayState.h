#pragma once

#include "Player.h"
#include "Trap.h"
#include "Potion.h"
#include <windows.h>
#include <vector>
#include <string>

namespace std
{
	class thread;
}

class Level;

class GameplayState
{


public:
	GameplayState();
	~GameplayState();
	
	bool Update();
	void Draw();

	bool IsGameOver() { return m_didBeatLevel; }
	Player m_player;
protected:
	void ProcessInput();
	void CheckBeatLevel();

	bool m_shouldProcessInput = false;
	std::thread* m_inputThread = nullptr;
private:
	void HandleCollision(int newPlayerX, int newPlayerY);

	void Load();

	void SwitchTrap(Trap* trap);
	
	Level* m_pLevel;
	Trap m_trap;
	Potion* m_Ppot;

	bool m_didBeatLevel;
	int m_skipFrameCount;
	static constexpr int kFramesToSkip = 2;

	int m_currentLevel;

	std::vector<std::string> m_LevelNames;
};
