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
#include "Log.h"
#include <GLES2/gl2.h>

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
	glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, 480, 480);

	shader->use();
	glGenBuffers(3, VBO);
	glesError("glGenBuffers");

//	GLfloat verts[] = {-0.25f, 0.25f, 0.0f,
//			0.25f, 0.25f, 0.0f,
//			-0.25f, 0.25f, 0.0f,

//			0.0f, 0.5f, 0.0f,
//			0.5f, -0.5f, -0.5f,
//			0.5f, -0.5f, 0.5f,
//
//			0.0f, 0.5f, 0.0f,
//			0.5f, -0.5f, -0.5f,
//			-0.5f, -0.5f, -0.5f,
//
//			0.0f, 0.5f, 0.0f,
//			-0.5f, -0.5f, 0.5f,
//			-0.5f, -0.5f, -0.5f,
//	};


	 float vertices[] = { // 5 vertices of the pyramid in (x,y,z)
	      -1.0f, -1.0f, -1.0f,  // 0. left-bottom-back
	       1.0f, -1.0f, -1.0f,  // 1. right-bottom-back
	       1.0f, -1.0f,  1.0f,  // 2. right-bottom-front
	      -1.0f, -1.0f,  1.0f,  // 3. left-bottom-front
	       0.0f,  1.0f,  0.0f   // 4. top
	   };

	  float colors[] = {  // Colors of the 5 vertices in RGBA
	      0.0f, 0.0f, 1.0f, 1.0f,  // 0. blue
	      0.0f, 1.0f, 0.0f, 1.0f,  // 1. green
	      0.0f, 0.0f, 1.0f, 1.0f,  // 2. blue
	      0.0f, 1.0f, 0.0f, 1.0f,  // 3. green
	      1.0f, 0.0f, 0.0f, 1.0f   // 4. red
	   };

	   int indices[] = { // Vertex indices of the 4 Triangles
	      2, 4, 3,   // front face (CCW)
	      1, 4, 2,   // right face
	      0, 4, 1,   // back face
	      4, 0, 3    // left face
	   };

	   LOGI("GLES allocated arrays");

//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 9, verts, GL_STATIC_DRAW);
//	posLoc = glGetAttribLocation(shader->getProgram(), "position");
//	glVertexAttribPointer(posLoc, 3, GL_FLOAT, GL_FALSE, 0, NULL);
//	glEnableVertexAttribArray(posLoc);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
//	glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 15, vertices, GL_STATIC_DRAW);
	posLoc = glGetAttribLocation(shader->program, "position");
	glVertexAttribPointer(posLoc, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glesError("GLES vertex buffer");

	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glesError("GLES color buffer BindBuffer");
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 20, colors, GL_STATIC_DRAW);
	glesError("GLES color buffer BufferData");
	colLoc = glGetAttribLocation(shader->program, "color");
	glesError("GLES color GAL");
	glVertexAttribPointer(colLoc, 4, GL_FLOAT, GL_FALSE, 0, NULL);
	glesError("GLES color VATP");
	glesError("GLES color buffer");

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO[2]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * 12, indices, GL_STATIC_DRAW);



	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glEnableVertexAttribArray(posLoc);
	glVertexAttribPointer(posLoc, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glEnableVertexAttribArray(colLoc);
	glVertexAttribPointer(colLoc, 4, GL_FLOAT, GL_FALSE, 0, NULL);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO[2]);
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, NULL);

	glesError("OpenGL ES rendering state");


	glDeleteBuffers(3, VBO);


	shader->useOff();
}
