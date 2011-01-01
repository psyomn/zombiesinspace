/**
  @author George Gonis
  @date June 19, 2010
  @section DESCRIPTION

  A 3d engine foundation.
*/


#include "Engine.h"

// Default constructor.
CEngine::CEngine()
{
	m_lLastTick		= 0;
	m_iWidth		= 800;
	m_iHeight		= 600;
    m_iBpp          = 32;
	m_czTitle		= 0;
 
	m_pScreen		= 0;
 
	m_iFPSTickCounter	= 0;
	m_iFPSCounter		= 0;
	m_iCurrentFPS		= 0;
 
	m_bMinimized		= false;
}
 
// Destructor. 
CEngine::~CEngine()
{
	SDL_Quit();
}
 
/** Sets the height and width of the window.
	@param iWidth   The width of the window
	@param iHeight  The height of the window
    @param iBpp     The bits per pixel
*/
void CEngine::SetSize(const int& iWidth, const int& iHeight, const int& iBpp)
{
	m_iWidth  = iWidth;
	m_iHeight = iHeight;
    m_iBpp = iBpp;  

    // Set OpenGL attributes before settign video mode
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );  // 1 for enable, 0 for disabled
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );      // 8 for 24 bit color (32 bit)
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );     // 8 for 24 bit color (32 bit)
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE,8 );     // 8 for 24 bit color (32 bit)
                                                    // 8*3 = 24 bit
    SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32 );  // 32 bit
    
    /** Set the videomode
     
        SDL_FULLSCREEN  for fullscreen
        SDL_NOFRAME     for no border around the window
        SDL_HWSURFACE   for surface to be in video card memory ( Hardware Rendering )
        SDL_SWSURFACE   for surface to be in computer ram ( Software rendering )
        SDL_OPENGL      for use with OpenGL
    */

    m_pScreen = SDL_SetVideoMode( iWidth, iHeight, iBpp, SDL_OPENGL | SDL_HWSURFACE | SDL_FULLSCREEN ); 
    
    // Check if setting video mode was successful
    if( m_pScreen == 0 )
    {
      fprintf( stderr, "Unable to set videomode: %s\n", SDL_GetError() );
      exit( 1 );
    }
}
 
// Initialize SDL, the window and the additional data. 
void CEngine::Init()
{
	// Register SDL_Quit to be called at exit; makes sure things are cleaned up when we quit.
	atexit( SDL_Quit );
 
	// Initialize SDL's subsystems - in this case , graphisc, sound, networking, threading, timers, input handling, init
	if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) 
	{
		fprintf( stderr, "Unable to init SDL: %s\n", SDL_GetError() );
		exit( 1 );
	}
	
	// Attempt to create a window with the specified height and width.
	SetSize( m_iWidth, m_iHeight, m_iBpp );

    glViewport(0, 0, m_iWidth, m_iHeight);      // Initialize viewport to start working with OpenGL
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);   // Clear background color  
    glClearDepth(1.0);                      // Clear depth buffer
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);                // Test for depth (use in 3d)
    glEnable(GL_LIGHTING);            // Enable lighting

// TESTING LIGHT
    GLfloat LightAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat LightDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat LightPosition[]= { 0.0f, 0.0f, -3.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);             
    glLightfv(GL_LIGHT0, GL_AMBIENT, LightDiffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT, LightPosition);
    glEnable(GL_LIGHT0);


    glShadeModel(GL_SMOOTH);                // Smooth polygon sides
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    perspectiveGL( 75, (float)m_iWidth/m_iHeight, 0.1, 100);
    glMatrixMode(GL_MODELVIEW); 


    // If we fail, return error.
    if ( m_pScreen == NULL ) 
    {
      fprintf( stderr, "Unable to set up video: %s\n", SDL_GetError() );
      exit( 1 );
    }

	AdditionalInit();
}
 
// The main loop. 
void CEngine::Start()
{
	m_lLastTick = SDL_GetTicks();
	m_bQuit = false;
 
	// Main loop: loop forever.
	while ( !m_bQuit )
	{
		// Handle mouse and keyboard input
		HandleInput();
 
		if ( m_bMinimized ) {
			// Release some system resources if the app. is minimized.

            // For windows
            #ifdef WIN32
			  WaitMessage(); // pause the application until focus in regained
            #endif

            // For linux
            #ifdef linux
			  // Release some system resources if the app. is minimized.
			  // function equivalent to WaitMessage() in windows
			  // WaitMessage(); // pause the application until focus in regained
            #endif

		} 
        else {
			// Do some thinking
			DoThink();
 
			// Render stuff
			DoRender();
		}
	}
 
	End();
}
 
