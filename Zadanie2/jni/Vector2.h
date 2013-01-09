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

#include <math.h>

#include "types.h"

namespace PG
{
/**
 * Reprezentuje wektor 2 elementowy dla typu float/GLfloat
 */
struct Vector2
{
	union
	{
		///tablica z składowymi wektora
		float vec[2];

		struct
		{
			///współrzędna x
			float x;
			///współrzędna y
			float y;
		};
	};
	/**
	 * Konstruktor domyślny
	 * tworzy x = 0, y = 0
	 */
	Vector2()
	{
		x = 0.0f;
		y = 0.0f;
	}
	/**
	 * Konstruktor tworzy wektor 
	 * @param x wartość x
	 * @param y wartość y
	 */
	Vector2(const float x, const float y)
	{
		this->x = x;
		this->y = y;
	}

	/**
	 * Konstruktor
	 * wskaźnmik do Vector2
	 */
	Vector2(const Vector2 *p)
	{
		x = p->x;
		y = p->y;
	}

	/**
	 * konstruktor kopiujący
	 */
	Vector2(const Vector2 &p)
	{
		x = p.x;
		y = p.y;
	}
	
	/**
     * Konstruktor
     * @param arr tablica 2-elementowa
     */
	Vector2(const float *arr)
	{
		vec[0] = arr[0];
		vec[1] = arr[1];
	}

	/** 
	 * Długość wektora
	 * @return długość wektora
	 */
	float getLength() const
	{
		return sqrtf(x * x + y * y);
	}

	/**
	 * Długość wektora
	 * @return długość
	 */
	float getLength2() const
	{
		return x * x + y * y;
	}

	/**
	 * Metoda liczy wektor znormalizowany
	 * @return wektor znormalizowany
	 */
	Vector2 getNormalized() const
	{
		float len = sqrtf(x * x + y * y);
		return Vector2(this->x / len, this->y / len);
	}

	/**
	 * powierzchnia
	 * @return powierzchnia
	 */
	float area() const
	{
		return x * y;
	}

	/**
	 * Mnożenie przez skalar z przypisaniem
	 * @param sk skalar
	 * @return nowy wektor
	 */
	Vector2 &operator*= (const float sk)
	{
		x *= sk;
		y *= sk;
		return *this;
	}

	/**
	 * Dodanie wektoru z przypisaniem
	 * @param v wektor
	 * @return nowy wektor
	 */
	Vector2 &operator+= (const Vector2 &v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	/**
	 * Odjęcie wektoru z przypisaniem
	 * @param v wektor
	 * @return nowy wektor
	 */
	Vector2 &operator-= (const Vector2 &v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}
	/**
	 * return operator tablicowy
	 */
	float operator[] (const uint32 idx) const
	{
		return vec[idx];
	}
	/**
	 * Zeruje wektor
	 */
	void zero()
	{
		x = y = 0.0f;
	}
	
};

/**
 * Dodawanie wektorów, referencje
 * @param v1 wektor do którego wykonywane jest dodawanie
 * @param v2 wektor dodawany
 * @return nowy wektor;
 */
 Vector2 operator+ (const Vector2 &v1, const Vector2 &v2);

/**
 * Odejmowanie wektorów, referencje
 * @param v1 wektor na którym wykonywane jest odejmowanie
 * @param v2 wektor odejmujący
 * @return nowy wektor;
 */
 Vector2 operator- (const Vector2 &v1, const Vector2 &v2);


/**
 * Mnożenie skalara przez wektor
 * @param sk skalar
 * @param v1 wektor
 * @return nowy wektor
 */
 Vector2 operator* (const float sk,const Vector2 &v1);


/**
 * Mnożenie wektoru przez skalar
 * @param v1 wektor
 * @param sk skalar
 * @return nowy wektor
 */
 Vector2 operator* (const Vector2 &v1,const float sk);

/**
 * Iloczyn skalarny, dot product
 * @param v1 wektor1
 * @param v2 wektor2
 * @return wartość iloczynu skalarnego
 */
 float operator* (const Vector2 &v1, const Vector2 &v2);



/**
 * Cross product
 * @param v1 wektor1
 * @param v1 wektor2
 * @return wartość
 */
//float operator^ (const Vector2 &v1, const Vector2 &v2)
//{
//	return v1.x * v2.y - v1.x * v2.y;
//}


/**
 * porównanie wartości wektorów
 * @param v wektor1
 * @param v1 wektor2
 * @return informacja czy wektory są równe
 */
 bool operator== (const Vector2 &v, const Vector2 &v1);

/**
 * spradzenie czy wektory nie są sobie równe
 * @param v wektor1
 * @param v1 wektor2
 * @return informacja czy wektiry nie są sobie równe
 */
 bool operator!= (const Vector2 &v, const Vector2 &v1);


/**
 * Punkt
 */
typedef Vector2 Point;

}
