

#pragma once

#include "Vector3.h"

namespace PG
{
	/**
	 * Wektor 4-elementowy
	 */
	struct Vector4
	{
		union
		{
			///składniki wektora
			float vec[4];
			struct
			{
				///składnik x
				float x;
				///składnik y
				float y;
				///składnik z
				float z;
				///składnik w
				float w;
			};
		};
		/**
		 * Konstruktor domyślny
		 */
		Vector4()
		{
			x = y = z = w = 0.0f;
		}

		/**
		 * Konstruktor
		 * @param x x
		 * @param y y
		 * @param z z
		 * @param w w
		 */
		Vector4(const float x, const float y, const float z, const float w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		/**
		 * Konstruktor
		 * @param p wskaźnik do Vector4
		 */
		Vector4(const Vector4 *p)
		{
			x = p->x;
			y = p->y;
			z = p->z;
			w = p->w;
		}

		/**
		 * Konstruktor kopiujący
		 * @param v Vector4
		 */
		Vector4(const Vector4 &v)
		{
			x = v.x;
			y = v.y;
			z = v.z;
			w = v.w;
		}

		/**
		 * Konstruktor
		 * @param p wskaźnik do Vector2
		 * @param z składowa z
		 * @param w składowa w
		 */
		Vector4(const Vector2 *p, const float z = 0.0f, const float w = 0.0f)
		{
			x = p->x;
			y = p->y;
			this->z = z;
			this->w = w;
		}

		/**
		 * Konstruktor
		 * @param v Vector2
		 * @param z z
		 * @param w w
		 */
		Vector4(const Vector2 &v, const float z = 0.0f, const float w = 0.0f)
		{
			x = v.x;
			y = v.y;
			this->z = z;
			this->w = w;
		}

		/**
		 * Konstruktor
		 * @param wskaźnik do Vector3
		 * @param w w
		 */
		Vector4(const Vector3 *p, const float w = 0.0f)
		{
			x = p->x;
			y = p->y;
			z = p->z;
			this->w = w;
		}

		/**
		 * Konstruktor
		 * @param v Vector3
		 * @param w w
		 */
		Vector4(const Vector3 &v, const float w = 0.0f)
		{
			x = v.x;
			y = v.y;
			z = v.z;
			this->w = w;
		}

		/**
		 * Konstruktor
		 * @param arr tablica 4-elementowa
		 */
		Vector4(const float *arr)
		{
			vec[0] = arr[0];
			vec[1] = arr[1];
			vec[2] = arr[2];
			vec[3] = arr[3];
		}

		/**
		 * Długość
		 * @return długość
		 */
		float getLength() const
		{
			return sqrtf(x * x  + y * y + z * z + w * w);
		}

		/**
		 * Długość
		 * @return długość
		 */
		float getSquaredLength() const
		{
			return x * x + y * y + z * z + w * w;
		}
		/**
		 * Normalizacja wektora
		 */
		float normalize()
		{
			float len = getLength();
			x = 1 / len;
			y = 1 / len;
			z = 1 / len;
			w = 1 / len;
		}

		/**
		 * Zerowanie wektoru
		 */
		void zero()
		{
			x = y =z = w = 0.0f;
		}

		/**
		 * Dodaj i przypisz wektor 2-elementowy
		 */
		Vector4 &operator+= (const Vector2 &v)
		{
			x += v.x;
			y += v.y;
			return *this;
		}

		/**
		 * Dodaj i przypisz wektor 3-elementowy
		 */
		Vector4 &operator+= (const Vector3 &v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}

		/**
		 * Dodaj i przypisz wektor 4-elementowy
		 */
		Vector4 &operator+= (const Vector4 &v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			w += v.w;
			return *this;
		}

		/**
		 * Pomnóż przez skalar i przypisz
		 */
		Vector4 &operator*= (const float sk)
		{
			x *= sk;
			y *= sk;
			z *= sk;
			w *= sk;
			return *this;
		}

		/**
		 * Odejmij wektor 2-elementowy i przypisz
		 */
		Vector4 &operator-= (const Vector2 &v)
		{
			x -= v.x;
			y -= v.y;
			return *this;
		}

		/**
		 * Odejmij i przypisz wektor 3-elementowy
		 */
		Vector4 &operator-= (const Vector3 &v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}

		/**
		 * Odejmij i przypisz wektor 4-elementowy
		 */
		Vector4 &operator-= (const Vector4 &v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			w -= v.z;
		}

		/**
		 * Operator tablicowy
		 * @return odpowiednia wartość skłanika wektora
		 */
		float operator[] (const uint32 idx) const
		{
			return vec[idx];
		}
	};

