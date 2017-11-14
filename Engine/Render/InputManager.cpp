//===========================================================================
// FILE: InputManager.cpp
// DESC: 
//===========================================================================

//===========================================================================
// INCLUDES
//===========================================================================
#include "InputManager.h"
#include "Common.h"
#include "RenderManager.h"

#include <map>
//===========================================================================

//===========================================================================
// Nameless namespace
//===========================================================================
namespace
{
	static InputManager* sInstance = nullptr;

	struct KeyReceipt
	{
		int scancode;
		int action;
		int mode;
	};

	std::map< Key, KeyReceipt > gKeyBuffer;

	void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
	{
		KeyReceipt receipt = { scancode, action, mode };
		gKeyBuffer[static_cast<Key>(key)] = receipt;
	}

	void MouseInputCallback(GLFWwindow* window, int btn, int action, int mode)
	{
		KeyReceipt receipt = { 0, action, mode };
		gKeyBuffer[static_cast<Key>(btn)] = receipt;
	}

}
//===========================================================================


//===========================================================================
// InputManager IMPL
//===========================================================================

InputManager* InputManager::GetInstance()
{
	return (sInstance == nullptr) ? sInstance = new InputManager() : sInstance;
}

//---------------------------------------------------------------------------

void InputManager::Shutdown()
{
	SAVE_DELETE(sInstance);
}

//---------------------------------------------------------------------------

void InputManager::PollInputDevices()
{
	gKeyBuffer.clear();
	glfwPollEvents();
}

//---------------------------------------------------------------------------

bool InputManager::KeyPressed(Key key, Modifier mod)
{
	auto res = gKeyBuffer.find(key);
	return (res != gKeyBuffer.end()) ? 
		(res->second.action == GLFW_PRESS && mod == static_cast<Modifier>( res->second.mode ))
		: false;
}

//---------------------------------------------------------------------------

bool InputManager::KeyReleased(Key key, Modifier mod)
{
	auto res = gKeyBuffer.find(key);
	return (res != gKeyBuffer.end()) ?
		(res->second.action == GLFW_RELEASE && mod == static_cast<Modifier>(res->second.mode))
		: false;
}

//---------------------------------------------------------------------------

InputManager::InputManager()
{
	glfwSetKeyCallback
	(
		RenderManager::GetInstance()->mRenderer.mWindow,
		KeyboardCallback
	);

	glfwSetMouseButtonCallback
	(
		RenderManager::GetInstance()->mRenderer.mWindow,
		MouseInputCallback
	);
}

//---------------------------------------------------------------------------

InputManager::~InputManager()
{
}

//---------------------------------------------------------------------------

//===========================================================================
