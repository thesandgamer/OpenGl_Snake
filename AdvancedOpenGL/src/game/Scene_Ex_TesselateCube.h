#ifndef SCENE_EX_TESSELATECUBE_H
#define SCENE_EX_TESSELATECUBE_H

#pragma once


#include "../engine/Scene.h"
#include "../engine/Assets.h"
#include "../engine/MeshObject.h"

class Scene_Ex_TesselateCube : public Scene {
public:
    Scene_Ex_TesselateCube();
    ~Scene_Ex_TesselateCube();
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
    GLuint vao;
    GLuint buffer;
    
    float totalTime;
    const float timeScale = 0.05f;

    // Uniforms
    Matrix4 mvp;
    Matrix4 view;
    Matrix4 proj;

    Shader shader;

    bool wireframe{false};

    GLsizei IndexCount;
};

#endif