	/**
	 * Dodawanie wektorów
	 * @param v Vector4
	 * @param v1 Vector2
	 * @return Vector4
	 */
	 Vector4 operator+ (const Vector4 &v, const Vector2 &v1);
	
	/**
	 * Dodawanie wektorów
	 * @param v Vector2
	 * @param v1 Vector4
	 * @return Vector4
	 */
	 Vector4 operator+ (const Vector2 &v, const Vector4 &v1);
	
	/**
	 * Dodawanie wektorów
	 * @param v Vector4
	 * @param v1 Vector3
	 * @return Vector4
	 */
	 Vector4 operator+ (const Vector4 &v, const Vector3 &v1);
	
	/**
	 * Dodawanie wektorów
	 * @param v Vector3
	 * @param v1 Vector4
	 * @return Vector4
	 */
	 Vector4 operator+ (const Vector3 &v,const Vector4 &v1);
	
	/**
	 * Dodawanie wektorów
	 * @param v Vector4
	 * @param v1 Vector4
	 * @return Vector4
	 */
	 Vector4 operator+ (const Vector4 &v, const Vector4 &v1);
	
	/**
	 * Odejmowanie wektorów
	 * @param v Vector4
	 * @param v1 Vector2
	 * @return Vector4
	 */
	 Vector4 operator- (const Vector4 &v, const Vector2 &v1);
	
	/**
	 * Odejmowanie wektorów
	 * @param v Vector2
	 * @param v1 Vector4
	 * @return Vector4
	 */
	 Vector4 operator- (const Vector2 &v, const Vector4 &v1);
	
	/**
	 * Odejmowanie wektorów
	 * @param v Vector4
	 * @param v1 Vector3
	 * @return Vector4
	 */
	 Vector4 operator- (const Vector4 &v, const Vector3 &v1);
	
	/**
	 * Odejmowanie wektorów
	 * @param v Vector3
	 * @param v1 Vector4
	 * @return Vector4
	 */
	 Vector4 operator- (const Vector3 &v, const Vector4 &v1);
	
	/**
	 * Odejmowanie wektorów
	 * @param v Vector4
	 * @param v1 Vector4
	 * @return Vector4
	 */
	 Vector4 operator- (const Vector4 &v, const Vector4 &v1);
	
	/**
	 * Sprawdzenie czy wektory są sobie równe
	 * @param v Vector4
	 * @param v1 Vector4
	 * @return true wektory równe
	 * @return false wektory nie równe
	 */
	 bool operator== (const Vector4 &v, const Vector4 &v1);
	
	/**
	 * Sprawdzenie czy wektory są różne
	 */
	 bool operator!= (const Vector4 &v, const Vector4 &v1);
	
	/**
	 * Mnożenie wektoru przez skalar
	 * @param v Vector4
	 * @param sk skalar
	 * return Vector4
	 */
	 Vector4 operator* (const Vector4 &v, const float sk);
	
	/**
	 * Mnożenie skalaru przez wektor
	 * @param sk skalar
	 * @param v Vector4
	 * @reyurn Vector4
	 */
	 Vector4 operator* (const float sk, const Vector4 &v);
	
	/**
	 * Iloczyn skalarny wektorów
	 * @param v Vector4
	 * @param v1 Vector4
	 * @return Vector4
	 */
	 float operator* (const Vector4 &v, const Vector4 &v1);
	
	/*
	 TODO: Zrobić iloczyn wektorowy
	 */
}
