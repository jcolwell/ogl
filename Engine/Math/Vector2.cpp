//===========================================================================
// FILE: Vector2.cpp
// DESC: 
//===========================================================================

//===========================================================================
// INCLUDE
//===========================================================================
#include "Vector2.h"

#include <Utilities.h>
//===========================================================================

//===========================================================================
// NAMESPACE Math
//===========================================================================
namespace Math
{
//===========================================================================
// FUNCTION DEFINITIONS 
//===========================================================================

Vector2::Vector2(const Vector2& other)
{
	if ( this != &other )
	{
		this->x = other.x;
		this->y = other.y;
	}
}

//---------------------------------------------------------------------------

Vector2::Vector2(const Vector2&& other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
}

//---------------------------------------------------------------------------

Vector2 Vector2::operator=(const Vector2& other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return *this;
}

//---------------------------------------------------------------------------

Vector2 Vector2::operator=(const Vector2&& other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return *this;
}

//---------------------------------------------------------------------------

static Vector2 Zero()
{
	return Vector2(0.0f, 0.0f);
}

//---------------------------------------------------------------------------

static Vector2 One()
{
	return Vector2(1.0f, 1.0f);
}

//---------------------------------------------------------------------------

Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}

//---------------------------------------------------------------------------

Vector2 Vector2::operator+(const Vector2& rhs) const
{
	return Vector2(x + rhs.x, y + rhs.y);
}

//---------------------------------------------------------------------------

Vector2 Vector2::operator-(const Vector2& rhs) const
{
	return Vector2(x - rhs.x, y - rhs.y);
}

//---------------------------------------------------------------------------

Vector2 Vector2::operator*(f32 s) const
{
	return Vector2(x * s, y * s);
}

//---------------------------------------------------------------------------

Vector2 Vector2::operator/(f32 s) const
{
	ASSERT(s != 0, "[Vector2] Attempted to divide by Zero!" )
	return Vector2(x / s, y / s);
}

//---------------------------------------------------------------------------

Vector2& Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

//---------------------------------------------------------------------------

Vector2& Vector2::operator-=(const Vector2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

//---------------------------------------------------------------------------

Vector2& Vector2::operator*=(f32 s)
{
	x *= s;
	y *= s;
	return *this;
}

//---------------------------------------------------------------------------

Vector2& Vector2::operator/=(f32 s)
{
	ASSERT(s != 0, "[Vector2] Attempted to divide by Zero!");
	x /= s;
	y /= s;
	return *this;
}

//---------------------------------------------------------------------------

bool Vector2::operator==(const Vector2& rhs) const
{
	return (x == rhs.x && y == rhs.y);
}

//---------------------------------------------------------------------------

bool Vector2::operator!=(const Vector2& rhs) const
{
	return !(*this == rhs);
}

//---------------------------------------------------------------------------
} //!NAMESPACE Math



//===========================================================================