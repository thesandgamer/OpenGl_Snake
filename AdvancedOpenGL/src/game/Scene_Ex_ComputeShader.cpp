#include "Scene_Ex_ComputeShader.h"
#include "../engine/Timer.h"
#include "../engine/MacroUtils.h"
#include "../engine/Log.h"

#include <cstdlib>
#include <ctime>
#include <GL/glew.h>


Scene_Ex_ComputeShader::Scene_Ex_ComputeShader() {

}

Scene_Ex_ComputeShader::~Scene_Ex_ComputeShader() {
    clean();
}

void Scene_Ex_ComputeShader::setGame(Game *_game) {
    game = _game;
}

void Scene_Ex_ComputeShader::clean() {

}

void Scene_Ex_ComputeShader::pause() {
}

void Scene_Ex_ComputeShader::resume() {
}

void Scene_Ex_ComputeShader::handleEvent(const InputState &inputState) {

}

void Scene_Ex_ComputeShader::load() {
    Assets::loadComputeShader(SHADER_COMP(SHADER_NAME), SHADER_ID(SHADER_NAME));
    cShader = Assets::getComputeShader(SHADER_ID(SHADER_NAME));


//--------------Setup des données pour le buffer--------------
                //Lit et écrit le stoquage du shader
    glGenBuffers(2, dataBuffer);    //Génère 2 buffer qu'on stoque dans dataBuffer

    val valeurs[25] = { {{0,0},0},{{1,0},0},{{2,0},0},{{2,0},0},{{2,0},0},
                        {{0,0},0},{{1,0},0},{{2,0},0},{{2,0},0},{{2,0},0},
                        {{0,0},0},{{1,0},0},{{2,0},0},{{2,0},0},{{2,0},0},
                        {{0,0},0},{{1,0},0},{{2,0},0},{{2,0},0},{{2,0},0},
                        {{0,0},0},{{1,0},0},{{2,0},0},{{2,0},0},{{2,0},0} 
    };

    glBindBuffer(GL_SHADER_STORAGE_BUFFER, dataBuffer[0]);  //On bind un shader à 0 du dataBuffer
    glBufferData(GL_SHADER_STORAGE_BUFFER, NUM_ELEMENTS*sizeof(val), &valeurs, GL_DYNAMIC_DRAW);//Init le buffer 0 avec ses données
                                                                    //PTR vers données
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, dataBuffer[1]);
    glBufferData(GL_SHADER_STORAGE_BUFFER, NUM_ELEMENTS*sizeof(val), NULL, GL_DYNAMIC_COPY);

   //directInputData[value].value = 1;
    cShader.use();
    glDispatchCompute(1, 1, 1);

/*
    glBindBuffer(GL_ARRAY_BUFFER, dataBuffer[0]);
    val* ptr = reinterpret_cast<val *>(glMapBufferRange(GL_ARRAY_BUFFER, 0, NUM_ELEMENTS * sizeof(val),GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT));
*/
    val* data = new val[25];
    glGetBufferSubData(GL_SHADER_STORAGE_BUFFER,dataBuffer[1],NUM_ELEMENTS*sizeof(val),data);
    
    
    
    for (int i = 0; i < NUM_ELEMENTS; i++)
    {
         //ptr[i].value = 0;
         LOG(Info) <<  data[i].pos.x;
    }

   


    //glUnmapBuffer(GL_ARRAY_BUFFER);


/*
    cShader = Assets::getComputeShader(SHADER_ID(SHADER_NAME));

    int n;
    glGetIntegerv(GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS, &n);

    //Bin les blocs
    glShaderStorageBlockBinding(cShader.id, 0, 0);
    glShaderStorageBlockBinding(cShader.id, 1, 1);*/
}

void Scene_Ex_ComputeShader::update(float dt) {

  //  glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 0, dataBuffer[0], 0, sizeof(val)*NUM_ELEMENTS); //Bind taille  dans le buffer0
  //  glBufferSubData(GL_SHADER_STORAGE_BUFFER, 0, sizeof(val)*NUM_ELEMENTS, directInputData);  //Ajoute les inputData (injection des données  du buffer au bind0 )

   // glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 1, dataBuffer[1], 0, sizeof(val)* NUM_ELEMENTS);//Bind la taille du buffer 1


    //glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, dataBuffer[0]);
    //glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, dataBuffer[1]);

  

    //glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT); //Créer une memeroy barrier 
    //glFinish();

   // glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 0, dataBuffer[1], 0, sizeof(val)* NUM_ELEMENTS);//Le résultat deviens la source
    
  // int * ptr;
  // ptr = (int *)glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, sizeof(val)* NUM_ELEMENTS, GL_MAP_READ_BIT);//Récupère les données finales(qui sont maintenant dans le buffer 0)

    
    /*
    char buffer[25];
    sprintf(buffer, "SUM: %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f "
                    "%2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f",
                    ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7],
                    ptr[8], ptr[9], ptr[10], ptr[11], ptr[12], ptr[13], ptr[14], ptr[15]);
    LOG(Info) << buffer;
    */
    //glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
}

void Scene_Ex_ComputeShader::draw()
{

}