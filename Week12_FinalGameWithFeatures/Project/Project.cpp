#include <iostream>

#include "GameplayState.h"



using namespace std;

int main()
{
	GameplayState game;

	bool isGameOver = false;

	while (!game.IsGameOver())
	{

		// Draw
		game.Draw();
		// update with no input
		game.Update();
		
	}


	return 0;
}