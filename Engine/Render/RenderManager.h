#ifndef RENDERING_RENDER_MANAGER__H__
#define RENDERING_RENDER_MANAGER__H__
//===========================================================================
// FILE: Common.h
// DESC: 
//===========================================================================

#include "Common.h"
#include "Renderer.h"

class InputManager;
//===========================================================================


class RenderManager
{
public:
	static RenderManager* GetInstance();
	
	void Shutdown();

	//Window stuff
	void OpenWindow(int width, int height, const char* name);
	void CloseWindow();

	bool IsWindowOpen();
	
	//Shader Management?
	//Sprite Texture Management?
	
	//Render stuff
	void Render();

	//@ToDo: Is this still valid?
	friend InputManager;

private:
	RenderManager();

	RenderManager(RenderManager const&)		= delete;
	RenderManager(RenderManager const&&)	= delete;
	void operator=(RenderManager const&)	= delete;
	void operator=(RenderManager const&&)	= delete;

private:
	Renderer mRenderer;
};

#endif //RENDERER__H__