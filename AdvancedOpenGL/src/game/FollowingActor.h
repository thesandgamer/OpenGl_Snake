#ifndef FOLLOWINGACTOR_H
#define FOLLOWINGACTOR_H

#pragma once

#include "../engine/maths/Matrix4.h"
#include "../engine/maths/Vector2.h"

#include "Actor.h"



class FollowingActor: public Actor
{
public:
    FollowingActor();
    FollowingActor(Vector3 positionP, Vector3 scaleP, Cube* cubeMeshP, Actor* actorToFollowP);
    ~FollowingActor();


    void Update(float dt) override;

    void SetActorToFollow(Actor* actor){actorToFollow = actor;}

    void MoveTo(Vector3 pos);

    int placeInQueue{0};

private:
    Actor* actorToFollow {nullptr};
    


};

#endif