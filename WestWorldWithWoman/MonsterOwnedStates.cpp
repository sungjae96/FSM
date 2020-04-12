#include "MinersWifeOwnedStates.h"
#include "MinerOwnedStates.h"
#include "MonsterOwnedStates.h"
#include "Monster.h"
#include "Locations.h"
#include "Time/CrudeTimer.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

//-----------------------------------------------------------------------Global state

MonsterGlobalState* MonsterGlobalState::Instance()
{
	static MonsterGlobalState instance;

	return &instance;
}


void MonsterGlobalState::Execute(Monster* monster)
{
	////1 in 10 chance of needing the bathroom (provided she is not already
	////in the bathroom)
	//if ((RandFloat() < 0.1) &&
	//	!monster->GetFSM()->isInState(*VisitBathroom::Instance()))
	//{
	//	monster->GetFSM()->ChangeState(VisitBathroom::Instance());
	//}
}

bool MonsterGlobalState::OnMessage(Monster* monster, const Telegram& msg)
{
	//SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	//switch (msg.Msg)
	//{
	//case Msg_HiHoneyImHome:
	//{
	//	cout << "\nMessage handled by " << GetNameOfEntity(monster->ID()) << " at time: "
	//		<< Clock->GetCurrentTime();

	//	SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	//	cout << "\n" << GetNameOfEntity(monster->ID()) <<
	//		": Hi honey. Let me make you some of mah fine country stew";

	//	monster->GetFSM()->ChangeState(AttackBob::Instance());
	//}

	//return true;

	//}//end switch

	return false;
}

//-------------------------------------------------------------------------DoHouseWork

Searching* Searching::Instance()
{
	static Searching instance;

	return &instance;
}


void Searching::Enter(Monster* monster)
{
	cout << "\n" << GetNameOfEntity(monster->ID()) << ": Time to Search my food!";
}


void Searching::Execute(Monster* monster)
{
	switch (RandInt(0, 2))
	{
	case 0:

		cout << "\n" << GetNameOfEntity(monster->ID()) << ": Nothing Found and Get Tired";

		monster->GetFSM()->ChangeState(TakeASleep::Instance());

		break;

	case 1:

		cout << "\n" << GetNameOfEntity(monster->ID()) << ": Found Bob";

		monster->GetFSM()->ChangeState(AttackBob::Instance());

		break;

	case 2:

		cout << "\n" << GetNameOfEntity(monster->ID()) << ": Found Elsa";

		monster->GetFSM()->ChangeState(AttackElsa::Instance());


		break;
	}
}

void Searching::Exit(Monster* monster)
{
}

bool Searching::OnMessage(Monster* monster, const Telegram& msg)
{
	return false;
}

//------------------------------------------------------------------------VisitBathroom

TakeASleep* TakeASleep::Instance()
{
	static TakeASleep instance;

	return &instance;
}


void TakeASleep::Enter(Monster* monster)
{
	cout << "\n" << GetNameOfEntity(monster->ID()) << ": I Should take a sleep";
}


void TakeASleep::Execute(Monster* monster)
{
	cout << "\n" << GetNameOfEntity(monster->ID()) << ": Zzz";

	monster->GetFSM()->RevertToPreviousState();
}

void TakeASleep::Exit(Monster* monster)
{
}


bool TakeASleep::OnMessage(Monster* monster, const Telegram& msg)
{
	return false;
}


//------------------------------------------------------------------------AttackBob

AttackBob* AttackBob::Instance()
{
	static AttackBob instance;

	return &instance;
}


void AttackBob::Enter(Monster* monster)
{
	//if not already cooking put the stew in the oven
	if (!monster->found())
	{
		cout << "\n" << GetNameOfEntity(monster->ID()) << ": I should wait for my chance!";

		//send a delayed message myself so that I know when to take the stew
		//out of the oven
		Dispatch->DispatchMessage(1.5,                  //time delay
			monster->ID(),           //sender ID
			monster->ID(),           //receiver ID
			Msg_BobAttack,        //msg
			NO_ADDITIONAL_INFO);

		monster->Setfound(true);
	}
}


void AttackBob::Execute(Monster* monster)
{
	cout << "\n" << GetNameOfEntity(monster->ID()) << ": Waiting";
}

void AttackBob::Exit(Monster* monster)
{
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	cout << "\n" << GetNameOfEntity(monster->ID()) << ": Arr! I'll be back";
}


bool AttackBob::OnMessage(Monster* monster, const Telegram& msg)
{
	switch (msg.Msg)
	{
	case Msg_BobAttack:
	{

		//let hubby know the stew is ready
		Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
			monster->ID(),
			ent_Miner_Bob,
			Msg_BobAttack,
			NO_ADDITIONAL_INFO);

		monster->Setfound(false);

		monster->GetFSM()->ChangeState(Searching::Instance());
	}

	return true;

	}//end switch

	return false;
}

//------------------------------------------------------------------------------attackelsa

AttackElsa* AttackElsa::Instance()
{
	static AttackElsa instance;

	return &instance;
}


void AttackElsa::Enter(Monster* monster)
{
	//if not already cooking put the stew in the oven
	if (!monster->found())
	{
		cout << "\n" << GetNameOfEntity(monster->ID()) << ": I should wait for my chance!";

		//send a delayed message myself so that I know when to take the stew
		//out of the oven
		Dispatch->DispatchMessage(1.5,                  //time delay
			monster->ID(),           //sender ID
			monster->ID(),           //receiver ID
			Msg_ElsaAttack,        //msg
			NO_ADDITIONAL_INFO);

		monster->Setfound(true);
	}
}


void AttackElsa::Execute(Monster* monster)
{
	cout << "\n" << GetNameOfEntity(monster->ID()) << ": Waiting";
}

void AttackElsa::Exit(Monster* monster)
{
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	cout << "\n" << GetNameOfEntity(monster->ID()) << ": Arr! She runs so fast";
}


bool AttackElsa::OnMessage(Monster* monster, const Telegram& msg)
{
	switch (msg.Msg)
	{
	case Msg_ElsaAttack:
	{

		//let hubby know the stew is ready
		Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
			monster->ID(),
			ent_Elsa,
			Msg_ElsaAttack,
			NO_ADDITIONAL_INFO);

		monster->Setfound(false);

		monster->GetFSM()->ChangeState(Searching::Instance());
	}

	return true;

	}//end switch

	return false;
}