#version 450 core
/*
    layout (triangles) in;
    layout (triangle_strip, max_vertices = 8) out;

    uniform float stretch = 0.7;

    flat out vec4 color;

    uniform mat4 mvpMatrix;
    uniform mat4 mvMatrix;

    void make_face(vec3 a, vec3 b, vec3 c)
    {
        vec3 face_normal = normalize(cross(c - a, c - b));
        vec4 face_color = vec4(0.55, 0.95, 1.0, 1.0) * (mat3(mvMatrix) * face_normal).z;
        gl_Position = mvpMatrix * vec4(a, 1.0);
        color = face_color;
        EmitVertex();

        gl_Position = mvpMatrix * vec4(b, 1.0);
        color = face_color;
        EmitVertex();

        gl_Position = mvpMatrix * vec4(c, 1.0);
        color = face_color;
        EmitVertex();

        EndPrimitive();
    }

    void main(void)
    {
        vec3 a = gl_in[0].gl_Position.xyz;
        vec3 b = gl_in[1].gl_Position.xyz;
        vec3 c = gl_in[2].gl_Position.xyz;

        vec3 d = (a + b); //* stretch;
        vec3 e = (b + c) ;//* stretch;
        vec3 f = (c + a) ;//* stretch;


        // a *= (2.0 - stretch);
        // b *= (2.0 - stretch);
        // c *= (2.0 - stretch);

        make_face(a, d, f);
        make_face(d, b, e);
        make_face(e, c, f);
        make_face(d, e, f);

        EndPrimitive();
    }
*/

uniform mat4 mvMatrix;
uniform mat4 mvpMatrix;
//uniform mat3 NormalMatrix;
uniform float stretch = 0.7;

layout(triangles) in;
layout(triangle_strip, max_vertices = 8) out;

in vec3 tePosition[3];
in vec3 tePatchDistance[3];

//in vec4 inColor[];
out vec4 color;

//out vec3 gFacetNormal;
//out vec3 gPatchDistance;
//out vec3 gTriDistance;


void main()
{
    //color = vColor;
    //vec3 A = tePosition[2] - tePosition[0];
    //vec3 B = tePosition[1] - tePosition[0];
    //gFacetNormal = NormalMatrix * normalize(cross(A, B));
    
    //gPatchDistance = tePatchDistance[0];
    //gTriDistance = vec3(1, 0, 0);
    gl_Position = gl_in[0].gl_Position; EmitVertex();

    //gPatchDistance = tePatchDistance[1];
    //gTriDistance = vec3(0, 1, 0);
    gl_Position = gl_in[1].gl_Position; EmitVertex();

    //gPatchDistance = tePatchDistance[2];
    //gTriDistance = vec3(0, 0, 1);
    gl_Position = gl_in[2].gl_Position; EmitVertex();

    //vColor = inColor[gl_InvocationID];
   // color = vec4(0.0,0.0,0.0,1.0);

    EndPrimitive();
}