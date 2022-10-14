#include "FollowingActor.h"

FollowingActor::FollowingActor()
{
}

FollowingActor::FollowingActor(Vector3 positionP, Vector3 scaleP, Cube* cubeMeshP,Actor* actorToFollowP): 
Actor(positionP,scaleP,cubeMeshP), actorToFollow{actorToFollowP}
{
    SetActorToFollow(actorToFollowP);
    SetTransform();
}

FollowingActor::~FollowingActor()
{

}



void FollowingActor::Update(float dt)
{
    //direction = actorToFollow->direction;
    
}

void FollowingActor::MoveTo(Vector3 pos)
{
    position = ( pos  );
    SetTransform();
}