#ifndef SNAKE_H
#define SNAKE_H

#pragma once

#include "FollowingActor.h"
#include "MovingActor.h"

#include <vector>

class Game;

class Snake
{
public:
    Snake();
    ~Snake();

    void Init(Cube* cubeMesh);
    void Update(float dt);
    void Draw(Shader& shader);

    void AddSegment();  

    MovingActor* Gethead(){return &head;}

    void CheckCollisions(Game* _game);

    void Destroy();

private:
    int length {0};

    MovingActor head;

    std::vector<FollowingActor> queue;
    std::vector<Actor*> snakeElements;
    Cube* cubeMesh  ;

    std::vector<Vector3> positionsOfElements;


    //---
    float timeToMove = 0.10f;
    float currentTime = 0;




};

#endif