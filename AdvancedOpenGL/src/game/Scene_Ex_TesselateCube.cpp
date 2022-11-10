#include "Scene_Ex_TesselateCube.h"
#include "../engine/Timer.h"
#include "../engine/MacroUtils.h"

#include <cstdlib>
#include <ctime>
#include <GL/glew.h>


Scene_Ex_TesselateCube::Scene_Ex_TesselateCube(): totalTime(0) {

}

Scene_Ex_TesselateCube::~Scene_Ex_TesselateCube() {
    clean();
}

void Scene_Ex_TesselateCube::setGame(Game *_game) {
    game = _game;
}

void Scene_Ex_TesselateCube::clean() {
    glDeleteVertexArrays(1, &vao);
}

void Scene_Ex_TesselateCube::pause() {
}

void Scene_Ex_TesselateCube::resume() {
}

void Scene_Ex_TesselateCube::handleEvent(const InputState &inputState) {
 if(inputState.keyboardState.isJustPressed(SDL_SCANCODE_W)) {
        wireframe = !wireframe;
    }
}

void Scene_Ex_TesselateCube::load() {
    //Assets::loadShader(SHADER_VERT(SHADER_NAME), SHADER_FRAG(SHADER_NAME), "", "", "", SHADER_ID(SHADER_NAME));
    Assets::loadShader(SHADER_VERT(SHADER_NAME), SHADER_FRAG(SHADER_NAME), SHADER_TECS(SHADER_NAME), SHADER_TESE(SHADER_NAME), SHADER_GEOM(SHADER_NAME), SHADER_ID(SHADER_NAME));


    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

/*
    const int Indices[] = {
        2, 1, 0,
        3, 2, 0,
        4, 3, 0,
        5, 4, 0,
        1, 5, 0,

        11, 6,  7,
        11, 7,  8,
        11, 8,  9,
        11, 9,  10,
        11, 10, 6,

        1, 2, 6,
        2, 3, 7,
        3, 4, 8,
        4, 5, 9,
        5, 1, 10,

        2,  7, 6,
        3,  8, 7,
        4,  9, 8,
        5, 10, 9,
        1, 6, 10 };

    const float Verts[] = {
         0.000f,  0.000f,  1.000f,
         0.894f,  0.000f,  0.447f,
         0.276f,  0.851f,  0.447f,
        -0.724f,  0.526f,  0.447f,
        -0.724f, -0.526f,  0.447f,
         0.276f, -0.851f,  0.447f,
         0.724f,  0.526f, -0.447f,
        -0.276f,  0.851f, -0.447f,
        -0.894f,  0.000f, -0.447f,
        -0.276f, -0.851f, -0.447f,
         0.724f, -0.526f, -0.447f,
         0.000f,  0.000f, -1.000f };

*/

    static const GLfloat Verts[] =
    {
         0.000f,  0.000f,  1.000f,
         0.943f,  0.000f, -0.333f,
        -0.471f,  0.816f, -0.333f,
        -0.471f, -0.816f, -0.333f
    };

    static const GLushort Indices[] =
    {
        0, 1, 2,
        0, 2, 3,
        0, 3, 1,
        3, 2, 1
    };

/*
   static const GLfloat Verts[] =
    {
        0.25f,  0.25f,   0.25f,
        -0.25f,  -0.25f, 0.25f,
        -0.25f,  0.25f,  0.25f,
        0.25f,  -0.25f, 0.25f,

        0.25f,  0.25f,   -0.25f,
        -0.25f,  -0.25f, -0.25f,
        -0.25f,  0.25f,  -0.25f,
        0.25f,  -0.25f, -0.25f,

    };

    static const GLushort Indices[] =
    {
        0, 1, 3,    
        1, 3, 2,
        0, 3, 1,
        3, 2, 1,

        3, 2, 1,
        3, 2, 1,
        0, 1, 3,    
        1, 3, 2,

        0, 3, 1,
        3, 2, 1,
        3, 2, 1,
        3, 2, 1,

        0, 1, 3,    
        1, 3, 2,
        0, 3, 1,
        3, 2, 1,

        3, 2, 1,
        3, 2, 1,
        0, 1, 3,    
        1, 3, 2,

        0, 3, 1,
        3, 2, 1,
        3, 2, 1,
        3, 2, 1,

       
    };*/
    IndexCount = sizeof(Indices) / sizeof(Indices[0]);

    glPatchParameteri(GL_PATCH_VERTICES, 3);


/*
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Verts) + sizeof(Indices), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(Indices), Verts);
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), sizeof(Verts), Verts);

    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)sizeof(Indices));
    glEnableVertexAttribArray(0);

    glDisable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glPatchParameteri(GL_PATCH_VERTICES, 3);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // GL_POINT  GL_LINE  GL_FILL
    */



    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Verts), Verts, GL_STATIC_DRAW);	

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
 
    // Create the VBO for indices:
    GLuint indices;
    glGenBuffers(1, &indices);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glFrontFace(GL_CW);


/*
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Verts), Verts, GL_STATIC_DRAW);

    // Setup vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
*/
    

    shader = Assets::getShader(SHADER_ID(SHADER_NAME));
}

void Scene_Ex_TesselateCube::update(float dt) {
    totalTime += dt;
}

void Scene_Ex_TesselateCube::draw()
{
    static const GLfloat black[] = {0.02f, 0.89f, 0.81f, 1.0f};
    static const GLfloat one = 1.0f;
    float f = totalTime * timeScale;

    glClearBufferfv(GL_COLOR, 0, black);
    glClearBufferfv(GL_DEPTH, 0, &one);

    float time = (float)SDL_GetTicks()/1000;
    float value =  (abs(cos(time)*10)) ;

    //Pour avoir le rendu avec camera
    proj = Matrix4::createPerspectiveFOV(45.0f, game->windowWidth, game->windowHeight, 0.1f, 1000.0f);
    view = Matrix4::createTranslation(Vector3(0.0f, 0.0f, -8.0f)) *
                            Matrix4::createRotationY(f * 10.0f) *
                            Matrix4::createRotationX(f * 10.0f);

    shader.use();
    shader.setMatrix4("mvpMatrix", proj * view);
    shader.setMatrix4("mvMatrix", view);
    shader.setMatrix4("projMatrix", proj);

    shader.setFloat("TessLevelInner", value);
    shader.setFloat("TessLevelOuter", value);

    if (wireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPointSize(5.0f);

    glDrawElements(GL_PATCHES, IndexCount, GL_UNSIGNED_SHORT, 0); //Draw le mesh
    //glDrawArrays(GL_TRIANGLES, 0, 36);
}
