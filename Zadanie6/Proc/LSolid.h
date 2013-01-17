#ifndef _LSOLID_H_
#define _LSOLID_H_

#include "headers.h"
#include "LShader.h"

/*!
 * Klasa s�u��ca do implementacji rysowantch obiekt�w
 */
class LSolid
{
public:
	virtual void draw(matrix4x4<> matrix, matrix4x4<> mvMatrix) = 0;
	GLuint getProgram()
	{
		return program;
	}
	virtual void changeState()
	{
		return;
	}
	virtual void setMatrixes(matrix4x4<> projMat, matrix4x4<> viewMat, GLfloat x = 0, GLfloat y = 0)
	{
		return;
	}
protected:
	/*!
	 program shadera
	 */
	GLuint program;
	/*!
	 * obs�uga shader�w
	 */
	LShader *shader;
};

#endif