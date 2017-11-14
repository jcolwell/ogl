#ifndef MATH_VECTOR_2_H__
#define MATH_VECTOR_2_H__
//===========================================================================
// FILE: Vector2.h
// DESC: 
//===========================================================================

//===========================================================================
// INCLUDE
//===========================================================================
#include "Types.h"
//===========================================================================

//===========================================================================
// NAMESPACE Math
//===========================================================================
namespace Math
{

//===========================================================================
// STRUCT Vector2
//===========================================================================

struct Vector2
{
	f32 x, y;

	Vector2() : x(0.0f), y(0.0f) {}
	Vector2(f32 x, f32 y) : x(x), y(y) {}

	Vector2(const Vector2& other);
	Vector2(const Vector2&& other);

	Vector2 operator=(const Vector2& other);
	Vector2 operator=(const Vector2&& other);

	static Vector2 Zero();
	static Vector2 One();

	Vector2 operator-() const;
	Vector2 operator+(const Vector2& rhs) const;
	Vector2 operator-(const Vector2& rhs) const;
	Vector2 operator*(f32 s) const;
	Vector2 operator/(f32 s) const;

	Vector2& operator+=(const Vector2& rhs);
	Vector2& operator-=(const Vector2& rhs);
	Vector2& operator*=(f32 s);
	Vector2& operator/=(f32 s);

	bool operator== (const Vector2& rhs) const;
	bool operator!= (const Vector2& rhs) const;

};
//===========================================================================
} //!namespace Math
//===========================================================================
#endif //!MATH_VECTOR_2_H__
