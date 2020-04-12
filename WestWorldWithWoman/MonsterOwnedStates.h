#ifndef MONSTER_OWNED_STATES_H
#define MONSTER_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   MinersWifeOwnedStates.h
//
//  Desc:   All the states that can be assigned to the MinersWife class
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "fsm/State.h"

class Monster;



//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class MonsterGlobalState : public State<Monster>
{
private:

	MonsterGlobalState() {}

	//copy ctor and assignment should be private
	MonsterGlobalState(const MonsterGlobalState&);
	MonsterGlobalState& operator=(const MonsterGlobalState&);

public:

	//this is a singleton
	static MonsterGlobalState* Instance();

	virtual void Enter(Monster* monster) {}

	virtual void Execute(Monster* monster);

	virtual void Exit(Monster* monster) {}

	virtual bool OnMessage(Monster* monster, const Telegram& msg);
};


//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class Searching : public State<Monster>
{
private:

	Searching() {}

	//copy ctor and assignment should be private
	Searching(const Searching&);
	Searching& operator=(const Searching&);

public:

	//this is a singleton
	static Searching* Instance();

	virtual void Enter(Monster* monster);

	virtual void Execute(Monster* monster);

	virtual void Exit(Monster* monster);

	virtual bool OnMessage(Monster* monster, const Telegram& msg);

};



//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class TakeASleep : public State<Monster>
{
private:

	TakeASleep() {}

	//copy ctor and assignment should be private
	TakeASleep(const TakeASleep&);
	TakeASleep& operator=(const TakeASleep&);

public:

	//this is a singleton
	static TakeASleep* Instance();

	virtual void Enter(Monster* monster);

	virtual void Execute(Monster* monster);

	virtual void Exit(Monster* monster);

	virtual bool OnMessage(Monster* monster, const Telegram& msg);

};


//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class AttackBob : public State<Monster>
{
private:

	AttackBob() {}

	//copy ctor and assignment should be private
	AttackBob(const AttackBob&);
	AttackBob& operator=(const AttackBob&);

public:

	//this is a singleton
	static AttackBob* Instance();

	virtual void Enter(Monster* monster);

	virtual void Execute(Monster* monster);

	virtual void Exit(Monster* monster);

	virtual bool OnMessage(Monster* monster, const Telegram& msg);
};

//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class AttackElsa : public State<Monster>
{
private:

	AttackElsa() {}

	//copy ctor and assignment should be private
	AttackElsa(const AttackElsa&);
	AttackElsa& operator=(const AttackElsa&);

public:

	//this is a singleton
	static AttackElsa* Instance();

	virtual void Enter(Monster* monster);

	virtual void Execute(Monster* monster);

	virtual void Exit(Monster* monster);

	virtual bool OnMessage(Monster* monster, const Telegram& msg);
};


#endif