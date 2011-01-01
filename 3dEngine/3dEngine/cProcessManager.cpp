/**
    Functions for cProcessManager class
**/
/*

#include "cProcessManager.h"


cProcessManager::cProcessManager()
{
	m_FirstProcess = NULL;
    m_LastProcess = NULL;
}

cProcessManager::~cProcessManager()
{
	PopAll(NULL);
}

int cProcessManager::Push( void (*Function)(void* CallerPtr, Purpose Purp), void* CallerPtr )
{
	//only add if the function is valid
	if(Function != NULL)
	{
		//create the new state
		sProcess* newProcess = new sProcess();
		newProcess->Prev = m_CurrentState;
		newProcess->Function = Function;
		
		//set the current state to the new one
		m_CurrentState = newState;
		
		//do init function on state
		newState->Function(CallerPtr, INIT_PURPOSE);
		
		return true; // indicate success
	}
	
	return false; // indicate failer
}

bool cProcessManager::Pop( unsigned int id, void* CallerPtr = NULL)
{
	//only pop if there is a state
	if(m_CurrentState != NULL)
	{
		//tell the state we all killing it
		m_CurrentState->Function(CallerPtr, STOP_PURPOSE);
		
		//create a temporary pointer to the state
		sState* delState = m_CurrentState;
		
		//make the current state the previous one
		m_CurrentState = m_CurrentState->Prev;
		
		//set the Prev to NULL so we only delete this state
		delState->Prev = NULL;
		delete delState;
		
		return true; //indicate success
	}
	
	return false; //indicate failure
}

bool cProcessManager::PopAll( void* CallerPtr )
{
	//check to see if there are states to delete
	if(m_CurrentState != NULL)
	{
		while( m_CurrentState != NULL )
		{
			Pop( CallerPtr );
		}
		
		return true; //indicate success
	}
	
	return false; //indicate failer
}

bool cProcessManager::Process( void* CallerPtr)
{
	//if there is a state then do it
	if(m_CurrentState != NULL)
	{
		m_CurrentState->Function( CallerPtr, FRAME_PURPOSE );
		
		return true; //indicate success
	}
	
	return false; //indicate success
}

*/