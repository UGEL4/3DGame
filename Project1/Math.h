#pragma once
#include <cmath>
#include <limits>
namespace Math 
{
	const float Pi = 3.1415926535f;
	const float TwoPi = Pi * 2.0f;
	const float PiOver2 = Pi / 2.0f;
	const float Infinity = std::numeric_limits<float>::infinity();
	const float NegInfinity = -std::numeric_limits<float>::infinity();

	inline float Sqrt(float value)
	{
		return sqrtf(value);
	}

	inline float Cos(float angle)
	{
		return cosf(angle);
	}

	inline float Sin(float angle)
	{
		return sinf(angle);
	}

	inline float Abs(float value)
	{
		return fabs(value);
	}

	inline bool NearZero(float val, float epsilon = 0.001f)
	{
		if (fabs(val) <= epsilon)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	inline float ToDegrees(float radians)
	{
		return radians * 180.0f / Pi;
	}
}

class Vector2
{
public:
	float x, y;

	Vector2():x(0.0f), y(0.0f){}
	explicit Vector2(float inX, float inY)
		:x(inX)
		, y(inY)
	{}

	friend Vector2 operator+(const Vector2& a, const Vector2& b)
	{
		return Vector2(a.x + b.x, a.y + b.y);
	}

	friend Vector2 operator-(const Vector2& a, const Vector2& b)
	{
		return Vector2(a.x - b.x, a.y - b.y);
	}

	friend Vector2 operator*(const Vector2& left, const Vector2& right)
	{
		return Vector2(left.x * right.x, left.y * right.y);
	}

	friend Vector2 operator*(const Vector2& left, float right)
	{
		return Vector2(left.x * right, left.y * right);
	}

	friend Vector2 operator*(float left, const Vector2& right)
	{
		return Vector2(left * right.x, left * right.y);
	}

	Vector2& operator*=(float scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vector2& operator+=(const Vector2& right)
	{
		x += right.x;
		y += right.y;
		return *this;
	}

	Vector2& operator-=(const Vector2& right)
	{
		x -= right.x;
		y -= right.y;
		return *this;
	}

	//向量的长度的平方
	float LengthSq() const
	{
		return (x*x + y * y);
	}

	static const Vector2 Zero;
};


//vector3
class Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3():x(0),y(0),z(0){}
	explicit Vector3(float X,float Y,float Z):x(X),y(Y),z(Z){}

	// Cast to a const float pointer
	const float* GetAsFloatPtr() const
	{
		return reinterpret_cast<const float*>(&x);
	}

	// Set all three components in one line
	void Set(float inX, float inY, float inZ)
	{
		x = inX;
		y = inY;
		z = inZ;
	}

	// Vector addition (a + b)
	friend Vector3 operator+(const Vector3& a, const Vector3& b)
	{
		return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
	}

	// Vector subtraction (a - b)
	friend Vector3 operator-(const Vector3& a, const Vector3& b)
	{
		return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
	}

	// Component-wise multiplication
	friend Vector3 operator*(const Vector3& left, const Vector3& right)
	{
		return Vector3(left.x * right.x, left.y * right.y, left.z * right.z);
	}

	// Scalar multiplication
	friend Vector3 operator*(const Vector3& vec, float scalar)
	{
		return Vector3(vec.x * scalar, vec.y * scalar, vec.z * scalar);
	}

	// Scalar multiplication
	friend Vector3 operator*(float scalar, const Vector3& vec)
	{
		return Vector3(vec.x * scalar, vec.y * scalar, vec.z * scalar);
	}

	// Scalar *=
	Vector3& operator*=(float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	// Vector +=
	Vector3& operator+=(const Vector3& right)
	{
		x += right.x;
		y += right.y;
		z += right.z;
		return *this;
	}

	// Vector -=
	Vector3& operator-=(const Vector3& right)
	{
		x -= right.x;
		y -= right.y;
		z -= right.z;
		return *this;
	}

	// Length squared of vector
	float LengthSq() const
	{
		return (x * x + y * y + z * z);
	}

	// Length of vector
	float Length() const
	{
		return (Math::Sqrt(LengthSq()));
	}

	// Normalize this vector
	void Normalize()
	{
		float length = Length();
		x /= length;
		y /= length;
		z /= length;
	}

	// Normalize the provided vector
	static Vector3 Normalize(const Vector3& vec)
	{
		Vector3 temp = vec;
		temp.Normalize();
		return temp;
	}

	// Dot product between two vectors (a dot b)
	static float Dot(const Vector3& a, const Vector3& b)
	{
		return (a.x * b.x + a.y * b.y + a.z * b.z);
	}

	// Cross product between two vectors (a cross b)
	static Vector3 Cross(const Vector3& a, const Vector3& b)
	{
		Vector3 temp;
		temp.x = a.y * b.z - a.z * b.y;
		temp.y = a.z * b.x - a.x * b.z;
		temp.z = a.x * b.y - a.y * b.x;
		return temp;
	}

	// Lerp from A to B by f
	static Vector3 Lerp(const Vector3& a, const Vector3& b, float f)
	{
		return Vector3(a + f * (b - a));
	}

	// Reflect V about (normalized) N
	static Vector3 Reflect(const Vector3& v, const Vector3& n)
	{
		return v - 2.0f * Vector3::Dot(v, n) * n;
	}

	static Vector3 Transform(const Vector3& vec, const class Matrix4& mat, float w = 1.0f);
	// This will transform the vector and renormalize the w component
	static Vector3 TransformWithPerspDiv(const Vector3& vec, const class Matrix4& mat, float w = 1.0f);

	// Transform a Vector3 by a quaternion
	//static Vector3 Transform(const Vector3& v, const class Quaternion& q);

	static const Vector3 Zero;
	static const Vector3 UnitX;
	static const Vector3 UnitY;
	static const Vector3 UnitZ;
	static const Vector3 NegUnitX;
	static const Vector3 NegUnitY;
	static const Vector3 NegUnitZ;
	static const Vector3 Infinity;
	static const Vector3 NegInfinity;
};

class Matrix4
{
public:
	float mat[4][4];
	static const Matrix4 Identity;

