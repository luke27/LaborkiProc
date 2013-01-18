#version 150

uniform mat4 modelViewProjectionMatrix;
in vec4 inPos;
in vec2 inTexCoord;
out vec2 outTexCoord;

void main()
{
	gl_Position = modelViewProjectionMatrix * inPos;
	outTexCoord = inTexCoord;
}
