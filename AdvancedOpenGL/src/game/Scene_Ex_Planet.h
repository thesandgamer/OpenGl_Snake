#ifndef SCENE_EX_PLANET_H
#define SCENE_EX_PLANET_H

#pragma once

#include "../engine/Scene.h"
#include "../engine/Assets.h"

class Scene_Ex_Planet : public Scene {
public:
    Scene_Ex_Planet();
    ~Scene_Ex_Planet();
    void load();
    void clean();
    void pause();
    void resume();
    void handleEvent(const InputState &);
    void update(float dt);
    void draw();
    void setGame(Game *);

    GLsizei IndexCount;


private:
    Game *game;
    GLuint vao;
    GLuint buffer;

    Matrix4 mvp;
    Matrix4 transform;
    Matrix4 projection;

    bool wireframe;

    Shader shader;

};


#endif