	Matrix4()
	{
		*this = Matrix4::Identity;
	}

	explicit Matrix4(float inMat[4][4])
	{
		memcpy(mat, inMat, 16 * sizeof(float));
	}

	// Cast to a const float pointer
	const float* GetAsFloatPtr() const
	{
		return reinterpret_cast<const float*>(&mat[0][0]);
	}

	// Matrix multiplication (a * b)
	friend Matrix4 operator*(const Matrix4& a, const Matrix4& b)
	{
		Matrix4 result;
		result.mat[0][0] =	a.mat[0][0] * b.mat[0][0] +
							a.mat[0][1] * b.mat[1][0] +
							a.mat[0][2] * b.mat[2][0] +
							a.mat[0][3] * b.mat[3][0];

		result.mat[0][1] =	a.mat[0][0] * b.mat[0][1] +
							a.mat[0][1] * b.mat[1][1] +
							a.mat[0][2] * b.mat[2][1] +
							a.mat[0][3] * b.mat[3][1];

		result.mat[0][2] =	a.mat[0][0] * b.mat[0][2] +
							a.mat[0][1] * b.mat[1][2] +
							a.mat[0][2] * b.mat[2][2] +
							a.mat[0][3] * b.mat[3][2];

		result.mat[0][3] =	a.mat[0][0] * b.mat[0][3] +
							a.mat[0][1] * b.mat[1][3] +
							a.mat[0][2] * b.mat[2][3] +
							a.mat[0][3] * b.mat[3][3];

		result.mat[1][0] =	a.mat[1][0] * b.mat[0][0] +
							a.mat[1][1] * b.mat[1][0] +
							a.mat[1][2] * b.mat[2][0] +
							a.mat[1][3] * b.mat[3][0];

		result.mat[1][1] =	a.mat[1][0] * b.mat[0][1] +
							a.mat[1][1] * b.mat[1][1] +
							a.mat[1][2] * b.mat[2][1] +
							a.mat[1][3] * b.mat[3][1];

		result.mat[1][2] =	a.mat[1][0] * b.mat[0][2] +
							a.mat[1][1] * b.mat[1][2] +
							a.mat[1][2] * b.mat[2][2] +
							a.mat[1][3] * b.mat[3][2];

		result.mat[1][3] =	a.mat[1][0] * b.mat[0][3] +
							a.mat[1][1] * b.mat[1][3] +
							a.mat[1][2] * b.mat[2][3] +
							a.mat[1][3] * b.mat[3][3];

		result.mat[2][0] =	a.mat[2][0] * b.mat[0][0] +
							a.mat[2][1] * b.mat[1][0] +
							a.mat[2][2] * b.mat[2][0] +
							a.mat[2][3] * b.mat[3][0];

		result.mat[2][1] =	a.mat[2][0] * b.mat[0][1] +
							a.mat[2][1] * b.mat[1][1] +
							a.mat[2][2] * b.mat[2][1] +
							a.mat[2][3] * b.mat[3][1];

		result.mat[2][2] =	a.mat[2][0] * b.mat[0][2] +
							a.mat[2][1] * b.mat[1][2] +
							a.mat[2][2] * b.mat[2][2] +
							a.mat[2][3] * b.mat[3][2];

		result.mat[2][3] =	a.mat[2][0] * b.mat[0][3] +
							a.mat[2][1] * b.mat[1][3] +
							a.mat[2][2] * b.mat[2][3] +
							a.mat[2][3] * b.mat[3][3];

		result.mat[3][0] =	a.mat[3][0] * b.mat[0][0] +
							a.mat[3][1] * b.mat[1][0] +
							a.mat[3][2] * b.mat[2][0] +
							a.mat[3][3] * b.mat[3][0];

		result.mat[3][1] =	a.mat[3][0] * b.mat[0][1] +
							a.mat[3][1] * b.mat[1][1] +
							a.mat[3][2] * b.mat[2][1] +
							a.mat[3][3] * b.mat[3][1];

		result.mat[3][2] =	a.mat[3][0] * b.mat[0][2] +
							a.mat[3][1] * b.mat[1][2] +
							a.mat[3][2] * b.mat[2][2] +
							a.mat[3][3] * b.mat[3][2];

		result.mat[3][3] =	a.mat[3][0] * b.mat[0][3] +
							a.mat[3][1] * b.mat[1][3] +
							a.mat[3][2] * b.mat[2][3] +
							a.mat[3][3] * b.mat[3][3];

		return result;
	}

