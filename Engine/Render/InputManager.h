#ifndef ENGINE_INPUT_MANAGER_H__
#define ENGINE_INPUT_MANAGER_H__
//===========================================================================
// FILE: InputManager.cpp
// DESC: 
//===========================================================================

//===========================================================================
// INCLUDES
//===========================================================================
#include "Common.h"
#include "Keys.h"
//===========================================================================

//===========================================================================
// INPUT MANAGER
//===========================================================================
class InputManager
{
public:
	static InputManager* GetInstance();
	static void Shutdown();

	void PollInputDevices();
	
	bool KeyPressed( Key key, Modifier mod = Modifier::None );
	bool KeyReleased( Key key, Modifier mod = Modifier::None );

private:
	InputManager();
	~InputManager();

	NONCOPYABLE(InputManager)

private:

	GLFWcursor* mStdCursor = nullptr;

};
//===========================================================================
#endif
