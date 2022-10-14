#ifndef MOVINGACTOR_H
#define MOVINGACTOR_H

#pragma once


#include "Actor.h"

class MovingActor: public Actor
{
public:
    MovingActor();
    MovingActor(Vector3 positionP, Vector3 scaleP, Cube* cubeMeshP);
    ~MovingActor();

    void MoveCube();

    void Update(float dt) override;


private:
    float moveSpeed;




};

#endif