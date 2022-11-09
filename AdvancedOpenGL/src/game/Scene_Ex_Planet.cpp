#include "Scene_Ex_Planet.h"

#include "../engine/Timer.h"
#include "../engine/MacroUtils.h"

#include <cstdlib>
#include <ctime>
#include <GL/glew.h>


Scene_Ex_Planet::Scene_Ex_Planet()
{
}

Scene_Ex_Planet::~Scene_Ex_Planet() {
    clean();
}

void Scene_Ex_Planet::setGame(Game *_game) {
    game = _game;
}


void Scene_Ex_Planet::load() {
    std::srand((int) std::time(nullptr));

    //Assets::loadShader(SHADER_VERT(SHADER_NAME), SHADER_FRAG(SHADER_NAME), SHADER_TECS(SHADER_NAME), SHADER_TESE(SHADER_NAME), "", SHADER_ID(SHADER_NAME));
    Assets::loadShader(SHADER_VERT(SHADER_NAME), SHADER_FRAG(SHADER_NAME), "", "", "", SHADER_ID(SHADER_NAME));

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glPatchParameteri(GL_PATCH_VERTICES, 3);


    //Génère les points pour le mesh
    static const GLfloat vertexPositions[]=
    {
            -0.25f,  0.25f, -0.25f,
            -0.25f, -0.25f, -0.25f,
             0.25f, -0.25f, -0.25f,

             0.25f, -0.25f, -0.25f,
             0.25f,  0.25f, -0.25f,
            -0.25f,  0.25f, -0.25f,

             0.25f, -0.25f, -0.25f,
             0.25f, -0.25f,  0.25f,
             0.25f,  0.25f, -0.25f,

             0.25f, -0.25f,  0.25f,
             0.25f,  0.25f,  0.25f,
             0.25f,  0.25f, -0.25f,

             0.25f, -0.25f,  0.25f,
            -0.25f, -0.25f,  0.25f,
             0.25f,  0.25f,  0.25f,

            -0.25f, -0.25f,  0.25f,
            -0.25f,  0.25f,  0.25f,
             0.25f,  0.25f,  0.25f,

            -0.25f, -0.25f,  0.25f,
            -0.25f, -0.25f, -0.25f,
            -0.25f,  0.25f,  0.25f,

            -0.25f, -0.25f, -0.25f,
            -0.25f,  0.25f, -0.25f,
            -0.25f,  0.25f,  0.25f,

            -0.25f, -0.25f,  0.25f,
             0.25f, -0.25f,  0.25f,
             0.25f, -0.25f, -0.25f,

             0.25f, -0.25f, -0.25f,
            -0.25f, -0.25f, -0.25f,
            -0.25f, -0.25f,  0.25f,

            -0.25f,  0.25f, -0.25f,
             0.25f,  0.25f, -0.25f,
             0.25f,  0.25f,  0.25f,

             0.25f,  0.25f,  0.25f,
            -0.25f,  0.25f,  0.25f,
            -0.25f,  0.25f, -0.25f
    };

    // Generate data and put it in buffer object
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);

    // Setup vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glEnable(GL_CULL_FACE);
   // glFrontFace(GL_CW);

   // glEnable(GL_DEPTH_TEST);
   // glDepthFunc(GL_LEQUAL);

    shader = Assets::getShader(SHADER_ID(SHADER_NAME));//Set le shader
}

void Scene_Ex_Planet::clean() {
    glDeleteVertexArrays(1, &vao);
}

void Scene_Ex_Planet::pause() {
}

void Scene_Ex_Planet::resume() {
}

void Scene_Ex_Planet::handleEvent(const InputState &inputState) {
    if(inputState.keyboardState.isJustPressed(SDL_SCANCODE_W)) {
        wireframe = !wireframe;
    }
}

void Scene_Ex_Planet::update(float dt) {
    
    const float t = Timer::getTimeSinceStart() * 0.3f;
    transform = Matrix4::createTranslation(Vector3(0.0f, 0.0f, -4.0f))    
        * Matrix4::createRotationY(t * 45.0f / 10.0f)
        * Matrix4::createRotationX(t * 81.0f / 10.0f);
}

void Scene_Ex_Planet::draw() {

    static const GLfloat bgColor[] = {0.2f, 0.26f, 0.38f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, bgColor);
    
    projection = Matrix4::createPerspectiveFOV(45.0f, game->windowWidth, game->windowHeight, 0.1f, 1000.0f);//Créer la vue la camera

    shader.use();
    shader.setMatrix4("mv_matrix", transform);
    shader.setMatrix4("proj_matrix", projection);
    shader.setMatrix4("mvp_matrix", projection * transform);
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    //Dessine en mode wireframe ou pas
    if (wireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

   // glDrawArrays(GL_PATCHES, 0, 36);//Dessin du cube
    glPointSize(5.0f);
    glDrawArraysInstanced(GL_PATCHES, 0, 3, 12);
}
