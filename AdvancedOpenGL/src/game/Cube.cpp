#include "Cube.h"

#include "../engine/Assets.h"


void Cube::Load()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    static const GLfloat vertexPositions[] =
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
    /*
    static const GLfloat vertexPositions[] =
    {
            -size.x,  size.y, -size.z,
            -size.x, -size.y, -size.z,
             size.x, -size.y, -size.z,

             size.x, -size.y, -size.z,
             size.x,  size.y, -size.z,
            -size.x,  size.y, -size.z,

             size.x, -size.y, -size.z,
             size.x, -size.y,  size.z,
             size.x,  size.y, -size.z,

             size.x, -size.y,  size.z,
             size.x,  size.y,  size.z,
             size.x,  size.y, -size.z,

             size.x, -size.y,  size.z,
            -size.x, -size.y,  size.z,
             size.x,  size.y,  size.z,

            -size.x, -size.y,  size.z,
            -size.x,  size.y,  size.z,
             size.x,  size.y,  size.z,

            -size.x, -size.y,  size.z,
            -size.x, -size.y, -size.z,
            -size.x,  size.y,  size.z,

            -size.x, -size.y, -size.z,
            -size.x,  size.y, -size.z,
            -size.x,  size.y,  size.z,

            -size.x, -size.y,  size.z,
             size.x, -size.y,  size.z,
             size.x, -size.y, -size.z,

             size.x, -size.y, -size.z,
            -size.x, -size.y, -size.z,
            -size.x, -size.y,  size.z,

            -size.x,  size.y, -size.z,
             size.x,  size.y, -size.z,
             size.x,  size.y,  size.z,

             size.x,  size.y,  size.z,
            -size.x,  size.y,  size.z,
            -size.x,  size.y, -size.z
    };*/

    // Generate data and put it in buffer object
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);

    // Setup vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);
}

void Cube::Clean()
{
    glDeleteVertexArrays(1, &vao);
    
}

void Cube::Draw()
{
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

