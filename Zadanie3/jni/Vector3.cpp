#include "Vector3.h"
#include "Neo3DMath.h"
namespace PG
{
	Vector3 Vector3::rotateX(const float angle)
		{
			float ty = y;
			y = ty * cosfa(angle) + z * sinfa(angle);
			z = ty * -sinfa(angle) * z * cosfa(angle);
			return *this;
		}

	Vector3 Vector3::rotateY(const float angle)
		{
			float tx = x;
			x = tx * cosfa(angle) + z * -sinfa(angle);
			z = tx * sinfa(angle) + z * cosfa(angle);
			return *this;
		}

	Vector3 operator+ (const Vector3 &v1, const Vector3 &v2)
	{
		return Vector3(v1.x + v2.y, v1.y + v2.y, v1.z + v2.z);
	}

	/**
	 * dodawanie wektor�w
	 * @param v1 wektor - typ Vector2
	 * @param v2 wektor - typ Wektor3
	 * @return nowy wektor
	 */
	 Vector3 operator+ (const Vector2 &v1, const Vector3 &v2)
	{
		return Vector3(v1.x + v2.x, v1.y + v2.y, v2.z);
	}

	/**
	 * dodawanie wektor�w
	 * @param v wektor - typ Vector3
	 * @paramm v1 wektor -typ Vector2
	 * @return nowy wektor
	 */
 	 Vector3 operator+ (const Vector3 &v, const Vector2 &v1)
	{
		return Vector3(v.x + v1.x, v.y + v1.y, v.z);
	}

	/**
	 * odejmowanie wektor�w
	 * @param v1 wektor1
	 * @param v2 wektor2
	 * @return nowy wektor
	 */
	 Vector3 operator- (const Vector3 &v1, const Vector3 &v2)
	{
		return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	}

	/**
	 * odejmowanie wektor�w
	 * @param v wektor Vector3
	 * @param v1 wektor Vector2
	 * @return nowy wektor
	 */
	 Vector3 operator- (const Vector3 &v, const Vector2 &v1)
	{
		return Vector3(v.x - v1.x, v.y - v1.y, v.z);
	}

	/**
	 * odejmowanie wektor�w
	 * @param v wektor Vector2
	 * @param v1 wektor Vector3
	 * @return nowy wektor
	 */
	 Vector3 operator- (const Vector2 &v,const Vector3 &v1)
	{
		return Vector3(v.x - v1.x, v.y - v1.y, v1.z);
	}

	/**
	 * sprawdzenie czy wektory s� r�wne
	 * @param v wektor1
	 * @param v1 wektor2
	 * @return true - wektory r�wne, false - nie r�wne
	 */
	 bool operator== (const Vector3 &v, const Vector3 &v1)
	{
		return v.x == v1.x && v.y == v1.y && v.z == v1.z;
	}

	/**
	 * sprawdzenie czy wektory s� r�ne
	 */
	 bool operator!= (const Vector3 &v, const Vector3 &v1)
	{
		return v.x != v1.x || v.y != v1.y || v.z != v1.z; 
	}

	/**
	 * Mno�enie skalara przez wektor
	 * @param sk skalar
	 * @param v wektor
	 * @return nowy wektor
	 */
	 Vector3 operator* (const float sk, const Vector3 &v)
	{
		return Vector3(sk * v.x, sk * v.y, sk * v.x);
	}

	/**
	 * Mno�enie wektoru przez skalar
	 * @param v wektor
	 * @param sk skalar
	 * @return nowy wektor
	 */ 
	 Vector3 operator* (const Vector3 &v, const float sk)
	{
		return Vector3(sk * v.x, sk * v.y, sk * v.z);
	}

	/**
	 * Iloczyn skalarny 
	 * @param v wektor1
	 * @param v1 wektor2
	 * @return iloczyn skalarny
	 */
	 float operator* (const Vector3 &v,const Vector3 &v1)
	{
		return v.x * v1.x + v.y * v1.y + v.z * v1.z;
	}
	
	/**
	 * Iloczyn wektoruwy
	 * @param v wektor1
	 * @param v1 wektor2
	 * @return nowy wektor
	 */
	Vector3 operator^ (const Vector3 &v, const Vector3 &v1)
	{
		return Vector3(v.y * v1.z - v.z * v1.y, v.z * v1.x - v.x * v1.z, v.x * v1.y - v.y * v1.x);
	}
}
