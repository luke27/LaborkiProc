#version 150
uniform mat4 modelViewProjectionMatrix;
in vec4 inPos;
in vec4 inCol;
out vec4 outColor;

void main()
{
	gl_Position = modelViewProjectionMatrix * inPos;
	outColor = inCol;
	
}