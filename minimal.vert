#version 150 core
#extension GL_ARB_explicit_attrib_location : require

layout(location=0) in vec2 in_pos;

void main(void)
{
	gl_Position.xy=in_pos;
}
