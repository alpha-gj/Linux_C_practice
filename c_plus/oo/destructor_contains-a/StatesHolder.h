#ifndef _STATESHOLDER_H_
#define _STATESHOLDER_H_
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

enum MAINSTATES {
	POWERUP,
	MAINSTATES_COUNT,
};

class StatesHolder
{
public:
	virtual ~StatesHolder ();
	static StatesHolder *CreateStatesHolder();
	static void releaseStatesHolder();

public:
	void SetMainStates(MAINSTATES s);
	MAINSTATES GetMainStates();
	MAINSTATES GetOldMainStates();

private:
	StatesHolder ();

private:

	//pthread_mutex_t mainStatesLock;
	MAINSTATES mainStates;
	MAINSTATES oldMainStates;

};

#endif