	Matrix4& operator*=(const Matrix4& right)
	{
		*this = *this * right;
		return *this;
	}

	// Invert the matrix - super slow
	void Invert();

	// Get the translation component of the matrix
	Vector3 GetTranslation() const
	{
		return Vector3(mat[3][0], mat[3][1], mat[3][2]);
	}

	// Get the X axis of the matrix (forward)
	Vector3 GetXAxis() const
	{
		return Vector3::Normalize(Vector3(mat[0][0], mat[0][1], mat[0][2]));
	}

	// Get the Y axis of the matrix (left)
	Vector3 GetYAxis() const
	{
		return Vector3::Normalize(Vector3(mat[1][0], mat[1][1], mat[1][2]));
	}

	// Get the Z axis of the matrix (up)
	Vector3 GetZAxis() const
	{
		return Vector3::Normalize(Vector3(mat[2][0], mat[2][1], mat[2][2]));
	}

	// Extract the scale component from the matrix
	//应该是从缩放矩阵中提取出缩放向量这个意思吧
	Vector3 GetScale() const
	{
		Vector3 scale;
		scale.x = Vector3(mat[0][0], mat[0][1], mat[0][2]).Length();
		scale.y = Vector3(mat[1][0], mat[1][1], mat[1][2]).Length();
		scale.z = Vector3(mat[2][0], mat[2][1], mat[2][2]).Length();

		return scale;
	}

	// Create a scale matrix with x, y, and z scales
	static Matrix4 CreateScale(float xScale, float yScale, float zScale)
	{
		float matx[4][4] = {
			{xScale,0.0f,	0.0f,	0.0f},
			{0.0f,	yScale,	0.0f,	0.0f},
			{0.0f,	0.0f,	zScale,	0.0f},
			{0.0f,	0.0f,	0.0f,	1.0f}
		};
		return Matrix4(matx);
	}

	static Matrix4 CreateScale(const Vector3& scaleVector)
	{
		return CreateScale(scaleVector.x, scaleVector.y, scaleVector.z);
	}

	// Create a scale matrix with a uniform factor
	static Matrix4 CreateScale(float scale)
	{
		return CreateScale(scale, scale, scale);
	}

	// Rotation about x-axis
	static Matrix4 CreateRotationX(float theta)
	{
		float mat[4][4] = {
			{1.0f, 0.0f,				0.0f,				0.0f},
			{0.0f, Math::Cos(theta),	Math::Sin(theta),	0.0f},
			{0.0f, -Math::Sin(theta),	Math::Cos(theta),	0.0f},
			{0.0f, 0.0f,				0.0f,				1.0f}
		};

		return Matrix4(mat);
	}

	// Rotation about y-axis
	static Matrix4 CreateRotationY(float theta)
	{
		float mat[4][4] = {
			{Math::Cos(theta),	0.0f,	-Math::Sin(theta),	0.0f},
			{0.0f,				1.0f,	0.0f,				0.0f},
			{Math::Sin(theta),	0.0f,	Math::Cos(theta),	0.0f},
			{0.0f,				0.0f,	0.0f,				1.0f}
		};
		return Matrix4(mat);
	}

	// Rotation about z-axis
	static Matrix4 CreateRotationZ(float theta)
	{
		float mat[4][4] = {
			{Math::Cos(theta),	Math::Sin(theta),	0.0f, 0.0f},
			{-Math::Sin(theta), Math::Cos(theta),	0.0f, 0.0f},
			{0.0f,				0.0f,				1.0f, 0.0f},
			{0.0f,				0.0f,				0.0f, 1.0f}
		};
		return Matrix4(mat);
	}

	static Matrix4 CreateTranslation(const Vector3& trans)
	{
		float mat[4][4] = {
			{1.0f,		0.0f,		0.0f,		0.0f},
			{0.0f,		1.0f,		0.0f,		0.0f},
			{0.0f,		0.0f,		1.0f,		0.0f},
			{trans.x,	trans.y,	trans.z,	1.0f}
		};
		return Matrix4(mat);
	}

	// Create "Simple" View-Projection Matrix from Chapter 6
	static Matrix4 CreateSimpleViewProj(float width, float height)
	{
		float temp[4][4] =
		{
			{ 2.0f / width, 0.0f, 0.0f, 0.0f },
			{ 0.0f, 2.0f / height, 0.0f, 0.0f },
			{ 0.0f, 0.0f, 1.0f, 0.0f },
			{ 0.0f, 0.0f, 1.0f, 1.0f }
		};
		return Matrix4(temp);
	}
};