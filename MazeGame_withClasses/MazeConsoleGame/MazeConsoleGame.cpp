#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	Game myGame;

	if (myGame.Load())
	{
		while (!myGame.isGameOver())
		{
			myGame.Run();
		}
		cout << "YOU WON !!!!" << endl;
		//PlayWinSound();
	}
	else
	{
		cout << "Game did not load. Terminating now!" << endl;
	}
}


//void PlayDoorClosedSound()
//{
//    Beep(500, 75);
//    Beep(500, 75);
//}
//void PlayDoorOpenSound()
//{
//    Beep(1397, 200);
//}
//void PlayKeyPickupSound()
//{
//    Beep(1568, 200);
//}
//void PlayWinSound()
//{
//    Beep(1568, 200);
//    Beep(1568, 200);
//    Beep(1568, 200);
//    Beep(1245, 1000);
//    Beep(1397, 200);
//    Beep(1397, 200);
//    Beep(1397, 200);
//    Beep(1175, 1000);
//}