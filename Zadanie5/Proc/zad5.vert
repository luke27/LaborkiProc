#version 150
uniform mat4 modelViewProjectionMatrix;
in vec4 inPos;
in vec3 normalVec;



void main()
{
	gl_Position = modelViewProjectionMatrix * inPos;
}