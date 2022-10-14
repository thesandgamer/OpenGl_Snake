#ifndef ACTOR_H
#define ACTOR_H

#pragma once

#include "../engine/maths/Matrix4.h"
#include "../engine/maths/Vector2.h"


class Shader;
class Cube;

class Actor
{
public:
    Actor();
    Actor(Vector3 positionP,Vector3 scaleP, Cube* cubeMeshP);
    ~Actor();

    void SetTransform();

    void Draw(Shader& shader);
    virtual void Update(float dt) = 0; 


    Vector3 GetPosition() {return position;}
    void SetPosition(Vector3 newPos)  {position = newPos;}

    Vector2 direction;

protected:
    Matrix4 transform;
    Vector3 position {0,0,0};
    Vector3 scale {1,1,1};
    Vector3 rotation {0,0,0};

    Cube* cubeMesh{nullptr};


};

#endif