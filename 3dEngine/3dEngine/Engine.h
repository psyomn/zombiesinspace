/**

  @author George Gonis
  @date June 22,2010
  @section DESCRIPTION

  The foundation of the 3d engine.

*/


#ifndef ENGINE_H
#define ENGINE_H


/**
======================================================
INCLUDE ALL INCLUDE FILES HERE
THIS FILE IS SEEN BY ALL AND ALL IS SEEN BY THIS FILE.
THIS FILE IS GOD. YOU MUST OBEY.

ADD "Engine.h" AS AN INCLUDE TO YOUR OTHER FILES.

THAT FILE HAS SPOKEN! THAT IS ALL.
======================================================
**/


#ifdef WIN32
  #include <windows.h> // For the WaitMessage() function.
  #include <iostream>

  using namespace std;
#endif

#ifdef linux
  // load all files needed for linux here
#endif


#include "SDL.h"
#include "SDL_opengl.h" 
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdlib.h>
#include "Camera.h"



// The base engine class. 
class CEngine  
{
private:
	// Last iteration's tick value 
	long m_lLastTick;
 
	// Window width 
	int m_iWidth;
	// Window height 
	int m_iHeight;
    // Bits per pixel 
    int m_iBpp;

	// Has quit been called? 
	bool m_bQuit;
 
	// The title of the window
	const char* m_czTitle;
 
	// Screen surface 
	SDL_Surface* m_pScreen;
 
	// Is the window minimized? 
	bool m_bMinimized;
 
	// Variables to calculate the frame rate 
	// Tick counter. 
	int m_iFPSTickCounter;
 
	// Frame rate counter. 
	int m_iFPSCounter;
 
	// Stores the last calculated frame rate. 
	int m_iCurrentFPS;
 
protected:
	void DoThink();
	void DoRender();
 
	void SetSize(const int& iWidth, const int& iHeight, const int& iBpp);
 
	void HandleInput();
 
public:
	CEngine();
	virtual ~CEngine();
 
	void Init();
	void Start();



	// OVERLOADED - Data that should be initialized when the application starts. 
	virtual void AdditionalInit	() {}
 
	/** OVERLOADED - All the games calculation and updating. 
		@param iElapsedTime The time in milliseconds elapsed since the function was called last.
	*/

	virtual void Think		( const int& iElapsedTime ) {}
	/** OVERLOADED - All the games rendering. 
		@param pDestSurface The main screen surface.
	*/

	virtual void Render		( SDL_Surface* pDestSurface ) {}
 
	// OVERLOADED - Allocated data that should be cleaned up.
	virtual void End		() {}
 
	// OVERLOADED - Window is active again. 
	virtual void WindowActive	() {}
 
	// OVERLOADED - Window is inactive. 
	virtual void WindowInactive	() {}
 
 
	/** OVERLOADED - Keyboard key has been released.
		@param iKeyEnum The key number.
	*/

	virtual void KeyUp		(const int& iKeyEnum) {}
 
	/** OVERLOADED - Keyboard key has been pressed.
		@param iKeyEnum The key number.
	*/

	virtual void KeyDown		(const int& iKeyEnum) {}
 
 
	/**  OVERLOADED - The mouse has been moved.
		@param iButton	Specifies if a mouse button is pressed.
		@param iX	The mouse position on the X-axis in pixels.
		@param iY	The mouse position on the Y-axis in pixels.
		@param iRelX	The mouse position on the X-axis relative to the last position, in pixels.
		@param iRelY	The mouse position on the Y-axis relative to the last position, in pixels.
 
		@bug The iButton variable is always NULL.
	*/

	virtual void MouseMoved		(const int& iButton,
					 const int& iX, 
					 const int& iY, 
					 const int& iRelX, 
					 const int& iRelY) {}
 
	/**  OVERLOADED - A mouse button has been released.
		@param iButton	Specifies if a mouse button is pressed.
		@param iX	The mouse position on the X-axis in pixels.
		@param iY	The mouse position on the Y-axis in pixels.
		@param iRelX	The mouse position on the X-axis relative to the last position, in pixels.
		@param iRelY	The mouse position on the Y-axis relative to the last position, in pixels.
	*/
 
	virtual void MouseButtonUp	(const int& iButton, 
					 const int& iX, 
					 const int& iY, 
					 const int& iRelX, 
					 const int& iRelY) {}
 
	/**  OVERLOADED - A mouse button has been pressed.
		@param iButton	Specifies if a mouse button is pressed.
		@param iX	The mouse position on the X-axis in pixels.
		@param iY	The mouse position on the Y-axis in pixels.
		@param iRelX	The mouse position on the X-axis relative to the last position, in pixels.
		@param iRelY	The mouse position on the Y-axis relative to the last position, in pixels.
	*/

	virtual void MouseButtonDown	(const int& iButton, 
					 const int& iX, 
					 const int& iY, 
					 const int& iRelX, 
					 const int& iRelY) {}
 


	void		SetTitle	( const char* czTitle);
	const char* 	GetTitle	();
 
	SDL_Surface* 	GetSurface	();
 
	int 		GetFPS		();


    // Replaces gluperspective() 
    virtual void perspectiveGL( GLdouble fovY,
                                GLdouble aspect,
                                GLdouble zNear,
                                GLdouble zFar );
};
 
#endif // ENGINE_H 
