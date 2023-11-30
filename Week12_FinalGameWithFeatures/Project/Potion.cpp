#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Potion.h"

Player m_player;

void Potion::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)m_color);

	std::cout << "P";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}