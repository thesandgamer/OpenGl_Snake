#version 450 core

layout (vertices = 4) out;
uniform float levelOfTesselation;

void main(void)
{
    if(gl_InvocationID == 0) {
        gl_TessLevelInner[0] = levelOfTesselation;
        gl_TessLevelInner[1] = levelOfTesselation;
        
        gl_TessLevelOuter[0] = levelOfTesselation;
        gl_TessLevelOuter[1] = levelOfTesselation;
        gl_TessLevelOuter[2] = levelOfTesselation;
        gl_TessLevelOuter[3] = levelOfTesselation;
    }
    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
}