/** Handles all controller inputs.
	@remark This function is called once per frame.
*/

void CEngine::HandleInput()
{
	// Poll for events, and handle the ones we care about.
	SDL_Event event;
	while ( SDL_PollEvent( &event ) ) 
	{
		switch ( event.type ) 
		{
		case SDL_KEYDOWN:
			// If escape is pressed set the Quit-flag
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				m_bQuit = true;
				break;
			}
 
			KeyDown( event.key.keysym.sym );
			break;
 
		case SDL_KEYUP:
			KeyUp( event.key.keysym.sym );
			break;
 
		case SDL_QUIT:
			m_bQuit = true;
			break;
 
		case SDL_MOUSEMOTION:
			MouseMoved(
				event.button.button, 
				event.motion.x, 
				event.motion.y, 
				event.motion.xrel, 
				event.motion.yrel);
			break;
 
		case SDL_MOUSEBUTTONUP:
			MouseButtonUp(
				event.button.button, 
				event.motion.x, 
				event.motion.y, 
				event.motion.xrel, 
				event.motion.yrel);
			break;
 
		case SDL_MOUSEBUTTONDOWN:
			MouseButtonDown(
				event.button.button, 
				event.motion.x, 
				event.motion.y, 
				event.motion.xrel, 
				event.motion.yrel);
			break;
 
		case SDL_ACTIVEEVENT:
			if ( event.active.state & SDL_APPACTIVE ) {
				if ( event.active.gain ) {
					m_bMinimized = false;
					WindowActive();
				} else {
					m_bMinimized = true;
					WindowInactive();
				}
			}
			break;
		} // switch
	} // while (handling input)
}
 
/** Handles the updating routine. 
*/

void CEngine::DoThink() 
{
	long iElapsedTicks = SDL_GetTicks() - m_lLastTick;
	m_lLastTick = SDL_GetTicks();
 
	Think( iElapsedTicks );
 
	m_iFPSTickCounter += iElapsedTicks;
}
 
/** Handles the rendering and FPS calculations. 
*/

void CEngine::DoRender()
{
    ++m_iFPSCounter;
	if ( m_iFPSTickCounter >= 1000 )
	{
		m_iCurrentFPS = m_iFPSCounter;
		m_iFPSCounter = 0;
		m_iFPSTickCounter = 0;
	}
 
	SDL_FillRect( m_pScreen, 0, SDL_MapRGB( m_pScreen->format, 0, 0, 0 ) );
 
	// Lock surface if needed
	if ( SDL_MUSTLOCK( m_pScreen ) )
		if ( SDL_LockSurface( m_pScreen ) < 0 )
			return;


	Render( GetSurface() );
 
	// Unlock if needed
	if ( SDL_MUSTLOCK( m_pScreen ) ) 
		SDL_UnlockSurface( m_pScreen );


	// Tell SDL to update the whole gScreen
    SDL_GL_SwapBuffers();
//	SDL_Flip( m_pScreen );      // Flips buffer on vsync  ( does not work for  some reason )
}
 
/** Sets the title of the window 
	@param czTitle A character array that contains the text that the window title should be set to.
*/

void CEngine::SetTitle( const char* czTitle)
{
    m_czTitle = czTitle;
	SDL_WM_SetCaption( czTitle, 0 );
}
 
/** Retrieve the title of the application window.
	@return The last set windows title as a character array.
	@remark Only the last set title is returned. If another application has changed the window title, then that title won't be returned.
*/

const char* CEngine::GetTitle()
{
	return m_czTitle;
}
 
/** Retrieve the main screen surface.
	@return A pointer to the SDL_Surface surface
	@remark The surface is not validated internally.
*/

SDL_Surface* CEngine::GetSurface()
{ 
	return m_pScreen;
}
 
/** Get the current FPS.
	@return The number of drawn frames in the last second.
	@remark The FPS is only updated once each second.
*/

int CEngine::GetFPS()
{
	return m_iCurrentFPS;
}

/** Replaces gluPerspective. Sets the frustum to perspective mode.
    fovY   - Field of vision in degrees in the y direction
    aspect - Aspect ratio of the viewport
    zNear   - The near clipping distance
    zFar    - The far clipping distance
*/

void CEngine::perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar )
{
	const GLdouble pi = 3.1415926535897932384626433832795;
	GLdouble fW, fH;

	fH = tan( fovY / 360 * pi ) * zNear;
	fW = fH * aspect;	
	glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}
