#ifndef ENGINE_ENIGNE_H__
#define ENGINE_ENGINE_H__
//===========================================================================
// FILE: main.cpp
// DESC: App Entry point for testing
//===========================================================================

//===========================================================================
// INCLUDE
//===========================================================================
#include <InputManager.h>
#include <RenderManager.h>
#include <EngineMath.h>
#include <Utilities.h>
//===========================================================================

//===========================================================================
// CLASS ENGINE
//===========================================================================

class Engine
{
public:
	static Engine* GetInstance();

	void Initialize( char* cfg );
	void Exit();
	bool IsRunning();

private:
	Engine();
	~Engine();

	NONCOPYABLE( Engine )

private:
	bool mIsIntialized;
};

//===========================================================================


#endif // !ENGINE_ENIGNE_H__
