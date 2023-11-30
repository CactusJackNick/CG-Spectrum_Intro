#include <iostream>
#include <windows.h>

#include "Portal.h"

void Portal::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)m_color);

	std::cout << "O";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}
