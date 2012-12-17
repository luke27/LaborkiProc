/**
 *
    Copyright (C) 2012 £ukasz Durlej

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
