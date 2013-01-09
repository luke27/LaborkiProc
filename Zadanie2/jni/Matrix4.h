

#pragma once

#include "types.h"
#include "Vector4.h"
#include "Matrix3.h"

#include <cstring>
#ifdef _MSC_VER
#define M_PI 3.14f
#include <cmath>
#endif
using namespace std;

namespace PG
{

	const float ZERO_MATRIX4[4][4] = { 0.0f, 0.0f, 0.0f, 0.0f,
									   0.0f, 0.0f, 0.0f, 0.0f,
									   0.0f, 0.0f, 0.0f, 0.0f,
									   0.0f, 0.0f, 0.0f, 0.0 };

	const float IDENTITY_MATRIX4[4][4] = { 1.0f, 0.0f, 0.0, 0.0f,
										   0.0f, 1.0f, 0.0f, 0.0f,
										   0.0f, 0.0f, 1.0f, 0.0f,
										   0.0f, 0.0f, 0.0f, 1.0f };

	/**
	 * Macierz o wymiarach 4x4
	 */
	struct Matrix4
	{
		union
		{
			///macierz jako tablica 2-wymiarowa 4x4
			float mat[4][4];
			///macierz jako tablica 1-wymiarowa 1x16
			float mat2[16];
			///poszczególne składowe macierzy
			struct
			{
				float m00, m01, m02, m03;
				float m10, m11, m12, m13;
				float m20, m21, m22, m23;
				float m30, m31, m32, m33;
			};
		};

		/**
		 * Konstruktor, towrzy wyzerowaną macierz
		 */
		Matrix4()
		{
			memcpy((void *)mat, (const void *)ZERO_MATRIX4, sizeof(mat));
		}

		/**
		 * Konstruktor
		 * @param tablica[4][4]
		 */
		Matrix4(const float arr[4][4])
		{
			memcpy((void *)mat, (const void *)arr, sizeof(mat));
		}

		/**
		 * Konstruktor
		 * @param tablica[16];
		 */
		Matrix4(const float *arr)
		{
			memcpy((void *)mat2, (const void *)arr, sizeof(mat2));
		}

		/**
		 * Konstruktor, kolejne argumenty składowe macierzy
		 */ 
		Matrix4(const float m00, const float m01, const float m02, const float m03,
			    const float m10, const float m11, const float m12, const float m13,
				const float m20, const float m21, const float m22, const float m23,
				const float m30, const float m31, const float m32, const float m33)
		{
			this->m00 = m00;
			this->m01 = m01;
			this->m02 = m02;
			this->m03 = m03;

			this->m10 = m10;
			this->m11 = m11;
			this->m12 = m12;
			this->m13 = m13;

			this->m20 = m20;
			this->m21 = m21;
			this->m22 = m22;
			this->m23 = m23;

			this->m30 = m30;
			this->m31 = m31;
			this->m32 = m32;
			this->m33 = m33;
		}

		/**
		 * Konstruktor
		 * @param p wskaźnik do Matrix4
		 */
		Matrix4(const Matrix4 *p)
		{
			memcpy((void *)mat, (const void *)p->mat, sizeof(mat));
		}

		/**
		 * Konstruktor
		 * @param ref referencja do Matrix4
		 */
		Matrix4(const Matrix4 &ref)
		{
			memcpy((void *)mat, (const void *)ref.mat, sizeof(mat));
		}

		/**
		 * Pobiera tablicę 1-wymiarową z wartościami macierzy
		 * @return wskaźnik do tablicy 1-wymiarowej z wartościami tablicy
		 */
		const float *data() const
		{
			return mat2;
		}

		/**
		 * Operator tablicowy
		 */
		float &operator[] (uint32 idx)
		{
			return mat2[idx];
		}

		/**
		 * Operator tablicowy
		 */
		const float &operator[] (uint32 idx) const
		{
			return mat2[idx];
		}

		Matrix4 &operator= (const Matrix4 &m)
		{
			for(int i = 0; i < 16; i++)
				mat2[i] = m.mat2[i];
		}

