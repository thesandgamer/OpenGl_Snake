#include "MovingActor.h"

#include "../engine/Shader.h"
#include "Cube.h"


#include "../engine/MacroUtils.h"

#include <cstdlib>
#include <GL/glew.h>
#include "../engine/Game.h"


MovingActor::MovingActor()
{
    SetTransform();
}

MovingActor::MovingActor(Vector3 positionP, Vector3 scaleP, Cube* cubeMeshP): 
Actor(positionP,scaleP,cubeMeshP)
{
    moveSpeed = 0.05f;
    direction.x = 1;
    SetTransform();
}

MovingActor::~MovingActor()
{
}

#include <iostream>

void MovingActor::MoveCube()
{

    const Uint8* keystate;
    Vector2 inputMovement {};
    keystate = SDL_GetKeyboardState(NULL);

        if (keystate[SDL_SCANCODE_A] ) {
            inputMovement.x -= moveSpeed;
            direction.x = -1;
            direction.y = 0;
        }
        if (keystate[SDL_SCANCODE_D] ) {
            inputMovement.x += moveSpeed;
            direction.x = 1;
            direction.y = 0;

        }
        if (keystate[SDL_SCANCODE_S] ) {
            inputMovement.y -= moveSpeed;
            direction.y = -1;
            direction.x = 0;



        }
        if (keystate[SDL_SCANCODE_W] ) {
            inputMovement.y += moveSpeed;
            direction.y = 1;
            direction.x = 0;


        }


    //rotation.z += inputMovement.x;     
    position += Vector3(direction.x*moveSpeed,direction.y*moveSpeed,0);
    //Quand on se déplace: prend l'ancinne postion de à qui on est lié et on set notre position à celle ci


   

    SetTransform();

}



void MovingActor::Update(float dt) 
{
    MoveCube();
}
