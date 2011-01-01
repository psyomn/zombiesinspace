/**
  @author George Gonis
  @date June 19, 2010
  @section DESCRIPTION

  Main 3dengine page.
*/


//#define _CRT_SECURE_NO_DEPRECATE  // Compiler bitching that scanf is unsafe so i put this here **MUST BE AT THE TOP**
                                  // before all include files

#include "Engine.h"

class CMyEngine: public CEngine, public Camera
{
public:
	void AdditionalInit ();
	void Think	    ( const int& iElapsedTime );
	void Render	    ( SDL_Surface* pDestSurface );
 
	void KeyUp  	    (const int& iKeyEnum);
	void KeyDown	    (const int& iKeyEnum);
 
	void MouseMoved     (const int& iButton, 
			     const int& iX, 
			     const int& iY, 
			     const int& iRelX, 
		             const int& iRelY);
 
	void MouseButtonUp  (const int& iButton, 
			     const int& iX, 
			     const int& iY, 
			     const int& iRelX, 
		             const int& iRelY);
 
	void MouseButtonDown(const int& iButton, 
			     const int& iX, 
			     const int& iY, 
			     const int& iRelX, 
		             const int& iRelY);
 
	void WindowInactive();
	void WindowActive();
 
	void End();
};
 
 
// Entry point
int main(int argc, char* argv[])  // <- this must match exactly, since SDL rewrites it
{
    CMyEngine Engine;
 
	Engine.SetTitle( "Loading..." );
	Engine.Init();
 
	Engine.SetTitle( "SDL Testing!" );
	Engine.Start();

	Engine.SetTitle( "Quitting..." );
 
	return 0;
}
 
void CMyEngine::AdditionalInit()
{
  // Load up additional data
}
 
void CMyEngine::Think( const int& iElapsedTime )
{
	// Do time-based calculations
}
 
void CMyEngine::Render( SDL_Surface* pDestSurface )
{
	// Display slick graphics on screen

    static GLfloat thetaTri = 0.0f, thetaQuad = 0.0f;
    static GLfloat x = 0.0f;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer 

    glMatrixMode( GL_MODELVIEW );   
    glLoadIdentity();               // Reset Matrix
    gluLookAt( Camera::getXpos(), Camera::getYpos(), Camera::getZpos(), Camera::getXrot(), Camera::getYrot(), -1.0f, 0.0f, 1.0f, 0.0f ); 

glPushMatrix();
    glTranslatef(-1.5f,0.0f,-6.0f);					// Move Left 1.5 Units And Into The Screen 6.0
    glRotatef( thetaTri, 0.0f, 1.0f, 0.0f);			// Rotate The Triangle On The Y axis

	glBegin( GL_TRIANGLES );				// Drawing Using Triangles
      	glColor3f(1.0f,0.0f,0.0f);			// Red
		glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Front)
		glColor3f(0.0f,1.0f,0.0f);			// Green
		glVertex3f(-1.0f,-1.0f, 1.0f);		// Left Of Triangle (Front)
		glColor3f(0.0f,0.0f,1.0f);		    // Blue
		glVertex3f( 1.0f,-1.0f, 1.0f);		// Right Of Triangle (Front)

        glColor3f(1.0f,0.0f,0.0f);			// Red
		glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Right)
		glColor3f(0.0f,0.0f,1.0f);			// Blue
		glVertex3f( 1.0f,-1.0f, 1.0f);      // Left Of Triangle (Right)
		glColor3f(0.0f,1.0f,0.0f);			// Green
		glVertex3f( 1.0f,-1.0f, -1.0f);		// Right Of Triangle (Right)

		glColor3f(1.0f,0.0f,0.0f);			// Red
		glVertex3f( 0.0f, 1.0f, 0.0f);			// Top Of Triangle (Back)
		glColor3f(0.0f,1.0f,0.0f);			// Green
		glVertex3f( 1.0f,-1.0f, -1.0f);			// Left Of Triangle (Back)
		glColor3f(0.0f,0.0f,1.0f);			// Blue
		glVertex3f(-1.0f,-1.0f, -1.0f);			// Right Of Triangle (Back)

		glColor3f(1.0f,0.0f,0.0f);			// Red
		glVertex3f( 0.0f, 1.0f, 0.0f);			// Top Of Triangle (Left)
		glColor3f(0.0f,0.0f,1.0f);			// Blue
		glVertex3f(-1.0f,-1.0f,-1.0f);			// Left Of Triangle (Left)
		glColor3f(0.0f,1.0f,0.0f);			// Green
		glVertex3f(-1.0f,-1.0f, 1.0f);			// Right Of Triangle (Left)
	glEnd();						// Done Drawing The Pyramid
