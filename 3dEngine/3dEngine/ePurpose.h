

#ifndef PURPOSE
#define PURPOSE

 enum Purpose
 {
 	STOP_PURPOSE = 0,   // when engine state is stopping
	INIT_PURPOSE,       // when engine state is being initialised
	FRAME_PURPOSE,      // when engine is in game loop
	NO_PURPOSE          // other states
 };
 
 #endif