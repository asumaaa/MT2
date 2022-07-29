#include "Vector3.h"
#include <cmath>		//sprt
#include "math.h"

Vector3::Vector3()
{
}

Vector3::Vector3(float x, float y, float z)
{
}

float Vector3::length() const
{
	return 0.0f;
}

Vector3& Vector3::normalize()
{
	// TODO: return ステートメントをここに挿入します
}

float Vector3::dot(const Vector3& v) const
{
	return 0.0f;
}

Vector3 Vector3::cross(const Vector3& v) const
{
	return Vector3();
}

Vector3 Vector3::operator+() const
{
	return Vector3();
}

Vector3 Vector3::operator-() const
{
	return Vector3();
}

Vector3& Vector3::operator+=(const Vector3& v)
{
	// TODO: return ステートメントをここに挿入します
}

Vector3& Vector3::operator-=(const Vector3& v)
{
	// TODO: return ステートメントをここに挿入します
}

Vector3& Vector3::operator*=(float s)
{
	// TODO: return ステートメントをここに挿入します
}

Vector3& Vector3::operator/=(float s)
{
	// TODO: return ステートメントをここに挿入します
}

const Vector3 operator+(const Vector3& v1, const Vector3& v2)
{
	return Vector3();
}

const Vector3 operator-(const Vector3& v1, const Vector3& v2)
{
	return Vector3();
}

const Vector3 operator*(const Vector3& v, float s)
{
	return Vector3();
}

const Vector3 operator*(float s, const Vector3& v)
{
	return Vector3();
}

const Vector3 operator/(const Vector3& v, float s)
{
	return Vector3();
}
