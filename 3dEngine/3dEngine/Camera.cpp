/** 
    Code for first person camera.
**/


#include "Engine.h"


// Default Constructor
Camera::Camera()
{
  xpos = 0;
  ypos = 0;
  zpos = 0;

  xrot = 0;
  yrot = 0;

  m_pCamera = 0;
}


// Destructor
Camera::~Camera()
{
}


// Get x-axis position
GLfloat Camera::getXpos( void )
{
  return xpos;
}


// Get y-axis position
GLfloat Camera::getYpos( void )
{
  return ypos;
}

// Get z-axis position
GLfloat Camera::getZpos( void )
{
  return zpos;
}

// Get x-axis rotation
GLfloat Camera::getXrot( void )
{
  return xrot;
}

// Get y-axis rotation
GLfloat Camera::getYrot( void )
{
  return yrot;
}


// Move camera to the left
void Camera::moveLeft( void )
{
  xpos += 1.0f;
}


// Move camera to the right
void Camera::moveRight( void )
{
  xpos -= 1.0f;
}


// Move camera upward
void Camera::moveUp( void )
{
  ypos -= 1.0f;
}


// Move camera downward
void Camera::moveDown( void )
{
  ypos += 1.0f;
}


// Move camera forward
void Camera::moveForward( void )
{
  zpos -= 1.0f;
}

// Move camera backward
void Camera::moveBackward( void )
{
  zpos += 1.0f;
}


/** ------------------------------------------------
    Mouse movement
-------------------------------------------------**/

// Look up
void Camera::mouseUp( void )
{
  yrot -= 0.05f;
}


// Look down
void Camera::mouseDown( void )
{
  yrot += 0.05f;
}

// Look left
void Camera::mouseLeft( void )
{
  xrot -= 0.05f;
}

// Look right
void Camera::mouseRight( void )
{
  xrot += 0.05f;
}


/**----------------------------------------------
    Saving and getting camera pointer
----------------------------------------------**/

// Return pointer to camera
Camera* Camera::Get_pCamera( void )
{
  return m_pCamera;
}


// Set pointer to camera
void Camera::Set_pCamera( Camera* num )
{
  m_pCamera = num;
}

