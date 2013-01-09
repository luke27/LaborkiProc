

#pragma once
#include <cmath>
#include "types.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"


namespace PG {

/**
 * konwersja stopni na radiany
 * @param angle kąt
 * @return wartość w radianach
 */
template<typename T>
inline T angleToRadian(T angle)
{
	return (angle * M_PI) / 180;
}

/**
 * sinus dla stopni
 * @param angle kąt
 * @return wynik
 */
template<typename T>
inline T sina(T angle)
{
	return std::sin(angleToRadian(angle));
}


/**
 * cosinus dla stopni
 * @param angle kąt w stopniach
 * @return wynik
 */
template<typename T>
inline T cosa(T angle)
{
	return std::cos(angleToRadian(angle));
}

/**
 * tangens dla stopni
 * @param angle kąt w stopniach
 * 
 */
template<typename T>
inline T tana(T angle)
{
	return std::tan(angleToRadian(angle));
}

/**
 * cotangens dla stopni
 * @param  angle kąt w stopniach
 * @return wynik
 */
template<typename T>
inline T ctga(T angle)
{
	T c = cosa(angle);
	if(c == 0)
		c = 0.0000001;
	T res = sina(angle) / c;
	return res;
}

//dla float/GLfloat

/**
 * kąt w float na radiany
 * @param angle kąt w radianach
 */
inline float angToRadf(float angle)
{
	return (angle * M_PI) / 180.0f;
}

/**
* sinus w stopniach dla float
 * @param angle kąt w stopniach
 * @return wynik
 */
inline float sinfa(float angle)
{
	return sinf(angToRadf(angle));
}

/**
 * cosinus dla float w stopniach
 * @param angle kąt w stopniach
 * @return wynik
 */
inline float cosfa(float angle)
{
	return cosf(angToRadf(angle));
}

/**
 * tangens w stopniach dla float
 * @param angle kąt w stopniach
 * @return wynik
 */
inline float tanfa(float angle)
{
	return tanf(angToRadf(angle));
}

/**
 * cotangens stopniach dla float
 * @param angle w stopnich
 * @return wynik
 */
inline float ctgfa(float angle)
{
	return 1 / tanfa(angle);
}

} //namespace Neo3D end
