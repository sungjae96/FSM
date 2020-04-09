#include "MonsterOwnedStates.h"
#include "Monster.h"
#include "Locations.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

//-----------------------------------------------------------------------Global state
WifesGlobalState* WifesGlobalState::Instance()
{
	static WifesGlobalState instance;

	return &instance;
}


void WifesGlobalState::Execute(Monster* monster)
{
	//1 in 10 chance of needing the bathroom
	if (RandFloat() < 0.1)
	{
		monster->GetFSM()->ChangeState(VisitBathroom::Instance());
	}
}

//---------------------------------------DoHouseWork

DoHouseWork* DoHouseWork::Instance()
{
	static DoHouseWork instance;

	return &instance;
}


void DoHouseWork::Enter(Monster* monster)
{
}


void DoHouseWork::Execute(Monster* monster)
{
	switch (RandInt(0, 2))
	{
	case 0:

		cout << "\n" << GetNameOfEntity(monster->ID()) << ": Moppin' the floor";

		break;

	case 1:

		cout << "\n" << GetNameOfEntity(monster->ID()) << ": Washin' the dishes";

		break;

	case 2:

		cout << "\n" << GetNameOfEntity(monster->ID()) << ": Makin' the bed";

		break;
	}
}

void DoHouseWork::Exit(Monster* monster)
{
}



//------------------------------------------------------------------------VisitBathroom
VisitBathroom* VisitBathroom::Instance()
{
	static VisitBathroom instance;

	return &instance;
}


void VisitBathroom::Enter(Monster* monster)
{
	cout << "\n" << GetNameOfEntity(monster->ID()) << ": Walkin' to the can. Need to powda mah pretty li'lle nose";
}


void VisitBathroom::Execute(Monster* monster)
{
	cout << "\n" << GetNameOfEntity(monster->ID()) << ": Ahhhhhh! Sweet relief!";

	monster->GetFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(Monster* monster)
{
	cout << "\n" << GetNameOfEntity(monster  ->ID()) << ": Leavin' the Jon";
}