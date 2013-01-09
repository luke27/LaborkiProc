

#pragma once

#include <math.h>
#include "Vector2.h"

namespace PG
{
	struct Vector3
	{
		union
		{
			///składniki wektora
			float vec[3];
			struct
			{
				///współrzędna x
				float x;
				///współrzędna y
				float y;
				///współrzędna x
				float z;
			};
		};
		/**
		 * konstruktor domyślny
		 * x = 0
		 * y = 0
		 * z = 0
		 */
		Vector3()
		{
			x = y = z = 0.0f;
		}

		/**
		 * Konstruktor
		 * @param x = wartość x
		 * @param y = wartość y
		 * @param z = wartość z
		 */
		Vector3(const float x, const float y,const  float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		/**
		 * Konstructor
		 */
		Vector3(const Vector3 *p)
		{
			x = p->x;
			y = p->y;
			z = p->z;
		}

		/**
		 * Konstruktor kopiujący
		 */
		Vector3(const Vector3 &p)
		{
			x = p.x;
			y = p.y;
			z = p.z;
		}

		/**
		 * Konstruktor
		 * p wskaźnik do wekoru dwuelementowego
		 * z współrzędna z
		 */
		Vector3(const Vector2 *p, const float z = 0.0f)
		{
			x = p->x;
			y = p->y;
			this->z = z;
		}

		/**
		 * Konstruktor
		 * @param p referencja do wektoru dwuelementowego
		 * @param z współrzędna z
		 */
		Vector3(const Vector2 &p, const float z = 0.0f)
		{
			x = p.x;
			y = p.y;
			this->z = z;
		}

		/**
		 * Konstruktor
		 * @param arr tablica 3-elementowa
		 */
		Vector3(const float *arr)
		{
			vec[0] = arr[0];
			vec[1] = arr[1];
			vec[2] = arr[2];
		}

		Vector3 &operator = (const Vector3 &v)
		{
			x = v.x;
			y = v.y;
			z = v.z;
			return *this;
		}

		/** 
		 * Długość wektora
		 * @return długość wektora
		 */
		float getLength() const
		{
			return sqrtf(x * x + y * y + z * z);
		}

		/**
		 * Długość wektora
		 * @return długość
		 */
		float getLength2() const //zmnienić na getSquaredLength
		{
			return x * x + y * y + z * z;
		}

		/**
		 * Długość wektora z bez z
		 * @return długość wektora bez z
		 */
		float getLength2D() const
		{
			return sqrtf(x * x + y * y);
		}

		/**
		 * Kwadratowa długość wektora bez z
		 * @return długość bez z
		 */
		float getSquaredLength2eD() const
		{
			return x * x + y * y;
		}

		/**
		 * Dystans między wektorami
		 * @param v1 wektor
		 * @return dystans
		 */
		float getDistance(const Vector3 v1) const
		{
			return sqrtf((x - v1.x) * (x - v1.x) + (y - v1.y) * (y - v1.y) + (z - v1.z) * (z-v1.z));
		}

		/**
		 * Dystans między wektorami
		 * @param v1 wektor
		 * @return dystans
		 */
		float getSquaredDistance(const Vector3 v1) const
		{
			return (x -v1.x) * (x - v1.x) + (y - v1.y) * (y - v1.y) + (z - v1.z) * (z - v1.z);
		}

		/**
		 * Dystans między wektorami bez z
		 * @param v wektor
		 * @return dystans bez z
		 */
		float getSquaredDistance2D(const Vector3 v) const
		{
			return (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y);
		}
		/**
		 * Metoda liczy wektor znormalizowany
		 * @return wektor znormalizowany
		 */
		Vector3 getNormalized() const
		{
			float len = sqrtf(x * x + y * y + z * z);
			return Vector3(x / len, y /len, z / len);
		}

		/**
		 * normalizuje wektor
		 */
		void normalize()
		{
			float len = sqrtf(x * x + y * y + z * z);
			x /= len;
			y /= len;
			z /= len;
		}
		
		/**
		 * Zeruje wektor
		 */ 
		void zero()
		{
			x = y = z = 0.0f;
		}

		/**
		 * Dodaj i przypisz wektor 2-elementowy
		 */
		Vector3 &operator +=(const Vector2 &v)
		{
			x += v.x;
			y += v.y;
			return *this;
		}

		/**
		 * Dodaj i przypisz wektor 3-elementowy
		 */
		Vector3 &operator +=(const Vector3 &v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}

		/**
		 * Pomnóż przez skalar i przypisz
		 */
		Vector3 &operator *=(const float sk)
		{
			x *= sk;
			y *= sk;
			z *= sk;
			return *this;
		}

		/**
		 * Odejmij i przypisz wektor 2-elementowy
		 */
		Vector3 &operator -=(const Vector2 &v)
		{
			x -= v.x;
			y -= v.y;
			return *this;
		}

		/**
		 * Odejmij i przypisz wektor 3-elementowy
		 */
		Vector3 &operator -=(const Vector3 &v)
		{
			x -= v.x;
			y -= v.y;
			x -= v.z;
			return *this;
		}

		/**
		 * Operator tablicowy
		 */
		float operator[] (const uint32 idx) const
		{
			return vec[idx];
		}

		///obrót o wektor
		Vector3 rotateX(const float angle);

		Vector3 rotateY(const float angle);
	};

