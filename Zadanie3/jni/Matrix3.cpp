#include "Matrix3.h"

namespace PG
{
	/**
	 * Operator porównania
	 */
	 bool operator== (const Matrix3 &m, const Matrix3 &m1)
	{
		return m.m00 == m1.m00 && m.m01 == m1.m01 && m.m02 == m1.m02
			&& m.m10 == m1.m10 && m.m11 == m1.m11 && m.m12 == m1.m12
			&& m.m20 == m1.m20 && m.m21 == m1.m21 && m.m22 == m1.m22;
	}

	/**
	 * Operator porownania
	 */
	 bool operator!= (const Matrix3 &m, const Matrix3 &m1)
	{
		return m.m00 != m1.m00 || m.m01 != m1.m01 || m.m02 != m1.m02
			|| m.m10 != m1.m10 || m.m11 != m1.m11 || m.m12 != m1.m12
			|| m.m20 != m1.m20 || m.m21 != m1.m21 || m.m22 != m1.m22;
	}

	/**
	 * Operator dodawanie
	 */
	 Matrix3 operator+ (const Matrix3 &m, const Matrix3 &m1)
	{
		Matrix3 mTmp;
		for(int i = 0; i < 9; i++)
			mTmp.mat2[i] = m[i] + m1[i];
		return mTmp;
	}

	/**
	 * Operator odejmowanie
	 */
	 Matrix3 operator- (const Matrix3 &m, const Matrix3 &m1)
	{
		Matrix3 mTmp;
		for(int i = 0; i < 9; i++)
			mTmp.mat2[i] = m[i] - m1[i];
		return mTmp;
	}

	/**
	 * Mno¿enie macierzy przez skalar
	 */
	 Matrix3 operator* (const Matrix3 &m, const float sk)
	{
		Matrix3 mTmp;
		for(int i = 0; i < 9; i++)
			mTmp.mat2[i] = m[i] * sk;
		return mTmp;
	}

	/**
	 * Mno¿enie skalara przez macierz
	 */
	 Matrix3 operator* (const float sk, const Matrix3 &m)
	{
		Matrix3 mTmp;
		for(int i = 0; i < 9; i++)
			mTmp.mat2[i] = sk * m[i];
		return mTmp;
	}

	/**
	 * Mno¿enie macierzy przez macierz
	 */
	 Matrix3 operator* (const Matrix3 &m, const Matrix3 &m1)
	{
		Matrix3 tmp;
		for(int row = 0; row < 3; row++)
		{
			for(int col = 0; col < 3; col++)
			{
				float sum = 0.0f;
				for(int i = 0; i < 3; i++)
					sum += m.mat[row][i] * m.mat[i][col];
				tmp.mat[row][col] = sum;
			}
		}
		return tmp;
	}

	/**
	 * Dzielenie macierzy przez skalar
	 */
	 Matrix3 operator/ (const Matrix3 &m, const float sk)
	{
		Matrix3 mTmp;
		for(int i = 0; i < 9; i++)
			mTmp.mat2[i] = m[i] / sk;
		return mTmp;
	}
}
