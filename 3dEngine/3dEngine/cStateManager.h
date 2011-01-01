/**
    Keeps track of the state within the engine.
    Works as a stack.
**/


#ifndef CSTAMAN_H
#define CSTAMAN_H

#include "globals.h"
#include "ePurpose.h"

struct sState
{
	sState* Prev;
	void (*Function)(void* CallerPtr, Purpose Purp);
	
	sState()
	{
		Prev = NULL;
		Function = NULL;
	}
	
	~sState()
	{
		delete Prev;
	}
};


class cStateManager
{
	public:
		cStateManager();
		~cStateManager();
		bool Push( void (*Function)(void* CallerPtr, Purpose Purp),  void* CallerPtr = NULL);
		bool Pop( void* CallerPtr = NULL);
		bool PopAll( void* CallerPtr = NULL);
		bool Process( void* CallerPtr = NULL);
	
	private:
			sState* m_CurrentState;
};

#endif CSTAMAN_H