#ifndef ENGINE_ENIGNE_H__
#define ENGINE_ENGINE_H__
//===========================================================================
// FILE: main.cpp
// DESC: App Entry point for testing
//===========================================================================

//===========================================================================
// INCLUDE
//===========================================================================
#include "Engine.h"
#include <cstdlib>
//===========================================================================

//===========================================================================
// Namespace
//===========================================================================

namespace
{
	static Engine* sEngine = nullptr;
}

//===========================================================================
// CLASS ENGINE
//===========================================================================

Engine* Engine::GetInstance()
{
	return (sEngine) ? sEngine : sEngine = new Engine();
}

//---------------------------------------------------------------------------

Engine::Engine()
	: mIsIntialized(false)
{
}

//---------------------------------------------------------------------------

Engine::~Engine()
{

}

//---------------------------------------------------------------------------

void Engine::Initialize( char* cfg )
{
	//TODO: Get Window size from cfg...
	//TODO: Get Window type (full screen, windowed, windowed full screen) from cfg...
	RenderManager::GetInstance()->OpenWindow(1280, 720, "test");
	this->mIsIntialized = true;
}

//---------------------------------------------------------------------------

void Engine::Exit()
{
	mIsIntialized = false;

	RenderManager::GetInstance()->Shutdown();
	InputManager::GetInstance()->Shutdown();

	delete sEngine;
	sEngine = nullptr;

	std::exit(EXIT_SUCCESS);
}

//---------------------------------------------------------------------------

bool Engine::IsRunning()
{
	return RenderManager::GetInstance()->IsWindowOpen();
}

//---------------------------------------------------------------------------




//===========================================================================


#endif // !ENGINE_ENIGNE_H__