glPopMatrix();

glPushMatrix();
	glTranslatef(1.5f,0.0f,-7.0f);				// Move Right And Into The Screen
	glRotatef( thetaQuad, 1.0f, 1.0f, 1.0f);			// Rotate The Cube On X, Y & Z

	glBegin(GL_QUADS);					// Start Drawing The Cube	
		glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Green
		glVertex3f( 1.0f, 1.0f,-1.0f);			// Top Right Of The Quad (Top)
		glVertex3f(-1.0f, 1.0f,-1.0f);			// Top Left Of The Quad (Top)
		glVertex3f(-1.0f, 1.0f, 1.0f);			// Bottom Left Of The Quad (Top)
		glVertex3f( 1.0f, 1.0f, 1.0f);			// Bottom Right Of The Quad (Top)	

		glColor3f(1.0f,0.5f,0.0f);			// Set The Color To Orange
		glVertex3f( 1.0f,-1.0f, 1.0f);			// Top Right Of The Quad (Bottom)
		glVertex3f(-1.0f,-1.0f, 1.0f);			// Top Left Of The Quad (Bottom)
		glVertex3f(-1.0f,-1.0f,-1.0f);			// Bottom Left Of The Quad (Bottom)
		glVertex3f( 1.0f,-1.0f,-1.0f);			// Bottom Right Of The Quad (Bottom)

		glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Red
		glVertex3f( 1.0f, 1.0f, 1.0f);			// Top Right Of The Quad (Front)
		glVertex3f(-1.0f, 1.0f, 1.0f);			// Top Left Of The Quad (Front)
		glVertex3f(-1.0f,-1.0f, 1.0f);			// Bottom Left Of The Quad (Front)
		glVertex3f( 1.0f,-1.0f, 1.0f);			// Bottom Right Of The Quad (Front)

		glColor3f(1.0f,1.0f,0.0f);			// Set The Color To Yellow
		glVertex3f( 1.0f,-1.0f,-1.0f);			// Bottom Left Of The Quad (Back)
		glVertex3f(-1.0f,-1.0f,-1.0f);			// Bottom Right Of The Quad (Back)
		glVertex3f(-1.0f, 1.0f,-1.0f);			// Top Right Of The Quad (Back)
		glVertex3f( 1.0f, 1.0f,-1.0f);			// Top Left Of The Quad (Back)	

		glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
		glVertex3f(-1.0f, 1.0f, 1.0f);			// Top Right Of The Quad (Left)
		glVertex3f(-1.0f, 1.0f,-1.0f);			// Top Left Of The Quad (Left)
		glVertex3f(-1.0f,-1.0f,-1.0f);			// Bottom Left Of The Quad (Left)
		glVertex3f(-1.0f,-1.0f, 1.0f);			// Bottom Right Of The Quad (Left)

		glColor3f(1.0f,0.0f,1.0f);			// Set The Color To Violet
		glVertex3f( 1.0f, 1.0f,-1.0f);			// Top Right Of The Quad (Right)
		glVertex3f( 1.0f, 1.0f, 1.0f);			// Top Left Of The Quad (Right)
		glVertex3f( 1.0f,-1.0f, 1.0f);			// Bottom Left Of The Quad (Right)
		glVertex3f( 1.0f,-1.0f,-1.0f);			// Bottom Right Of The Quad (Right)
	glEnd();						// Done Drawing The Quad
