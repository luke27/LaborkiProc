#ifndef _LLIGHTCUBE_H_
#define _LLIGHTCUBE_H_

#include "headers.h"
#include "LSolid.h"

/*!
 * sze�cian demonstruj�cy o�wietlenie
 */
class LLightCube : public LSolid
{
public:
	LLightCube()
	{
		ambient[0] = 0.25f;
		ambient[1] = 0.25f;
		ambient[2] = 0.25f;
		ambient[1] = 1.0f;
		diffuse[0] = 0.4f;
		diffuse[1] = 0.4f;
		diffuse[2] = 0.4f;
		diffuse[3] = 1.0f;
		specular[0] = 0.774597f;
		specular[1] = 0.774597f;
		specular[2] = 0.774597f;
		specular[3] = 1.0f;
		shininess = 76.8f;
		glEnable(GL_DEPTH_TEST);

		//wsp�rz�dne wiecho�k�w
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
		//normalne
		GLfloat normals[8*3] = 
		{
			0.408248f,0.408248f,0.816497f,
			-0.666667f,0.666667f,0.333333f,
			-0.333333f,-0.666667f,0.666667f,
			0.816497f,-0.408248f,0.408248f,
			0.666667f,0.666667f,-0.333333f,
			-0.408248f,0.408248f,-0.816497f,
			-0.816497f,-0.408248f,-0.408248f,
			0.333333f,-0.666667f,-0.666667f
		};
		//kolory
		const GLfloat color[8*3] =
		{
			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f
		};
		//tablica indeks�w
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

		//wczytanie szader�w
		shader = new LShader("LightCube.vert", "LightCube.frag");
		program = shader->getProgram();

		
		//nowy obiekty tablicy wierzcho�k�w
		glGenVertexArrays(1, &cubeVAO);
		//zbindowanie
		glBindVertexArray(cubeVAO);


		//bufory i �adowanie danych wierzcho�k�w
		glGenBuffers(1, &posBuff);
		glBindBuffer(GL_ARRAY_BUFFER, posBuff);
		glBufferData(GL_ARRAY_BUFFER, sizeof(position), position, GL_STATIC_DRAW);
		posLoc = glGetAttribLocation(program, "inPos");
		glVertexAttribPointer(posLoc, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		//bufory i �adowanie danych normalnych
		glGenBuffers(1, &posBuff);
		glBindBuffer(GL_ARRAY_BUFFER, posBuff);
		glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);
		normLoc = glGetAttribLocation(program, "inNormal");
		glVertexAttribPointer(normLoc, 3, GL_FLOAT, GL_FALSE, 0, NULL);


		//bufory i �adowanie kolor�w
		glGenBuffers(1, &colBuff);
		glBindBuffer(GL_ARRAY_BUFFER, colBuff);
		glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);
		GLuint colLoc = glGetAttribLocation(program, "inCol");
		glVertexAttribPointer(colLoc, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		// w��czenie tablic wierzcho�k�w
		glEnableVertexAttribArray(posLoc);
		glEnableVertexAttribArray(colLoc);

		//bufor indeks�w i �adowanie danych
		glGenBuffers(1, &indBuff);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indBuff);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indx), indx, GL_STATIC_DRAW);

		glBindVertexArray(0);
		////�wiat�o
		//glGenVertexArrays(1, &lightVAO);
		//glBindVertexArray(lightVAO);
		//GLfloat lpos[2 * 3] =
		//{
		//	0.0f, 0.0f, 0.0f,
		//	0.0f, 0.0f, 5.0f,
		//};
		//glGenBuffers(1, &lightBuff);
		//glBindBuffer(GL_ARRAY_BUFFER, lightBuff);
		//glBufferData(GL_ARRAY_BUFFER, sizeof(lpos), lpos, GL_STATIC_DRAW);
		//GLuint locL = glGetAttribLocation(shader2->getProgram(), "inPos");
		//glVertexAttribPointer(locL, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		//glEnableVertexAttribArray(locL);
		////w�aczenie tablic wierzcho�k�w
		//glBindVertexArray(0);

		//przekazanie w���ciowo�ci materia�u do shadera
		

		//wy��czenie rysowania tylcnych �cian
		glEnable(GL_CULL_FACE);


	}

	void draw(matrix4x4<> matrix)
	{
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//// odwr�cona macierz modelu-widoku niezb�dna do przekszta�ce�
		//// do uk�adu wsp�rz�dnych obiektu
		//matrix4x4<> modelViewMatrixInverse( inverse( modelViewMatrix ) );
		//// obroty kierunku �wiat�a i jego transformacja do uk�adu wsp�rz�dnych obiektu
		//quaternion<> rotateLightDir( vector3<> ( 1.0f, 0.0f, 0.0f ), 1.0f );
		//rotateLightDir *= quaternion<> ( vector3<> ( 0.0f, 1.0f, 0.0f ), 1.0f);
		//vector4<> lightPosition( 0.0f, 0.0f, 1.0f, 0.0f );
		//lightPosition = rotateLightDir.matrix4() * lightPosition;
		//lightPosition = modelViewMatrixInverse * lightPosition;
		//lightPosition.normalize3();

		//// przekszta�cenie po�o�enia obserwatora do uk�adu wsp�rz�dnych obiektu
		//vector4<> observer(0.0f, 0.0f, 0.0f, 1.0f);
		//observer = modelViewMatrixInverse * observer;

		//glBindVertexArray(cubeVAO);
		//shader->use();
		////matrix4x4<> vmatrix = transpose(projectionMatrix * modelViewMatrix);
		//glUniformMatrix4fv(glGetUniformLocation(program, "modelViewProjectionMatrix" ), 1, GL_FALSE, matrix.data());
		////pozycja �wat�a
	
		//glUniform4fv(glGetUniformLocation(program, "lightPos"), 1, lightPosition.data());
		//glUniform4fv(glGetUniformLocation(program, "observer"), 1, observer.data());
		////przekazanie w�a�ciwo�ci materia�u do shadera
		//glUniform4fv(glGetUniformLocation(program, "ambient"), 1, ambient);
		//glUniform4fv(glGetUniformLocation(program, "diffuse"), 1, diffuse);
		//glUniform4fv(glGetUniformLocation(program, "specular"), 1, specular);
		//glUniform1f(glGetUniformLocation(program, "shininess"), shininess);

		//glDrawElements(GL_TRIANGLES, 12 * 3, GL_UNSIGNED_INT, NULL);
		//shader->useOff();
		//glBindVertexArray(0);
		//glBindVertexArray(lightVAO);

		//// transformacje po�o�enia wektora kierunku �wiat�a
		//modelViewMatrix.LoadIdentity();
		//modelViewMatrix.Translatef( 0.0f, 0.0f, -(3.0f + 7.0f)/2.0f );
		//modelViewMatrix *= rotateLightDir.matrix4();

		//mtmp = modelViewMatrix;

		//shader2->use();
		//matrix4x4<> mvpMatrix = transpose(projectionMatrix * modelViewMatrix);
		//glUniformMatrix4fv(glGetUniformLocation(shader2->getProgram(), "modelViewProjectionMatrix" ), 1, GL_FALSE, mvpMatrix.data());
		//glDrawArrays(GL_LINES, 0, 2);
		//shader2->useOff();

		//glBindVertexArray(0);
		////vmatrix = mvpMatrix;
		return;
	}
	~LLightCube()
	{
		delete shader;
		delete shader2;
		glDeleteBuffers(1, &posBuff);
		glDeleteBuffers(1, &colBuff);
		glDeleteBuffers(1, &indBuff);
		glDeleteVertexArrays(1, &cubeVAO);
	}
	
	void setMatrixes(matrix4x4<> projMat, matrix4x4<> viewMat, GLfloat x = 0, GLfloat y = 0)
	{
		projectionMatrix = projMat;
		modelViewMatrix = viewMat;
		xR = x;
		yR = y;
	}

	matrix4x4<> draw(matrix4x4<> projMat, matrix4x4<> viewMat, GLfloat xR, GLfloat yR)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// odwr�cona macierz modelu-widoku niezb�dna do przekszta�ce�
		// do uk�adu wsp�rz�dnych obiektu
		matrix4x4<> modelViewMatrixInverse( inverse(viewMat) );
		// obroty kierunku �wiat�a i jego transformacja do uk�adu wsp�rz�dnych obiektu
		//quaternion<> rotateLightDir( vector3<> ( 1.0f, 0.0f, 0.0f ), 0.0f );
		//rotateLightDir *= quaternion<> ( vector3<> ( 0.0f, 1.0f, 0.0f ), 0.0f);
		vector4<> lightPosition( 0.0f, 0.0f, 1.0f, 0.0f );
		//lightPosition = rotateLightDir.matrix4() * lightPosition;
		lightPosition = modelViewMatrixInverse * lightPosition;
		lightPosition.normalize3();

		// przekszta�cenie po�o�enia obserwatora do uk�adu wsp�rz�dnych obiektu
		vector4<> observer(0.0f, 0.0f, 0.0f, 1.0f);
		observer = modelViewMatrixInverse * observer;

		glBindVertexArray(cubeVAO);
		shader->use();
		matrix4x4<> vmatrix = transpose(projMat * viewMat);
		glUniformMatrix4fv(glGetUniformLocation(program, "modelViewProjectionMatrix" ), 1, GL_FALSE, vmatrix.data());
		//pozycja �wat�a
	
		glUniform4fv(glGetUniformLocation(program, "lightPos"), 1, lightPosition.data());
		glUniform4fv(glGetUniformLocation(program, "observer"), 1, observer.data());
		//przekazanie w�a�ciwo�ci materia�u do shadera
		glUniform4fv(glGetUniformLocation(program, "ambient"), 1, ambient);
		glUniform4fv(glGetUniformLocation(program, "diffuse"), 1, diffuse);
		glUniform4fv(glGetUniformLocation(program, "specular"), 1, specular);
		glUniform1f(glGetUniformLocation(program, "shininess"), shininess);

		glDrawElements(GL_TRIANGLES, 12 * 3, GL_UNSIGNED_INT, NULL);
		shader->useOff();
		glBindVertexArray(0);
		//glBindVertexArray(lightVAO);

		////// transformacje po�o�enia wektora kierunku �wiat�a
		//viewMat.LoadIdentity();
		//viewMat.Translatef( 0.0f, 0.0f, -(3.0f + 7.0f)/2.0f );
		//viewMat *= rotateLightDir.matrix4();

		//mtmp = modelViewMatrix;

		//shader2->use();
		//matrix4x4<> mvpMatrix = transpose(projMat * viewMat);
		//glUniformMatrix4fv(glGetUniformLocation(shader2->getProgram(), "modelViewProjectionMatrix" ), 1, GL_FALSE, mvpMatrix.data());
		//glDrawArrays(GL_LINES, 0, 2);
		//shader2->useOff();

		//glBindVertexArray(0);
		return viewMat;
	}

private:
	//bufory wierzcho�k�w wsp�rz�dne i kolory
	GLuint posBuff;
	GLuint colBuff;
	//indentyfikator buffora tablicy indeks�w wierzcho�k�w
	GLuint indBuff;
	//indetyfikator tablicy wierzcho��w
	GLuint cubeVAO;
	GLuint posLoc;
	//normalne 
	GLuint normBuff;
	GLuint normLoc;
	//materia� chrom
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat shininess;
	LShader *shader2;
	matrix4x4<> modelViewMatrix;
	//matrix4x4<> modelViewMatrix2;
	matrix4x4<> projectionMatrix;
	matrix4x4<> vmatrix;
	matrix4x4<> mtmp;
	//bufory �wiat�a
	//GLuint lightVAO;
	//GLuint lightBuff;
	GLfloat xR, yR;
	

};


#endif;