/*
 * Zad1Rend.cpp
 *
 *  Created on: 17-12-2012
 *      Author: Luke
 */

#include "Zad1Rend.h"

namespace PG {

Zad1Rend::Zad1Rend()
{
	shader = new Shader("z1.vert", "z1.frag", 1);
}

Zad1Rend::~Zad1Rend()
{
	delete shader;
}

} /* namespace PG */


void PG::Zad1Rend::render()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, 480, 480);

	shader->use();
	glGenBuffers(1, VBO);
	glesError("glGenBuffers");

	GLfloat verts[] = {-.25f, 0.0f, 0.0f,
					   0.0f, -.25f, 0.0f,
					   .25f, .0f, 0.0f};


	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 9, verts, GL_STATIC_DRAW);
	posLoc = glGetAttribLocation(shader->getProgram(), "position");
	glVertexAttribPointer(posLoc, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(posLoc);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glDrawArrays(GL_TRIANGLES, 0, 9);


	glDeleteBuffers(1, VBO);


	shader->useOff();
}
