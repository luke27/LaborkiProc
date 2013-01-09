/**
 *
    Copyright (C) 2012 Łukasz Durlej

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

#pragma once

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"

#include <GLES2/gl2.h>

namespace PG
{
	/**
	 * reprezentacja kamery
	 */
	class Camera
	{
	public:
		Camera();
		///wywoływana przez Scene gdy jest używana kamera
		//void look();
		/**
		 * Ustawienie rozdzielczości ekranu
		 * @param x szerokość ekranu
		 * @param y wysokość ekranu
		 */
		void setScreenSize(const int x, const int y);
		/**
		 * Ustawienie FOVy - kątu widzenia
		 * @param fovy fovy
		 */
		void setFOVy(const GLfloat fovy);
		/**
		 * Ustawienie odległóści rzutowania
		 * @param n near
		 */
		void setNear(const GLfloat n);
		/**
		 * Ustawienie odległóści rzutowania
		 * @param f far
		 */
		void setFar(const GLfloat f);
		/**
		 * Ustawienie kierunku w górę
		 * @param vec Vector3 kierunekj w górę
		 */
		void setUpDir(const Vector3 &vec);
		/**
		 * Ustawienie kierunku patrzenie
		 * @param vec kierunek patrzenia Vector3
		 */
		void setForwardDir(const Vector3 &vec);
		/**
		 * Ustawienie pozycji kamery
		 * @param Vector3 - pozycja kamery
		 */
		void setEyePos(const Vector3 &vec);
		/**
		 * Ustawienie kąta patrzenia wzdłóż y
		 * @param angle kąt
		 */
		void setYaw(const GLfloat angle);
		/**
		 * Ustawienie kąta patrzenie wzdłóż x
		 * @param angle kąt
		 */
		void setPitch(const GLfloat angle);
		/**
		 * Ustawienie kątów patrzenia kamery
		 * @param y kąt
		 * @param p kąt
		 */ 
		void setYawPitch(const GLfloat y, const GLfloat p);
		/**
		 * Ustawienie kątów patrzenia kamery
		 * @param x kąt
		 * @param y kąt
		 */
		void setPitchYaw(const GLfloat x, const GLfloat y);
		/**
		 * Ustawienie pozycji xy palca dotykąjącego ekran
		 * @param x pozycja x
		 * @param y pozycja y
		 */
		void setTouchXY(const GLfloat x, const GLfloat y);

		/**
		 * pobranie rozdzielczości ekranu
		 * @param x referencja zwraca szerokość ekranu
		 * @param y referencja zwraca wysokość ekranu
		 */
		void getScreenSize(int &x, int &y) const;
		/**
		 * Pobranie FOVy
		 * @return FOVy
		 */
		GLfloat getFOVy() const;
		/**
		 * Pobranie obszaru rzutowania near
		 * @return near
		 */
		GLfloat getNear() const;
		/**
		 * Pobranie obszaru rzutowania far
		 * @return far
		 */
		GLfloat getFar() const;
		/**
		 * Pobranie wektoru skierowanego w górę
		 * @param wektor skierowany w górę
		 */
		Vector3 &getUpDir() const;
		/**
		 * Pobranie kierunku patrzenia
		 * @return kierunek patrzenia
		 */
		Vector3 &getForwardDir() const;
		/**
		 * Pobranie pozycji kamery
		 * @return pozycja kamery
		 */
		Vector3 &getEyePis() const;
		/**
		 * Pobranie kąta obrotu kamery wokół y
		 * @return kąt obrotu
		 */
		GLfloat getYaw() const;
		/**
		 * Pobranie kąta obrotu kamery wokół x
		 * @return kąt obrotu
		 */
		GLfloat getPitch() const;
		 
	private:
		/// macierz projekcji
		Matrix4 projectionMatrix;
		/// macierz widoku
		Matrix4 viewMatrix;
		
		/// wektor skierowany w górę
		Vector3 upDir;
		/// wektor z kierunkiem patrzenia kamery
		Vector3 forwardDir;
		/// wektor z pozycją kamery
		Vector3 eyePos;
		/// wektor u
		Vector3 uVec;
		/// kąt nachylenie - y;
		GLfloat yawAngle;
		/// kąt skrętu - x
		GLfloat pitchAngle;
		/// deklaracja przyjaźni z Scene
		friend class Scene;

		/// stara współrzędna X
		GLfloat oldX;
		/// stara współrzędna Y
		GLfloat oldY;

		/// szerokość
		int width;
		/// wysokość
		int height;
		/// kąt widzenia
		GLfloat FOVy;
		/// Odległości rzutowania near
		GLfloat near;
		/// odległóść rzutowania far
		GLfloat far;
		/// Współczynnik proporcji ekranu
		float aspectRatio;

		/// wyliczenie macierzy projekcji
		void calcProjectionMatrix();
		/// wyliczenie macierzy widolu
		void calcViewMatrix();
		/// wysłanie odpowiednich danych
		void sendData();
	};
}
