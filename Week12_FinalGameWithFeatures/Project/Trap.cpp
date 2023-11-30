#include "Trap.h"
#include <iostream>
#include <windows.h>

Trap::Trap(int x, int y)
	: PlacableActor(x,y)
{
	damage = 10;
	color = 9;
}

Trap::~Trap()
{
	
}

void Trap::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)color);
	std::cout << "T";
	SetConsoleTextAttribute(console, 7);
}

void Trap::SwitchColor()
{
	if (color == 9)
	{
		color = 10;
	}
	else
	{
		color = 9;
	}
}