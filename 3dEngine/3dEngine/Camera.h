/**

  @author George Gonis
  @date August 29,2010
  @section DESCRIPTION

  Store camera values.

*/

#include "Engine.h"

#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
private:
    // Position on x-axis
    GLfloat xpos; 
    // Position on y-axis
    GLfloat ypos;
    // Position on z-axis
    GLfloat zpos;

    // Rotation angle on x-axis
    GLfloat xrot;
    // Rotation angle on y-axis
    GLfloat yrot;

    // Direction of vector  // <---------TEST


    // Pointer to new created camera
    Camera* m_pCamera;

public:
    // Constructor
    Camera();
    // Destructor
    virtual ~Camera();

    // Move camera to the left
    virtual void moveLeft( void );
    // Move camera to the right
    virtual void moveRight( void );
    // Move camera upward
    virtual void moveUp( void );
    // Move camera downward
    virtual void moveDown( void );
    // Move camera forward
    virtual void moveForward( void );
    // Move camera backward
    virtual void moveBackward( void );

    // Look up
    virtual void mouseUp( void );
    // Look down
    virtual void mouseDown( void );
    // Look left
    virtual void mouseLeft( void );
    // Look right
    virtual void mouseRight( void );

    // Get x-axis position
    virtual GLfloat getXpos( void );
    // Get y-axis position
    virtual GLfloat getYpos( void );
    // Get z-axis position
    virtual GLfloat getZpos( void );

    // Get x-axis rotation
    virtual GLfloat getXrot( void );
    // Get y-axis rotation
    virtual GLfloat getYrot( void );    

    // Get pointer of camera
    virtual Camera* Get_pCamera( void );
    // Set pointer of camera
    virtual void Set_pCamera( Camera* );
};

#endif CAMERA_H     // CAMERA_H