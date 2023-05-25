#ifndef Scene_Ex_ComputeShader_H
#define Scene_Ex_ComputeShader_H

#include "../engine/Scene.h"
#include "../engine/Assets.h"
#include "../engine/MeshObject.h"

constexpr int NUM_ELEMENTS = 25;

struct val
{
    Vector2 pos;
    int value;


};

class Scene_Ex_ComputeShader : public Scene {
public:
    Scene_Ex_ComputeShader();
    ~Scene_Ex_ComputeShader();
    void load();
    void clean();
    void pause();
    void resume();
    void handleEvent(const InputState &);
    void update(float dt);
    void draw();
    void setGame(Game *);

private:
    Game *game;

    GLuint dataBuffer[2];

    val directInputData[NUM_ELEMENTS];
    val directOutputData[NUM_ELEMENTS];

    ComputeShader cShader;
};




#endif //Scene_Ex_ComputeShader_H
