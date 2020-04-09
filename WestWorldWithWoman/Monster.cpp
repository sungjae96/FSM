#include "Monster.h"


void Monster::Update()
{
	//set text color to green
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	m_pStateMachine->Update();
}



