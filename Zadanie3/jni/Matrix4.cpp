#include "Matrix4.h"

namespace PG
{
	/**
	 * Operator porównania
	 */
	 bool operator== (const Matrix4 &m,const Matrix4 &m1)
	{
		return m.m00 == m1.m00 && m.m01 == m1.m01 && m.m02 == m1.m02 && m.m03 == m1.m03
			&& m.m10 == m1.m10 && m.m11 == m1.m11 && m.m12 == m1.m12 && m.m13 == m1.m13
			&& m.m20 == m1.m20 && m.m21 == m1.m21 && m.m22 == m1.m22 && m.m23 == m1.m23
			&& m.m30 == m1.m30 && m.m31 == m1.m31 && m.m32 == m1.m32 && m.m33 == m1.m33;
	}
	/**
	 * Operator porównania
	 */
	 bool operator!= (const Matrix4 &m, const Matrix4 &m1)
	{
		return m.m00 != m1.m00 || m.m01 != m1.m01 || m.m02 != m1.m02 || m.m03 != m1.m03
			|| m.m10 != m1.m10 || m.m11 != m1.m11 || m.m12 != m1.m12 || m.m13 != m1.m13
			|| m.m20 != m1.m20 || m.m21 != m1.m21 || m.m22 != m1.m22 || m.m23 != m1.m23
			|| m.m30 != m1.m30 || m.m31 != m1.m31 || m.m32 != m1.m32 || m.m33 != m1.m33;
	}

	/**
	 * Operator dodawania
	 */
	 Matrix4 operator+ (const Matrix4 &m, const Matrix4 &m1)
	{
		Matrix4 mTmp;
		for(int i = 0; i < 16; i++)
			mTmp.mat2[i] = m[i] + m1[i];
		return mTmp;
	}

	/**
	 * Operator odejmowania
	 */
	 Matrix4 operator- (const Matrix4 &m, const Matrix4 &m1)
	{
		Matrix4 mTmp;
		for(int i = 0; i < 16; i++)
			mTmp.mat2[i] = m[i] - m1[i];
		return mTmp;
	}

	/**
	 * Mno¿enie macierzy przez skalar
	 */
	 Matrix4 operator* (const Matrix4 &m, const float sk)
	{
		Matrix4 mtmp;
		for(int i = 0; i < 16; i++)
			mtmp.mat2[i] = m[i] * sk;
		return mtmp;
	}

	/**
	 * Mno¿enie skalara przez macierz
	 */
	 Matrix4 operator* (const float sk, const Matrix4 &m)
	{
		Matrix4 mTmp;
		for(int i = 0; i < 16; i++)
			mTmp.mat2[i] = sk * m[i];
		return mTmp;
	}

	Matrix4 operator* (const Matrix4 &m, const Matrix4 &m1)
	{
		float tmp[4][4];
		for(int row = 0; row < 4; row++)
		{
			for(int col = 0; col < 4; col++)
			{
				float sum = 0.0f;
				for(int i = 0; i < 4; i++)
					sum += m.mat[row][i] * m1.mat[i][col];
				tmp[row][col] = sum;
			}
		}
		return Matrix4(tmp);
	}

	/**
	 * Dzielenie macierzy przez skalara
	 */
	 Matrix4 operator/ (const Matrix4 &m, const float sk)
	{
		Matrix4 mTmp;
		for(int i = 0; i < 16; i++)
			mTmp.mat2[i] = m[i] / sk;
		return mTmp;
	}


	 Vector4 operator* (const Matrix4 &m, const Vector4 &v)
	 {
		 return Vector4(m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3] * v[3],
                        m[4] * v[0] + m[5] * v[1] + m[6] * v[2] + m[7] * v[3],
                        m[8] * v[0] + m[9] * v[1] + m[10] * v[2] + m[11] * v[3],
                        m[12] * v[0] + m[13] * v[1] + m[14] * v[2] + m[15] * v[3]);
	 }

	 Matrix4 traspose(const Matrix4 &m)
	 {
		 return Matrix4(m.m00, m.m10, m.m20,m.m30,
				        m.m01, m.m11, m.m21, m.m31,
						m.m02, m.m12, m.m22, m.m32,
						m.m03, m.m13, m.m23, m.m33);
	 }

	 void Matrix4::lookAt(float eyex, float eyey, float eyez, float centerx, float centery, float centerz, float upx, float upy, float upz)
	 {
		 float forward[3];
		 forward[0] = centerx - eyex;
		 forward[1] = centery - eyey;
		 forward[2] = centerz - eyez;
		 float d = sqrtf(forward[0] * forward[0] + forward[1] * forward[1] + forward[2] * forward[2]);
		 if(d != 1.0f && d != 0.0f)
		 {
			 forward[0] /= d;
			 forward[1] /= d;
			 forward[2] /= d;
		 }

		 float up[3];
		 up[0] = upx;
		 up[1] = upy;
		 up[2] = upz;

		 float slide[3];
		 slide[0] = forward[1] * up[2] - forward[2] * up[1];
		 slide[1] = forward[2] * up[0] - forward[0] * up[2];
		 slide[2] = forward[0] * up[1] - forward[1] * up[0];
		 d = sqrtf(slide[0] * slide[0] + slide[1] * slide[1] + slide[2] * slide[2] );
		 if(d != 1.0f && d != 0.0f)
		 {
			 forward[0] /= d;
			 forward[1] /= d;
			 forward[2] /= d;
		 }

		 up[0] = slide[1] * forward[2] - slide[2] * forward[1];
		 up[1] = slide[2] * forward[0] - slide[0] * forward[2];
		 up[2] = slide[0] * forward[1] - slide[1] * forward[0];

		 Matrix4 mTmp(slide[0], slide[1], slide[2], -eyex,
					 up[0], up[1], up[2], -eyey,
					 -forward[0], -forward[1], -forward[2], -eyez, 
					 0.0f, 0.0f, 0.0f, 1.0f);
		 /* Matrix4 mTmp(slide[0], slide[1], slide[2], eyex,
					 up[0], up[1], up[2], eyey,
					 forward[0], forward[1], forward[2], eyez, 
					 0.0f, 0.0f, 0.0f, 1.0f);*/
		 *this *= mTmp;
	 }


	 void Matrix4::lookAt(const Vector3 &eye, const Vector3 &center, const Vector3 &up)
	 {
		 this->lookAt(eye.x, eye.y, eye.z, center.x, center.y, center.z, up.x, up.y, up.z);
	 }
}
