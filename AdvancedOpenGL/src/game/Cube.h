#ifndef CUBE_H
#define CUBE_H

#include <GL/glew.h>

#pragma once

class Cube
{
public:

    void Load();
    void Clean();
    void Draw();



private:
    GLuint vao;
    GLuint buffer;


};

#endif