#ifndef _COMMON_UTILITIES_H_
#define _COMMON_UTILITIES_H_
//==================================================================================
// File: Utilities.h
// Desc: 
//==================================================================================

//==================================================================================
// INCLUDES
//==================================================================================
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cassert>
//==================================================================================
// MACROS
//==================================================================================

#ifdef _DEBUG

#define LOG( condition, ...)\
{\
	printf("\n****************************************************************************************"); \
	printf("\nASSERT: " #condition);\
	printf("\n\tFILE: %s", __FILE__); \
	printf("\n\tLINE: %d", __LINE__); \
	printf("\n\tFUNCTION: %s", __func__); \
	printf("\n\tMESSAGE:"); \
	printf(__VA_ARGS__); \
	printf("\n****************************************************************************************"); \
}

#define ASSERT(condition, ...)\
{\
	if (!(condition))\
	{\
		LOG(condition, __VA_ARGS__)\
		assert(condition);\
	}\
}\

#else
	#define ASSERT(condition, format, ...)
#endif

#define NONCOPYABLE(type)\
	type(const type&) = delete;\
	type(const type&&) = delete;\
	type& operator=(const type&) = delete;\
	type& operator=(const type&&) = delete;

//----------------------------------------------------------------------------------

#define SAVE_DELETE( obj )\
	delete obj;\
	obj = nullptr;

//----------------------------------------------------------------------------------

//==================================================================================
// NAMESPACE Util
//==================================================================================
namespace Util
{

//==================================================================================
// FUNCTIONS
//==================================================================================

extern char* ReadFile(const char* path);

}


//==================================================================================
#endif // !_COMMON_UTILITIES_H_



