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

#include "Camera.h"
#include "Log.h"

using namespace PG;
//#include "Scene.h"
//extern Scene *_scene;

GLfloat _projectionMatrix[16];
GLfloat _viewMatrix[16];
GLfloat _viewRotComponent[9];

Camera::Camera()
{
	LOGV("Camera::Camera begin %d", this);
	//viewMatrix.identityThis();
	//viewMatrix.translate(0.0f, 0.0f, -(0.01 + 1.0f) / 2.0f);
	FOVy = 45.0f;
	near = 0.01f; //3.0f; //0.01f; 
	far = 100.0f; //10.0f lub 7
	upDir = Vector3(0.0f, 1.0f, 0.0f);
	eyePos = Vector3(far, 0.0f, 0.0f);
	forwardDir = Vector3(0.0f, 0.0f, 0.0f);
	yawAngle = pitchAngle = 0.0f;
	oldX = oldY = 0.0f;
	LOGV("Camera::Camera end");
}

//void Camera::look()
//{
//	//LOGV("Camera::look begin addr= %d scene = %d", this, _scene);
//
//	//GLint loc =  glGetUniformLocation(_scene->getProgram(), "u_viewMatrix");
//	//glesError("glGetUniformLocation");
//	//float *p = (float *)viewMatrix.data();
//	//glUniformMatrix4fv(loc, 1, GL_FALSE, p);
//	//lesError("Camera glUniformMatrix4fv");
//
//	LOGV("Camera::look end");
//}

void Camera::setScreenSize(const int x, const int y)
{
	width = x;
	height = y;
	aspectRatio = (float)width / (float)height;
	calcProjectionMatrix();
}




void Camera::setFOVy(const GLfloat fovy)
{
	FOVy = fovy;
}

void Camera::setNear(const GLfloat n)
{
	near = n;
}

void Camera::setFar(const GLfloat f)
{
	far = f;
}

void Camera::getScreenSize(int &x, int &y) const
{
	x = width;
	y = height;
}

GLfloat Camera::getFOVy() const
{
	return FOVy;
}

GLfloat Camera::getNear() const
{
	return near;
}

GLfloat Camera::getFar() const
{
	return far;
}

void Camera::setUpDir(const Vector3 &vec)
{
	upDir = vec;
	upDir.normalize();
	calcViewMatrix();
}

Vector3 &Camera::getUpDir() const
{
	return const_cast<Vector3 &>(upDir);
}

void Camera::setForwardDir(const Vector3 &vec)
{
	forwardDir = vec;
	forwardDir.normalize();
	calcViewMatrix();
}

Vector3 &Camera::getForwardDir() const
{
	return const_cast<Vector3 &>(forwardDir);
}

void Camera::setEyePos(const Vector3 &vec)
{
	eyePos = vec;
	calcViewMatrix();
}

Vector3 &Camera::getEyePis() const
{
	return const_cast<Vector3 &>(eyePos);
}

void Camera::calcProjectionMatrix()
{
	////	OpenGL ver 2
	GLfloat ymax = near * tanf(FOVy * M_PI / 360.0f);
	GLfloat xmax = ymax * aspectRatio;
	GLfloat temp = near * 2.0f;
	GLfloat temp2 = xmax - -xmax;
	GLfloat temp3 = ymax - -ymax;
	GLfloat temp4 = far - near;
	projectionMatrix = Matrix4(temp / temp2, 0.0f, 0.0f, 0.0f,
							   0.0f, temp / temp3, 0.0f, 0.0f,
							  (xmax + -xmax) / temp2, (ymax + -ymax) / temp3, (-far - near) / temp4, -1.0f, 
						       0.0f, 0.0f, (-temp * far) / temp4, 0.0f);
				
}

void Camera::calcViewMatrix()
{
	
	viewMatrix.identityThis();
	viewMatrix.rotate(0.0f, 0.0f, 0.0f, 1.0f);
	viewMatrix.rotate(pitchAngle, 1.0f, 0.0f, 0.0f);
	viewMatrix.rotate(yawAngle, 0.0f, 1.0f, 0.0f);
	viewMatrix.translate(eyePos.x, eyePos.y, eyePos.z);
	viewMatrix.transpose();

	/*Vector3 rLookAt(0.0f, 0.0f, 0.0f);
	rLookAt.rotateX(pitchAngle);
	rLookAt.rotateY(yawAngle);
	Vector3 lookAt = eyePos + rLookAt;

	upDir.rotateX(pitchAngle);
	upDir.rotateY(yawAngle);

	viewMatrix.translate(eyePos.x, eyePos.y, eyePos.z);
	viewMatrix.lookAt(eyePos.x, eyePos.y, eyePos.z, lookAt.x, lookAt.y, lookAt.z, upDir.x, upDir.y, upDir.z);
	viewMatrix.transpose();*/
	
	sendData();
}


inline void Camera::sendData()
{
	memcpy((void *)_projectionMatrix, (const void *)projectionMatrix.data(), sizeof(GLfloat) * 16);
	memcpy((void *)_viewMatrix, (const void *)viewMatrix.data(), sizeof(GLfloat) * 16);
	memcpy((void *)_viewRotComponent, (const void *)viewMatrix.rotationComponent.data(), sizeof(GLfloat) * 9);
}

void Camera::setYaw(const GLfloat angle)
{
	yawAngle = angle;
	calcViewMatrix();
}

void Camera::setPitch(const GLfloat angle)
{
	pitchAngle = angle;
	calcViewMatrix();
}

GLfloat Camera::getYaw() const
{
	return yawAngle;
}

GLfloat Camera::getPitch() const
{
	return pitchAngle;
}

void Camera::setPitchYaw(const GLfloat x, const GLfloat y) 
{
	pitchAngle = x;
	yawAngle = y;
	calcViewMatrix();
}

void Camera::setTouchXY(const GLfloat x, const GLfloat y)
{
	//GLfloat tx = x - oldX;
	////yawAngle += tx / width * 100;
	//if(tx > 0)
	//	yawAngle += 1;
	//else
	//	yawAngle -= 1;

	//GLfloat ty = y - oldY;
	//if(ty > 0)
	//	pitchAngle -= 1;
	//else
	//	pitchAngle += 1;
	/*GLfloat z = 1.0f;
	GLfloat r = sqrtf(x * x + y * y + z * z);
	pitchAngle += atanf(1 / ((sqrtf(x * x + y * y)) / z)) * 0.1f;
	yawAngle += atanf(1 / (z / r)) * 0.1f;*/

	GLfloat tx = x - oldX;
	GLfloat ty = y - oldY;
	LOGV("TX = %f	TY = %f", tx, ty);
	if(tx > 0.0f && abs(tx) > 10)
		yawAngle -= 1.0f;
	else if(abs(tx) > 10.0f)
		yawAngle += 1.0f;
	/*if(ty > 0.0f && abs(ty) > 10)
		pitchAngle -= 1.0f;
	else if(abs(ty) > 10.0f)
		pitchAngle += 1.0f;*/



	oldX = x;
	oldY = y;
	//policzenie nowej macierzy widoku
	calcViewMatrix();
}
