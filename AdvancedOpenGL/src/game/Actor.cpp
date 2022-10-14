#include "Actor.h"


#include "../engine/Shader.h"
#include "Cube.h"


#include "../engine/MacroUtils.h"

#include <cstdlib>
#include <GL/glew.h>
#include "../engine/Game.h"

#include <iostream>

Actor::Actor()
{
    position = Vector3(0,0,0);
    scale = Vector3(1,1,1);
    SetTransform();
}

Actor::Actor(Vector3 positionP,Vector3 scaleP, Cube* cubeMeshP):
position{positionP},scale{scaleP},cubeMesh{cubeMeshP}
{
    SetTransform();
}

Actor::~Actor()
{
}

void Actor::SetTransform()
{
    transform =  Matrix4::createTranslation(position)*
                 Matrix4::createScale(scale)*
                 Matrix4::createRotationZ(rotation.z)*
                 Matrix4::createRotationX(rotation.x)*
                 Matrix4::createRotationY(rotation.y);

}

void Actor::Draw(Shader& shader)
{
    shader.setMatrix4("mv_matrix", transform);
    cubeMesh->Draw();

}


/*
void Actor::Update(float dt)
{
    std::cout << "Parent actor update"<<std::endl;
}
*/
