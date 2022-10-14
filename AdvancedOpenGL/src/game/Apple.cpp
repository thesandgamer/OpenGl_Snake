#include "Apple.h"

#include "../engine/Timer.h"

#include "Snake.h"

Apple::Apple()
{
    SetTransform();
}

Apple::Apple(Vector3 positionP, Vector3 scaleP, Cube* cubeMeshP):
    Actor(positionP,scaleP,cubeMeshP)
{
    rotation.z = 15;

    SetTransform();
}

Apple::~Apple()
{

}

void Apple::Update(float dt)
{
    const float t = Timer::getTimeSinceStart() * 0.3f;
    rotation.z = t * 81.0f / 10.0f;
    rotation.x = t * 81.0f / 10.0f;
    rotation.y = t * 81.0f / 10.0f;

    CheckCollisions();
    SetTransform();


}

void Apple::CheckCollisions()
{
    if (snake->Gethead()->GetPosition().x < position.x + 0.5f &&
    snake->Gethead()->GetPosition().x > position.x -0.5f &&
    snake->Gethead()->GetPosition().y < position.y +.5f &&
    snake->Gethead()->GetPosition().y > position.y -.5f

    )
    {
        //delete this;
        snake->AddSegment();
        position.x =10;
    }
}


