#ifndef RENDERING_RENDERER__H__
#define RENDERING_RENDERER__H__
//===========================================================================
// FILE: Renderer.h
// DESC: 
//===========================================================================
#include "Common.h"
#include "Shader.h"
#include "Texture2D.h"

#include <vector>

class InputManager;
//===========================================================================

//===========================================================================
// ENUM ShaderType
//===========================================================================
enum class ShaderType
{
	Fragmentation,
	Vertex
};
//===========================================================================

//===========================================================================
// CLASS Renderer
//===========================================================================

using Texture2DList = std::vector<Texture2D>;
using Texture2DHandle = std::vector<Texture2D>::iterator;

class Renderer
{

public:
	friend InputManager; //So the InputManager can get input from the window...
	
	Renderer();
	~Renderer();

	void OpenWindow(int width, int height, const char* name);
	void CloseWindow();
	bool IsWindowOpen() const;

	//Shader Management?
	//Texture/Sprite Management?

	void Render();

private:
	NONCOPYABLE(Renderer);

private:
	//std::vector< std::tuple< const char*, ShaderType> > mShaders;
	GLFWwindow* mWindow = nullptr;
	Texture2D* mTexture2D;
};

//===========================================================================
#endif