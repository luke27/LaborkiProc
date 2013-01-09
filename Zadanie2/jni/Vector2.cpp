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

#include "Vector2.h"

namespace PG {

 Vector2 operator+ (const Vector2 &v1, const Vector2 &v2)
{
	return Vector2(v1.x + v2.x, v1.y + v2.y);
}

 Vector2 operator- (const Vector2 &v1, const Vector2 &v2)
{
	return Vector2(v1.x - v2.x, v1.y - v2.y);
}

/**
 * Mno¿enie skalara przez wektor
 * @param sk skalar
 * @param v1 wektor
 * @return nowy wektor
 */
 Vector2 operator* (const float sk,const Vector2 &v1)
{
	return Vector2(sk * v1.x, sk * v1.y);
}

/**
 * Mno¿enie wektoru przez skalar
 * @param v1 wektor
 * @param sk skalar
 * @return nowy wektor
 */
 Vector2 operator* (const Vector2 &v1,const float sk)
{
	return Vector2(v1.x * sk, v1.y * sk);
}

/**
 * Iloczyn skalarny, dot product
 * @param v1 wektor1
 * @param v2 wektor2
 * @return wartoœæ iloczynu skalarnego
 */
 float operator* (const Vector2 &v1, const Vector2 &v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}


/**
 * Cross product
 * @param v1 wektor1
 * @param v1 wektor2
 * @return wartoœæ
 */
//float operator^ (const Vector2 &v1, const Vector2 &v2)
//{
//	return v1.x * v2.y - v1.x * v2.y;
//}


/**
 * porównanie wartoœci wektorów
 * @param v wektor1
 * @param v1 wektor2
 * @return informacja czy wektory s¹ równe
 */
 bool operator== (const Vector2 &v, const Vector2 &v1)
{
	return v.x == v1.x && v.y == v1.y;
}

/**
 * spradzenie czy wektory nie s¹ sobie równe
 * @param v wektor1
 * @param v1 wektor2
 * @return informacja czy wektiry nie s¹ sobie równe
 */
 bool operator!= (const Vector2 &v, const Vector2 &v1)
{
	return v.x != v1.x || v.y != v1.y;
}

} //namespace Neo3D
