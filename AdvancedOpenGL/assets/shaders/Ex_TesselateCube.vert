
#version 450 core

in vec4 vVertex;

out VS_OUT
{
    vec4 color;
} vs_out;

uniform mat4 mvMatrix;
uniform mat4 projMatrix;


void main(void)
{
    gl_Position = projMatrix * mvMatrix * vVertex;
    vs_out.color = vVertex * 2.0 + vec4(0.5, 0.5, 0.5, 0.0);
}