glPopMatrix(); 

  
    // Draw wall behind everything
glPushMatrix();
    glTranslatef( 0.0f, 0.0f, -10.0f );
    glBegin(GL_QUADS);
        glColor3f( 1.0f, 1.0f, 1.0f );
        glVertex3f( -4.0f, 4.0f, 0.0f );
        glVertex3f( -4.0f, -4.0f, 0.0f );
        glVertex3f( 4.0f, -4.0f, 0.0f );
        glVertex3f( 4.0f, 4.0f, 0.0f );
    glEnd();
glPopMatrix();




    if( thetaTri > 360 )       // Takes care of overflow (Triangle)
        thetaTri = 0.0f;

    if( thetaQuad > 360 )       // Takes care of overflow (Quad)
        thetaQuad = 0.0f;

    // Rotating speed
    thetaTri += 0.01f;
    thetaQuad += 0.05f;
}

void CMyEngine::KeyDown(const int& iKeyEnum)
{       
    switch (iKeyEnum)
    {
    case SDLK_LEFT:
      printf("Pressed LeftArrow\n");
      break;
    case SDLK_RIGHT:
      printf("Pressed RightArrow\n");
      break;
    case SDLK_UP:
      printf("Pressed UpArrow\n");
      break;
    case SDLK_DOWN:
      printf("Pressed DownArrow\n");
      break;
    case SDLK_a:            // Move camera left
      printf("Pressed 'a' \n");
      moveLeft();
      break;
    case SDLK_d:            // Move camera right
      printf("Pressed 'd' \n");
      moveRight();
      break;
    case SDLK_s:            // Move camera backward
      printf("Pressed 's' \n");
      moveBackward();
      break;
    case SDLK_w:            // Move camera forward
      printf("Pressed 'w' \n");
      moveForward();
      break;
  //  case SDLK_d:            // Move camera right
  //    printf("Pressed 'd' \n");
//      moveRight();
 //     break;
    default:
      break;
      
    }
}
 
 
void CMyEngine::KeyUp(const int& iKeyEnum)
{
	switch (iKeyEnum)
	{
	case SDLK_LEFT:
      printf("Released LeftArrow\n");
	  break;
	case SDLK_RIGHT:
      printf("Released RightArrow\n");
	  break;
	case SDLK_UP:
      printf("Released UpArrow\n");
	  break;
	case SDLK_DOWN:
      printf("Released DownArrow\n");
	  break;
    default:
      break;
	}
}
 
void CMyEngine::MouseMoved(const int& iButton, 
			   const int& iX, 
			   const int& iY, 
			   const int& iRelX, 
			   const int& iRelY)
{
	// Handle mouse movement
 
	// iX and iY are absolute screen positions
	// iRelX and iRelY are screen position relative to last detected mouse movement
  printf("Mouse: x-pos: %4d y-pos: %4d\n", iX, iY);
  printf("Mouse: x-pos: %4d y-pos: %4d\n", iRelX, iRelY);
    
    // Check which way mouse moved then move camera accordingly
    if( iRelX > 0 )
        Camera::mouseRight();
    else if( iRelX < 0 )
        Camera::mouseLeft();
    
    if( iRelY > 0 )
        Camera::mouseUp();
    else if( iRelY < 0 )
        Camera::mouseDown();
}
 
void CMyEngine::MouseButtonUp(const int& iButton, 
			      const int& iX, 
			      const int& iY, 
			      const int& iRelX, 
			      const int& iRelY)
{
	// Handle mouse button released
  printf("Mouse button released.\n");
}
 
