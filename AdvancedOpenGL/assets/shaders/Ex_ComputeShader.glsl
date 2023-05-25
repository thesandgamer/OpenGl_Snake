#version 450 core

layout (local_size_x = 25) in;

//gl_WorkGroupSize: nombre d'operation

struct val
{
    vec2 pos;
    int value;
};
//Input 
layout (std430, binding = 0) buffer block1
{
    val input_data[];
};
//Output
layout (std430, binding = 1) buffer block2
{
    val output_data[];
};

shared int shared_data[gl_WorkGroupSize.x];

void main(void)
{
    uint id = gl_LocalInvocationID.x;

    uint mask;
    // For each step...
    for (int y=0; y < 9;y++ )
    {
       for (int x=0; x < 9;y++ )
        {
            if(x ==0 && y==0)continue;

            if ( (input_data[id].pos.x + x) == 1)   //A droite
            {
                mask | 00010000;
            }
        
        }
       
    }

    barrier();
    memoryBarrierShared();
    // Finally write our data back to the output image
    output_data[id] = input_data[id]; 

s}