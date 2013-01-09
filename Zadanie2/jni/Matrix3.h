

#pragma once

#include "types.h"

#include <cstring>
using namespace std;

namespace PG
{	
	const float ZERO_MATRIX3[3][3] = { 0.0f, 0.0f, 0.0f,
									   0.0f, 0.0f, 0.0f,
									   0.0f, 0.0f, 0.0f };

	const float IDENTITY_MATRIX[3][3] = { 1.0f, 0.0f, 0.0f,
										  0.0f, 1.0f, 0.0f,
										  0.0f, 0.0f, 1.0f };

	/**
	 * Macierz 3x3
	 */
	struct Matrix3
	{
		union
		{
			float mat[3][3];
			float mat2[9];
			struct
			{
				float m00, m01, m02;
				float m10, m11, m12;
				float m20, m21, m22;
			};
		};

		/**
		 * Konstruktor
		 * tworzy wyzerowaną macierz
		 */
		Matrix3()
		{
			memcpy((void *)mat, (const void *)ZERO_MATRIX3, sizeof(mat));
		}

		/**
		 * KOnstruktor
		 * @param arr tablica[3][3] 
		 */
		Matrix3(const float arr[3][3])
		{
			memcpy((void *)mat, (const void *)arr, sizeof(mat));
		}

		/**
		 * Konstruktor
		 * @param arr tablica[9]
		 */
		Matrix3(const float *arr)
		{
			memcpy((void *)mat2, (const void *)arr, sizeof(mat2));
		}

		/**
		 * Konstruktor
		 * 
		 */
		Matrix3(const float m00, const float m01, const float m02, const float m10, const float m11, const float m12, const float m20, const float m21, const float m22)
		{
			this->m00 = m00;
			this->m01 = m01;
			this->m02 = m02;
			this->m10 = m10;
			this->m11 = m11;
			this->m12 = m12;
			this->m20 = m20;
			this->m21 = m21;
			this->m22 = m22;
		}

		/**
		 * Konstruktor
		 * @param p wskaźnik do Matrix3
		 */
		Matrix3(const Matrix3 *p)
		{
			memcpy((void *)mat, (const void *)p->mat, sizeof(mat));
		}