		/**
		 * Dodaj i przypisz Matrix4
		 * @param m Matrix4
		 */
		Matrix4 &operator+= (const Matrix4 &m)
		{
			for(int i = 0; i < 16; i++)
				mat2[i] += m.mat2[i];
			return *this;
		}

		/**
		 * Odejmij i przypisz
		 * @param m Matrix4
		 */
		Matrix4 &operator-= (const Matrix4 &m)
		{
			for(int i = 0; i < 16; i++)
				mat2[i] -= m.mat2[i];
			return *this;
		}

		/**
		 * Pomnóż macierz przez skalar i przypisz
		 * @param sk skalar
		 */
		Matrix4 &operator*= (const float sk)
		{
			for(int i = 0; i < 16; i++)
				mat2[i] *= sk;
			return *this;
		}

		/**
		 * Podziel macierz przez skalar i przypisz
		 */
		Matrix4 &operator/= (const float sk)
		{
			for(int i = 0; i < 16; i++)
				mat2[i] /= sk;
			return *this;
		}

		/**
		 * Pomnóż macierz przez macierz
		 */
		Matrix4 &operator*= (const Matrix4 &m)
		{
			float tmp[4][4];
			for(int row = 0; row < 4; row++)
			{
				for(int col = 0; col < 4; col++)
				{
					float sum = 0.0f;
					for(int i = 0; i < 4; i++)
						sum += mat[row][i] * m.mat[i][col];
					tmp[row][col] = sum;
				}
			}
			*this = Matrix4(tmp);
			return *this;
		}

		/**
		 * Zrób z TEJ macierzy macierz jednostkową
		 */
		void identityThis()
		{
			memcpy((void *)mat, (const void *)IDENTITY_MATRIX4, sizeof(mat));
		}

		/**
		 * Macierz jednostkowa
		 * @return macierz jednostkowa
		 */
		static Matrix4 identity()
		{
			return Matrix4(1.0f, 0.0f, 0.0f, 0.0f,
						   0.0f, 1.0f, 0.0f, 0.0f,
						   0.0f, 0.0f, 1.0f, 0.0f,
						   0.0f, 0.0f, 0.0f, 1.0f);
		}

		/**
		 * Transponuj macierz
		 */
		Matrix4 &transpose()
		{
			*this = Matrix4(m00, m10, m20, m30,
				            m01, m11, m21, m31,
							m02, m12, m22, m32,
							m03, m13, m23, m33);
			return *this;
		}

		/**
		 * Wyznacznik macierzy
		 * @return wyznacznik macierzy
		 */
		float det() const
		{
			/*return (m00 * m11 - m01 * m10) * (m22 * m33 - m23 * m32) +
				   (m02 * m10 - m00 * m12) * (m21 * m33 - m23 * m31) +
				   (m00 * m13 - m03 * m10) * (m21 * m32 - m22 * m31) +
				   (m01 * m12 - m02 * m11) * (m20 * m33 - m22 * m30) +
				   (m02 * m13 - m03 * m12) * (m20 * m31 - m21 * m30) +
				   (m03 * m11 - m01 * m13) * (m20 * m32 - m22 * m30);*/

			const float d12 = mat2[8] * mat2[13] - mat2[12] * mat2[9];
			const float d13 = mat2[8] * mat2[14] - mat2[12] * mat2[10];
			const float d23 = mat2[9] * mat2[14] - mat2[13] * mat2[10];
			const float d24 = mat2[9] * mat2[15] - mat2[13] * mat2[11];
			const float d34 = mat2[10] * mat2[15] - mat2[14] * mat2[11];
			const float d41 = mat2[11] * mat2[12] - mat2[15] * mat2[8];
			return mat2[0] * (mat2[5] * d34 - mat2[6] * d24 + mat2[7] * d23) - 
				   mat2[1] * (mat2[4] * d34 + mat2[6] * d41 + mat2[7] * d13) + 
				   mat2[2] * (mat2[4] * d24 + mat2[5] * d41 + mat2[7] * d12) -
				   mat2[3] * (mat2[4] * d23 - mat2[5] * d13 + mat2[6] * d12);
		}


