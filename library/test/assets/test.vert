#version 450

layout(location = 0) in vec2 i_position;

layout(binding = 0, std140) uniform u_block1
{
    vec2 topLeft;
    vec2 size;
};

void main()
{
    gl_Position = vec4(i_position, 0.5f, 1.0f);
    gl_Position += vec4(topLeft, 0.0, 0.0);
    gl_Position *= vec4(size, 1.0, 1.0);
    gl_Position = (gl_Position * vec4(2.0,-2.0,1.0,1.0)) + vec4(-1.0, 1.0, 0.0, 0.0);
}