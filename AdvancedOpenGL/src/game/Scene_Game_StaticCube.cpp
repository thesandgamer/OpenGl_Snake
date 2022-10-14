

#include "Scene_Game_StaticCube.h"
#include "../engine/MacroUtils.h"

#include <cstdlib>
#include <GL/glew.h>

#include "Cube.h"

#include <stdlib.h>

Scene_Game_StaticCube::Scene_Game_StaticCube()
{
}

Scene_Game_StaticCube::~Scene_Game_StaticCube() {
    clean();
}

void Scene_Game_StaticCube::setGame(Game *_game) {
    game = _game;
}

void Scene_Game_StaticCube::SpawnApple()
{
    int x = -80 + rand() % 150;
    int y = -50 + rand() % 100;

    apples.emplace_back(Vector3(x/10.0f,y/10.0f,-8),Vector3(0.5f,0.5f,0.5f),cubeMesh);
    apples.back().SetSnak(&snake);
    
}

void Scene_Game_StaticCube::load() {

    std::srand((int) std::time(nullptr));
//------------Asset visuel du cube mesh---------
    Assets::loadShader(SHADER_VERT(SHADER_NAME), SHADER_FRAG(SHADER_NAME), "", "", "", SHADER_ID(SHADER_NAME));
    projection = Matrix4::createPerspectiveFOV(70.0f, game->windowWidth, game->windowHeight, 0.1f, 1000.0f);
   
    cubeMesh = new Cube();
    cubeMesh->Load();

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    shader = Assets::getShader(SHADER_ID(SHADER_NAME));

//-----------
    snake.Init(cubeMesh);
    for (int i = 0; i < 2;i++)
    {
        SpawnApple();
    }


}

void Scene_Game_StaticCube::clean() {
    if (cubeMesh != nullptr)
    {
        cubeMesh->Clean();
        delete cubeMesh;
    }

}

void Scene_Game_StaticCube::pause() {
}

void Scene_Game_StaticCube::resume() {
}

void Scene_Game_StaticCube::handleEvent(const InputState &inputState) {
}

void Scene_Game_StaticCube::update(float dt) {
    snake.Update(dt);
    snake.CheckCollisions(game);
    if (currentTime <= timeToSpawnApple)
    {
        currentTime += dt;
    }
    else
    {
        SpawnApple();
        if (timeToSpawnApple < 1)
        {
            timeToSpawnApple --;
        }
        currentTime = 0;
    }


   for (int i = 0; i < apples.size(); i++)
   {
        apples[i].Update(dt);
   }
   
}

void Scene_Game_StaticCube::draw() {

    static const GLfloat bgColor[] = {0.5, 0.2, 0.3, 1.0f};  //Couleur du background de l'écran  
    glClearBufferfv(GL_COLOR, 0, bgColor);

    shader.use();
    shader.setMatrix4("proj_matrix", projection);

    snake.Draw(shader);

    for(Apple apple : apples)
    {
        apple.Draw(shader);
    }
    

}