		/**
		 * Kosntruktor kopiujący
		 * @param m referencja do Matrix3
		 */
		Matrix3(const Matrix3 &m)
		{
			memcpy((void *)mat, (const void *)m.mat, sizeof(mat));
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

		/**
		 * Dodaj i przypisz macierz Matrix3
		 * @param m macierz Matrix3
		 */
		Matrix3 &operator+= (const Matrix3 &m)
		{
			// GetTickCount = 0
		/*	m00 += m.m00;
			m01 += m.m01;
			m02 += m.m02;
			m10 += m.m10;
			m11 += m.m11;
			m12 += m.m12;
			m20 += m.m20;
			m21 += m.m21;
			m22 += m.m22;*/
			
			//0
			for(int i = 0; i < 9; i++)
				mat2[i] += m.mat2[i];

			/*for(int i = 0; i < 3; i++)
				for(int j = 0; j < 3; j++)
					mat[i][j] += m.mat[i][j];*/

			return *this;
		}

		/**
		 * Operator -=
		 * @param m Matrix3
		 */
		Matrix3 &operator-= (const Matrix3 &m)
		{
			for(int i = 0; i < 9; i++)
				mat2[i] -= m.mat2[i];
			return *this;
		}

		/**
		 * Pomnóż macierz przez skalar i przypisz
		 */
		Matrix3 &operator*= (const float sk)
		{
			for(int i = 0; i < 9; i++)
				mat2[i] *= sk;
			return *this;
		}

		/**
		 * Podziel macierz przez skalar i przypisz
		 */
		Matrix3 &operator/= (const float sk)
		{
			for(int i = 0; i < 9; i++)
				mat2[i] /= sk;
			return *this;
		}

		/**
		 * Pomnóż macierz przez macierz
		 */
		Matrix3 &operator*= (const Matrix3 &m)
		{
			/*Matrix3 tmp;
			for(int row = 0; row < 3; row++)
			{
				for(int col = 0; col < 3; col++)
				{
					float sum = 0.0f;
					for(int i = 0; i < 3; i++)
						sum += mat[row][i] * m.mat[i][col];
					tmp.mat[row][col] = sum;
				}
			}

		  	for(int i = 0; i < 9; i++)
				mat2[i] = tmp.mat2[i];*/

			Matrix3 tmp(m00 * m.m00 + m01 * m.m10 + m02 * m.m20, m00 * m.m01 + m01 * m.m11 + m02 * m.m21, m00 * m.m02 + m01 * m.m12 + m02 * m.m22,
				m10 * m.m00 + m11 * m.m10 + m12 * m.m20, m10 * m.m01 + m11 * m.m11 + m12 * m.m21, m10 * m.m02 + m11 * m.m12 + m12 * m.m22,
				m20 * m.m00 + m21 * m.m10 + m22 * m.m20, m20 * m.m01 + m21 * m.m11 + m22 * m.m21, m20 * m.m02 + m21 * m.m12 + m22 * m.m22 
				);
			*this = tmp;
			return *this;
		  //TODO: poprawić aby nie był potrzebny tmp, jednak będzie bez pętli
		}

		/**
		  * Zrób z macierzy macierz jednostkową
		  */
		void identityThis()
		{
			memcpy((void *)mat, (const void *)IDENTITY_MATRIX, sizeof(mat));
		}

		/**
		 * Macierz jednostkowa
		 * @return macierz jednostkowa
		 */
		static Matrix3 identity()
		{
			return Matrix3(1.0f, 0.0f, 0.0f,
						   0.0f, 1.0f, 0.0f,
						   0.0f, 0.0f, 1.0f);
		}

		/**
		 * Transponuj macierz
		 */
		Matrix3 &transpose()
		{
			Matrix3 mTmp(m00, m10, m20, m01, m11, m21, m02, m12, m22);
			*this = mTmp;
			return *this;
		}

		/**
		 * Wyznacznik macierzy
		 */
		float det() const
		{
			return m00 * (m11 * m22 - m21 * m12) - m01 * (m10 * m22 - m20 * m12) + m02 * (m10 * m21 - m20 * m11);
		}

		/**
		 * Macierz odwrotna
		 */
		Matrix3 inverse()
		{
			float d = det();

			if(d == 0.0f)
				return identity();
			else
			{
				float detInv = 1.0f / d;

				float tmp[9];
				tmp[0] = detInv * (m11 * m22 - m21 * m12);
				tmp[1] = -detInv * (m01 * m22 - m21 * m02);
				tmp[2] = detInv * (m01 * m12 - m11 * m02);
				tmp[3] = -detInv * (m10 * m22 - m20 * m12);
				tmp[4] = detInv * (m00 * m22 - m20 * m02);
				tmp[5] = -detInv * (m00 * m12 - m10 * m02);
				tmp[6] = detInv * (m10 * m21 - m20 * m11);
				tmp[7] = -detInv * (m00 * m21 - m20 * m01);
				tmp[8] = detInv * (m00 * m11 - m10 * m01);
				Matrix3 mTmp(tmp);
				return mTmp;
			}
		}

		/**
		 * Odwróć TĄ macierz
		 */
		Matrix3 &inverseThis()
		{
			*this = inverse();
			return *this;
		}
	};

	/**
	 * Operator porównania
	 */
	 bool operator== (const Matrix3 &m, const Matrix3 &m1);
	
	/**
	 * Operator porownania
	 */
	 bool operator!= (const Matrix3 &m, const Matrix3 &m1);
	
	/**
	 * Operator dodawanie
	 */
	 Matrix3 operator+ (const Matrix3 &m, const Matrix3 &m1);
	
	/**
	 * Operator odejmowanie
	 */
	 Matrix3 operator- (const Matrix3 &m, const Matrix3 &m1);
	
	/**
	 * Mnożenie macierzy przez skalar
	 */
	 Matrix3 operator* (const Matrix3 &m, const float sk);
	
	/**
	 * Mnożenie skalara przez macierz
	 */
	 Matrix3 operator* (const float sk, const Matrix3 &m);
	
	/**
	 * Mnożenie macierzy przez macierz
	 */
	 Matrix3 operator* (const Matrix3 &m, const Matrix3 &m1);
	
	/**
	 * Dzielenie macierzy przez skalar
	 */
	 Matrix3 operator/ (const Matrix3 &m, const float sk);
	
}
