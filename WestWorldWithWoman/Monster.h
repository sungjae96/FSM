#ifndef MONSTER_H
#define MONSTER_H

#include "State.h"
#include "BaseGameEntity.h"
#include "Locations.h"
#include "MinersWifeOwnedStates.h"
#include "misc/ConsoleUtils.h"
#include "Miner.h"
#include "StateMachine.h"
#include "misc/Utils.h"

class Monster : public BaseGameEntity
{
private:
	StateMachine<MinersWife>*  m_pStateMachine;

	location_type              m_Location;

public:
	Monster(int id) :BaseGameEntity(id),
		m_Location(shack)

	{
		m_pStateMachine = new StateMachine<MinersWife>(this);

		m_pStateMachine->SetCurrentState(DoHouseWork::Instance());

		m_pStateMachine->SetGlobalState(WifesGlobalState::Instance());
	}

	~Monster() { delete m_pStateMachine; }


	void Update();

	StateMachine<MinersWife>*  GetFSM()const { return m_pStateMachine; }

	//----------------------------------------------------accessors
	location_type Location()const { return m_Location; }
	void          ChangeLocation(const location_type loc) { m_Location = loc; }

};

#endif