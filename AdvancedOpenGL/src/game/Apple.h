#ifndef APPLE_H
#define APPLE_H

#pragma once


#include "Actor.h"

class Snake;

class Apple: public Actor
{
public:
    Apple();
    Apple(Vector3 positionP, Vector3 scaleP, Cube* cubeMeshP);
    ~Apple();

    void Update(float dt) override;

    void CheckCollisions();

    void SetSnak(Snake* snakeToCheck){snake = snakeToCheck;}

private:
    Snake* snake;

};

#endif