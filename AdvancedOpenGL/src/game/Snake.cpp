#include "Snake.h"

#include "../engine/Game.h"
#include <iostream>
Snake::Snake()
{

}

Snake::~Snake()
{

}

void Snake::Init(Cube* cubeMesh)
{
    cubeMesh = cubeMesh;
    head = {Vector3(0,0,-8),Vector3(1.f,1.f,1.f),cubeMesh};
    positionsOfElements.emplace_back(head.GetPosition());
    snakeElements.emplace_back(&head);

    for (int i = 0; i < snakeElements.size(); i++)
    {
        positionsOfElements.emplace_back(snakeElements[i]->GetPosition());
    }


}



void Snake::Update(float dt)
{
    if(snakeElements.capacity() <=0 ) return;
    for (int i = 0; i < snakeElements.size(); i++)
    {
        snakeElements[i]->Update(dt);
    }

    if (currentTime <= timeToMove)
    {
        currentTime += dt;
    }
    else
    {
        
        for (int i = 0; i < snakeElements.size(); i++)
        {
            positionsOfElements[i] = snakeElements[i]->GetPosition();
        }

        for (int i = 1; i < snakeElements.size(); i++)
        {
            // positionsOfElements[i] = static_cast<FollowingActor*>(snakeElements[i]->GetPosition());
             //static_cast<FollowingActor*>(snakeElements[i])->MoveTo(snakeElements[i-1]->GetPosition());
             static_cast<FollowingActor*>(snakeElements[i])->MoveTo(positionsOfElements[i-1]);
        }
        currentTime = 0;

       

    }


    
}

void Snake::Draw(Shader& shader)
{
   for (int i = 0; i < snakeElements.size(); i++)
    {
        snakeElements[i]->Draw(shader);
    }

}

void Snake::AddSegment()
{
    Vector3 spawnLocation = Vector3(snakeElements.back()->GetPosition().x,
                                    snakeElements.back()->GetPosition().y,-8);

    FollowingActor* queuePart = new FollowingActor(spawnLocation,Vector3(0.7f,0.7f,0.7f),cubeMesh, snakeElements[snakeElements.size()-1]);
   // queuePart->SetActorToFollow(snakeElements[snakeElements.size()-1]);
  //  queuePart->placeInQueue = snakeElements.size();
   // queue.emplace_back (*queuePart);
    snakeElements.emplace_back(queuePart);

    positionsOfElements.emplace_back(snakeElements.back()->GetPosition());



    //positionsOfElements.emplace_back(queue[length].GetPosition());
    //length++;

    
}

//Les collisions ici c'est pas terrible, faire autrement
void Snake::CheckCollisions(Game* _game)
{
    //Très sale de faire comme ça, préférer faire 4 murs
    if (head.GetPosition().x < -6.5f ||
    head.GetPosition().x >  6.5f||
    head.GetPosition().y < -4||
    head.GetPosition().y > 4 )
    {
        std::cout <<"Destroy"<<std::endl;
        Destroy();
    }


    //Il faudrait faire les collisons avec les parties du corps, mais pas avec les première parceque
    //elle sont dans la tête
    
    for (int i = 2; i < snakeElements.size(); i++)
    {
            if (head.GetPosition().x < snakeElements[i]->GetPosition().x + 0.12f &&
        head.GetPosition().x > snakeElements[i]->GetPosition().x -0.12f &&
        head.GetPosition().y < snakeElements[i]->GetPosition().y +0.12f &&
        head.GetPosition().y > snakeElements[i]->GetPosition().y -0.12f )
        {
            //delete this;
            Destroy();

        }
    }
    
    
}

void Snake::Destroy()
{
    for (size_t i = 0; i < snakeElements.size(); i++)
    {
        snakeElements[i]->SetPosition(Vector3(-10,10,10));
    }
    
}