void CMyEngine::MouseButtonDown(const int& iButton, 
				const int& iX, 
				const int& iY, 
				const int& iRelX, 
				const int& iRelY)
{
	// Handle mouse button pressed
  printf("Mouse button pressed.\n");
}
 
void CMyEngine::WindowInactive()
{
	// Pause game
  printf("Window is now inactive.\n");
}
 
void CMyEngine::WindowActive()
{
	// Un-pause game
  printf("Window is now active.\n");
}
 
 
void CMyEngine::End()
{
	// Clean up
}




/**  FIX IT -------------------------------------------------------------------------
#include "cStateManager.h"
#include "cProcessManager.h"
//#include "example.h"

using namespace std;

void fun1(void* CallerPtr, Purpose Purp);
void fun2(void* CallerPtr, Purpose Purp);
void fun3(void* CallerPtr, Purpose Purp);


int main(int argc, char *argv[])
{	

    cStateManager StateMan;
     
    cout << "  <process>" << endl;
    StateMan.Process(NULL);
     
    cout << "  <change to fun1>" << endl;
    StateMan.Push(fun1, NULL);
     
    cout << "  <change to fun2>" << endl;
    StateMan.Push(fun2, NULL);
     
    cout << "  <process>" << endl;
    StateMan.Process(NULL);
     
    cout << "  <kill fun2>" << endl;
    StateMan.Pop();
     
    cout << "  <change to fun3>" << endl;
    StateMan.Push(fun3);
     
    cout << "  <process>" << endl;
    StateMan.Process(NULL);
     
    cout << "  <kill all>" << endl;
    StateMan.PopAll(NULL);
     
    cout << "  <process>" << endl;
    StateMan.Process(NULL);


cProcessManager ProcMan;
 
    cout << "  <process>" << endl;
    ProcMan.Process(NULL);
 
    cout << "  <create fun1>" << endl;
    int id1 = ProcMan.Push(fun1, NULL);
 
    cout << "  <create fun2>" << endl;
    ProcMan.Push(fun2, NULL);
 
    cout << "  <process>" << endl;
    ProcMan.Process(NULL);
 
    cout << "  <kill fun1>" << endl;
    ProcMan.Pop(id1);
 
    cout << "  <create fun 3>" << endl;
    ProcMan.Push(fun3);
 
    cout << "  <process>" << endl;
    ProcMan.Process(NULL);
 
    cout << "  <kill all>" << endl;
    ProcMan.PopAll(NULL);
 
    cout << "  <process>" << endl;
    ProcMan.Process(NULL);
	
    return 0;
}

void fun1(void* CallerPtr, Purpose Purp)
{
    switch(Purp)
    {
        case STOP_PURPOSE:
            cout << "fun1 Stopping" << endl;
            break;
        case INIT_PURPOSE:
            cout << "fun1 Starting" << endl;
            break;
        case FRAME_PURPOSE:
            cout << "fun1 processing" << endl;
            break;
        default:
            cout << "fun1 no purpose" << endl;
            break;
    }
}
 
void fun2(void* CallerPtr, Purpose Purp)
{
 
    switch(Purp)
    {
        case STOP_PURPOSE:
            cout << "fun2 Stopping" << endl;
            break;
        case INIT_PURPOSE:
            cout << "fun2 Starting" << endl;
            break;
        case FRAME_PURPOSE:
            cout << "fun2 processing" << endl;
            break;
        default:
            cout << "fun2 no purpose" << endl;
            break;
    }
 
}
 
void fun3(void* CallerPtr, Purpose Purp)
{
 
    switch(Purp)
    {
        case STOP_PURPOSE:
            cout << "fun3 Stopping" << endl;
            break;
        case INIT_PURPOSE:
            cout << "fun3 Starting" << endl;
            break;
        case FRAME_PURPOSE:
            cout << "fun3 processing" << endl;
            break;
        default:
            cout << "fun3 no purpose" << endl;
            break;
    }
 
}
 
*/