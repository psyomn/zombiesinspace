/**
    Keeps track of the processes within the engine.
    Works as a queue.
    Each process has its own ID.
**/


#include "globals.h"
#include "ePurpose.h"


#ifndef CPROCMAN_H
#define CPROCMAN_H


struct sProcess
{
    sProcess* Next;
    sProcess* Prev;
    void (*Function)(void* CallerPtr, Purpose Purp);
 
    unsigned int Id;
 
    sProcess()
    {
        Prev = NULL;
        Next = NULL;
        Function = NULL;
        Id = 0;
    }
 
    ~sProcess()
    {
        delete Prev;
        delete Next;
    }
};


class cProcessManager
{
    public:
        cProcessManager();
        ~cProcessManager();
        int Push( void (*Function)(void* CallerPtr, Purpose Purp),  void* CallerPtr = NULL);
        bool Pop( unsigned int id, void* CallerPtr = NULL);
        bool PopAll( void* CallerPtr = NULL);
        bool Process( void* CallerPtr = NULL);
 
    private:
        sProcess* m_FirstProcess;
        sProcess* m_LastProcess;
};

#endif CPROCMAN_H

