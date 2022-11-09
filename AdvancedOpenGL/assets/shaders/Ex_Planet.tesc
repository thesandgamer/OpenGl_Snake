#version 450 core

layout (vertices = 3) out;


void main(void)
{
    if (gl_InvocationID == 0)   //Set les niveaux de tesselation du triangle
    {
        gl_TessLevelInner[0] = 2.0;

        gl_TessLevelOuter[0] = 2.0;
        gl_TessLevelOuter[1] = 2.0;
        gl_TessLevelOuter[2] = 2.0;

    }
    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
}