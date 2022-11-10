#version 450 core
 
layout (triangles, equal_spacing,ccw) in;


/*
uniform mat4 proj_matrix;
uniform mat4 mv_matrix;

out vec3 tePosition;
out vec3 tePatchDistance;
*/
void main(void)
{
    /*
    vec3 p0 = gl_TessCoord.x * gl_in[0].gl_Position;
    vec3 p1 = gl_TessCoord.y * gl_in[1].gl_Position;
    vec3 p2 = gl_TessCoord.z * gl_in[2].gl_Position;

    tePatchDistance = gl_TessCoord;
    tePosition = normalize(p0 + p1 + p2);

    gl_Position = proj_matrix * mv_matrix * vec4(tePosition, 1);
*/

    gl_Position = (gl_TessCoord.x * gl_in[0].gl_Position +
        gl_TessCoord.y * gl_in[1].gl_Position +
        gl_TessCoord.z * gl_in[2].gl_Position);
}