		/**
		 * Liczenie macierzy odwrotnej
		 * @return macierz odwrotna
		 */
		Matrix4 inverse()
		{
			float d = det();
			if(d == 0.0f)
				return identity();
			else
			{
				float mTmp[16];
				const float invDet = 1.0f / d;
				float d12 = mat2[8] * mat2[13] - mat2[12] * mat2[9];
				float d13 = mat2[8] * mat2[14] - mat2[12] * mat2[10];
				float d23 = mat2[9] * mat2[14] - mat2[13] * mat2[10];
				float d24 = mat2[9] * mat2[15] - mat2[13] * mat2[11];
				float d34 = mat2[10] * mat2[15] - mat2[14] * mat2[11];
				float d41 = mat2[11] * mat2[12] - mat2[15] * mat2[8];

				mTmp[0] =  (mat2[5] * d34 - mat2[6] * d24 + mat2[7] * d23) * invDet;
				mTmp[4] = -(mat2[4] * d34 + mat2[6] * d41 + mat2[7] * d13) * invDet;
				mTmp[8] =  (mat2[4] * d24 + mat2[5] * d41 + mat2[7] * d12) * invDet;
				mTmp[12] = -(mat2[4] * d23 - mat2[5] * d13 + mat2[6] * d12) * invDet;
				mTmp[1] = -(mat2[1] * d34 - mat2[2] * d24 + mat2[3] * d23) * invDet;
				mTmp[5] =  (mat2[0] * d34 + mat2[2] * d41 + mat2[3] * d13) * invDet;
				mTmp[9] = -(mat2[0] * d24 + mat2[1] * d41 + mat2[3] * d12) * invDet;
				mTmp[13] =  (mat2[0] * d23 - mat2[1] * d13 + mat2[2] * d12) * invDet;

				d12 = mat2[0] * mat2[5] - mat2[4] * mat2[1];
				d13 = mat2[0] * mat2[6] - mat2[4] * mat2[2];
				d23 = mat2[1] * mat2[6] - mat2[5] * mat2[2];
				d24 = mat2[1] * mat2[7] - mat2[5] * mat2[3];
				d34 = mat2[2] * mat2[7] - mat2[6] * mat2[3];
				d41 = mat2[0] * mat2[4] - mat2[7] * mat2[0];

				mTmp[2]  =  (mat2[13] * d34 - mat2[14] * d24 + mat2[15] * d23) * invDet;
				mTmp[6]  = -(mat2[12] * d34 + mat2[14] * d41 + mat2[15] * d13) * invDet;
				mTmp[10] =  (mat2[12] * d24 + mat2[13] * d41 + mat2[15] * d12) * invDet;
				mTmp[14] = -(mat2[12] * d23 - mat2[13] * d13 + mat2[14] * d12) * invDet;
				mTmp[3] = -(mat2[9] * d34 - mat2[10] * d24 + mat2[11] * d23) * invDet;
				mTmp[7] =  (mat2[8] * d34 + mat2[10] * d41 + mat2[11] * d13) * invDet;
				mTmp[11] = -(mat2[8] * d24 + mat2[9] * d41 + mat2[11] * d12) * invDet;
				mTmp[15] =  (mat2[8] * d23 - mat2[9] * d13 + mat2[10] * d12) * invDet;
				Matrix4 tmp(mTmp);
				return mTmp;
			}
		}

		/**
		 * Odwróć tą macierz
		 */
		Matrix4 &inverseThis()
		{
			*this = inverse();
			return *this;
		}

		Matrix4 &frustum(const float left, const float right, const float bottom, const float top, const float near, const float far)
		{
			Matrix4 mTmp(2.0f * near / (right - left), 0.0f, (right + left) / (right - left), 0.0f,
						0.0f, 2.0f * near / (top - bottom), (top + bottom) / (top - bottom), 0.0f,
						0.0f, 0.0f, -(far + near) / (far - near), -2.0f * far * near / (far - near),
						0.0f, 0.0f, -1.0f, 0.0f);
			*this *= mTmp;
		}

