#include "LRender.h"
#include <stack>
#include "Zadanie5.h"
using namespace std;

LRender::LRender(int x, int y)
{
	this->x = x;
	this->y = y;

	scale = 1.0f;
	xRotate = 50.0f;
	yRotate = 0.0f;
	xTranslate = 0.0f;
	yTranslate = 0.0f;

	left = -2.0f;
	right = 2.0f;
	bottom = -2.0f;
	top = 2.0f;
	gnear = 3.0f;
	gfar = 7.0f;

	solid = new Zadanie5();

}
 
LRender::~LRender()
{
	delete solid;	
}
	

void LRender::draw()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	modelViewMatrix.LoadIdentity();
	// przesuni�cie uk�adu wsp�rz�dnych obiektu do �rodka bry�y obcinania
    modelViewMatrix.Translatef( 0.0f, 0.0f, -(gnear + gfar) / 2.0f );
	//modelViewMatrix.Translatef(0.0f, 0.0f, 3.0f);
	//skalowanie
	modelViewMatrix.Scalef(scale, scale, scale);
	//przesuni�cie
	modelViewMatrix.Translatef(xTranslate, yTranslate, 0.0f);
	//rotacja
	modelViewMatrix.Rotatef(xRotate, 1.0f, 0.0f, 0.0f);
	modelViewMatrix.Rotatef(yRotate, 0.0f, 1.0f, 0.0f);

	modelViewProjectionMatrix = transpose(projectionMatrix * modelViewMatrix);
	solid->draw(modelViewProjectionMatrix);
	
}

void LRender::resize()
{
	glViewport(0, 0, x, y);
	projectionMatrix.LoadIdentity();
	//projectionMatrix.Ortho(left, right, bottom, top, gnear, gfar);
	if(x < y && x > 0)
		projectionMatrix.Frustum(left, right, bottom * y / x, top * y / x, gnear, gfar);
	else
		if(x >= y && y > 0)
			projectionMatrix.Frustum(left * x / y, right * x / y, bottom, top, gnear, gfar);
		else
			projectionMatrix.Frustum(left, right, bottom, top, gnear, gfar);
}

void LRender::scaleDown()
{
	scale -= 0.025f;
}

void LRender::scaleUp()
{
	scale += 0.025f;
}

void LRender::translateLeft()
{
	xTranslate -= 0.025f;
}

void LRender::translateRight()
{
	xTranslate += 0.025f;
}

void LRender::translateUp()
{
	yTranslate += 0.025f;
}

void LRender::translateDown()
{
	yTranslate -= 0.025f;
}

void LRender::neutralize()
{
	scale = 1.0f;
	xTranslate = 0.0f;
	yTranslate = 0.0f;
	xRotate = 0.0f;
	yRotate = 0.0f;
}

void LRender::getRotatexy(GLfloat *x, GLfloat *y)
{
	*x = xRotate;
	*y = yRotate;
}

void LRender::getMAtrix(GLenum type,GLdouble tab[16])
{
	matrix4x4<> tmp;
	if(type == GL_MODELVIEW_MATRIX)
		tmp = modelViewMatrix;
	else
		tmp = projectionMatrix;

	const GLfloat * arr = tmp.data();
	for(int i = 0; i < 16; i++)
	{
		tab[i] = static_cast<GLfloat>(arr[i]);
	}
}

void LRender::setRotation(GLfloat x, GLfloat y)
{
	xRotate = x;
	yRotate = y;
}

void LRender::changeSolid(int obiekt)
{
	actualSolid = obiekt;
	delete solid;
	switch(obiekt)
	{
	
	default:
		solid = new Zadanie5();
	}
}

void LRender::changeState()
{
	solid->changeState();
}
