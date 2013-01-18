#ifndef _TEXTURE_CUBE_H
#define _TEXTURE_CUBE_H

#include "headers.h"
#include "LSolid.h"
#include "Targa.h"

#include <iostream>

class TextureCube : public LSolid
{
public:
	TextureCube()
	{
		glEnable(GL_DEPTH_TEST);
		//wspó³rzêdne wiecho³ków
		GLfloat position[8*3] =
		{
			1.0f, 1.0f, 1.0f,
			-1.0f, 1.0f, 1.0f,
			-1.0f, -1.0f, 1.0f,
			1.0f, -1.0f, 1.0f,
			1.0f, 1.0f, -1.0f,
			-1.0f, 1.0f, -1.0f,
			-1.0f, -1.0f, -1.0f,
			1.0f, -1.0f, -1.0f
		};
		//tablica wspó³rzêdnych tekstury
		GLfloat texCord[8 * 2] =
		{
			1.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 1.0f,
			1.0f, 1.0f,
		};

		
		//tablica indeksów
		GLuint indx[12*3] =
		{
			5, 1, 0,
			5, 0, 4,
			2, 3, 0,
			2, 0, 1,
			7, 4, 0,
			7, 0, 3,
			3, 2, 6,
			3, 6, 7,
			1, 6, 2,
			1, 5, 6,
			4, 6, 5,
			4, 7, 6
		};

		//wczytanie szaderów
		shader = new LShader("TextureCube.vert", "TextureCube.frag");
		program = shader->getProgram();

		//wczytanie tekstury
		if(LoadTGATexture("tex.tga") == false)
			MessageBoxA(NULL, "Nie mo¿na za³adowaæ tekstury, B³edny plik", "TextureCube.h", MB_OK | MB_ICONERROR);


		//nowy obiekty tablicy wierzcho³ków
		glGenVertexArrays(1, &cubeVAO);
		//zbindowanie
		glBindVertexArray(cubeVAO);


		//bufory i ³adowanie danych wierzcho³ków
		glGenBuffers(1, &posBuff);
		glBindBuffer(GL_ARRAY_BUFFER, posBuff);
		glBufferData(GL_ARRAY_BUFFER, sizeof(position), position, GL_STATIC_DRAW);
		posLoc = glGetAttribLocation(program, "inPos");
		glVertexAttribPointer(posLoc, 3, GL_FLOAT, GL_FALSE, 0, NULL);


		//bufory i ³adowanie texCOrd
		glGenBuffers(1, &texBuff);
		glBindBuffer(GL_ARRAY_BUFFER, texBuff);
		glBufferData(GL_ARRAY_BUFFER, sizeof(texCord), texCord, GL_STATIC_DRAW);
		GLuint texLoc = glGetAttribLocation(program, "inTexCoord");
		glVertexAttribPointer(texLoc, 4, GL_FLOAT, GL_FALSE, 0, NULL);
	

		// w³¹czenie tablic wierzcho³ków
		glEnableVertexAttribArray(posLoc);
		glEnableVertexAttribArray(texLoc);

		//bufor indeksów i ³adowanie danych
		glGenBuffers(1, &indBuff);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indBuff);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indx), indx, GL_STATIC_DRAW);

		//w³aczenie tablic wierzcho³ków
		glBindVertexArray(0);

		std::cout << "posLoc = " << posLoc << endl
			<< "texLoc = " << texLoc << endl;

		//wy³¹czenie rysowania tylcnych œcian
		glEnable(GL_CULL_FACE);

	}
	void draw(matrix4x4<> matrix)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//glProvokingVertex(GL_FIRST_VERTEX_CONVENTION);
		glBindVertexArray(cubeVAO);
		shader->use();
		glUniform1i(glGetAttribLocation(program, "tex"), 0);
		glUniformMatrix4fv(glGetUniformLocation(program, "modelViewProjectionMatrix" ), 1, GL_FALSE, matrix.data());
		glDrawElements(GL_TRIANGLES, 12 * 3, GL_UNSIGNED_INT, NULL);
		shader->useOff();
		glBindVertexArray(0);
	}
	~TextureCube()
	{
		delete shader;
		glDeleteBuffers(1, &posBuff);
		glDeleteBuffers(1, &texBuff);
		glDeleteBuffers(1, &indBuff);
		glDeleteVertexArrays(1, &cubeVAO);
	}
private:
	//bufory wierzcho³ków wspó³rzêdne i kolory
	GLuint posBuff;
	GLuint texBuff;
	//indentyfikator buffora tablicy indeksów wierzcho³ków
	GLuint indBuff;
	//indetyfikator tablicy wierzcho³ów
	GLuint cubeVAO;
	GLuint posLoc;
};

#endif