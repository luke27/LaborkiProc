#pragma once
#include "headers.h"
#include "LSolid.h"

#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;



class Zadanie5 : public LSolid
{
public:
	Zadanie5()
	{
		glEnable(GL_DEPTH_TEST);
		flatShading = GL_FALSE; //cieniowanie smooth

		ilewie = 0;
		ileFaces = 0;

		readFromFile();
		readFacesFromFile();


	
	
		
		

		//wczytanie szaderów
		shader = new LShader("zad5.vert", "zad5.frag");
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
		//normalLoc = glGetAttribLocation(program, "normalVec");
		//glVertexAttribPointer(normalLoc, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (const GLvoid *) (4 * sizeof(float)));
	

	

		// w³¹czenie tablic wierzcho³ków
		glEnableVertexAttribArray(posLoc);
		//glEnableVertexAttribArray(normalLoc);
	
		//bufor indeksów i ³adowanie danych
		glGenBuffers(1, &indBuff);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indBuff);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * ileFaces * 3 , &faces[0], GL_STATIC_DRAW);

		//w³aczenie tablic wierzcho³ków
		glBindVertexArray(0);

		//wy³¹czenie rysowania tylcnych œcian
		//glEnable(GL_CULL_FACE);

		
	}

	void draw(matrix4x4<> matrix)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//glProvokingVertex(GL_FIRST_VERTEX_CONVENTION);
		glBindVertexArray(cubeVAO);
		shader->use();
		glUniformMatrix4fv(glGetUniformLocation(program, "modelViewProjectionMatrix" ), 1, GL_FALSE, matrix.data());
		glDrawElements(GL_LINES_ADJACENCY, ileFaces * 3, GL_UNSIGNED_INT, NULL);
		shader->useOff();
		glBindVertexArray(0);
		
	}
	~Zadanie5()
	{
		delete shader;
		glDeleteBuffers(1, &posBuff);
		glDeleteBuffers(1, &colBuff);
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

};