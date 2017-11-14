//===========================================================================
// FILE: main.cpp
// DESC: App Entry point for testing
//===========================================================================

//===========================================================================
// INCLUDE
//===========================================================================
#include <cstdio>
#include <cmath>
#include <thread>

#include "Engine.h"

#include <RenderManager.h>
#include "InputManager.h"
//===========================================================================

//@ToDo: Networking!
//@ToDo: Multi Platform building! (Android/iOS/MacOS)
//@ToDo: Editor Application!
//@ToDo: Memory Management!
//@ToDo: Multi-Threading!
//@ToDo: Profiling and other tools!

//@TODO: Sound Library!
//@TODO: Resource/Memory Manager
//@TODO: Rendering --> 3D Models/Textures
//@TODO: Rendering --> 2D Sprites
//@TODO: Rendering --> Font
//@TODO: [CORE] Gameplay --> Global Gametime
//@TODO: Entity Component System
//@ToDo: Maths library (And test it!)
//@TODO: InputManager --> Custom Cursor Img


//===========================================================================
// MAIN
//===========================================================================
int main()
{
	Engine::GetInstance()->Initialize( "config.ini" );
	
	//Texture2D someTexture( Math::Vector2 pos, Math::Vector2 size );

	while( Engine::GetInstance()->IsRunning() )
	{
		InputManager::GetInstance()->PollInputDevices();

		//GameLogic
		if (InputManager::GetInstance()->KeyPressed(Key::Escape))
		{
			printf("Pressed Escape!\n");
			Engine::GetInstance()->Exit();
		}

		//someTexture.SetPos(pos);



		//Render
		RenderManager::GetInstance()->Render();
		
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}


	return EXIT_SUCCESS;
}
//===========================================================================


