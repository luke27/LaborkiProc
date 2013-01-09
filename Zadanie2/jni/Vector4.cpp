#include "Vector4.h"

namespace PG
{
	/**
	 * Dodawanie wektorów
	 * @param v Vector4
	 * @param v1 Vector2
	 * @return Vector4
	 */
	 Vector4 operator+ (const Vector4 &v, const Vector2 &v1)
	{
		return Vector4(v.x + v1.x, v.y + v1.y, v.z, v.w);
	}
	
	/**
	 * Dodawanie wektorów
	 * @param v Vector2
	 * @param v1 Vector4
	 * @return Vector4
	 */
	 Vector4 operator+ (const Vector2 &v, const Vector4 &v1)
	{
		return Vector4(v.x + v1.x, v.y + v1.y, v1.z, v1.w);
	}

	/**
	 * Dodawanie wektorów
	 * @param v Vector4
	 * @param v1 Vector3
	 * @return Vector4
	 */
	 Vector4 operator+ (const Vector4 &v, const Vector3 &v1)
	{
		return Vector4(v.x + v1.x, v.y + v1.y, v.z + v1.z, v.w);
	}

	/**
	 * Dodawanie wektorów
	 * @param v Vector3
	 * @param v1 Vector4
	 * @return Vector4
	 */
	 Vector4 operator+ (const Vector3 &v,const Vector4 &v1)
	{
		return Vector4(v.x + v1.x, v.y + v1.y, v.z + v1.z, v1.w);
	}

	/**
	 * Dodawanie wektorów
	 * @param v Vector4
	 * @param v1 Vector4
	 * @return Vector4
	 */
	 Vector4 operator+ (const Vector4 &v, const Vector4 &v1)
	{
		return Vector4(v.x + v1.x, v.y + v1.y , v.z + v1.z, v.w + v1.w);
	}

	/**
	 * Odejmowanie wektorów
	 * @param v Vector4
	 * @param v1 Vector2
	 * @return Vector4
	 */
	 Vector4 operator- (const Vector4 &v, const Vector2 &v1)
	{
		return Vector4(v.x - v1.x, v.y - v1.y, v.z, v.w);
	}

	/**
	 * Odejmowanie wektorów
	 * @param v Vector2
	 * @param v1 Vector4
	 * @return Vector4
	 */
	 Vector4 operator- (const Vector2 &v, const Vector4 &v1)
	{
		return Vector4(v.x - v1.x, v.y - v1.y, v1.z, v1.w);
	}

	/**
	 * Odejmowanie wektorów
	 * @param v Vector4
	 * @param v1 Vector3
	 * @return Vector4
	 */
	 Vector4 operator- (const Vector4 &v, const Vector3 &v1)
	{
		return Vector4(v.x - v1.x, v.y - v1.y, v.z - v1.z, v.w);
	}

	/**
	 * Odejmowanie wektorów
	 * @param v Vector3
	 * @param v1 Vector4
	 * @return Vector4
	 */
	 Vector4 operator- (const Vector3 &v, const Vector4 &v1)
	{
		return Vector4(v.x - v1.x, v.y - v1.y, v.z - v1.z, v1.w);
	}

	/**
	 * Odejmowanie wektorów
	 * @param v Vector4
	 * @param v1 Vector4
	 * @return Vector4
	 */
	 Vector4 operator- (const Vector4 &v, const Vector4 &v1)
	{
		return Vector4(v.x - v1.x, v.y - v1.y, v.z - v1.z, v.w - v1.w);
	}

	/**
	 * Sprawdzenie czy wektory s¹ sobie równe
	 * @param v Vector4
	 * @param v1 Vector4
	 * @return true wektory równe
	 * @return false wektory nie równe
	 */
	 bool operator== (const Vector4 &v, const Vector4 &v1)
	{
		return v.x == v1.x && v.y == v1.y && v.z == v1.z && v.w == v1.w;
	}

	/**
	 * Sprawdzenie czy wektory s¹ ró¿ne
	 */
	 bool operator!= (const Vector4 &v, const Vector4 &v1)
	{
		return v.x != v1.x || v.y != v1.y || v.z != v1.z || v.w != v.w;
	}

	/**
	 * Mno¿enie wektoru przez skalar
	 * @param v Vector4
	 * @param sk skalar
	 * return Vector4
	 */
	 Vector4 operator* (const Vector4 &v, const float sk)
	{
		return Vector4(v.x * sk, v.z * sk, v.y * sk, v.w * sk);
	}

	/**
	 * Mno¿enie skalaru przez wektor
	 * @param sk skalar
	 * @param v Vector4
	 * @reyurn Vector4
	 */
	 Vector4 operator* (const float sk, const Vector4 &v)
	{
		return Vector4(sk * v.x, sk * v.y, sk * v.z, sk * v.w);
	}

	/**
	 * Iloczyn skalarny wektorów
	 * @param v Vector4
	 * @param v1 Vector4
	 * @return Vector4
	 */
	 float operator* (const Vector4 &v, const Vector4 &v1)
	{
		return v.x * v1.x + v.y * v1.y + v.z * v1.z + v.w * v1.w;
	}
}