		/**
		 * translacja macierzu
		 */
		Matrix4 &translate(const float x, const float y, const float z)
		{
			Matrix4 mTmp(1.0f, 0.0f, 0.0f, x,
						 0.0f, 1.0f, 0.0f, y,
						 0.0f, 0.0f, 1.0f, z,
						 0.0f, 0.0f, 0.0f, 1.0f);
		/*	Matrix4 mTmp(1.0f, 0.0f, 0.0f, 0.0f,
						 0.0f, 1.0f, 0.0f, 0.0f,
						 0.0f, 0.0f, 1.0f, 0.0f,
						 x, y, z, 1.0f);*/
			*this *= mTmp;
		}

		Matrix4 &rotate(float angle, float x, float y, float z)
		{
			float d = sqrtf(x * x + y * y + z * z);
			if(d != 1.0f && d != 0.0f)
			{
				x /= d;
				y /= d;
				z /= d;
			}
			float c = cosf(angle * M_PI / 180.0f);
			float s = sinf(angle * M_PI / 180.0f);
			float tt = 1 - c;

			Matrix4 mTmp(x * x * tt + c,
						 x * y * tt - z * s,
						 x * z * tt + y * s,
						 0.0f,
						 y * x * tt + z * s,
						 y * y * tt + c,
						 y * z * tt - x * s,
						 0.0f,
						 x * z * tt - y * s,
						 y * z * tt + x * s,
						 z * z * tt + c,
						 0.0f,
						 0.0f,
						 0.0f,
						 0.0f,
						 1.0f);
			*this *= mTmp;
			rotationComponent = Matrix3(mTmp.m00, mTmp.m01, mTmp.m02,
							  mTmp.m10, mTmp.m11, mTmp.m12,
							  mTmp.m20, mTmp.m21, mTmp.m22);
		}

		Matrix4 &scale(const float x, const float y, const float z)
		{
			Matrix4 mTmp(x, 0.0f, 0.0f, 0.0f,
				         0.0f, y, 0.0f, 0.0f,
						 0.0f, 0.0f, z, 0.0f,
						 0.0f, 0.0f, 0.0f, 1.0f);
			*this *= mTmp;
		}
		///liczy macierz rzutowania na podstawie parametrów
		void lookAt(float eyex, float eyey, float eyez, float centerx, float centery, float centerz, float upx, float upy, float upz);
		void lookAt(const Vector3 &eye, const Vector3 &center, const Vector3 &up);
		Matrix3 rotationComponent;
	};


	/**
	 * Operator porównania
	 */
	 bool operator== (const Matrix4 &m,const Matrix4 &m1);
	
	/**
	 * Operator porównania
	 */
	 bool operator!= (const Matrix4 &m, const Matrix4 &m1);
	
	/**
	 * Operator dodawania
	 */
	 Matrix4 operator+ (const Matrix4 &m, const Matrix4 &m1);
	
	/**
	 * Operator odejmowania
	 */
	 Matrix4 operator- (const Matrix4 &m, const Matrix4 &m1);
	
	/**
	 * Mnożenie macierzy przez skalar
	 */
	 Matrix4 operator* (const Matrix4 &m, const float sk);
	
	/**
	 * Mnożenie skalara przez macierz
	 */
	 Matrix4 operator* (const float sk, const Matrix4 &m);
	
	/**
	 * Mnożenie macierzy przez macierz
	 */
	Matrix4 operator* (const Matrix4 &m, const Matrix4 &m1);
	
	Vector4 operator* (const Matrix4 &m, const Vector4 &v);

	/**
	 * Dzielenie macierzy przez skalara
	 */
	 Matrix4 operator/ (const Matrix4 &m, const float sk);
	

	 /**
	  * trasnsponowanie macierzy
	  * @param m macierz
	  * @return macierz transponowana
	  */
	 Matrix4 traspose(const Matrix4 &m);
}
