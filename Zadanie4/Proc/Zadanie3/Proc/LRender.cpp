#include "LRender.h"
#include <stack>
using namespace std;

LRender::LRender(int x, int y)
{
	this->x = x;
	this->y = y;

	scale = 1.0f;
	xRotate = 0.0f;
	yRotate = 0.0f;
	xTranslate = 0.0f;
	yTranslate = 0.0f;

	left = -2.0f;
	right = 2.0f;
	bottom = -2.0f;
	top = 2.0f;
	gnear = 3.0f;
	gfar = 7.0f;

	solid = new LPiramid();
	solid1 = new LPiramid();
}
 
LRender::~LRender()
{
	delete solid;	
	delete solid1;
}
	

void LRender::draw()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	modelViewMatrix.LoadIdentity();
	// przesuniêcie uk³adu wspó³rzêdnych obiektu do œrodka bry³y obcinania
    modelViewMatrix.Translatef( 0.0f, 0.0f, -(gnear + gfar) / 2.0f );
	//modelViewMatrix.Translatef(0.0f, 0.0f, 3.0f);
	//skalowanie
	modelViewMatrix.Scalef(scale, scale, scale);
	//przesuniêcie
	modelViewMatrix.Translatef(xTranslate, yTranslate, 0.0f);
	//rotacja
	modelViewMatrix.Rotatef(xRotate, 1.0f, 0.0f, 0.0f);
	modelViewMatrix.Rotatef(yRotate, 0.0f, 1.0f, 0.0f);
	
	mv.push(modelViewMatrix);

	modelViewProjectionMatrix = transpose(projectionMatrix * mv.top());
	solid->draw(modelViewProjectionMatrix);


	mv.top().Translatef(1.5f, 0.0f, 0.0f);
	mv.push(mv.top());

	//modelViewProjectionMatrix.LoadIdentity();
	modelViewProjectionMatrix = transpose(projectionMatrix * mv.top());
	solid1->draw(modelViewProjectionMatrix);

	mv.top().Translatef(0.0f, 1.5f, 0.0f);
	mv.push(mv.top());
	modelViewProjectionMatrix = transpose(projectionMatrix * mv.top());
	solid1->draw(modelViewProjectionMatrix);

	mv.pop();
	mv.pop();

	mv.push(mv.top());
	mv.top().Translatef(0.0f, -1.5f, 0.0f);
	modelViewProjectionMatrix = transpose(projectionMatrix * mv.top());
	solid1->draw(modelViewProjectionMatrix);
	
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
		solid = new LPiramid();
	}
}

void LRender::changeState()
{
	solid->changeState();
}
