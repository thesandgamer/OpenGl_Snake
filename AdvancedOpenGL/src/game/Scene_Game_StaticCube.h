

#ifndef Scene_Game_StaticCube_H
#define Scene_Game_StaticCube_H

#include "../engine/Scene.h"
#include "../engine/Assets.h"

#include "Snake.h"
#include "Apple.h"

class Scene_Game_StaticCube : public Scene {
public:
    Scene_Game_StaticCube();
    ~Scene_Game_StaticCube();
    void load();
    void clean();
    void pause();
    void resume();
    void handleEvent(const InputState &);
    void update(float dt);
    void draw();
    void setGame(Game *);

    void SpawnApple();

private:
    Game* game;

//----------Mesh du cube utilisé pour les objects
    Cube* cubeMesh;

//----------Lié au rendu graphique des cubes
    Matrix4 projection;
    Shader shader;

//------------Lié au gameplay
    Snake snake;
    std::vector<Apple> apples;

    float timeToSpawnApple = 5.f;
    float currentTime = 0;

};


#endif //Scene_Game_StaticCube_H
