#include "Trap.h"
#include "Player.h"
#include <iostream>
using namespace std;

Trap::Trap()
	:m_isTrapped(false)
{

}
Trap::~Trap()
{

}

void Trap::SetPosition(int x, int y)
{
	m_TrapPos.x = x;
	m_TrapPos.y = y;
}

bool Trap::trapIsUsed()
{
	if (m_player.GetXPosition() == m_TrapPos.x && m_player.GetYPosition() == m_TrapPos.y) 
	{
		m_isTrapped = true;
		cout << "You got trapped!" << endl;
	}
	return true;
}