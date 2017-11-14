#ifndef ENGINE_MATH_H__
#define ENGINE_MATH_H__
//==================================================================================
// File: Math.h
// Desc: 
//==================================================================================

//==================================================================================
// INCLUDES
//==================================================================================
#include "Types.h"
//==================================================================================
namespace Math
{

#include "Vector2.h"

//======================================================================================
// Constants
//======================================================================================

extern const f32 kPi;
extern const f32 kTwoPi;
extern const f32 kPiByTwo;
extern const f32 kRootTwo;
extern const f32 kRootThree;
extern const f32 kDegToRad;
extern const f32 kRadToDeg;

//======================================================================================
// Function Declarations
//======================================================================================

template <typename T> T Min(T a, T b);
template <typename T> T Max(T a, T b);
template <typename T> T Clamp(T value, T min, T max);

f32 Abs(f32 value);
f32 Sign(f32 value);
f32 Sqr(f32 value);
f32 Sqrt(f32 value);

bool Compare(f32 a, f32 b, f32 epsilon = 0.000001f);

bool IsZero(f32 value);
bool IsZero(const Math::Vector2 & v);
//bool IsZero(const Vector3 & v);

f32 MagnitudeSqr(const Math::Vector2& v);
//f32 MagnitudeSqr(const Vector3& v);
f32 Magnitude(const Math::Vector2& v);
//f32 Magnitude(const Vector3& v);

//f32 MagnitudeXZSqr(const Vector3& v);
//f32 MagnitudeXZ(const Vector3& v);

Math::Vector2 Normalize(const Math::Vector2& v);
//Vector3 Normalize(const Vector3& v);

f32 DistanceSqr(const Math::Vector2& a, const Math::Vector2& b);
//f32 DistanceSqr(const Vector3& a, const Vector3& b);
f32 Distance(const Math::Vector2& a, const Math::Vector2& b);
//f32 Distance(const Vector3& a, const Vector3& b);

//f32 DistanceXZSqr(const Vector3& a, const Vector3& b);
//f32 DistanceXZ(const Vector3& a, const Vector3& b);

//f32 Dot(const Vector3& a, const Vector3& b);
//Vector3 Cross(const Vector3& a, const Vector3& b);
//Vector3 Project(const Vector3& v, const Vector3& n);

//f32 Determinant(const Matrix& m);
//Matrix Adjoint(const Matrix& m);
//Matrix Inverse(const Matrix& m);
//Matrix Transpose(const Matrix& m);

//Vector3 TransformCoord(const Vector3& v, const Matrix& m);
//Vector3 TransformNormal(const Vector3& v, const Matrix& m);

Math::Vector2 Lerp(const Math::Vector2& v0, const Math::Vector2& v1, f32 t);
//Vector3 Lerp(const Vector3& v0, const Vector3& v1, f32 t);

}

//======================================================================================
// Inline Definitions
//======================================================================================
//#include "EngineMath.inl"

//==================================================================================
#endif // !MATH_H__
