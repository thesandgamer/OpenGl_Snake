#include "Scene_Ex_Planet.h"

#include "../engine/Timer.h"
#include "../engine/MacroUtils.h"

#include <cstdlib>
#include <ctime>
#include <GL/glew.h>

const float* tessellationLevels= new float[4]{5.0f, 5.0f, 5.0f, 5.0f};

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

   // Assets::loadShader(SHADER_VERT(SHADER_NAME), SHADER_FRAG(SHADER_NAME), SHADER_TECS(SHADER_NAME), SHADER_TESE(SHADER_NAME), "", SHADER_ID(SHADER_NAME));
   // Assets::loadShader(SHADER_VERT(SHADER_NAME), SHADER_FRAG(SHADER_NAME), "", SHADER_TESE(SHADER_NAME), "", SHADER_ID(SHADER_NAME));
    Assets::loadShader(SHADER_VERT(SHADER_NAME), SHADER_FRAG(SHADER_NAME), "", "", "", SHADER_ID(SHADER_NAME));

    glGenVertexArrays(1, &vao); //Génère le VAO
    glBindVertexArray(vao); //Bind le VAO

    glPatchParameteri(GL_PATCH_VERTICES, 3); //Set le comportement des patchs

   // glPatchParameterfv(GL_PATCH_DEFAULT_INNER_LEVEL,tessellationLevels);
   // glPatchParameterfv(GL_PATCH_DEFAULT_OUTER_LEVEL,tessellationLevels);

    //Génère les points pour le mesh
    /*
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
*/


    const int Faces[] = {
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
/*
static const GLfloat Verts[] =
    {
            0.000f,  0.000f,  1.000f,
            0.943f,  0.000f, -0.333f,
        -0.471f,  0.816f, -0.333f,
        -0.471f, -0.816f, -0.333f
    };

    static const GLushort Faces[] =
    {
        0, 1, 2,
        0, 2, 3,
        0, 3, 1,
        3, 2, 1
    };*/
    IndexCount = sizeof(Verts) ;

    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer); // GL_ELEMENT_ARRAY_BUFFER = vertex array indices
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Verts) + sizeof(Faces), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(Faces), Faces);
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Faces), sizeof(Verts), Verts);

    glBindBuffer(GL_ARRAY_BUFFER, buffer); // GL_ARRAY_BUFFER = vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)sizeof(Faces)); // Define an array of generic vertex attributes data
    glEnableVertexAttribArray(0);

/*
    // Generate data and put it in buffer object
    glGenBuffers(1, &buffer);//On le génère
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);//On le bind au current
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Verts) + sizeof(Faces), NULL, GL_STATIC_DRAW); //Rajoute les vertex dans le buffer

    // Setup vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr); //Défiinit comment on doit lire les données: de 0 à 3, en float,....
    glEnableVertexAttribArray(0);

    GLuint indices;
    glGenBuffers(1, &indices);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Faces), Faces, GL_STATIC_DRAW);*/



   // glEnable(GL_CULL_FACE);
    glDisable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glPatchParameteri(GL_PATCH_VERTICES, 3);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // GL_POINT  GL_LINE  GL_FILL



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
    
    //------------
    projection = Matrix4::createPerspectiveFOV(45.0f, game->windowWidth, game->windowHeight, 0.1f, 1000.0f);//Créer la vue la camera

    shader.use();

    //------------
    shader.setMatrix4("mv_matrix", transform);
    shader.setMatrix4("proj_matrix", projection);
    shader.setMatrix4("mvp_matrix", projection * transform);


    //Dessine en mode wireframe ou pas
    if (wireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


    //glDrawArrays(GL_PATCHES, 0, 36);//Dessin du cube, on prend chacun des vertices et on le dessine 
    glPointSize(5.0f);
    //glDrawArraysInstanced(GL_PATCHES, 0, 3, 12);
    glDrawElements(GL_PATCHES, IndexCount, GL_UNSIGNED_SHORT, NULL); 
}
