#include "headers.h"
#include "LSolid.h"
#include "LShader.h"


class LPiramid : public LSolid
{
public:
	LPiramid()
	{
		glEnable(GL_DEPTH_TEST);
		shader = new LShader("piramid.vert", "piramid.frag");
		program = shader->getProgram();

		
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

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);


		glGenBuffers(1, &posBuff);
		glBindBuffer(GL_ARRAY_BUFFER, posBuff);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		posLoc = glGetAttribLocation(program, "inPos");
		glVertexAttribPointer(posLoc, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		glGenBuffers(1, &colBuff);
		glBindBuffer(GL_ARRAY_BUFFER, colBuff);
		glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
		GLuint colLoc = glGetAttribLocation(program, "inCol");
		glVertexAttribPointer(colLoc, 4, GL_FLOAT, GL_FALSE, 0, NULL);

		glEnableVertexAttribArray(posLoc);
		glEnableVertexAttribArray(colLoc);

		//bufor indeksów i ³adowanie danych
		glGenBuffers(1, &indBuff);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indBuff);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		//w³aczenie tablic wierzcho³ków
		glBindVertexArray(0);

		//wy³¹czenie rysowania tylcnych œcian
		//glEnable(GL_CULL_FACE);

	}

	void draw(matrix4x4<> matrix)
	{
		

		//glProvokingVertex(GL_FIRST_VERTEX_CONVENTION);
		glBindVertexArray(VAO);
		shader->use();
		glUniformMatrix4fv(glGetUniformLocation(program, "modelViewProjectionMatrix" ), 1, GL_FALSE, matrix.data());
		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, NULL);
		shader->useOff();
		glBindVertexArray(0);
	}

	~LPiramid()
	{
		delete shader;
		glDeleteBuffers(1, &posBuff);
		glDeleteBuffers(1, &colBuff);
		glDeleteBuffers(1, &indBuff);
		glDeleteVertexArrays(1, &VAO);

	}

private:
	GLuint VAO;
	GLuint posBuff;
	GLuint colBuff;
	GLuint indBuff;

	GLuint posLoc;
};