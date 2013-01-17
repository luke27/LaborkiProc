#version 150
uniform mat4 modelViewProjectionMatrix;
in vec4 inPos;
in vec4 inCol;
out vec4 outCol;
in vec3 inNormal;
out vec3 inoutNormal;
out vec3 outPos;
//materia³

void main()
{

	gl_Position = modelViewProjectionMatrix * inPos;
	outCol = inCol;
	inoutNormal = inNormal;
	outPos = inPos.xyz;
}