#ifndef MONSTER_H
#define MONSTER_H
//------------------------------------------------------------------------
//
//  Name: MinersWife.h
//
//  Desc: class to implement Miner Bob's wife.
//
//  Author: Mat Buckland 2003 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------

#include <string>

#include "fsm/State.h"
#include "BaseGameEntity.h"
#include "Locations.h"
#include "MinersWifeOwnedStates.h"
#include "MonsterOwnedStates.h"
#include "misc/ConsoleUtils.h"
#include "Miner.h"
#include "fsm/StateMachine.h"
#include "misc/Utils.h"



class Monster : public BaseGameEntity
{
private:

	//an instance of the state machine class
	StateMachine<Monster>* m_pStateMachine;

	location_type   m_Location;

	//is she presently cooking?
	bool            m_found;


public:

	Monster(int id) :m_Location(shack),
		m_found(false),
		BaseGameEntity(id)

	{
		//set up the state machine
		m_pStateMachine = new StateMachine<Monster>(this);

		m_pStateMachine->SetCurrentState(Searching::Instance());

		m_pStateMachine->SetGlobalState(MonsterGlobalState::Instance());
	}

	~Monster() { delete m_pStateMachine; }


	//this must be implemented
	void          Update();

	//so must this
	virtual bool  HandleMessage(const Telegram& msg);

	StateMachine<Monster>* GetFSM()const { return m_pStateMachine; }

	//----------------------------------------------------accessors
	location_type Location()const { return m_Location; }
	void          ChangeLocation(location_type loc) { m_Location = loc; }

	bool          found()const{ return m_found; }
	void          Setfound(bool val) { m_found = val; }

};

#endif
