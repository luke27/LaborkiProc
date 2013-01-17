#pragma once
#include "headers.h"
#include "LSolid.h"

#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

#include "vecmatquat.h"

class Zadanie6 : public LSolid
{
public:
	Zadanie6()
	{

			ambient[0] = 0.25f;
		ambient[1] = 1.25f;
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
		flatShading = GL_FALSE; //cieniowanie smooth

		ilewie = 0;
		ileFaces = 0;

		readFromFile();
		readFacesFromFile();


	
	
		
		

		//wczytanie szaderów
		shader = new LShader("zad6.vert", "zad6.frag");
		program = shader->getProgram();

		//nowy obiekty tablicy wierzcho³ków
		glGenVertexArrays(1, &cubeVAO);
		//zbindowanie
		glBindVertexArray(cubeVAO);


		//bufory i ³adowanie danych wierzcho³ków
		glGenBuffers(1, &posBuff);
		glBindBuffer(GL_ARRAY_BUFFER, posBuff);cout << "Err = " << glGetError() << endl;
		cout << "Ile = " << verts.size() << "VVV = " << ilewie << endl;
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * ilewie * 7 ,verts.data(), GL_STATIC_DRAW);
		cout << "Err = " << glGetError() << endl;
		posLoc = glGetAttribLocation(program, "inPos");
		glVertexAttribPointer(posLoc, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (const GLvoid *) 0);
		normalLoc = glGetAttribLocation(program, "inNormal");
		glVertexAttribPointer(normalLoc, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (const GLvoid *) (4 * sizeof(float)));
	

	

		// w³¹czenie tablic wierzcho³ków
		glEnableVertexAttribArray(posLoc);
		glEnableVertexAttribArray(normalLoc);
	
		//bufor indeksów i ³adowanie danych
		glGenBuffers(1, &indBuff);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indBuff);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * ileFaces * 3 , &faces[0], GL_STATIC_DRAW);

		//w³aczenie tablic wierzcho³ków
		glBindVertexArray(0);

		//wy³¹czenie rysowania tylcnych œcian
		//glEnable(GL_CULL_FACE);

		
	}

	void setMatrixes(matrix4x4<> projMat, matrix4x4<> viewMat, GLfloat x = 0, GLfloat y = 0)
	{
		projectionMatrix = projMat;
		modelViewMatrix = viewMat;
		xR = x;
		yR = y;
	}

	void draw(matrix4x4<> matrix,  matrix4x4<> mvMatrix)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			// odwrócona macierz modelu-widoku niezbêdna do przekszta³ceñ
		// do uk³adu wspó³rzêdnych obiektu
		matrix4x4<> modelViewMatrixInverse( inverse(mvMatrix) );
		// obroty kierunku œwiat³a i jego transformacja do uk³adu wspó³rzêdnych obiektu
		//quaternion<> rotateLightDir( vector3<> ( 1.0f, 0.0f, 0.0f ), 0.0f );
		//rotateLightDir *= quaternion<> ( vector3<> ( 0.0f, 1.0f, 0.0f ), 0.0f);
		vector4<> lightPosition( 0.0f, 0.0f, 1.0f, 0.0f );
		//lightPosition = rotateLightDir.matrix4() * lightPosition;
		lightPosition = modelViewMatrixInverse * lightPosition;
		lightPosition.normalize3();

		// przekszta³cenie po³o¿enia obserwatora do uk³adu wspó³rzêdnych obiektu
		vector4<> observer(0.0f, 0.0f, 0.0f, 1.0f);
		observer = modelViewMatrixInverse * observer;


		//glProvokingVertex(GL_FIRST_VERTEX_CONVENTION);
		glBindVertexArray(cubeVAO);
		shader->use();

		
		glUniform4fv(glGetUniformLocation(program, "lightPos"), 1, lightPosition.data());
		glUniform4fv(glGetUniformLocation(program, "observer"), 1, observer.data());
		//przekazanie w³aœciwoœci materia³u do shadera
		glUniform4fv(glGetUniformLocation(program, "ambient"), 1, ambient);
		glUniform4fv(glGetUniformLocation(program, "diffuse"), 1, diffuse);
		glUniform4fv(glGetUniformLocation(program, "specular"), 1, specular);
		glUniform1f(glGetUniformLocation(program, "shininess"), shininess);


		glUniformMatrix4fv(glGetUniformLocation(program, "modelViewProjectionMatrix" ), 1, GL_FALSE, matrix.data());
		//glUniformMatrix4fv(glGetUniformLocation(program, "MVMatrix" ), 1, GL_FALSE, mvMatrix.data());
		glDrawElements(GL_TRIANGLES, ileFaces * 3, GL_UNSIGNED_INT, NULL);
		shader->useOff();
		glBindVertexArray(0);
		
	}
	~Zadanie6()
	{
		delete shader;
		glDeleteBuffers(1, &posBuff);
		glDeleteBuffers(1, &indBuff);
		glDeleteVertexArrays(1, &cubeVAO);
	}
	void changeState()
	{
	}

	void readFromFile()
	{
		FILE *fvertices=fopen("geode_vertices.dat","r");
		if(fvertices==NULL)
		{
			fprintf(stderr,"cannot open vertices file for reading\n");
		 exit(-1);
		}
	
	    char line[120];
   
	   while(fgets(line,120,fvertices)!=NULL)
	   {
		   float x,y,z;
		   double norm;
		   sscanf(line,"%f %f %f",&x,&y,&z);
  
		   norm=x*x+y*y+z*z;
		   norm=sqrt(norm);
		   ilewie++;

		  // cout << "X = " << x << " Y = " << y << " Z = " << z << endl;
		   verts.push_back(x);
		   verts.push_back(y);
		   verts.push_back(z);
		   verts.push_back(1.0f);
		   verts.push_back(x/norm);
		   verts.push_back(y/norm);
		   verts.push_back(z/norm);
	   }
	}

	
	void readFacesFromFile()
	{
	   FILE *ffaces=fopen("geode_faces.dat","r");
	   if(ffaces==NULL)
	   {
			fprintf(stderr,"cannot open faces file for reading\n");
			exit(-1);
	   }

	    char line[120];
		while(fgets(line,120,ffaces)!=NULL)
		{
		   GLuint  i,j,k;
   
		   if(3!=sscanf(line,"%u %u %u",&i,&j,&k))
		   {
				fprintf(stderr,"error reading faces\n"); 
				exit(-1);
		   }
		   //fprintf(stderr,"%u %u %u\n",i-1,j-1,k-1);
		   ileFaces++;
		   faces.push_back(i-1);
		   faces.push_back(j-1);
		   faces.push_back(k-1);
   
	   }
	   fprintf(stderr,"nf = %u\n",ileFaces);
	}

private:
	//bufory wierzcho³ków wspó³rzêdne i kolory
	GLuint posBuff;
	GLuint colBuff;
	//indentyfikator buffora tablicy indeksów wierzcho³ków
	GLuint indBuff;
	//indetyfikator tablicy wierzcho³ów
	GLuint normalLoc;
	GLuint cubeVAO;
	GLuint posLoc;
	GLboolean flatShading; //zmienna okreœla czy ma byæ u¿yte cieniowanie smooth czy flat;

	vector<GLuint> faces;
	vector<float> verts;
	int ilewie;
	int ileFaces;


	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat shininess;


	matrix4x4<> modelViewMatrix;
	//matrix4x4<> modelViewMatrix2;
	matrix4x4<> projectionMatrix;
	matrix4x4<> vmatrix;
	matrix4x4<> mtmp;
	GLfloat xR, yR;
};