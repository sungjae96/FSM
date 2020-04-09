#ifndef MONSTER_OWNED_STATES_H
#define MONSTER_OWNED_STATES_H

#include "State.h"

class Monster;

class WifesGlobalState : public State<Monster>
{
private:

	WifesGlobalState() {}

	//copy ctor and assignment should be private
	WifesGlobalState(const WifesGlobalState&);
	WifesGlobalState& operator=(const WifesGlobalState&);

public:

	static WifesGlobalState* Instance();

	virtual void Enter(Monster* monster) {}

	virtual void Execute(Monster* monster);

	virtual void Exit(Monster* monster) {}
};


//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class DoHouseWork : public State<Monster>
{

private:

	DoHouseWork() {}

	//copy ctor and assignment should be private
	DoHouseWork(const DoHouseWork&);
	DoHouseWork& operator=(const DoHouseWork&);

public:

	static DoHouseWork* Instance();

	virtual void Enter(Monster* monster);

	virtual void Execute(Monster* monster);

	virtual void Exit(Monster* monster);

};



//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class VisitBathroom : public State<Monster>
{
private:

	VisitBathroom() {}

	//copy ctor and assignment should be private
	VisitBathroom(const VisitBathroom&);
	VisitBathroom& operator=(const VisitBathroom&);

public:

	static VisitBathroom* Instance();

	virtual void Enter(Monster* monster);

	virtual void Execute(Monster* monster);

	virtual void Exit(Monster* monster);

};

#endif