	/**
	 * dodawanie wektorów
	 * @param v1 wektor1
	 * @param v2 wektor2
	 * @return nowy wektor
	 */
	 Vector3 operator+ (const Vector3 &v1, const Vector3 &v2);
	

	/**
	 * dodawanie wektorów
	 * @param v1 wektor - typ Vector2
	 * @param v2 wektor - typ Wektor3
	 * @return nowy wektor
	 */
	 Vector3 operator+ (const Vector2 &v1, const Vector3 &v2);
	

	/**
	 * dodawanie wektorów
	 * @param v wektor - typ Vector3
	 * @paramm v1 wektor -typ Vector2
	 * @return nowy wektor
	 */
 	 Vector3 operator+ (const Vector3 &v, const Vector2 &v1);
	

	/**
	 * odejmowanie wektorów
	 * @param v1 wektor1
	 * @param v2 wektor2
	 * @return nowy wektor
	 */
	 Vector3 operator- (const Vector3 &v1, const Vector3 &v2);
	

	/**
	 * odejmowanie wektorów
	 * @param v wektor Vector3
	 * @param v1 wektor Vector2
	 * @return nowy wektor
	 */
	 Vector3 operator- (const Vector3 &v, const Vector2 &v1);
	

	/**
	 * odejmowanie wektorów
	 * @param v wektor Vector2
	 * @param v1 wektor Vector3
	 * @return nowy wektor
	 */
	 Vector3 operator- (const Vector2 &v,const Vector3 &v1);
	

	/**
	 * sprawdzenie czy wektory są równe
	 * @param v wektor1
	 * @param v1 wektor2
	 * @return true - wektory równe, false - nie równe
	 */
	 bool operator== (const Vector3 &v, const Vector3 &v1);
	

	/**
	 * sprawdzenie czy wektory są różne
	 */
	 bool operator!= (const Vector3 &v, const Vector3 &v1);
	

	/**
	 * Mnożenie skalara przez wektor
	 * @param sk skalar
	 * @param v wektor
	 * @return nowy wektor
	 */
	 Vector3 operator* (const float sk, const Vector3 &v);
	

	/**
	 * Mnożenie wektoru przez skalar
	 * @param v wektor
	 * @param sk skalar
	 * @return nowy wektor
	 */ 
	 Vector3 operator* (const Vector3 &v, const float sk);
	

	/**
	 * Iloczyn skalarny 
	 * @param v wektor1
	 * @param v1 wektor2
	 * @return iloczyn skalarny
	 */
	 float operator* (const Vector3 &v,const Vector3 &v1);
	
	
	/**
	 * Iloczyn wektoruwy
	 * @param v wektor1
	 * @param v1 wektor2
	 * @return nowy wektor
	 */
	 Vector3 operator^ (const Vector3 &v, const Vector3 &v1);
	

	typedef Vector3 Vertex;
}
