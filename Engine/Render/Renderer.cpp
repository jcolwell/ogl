//===========================================================================
// FILE: Renderer.cpp
// DESC: 
//===========================================================================
#include "Renderer.h"
#include "Shader.h"

#include <cstdio>
//===========================================================================

//===========================================================================
// Renderer IMPLEMENTATION
//===========================================================================

Renderer::Renderer()
	: mWindow(nullptr)
	, mTexture2D(nullptr)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

//---------------------------------------------------------------------------

Renderer::~Renderer()
{
	SAVE_DELETE(mTexture2D);

	this->CloseWindow();
	glfwTerminate();
}

//---------------------------------------------------------------------------

void Renderer::OpenWindow(int width, int height, const char* name)
{
	ASSERT(mWindow == nullptr, "[Renderer] Attempted to create a new window, when one already exists");
	
	mWindow = glfwCreateWindow(width, height, name, nullptr, nullptr);
	glfwMakeContextCurrent(mWindow);
	glCheckError();

	glewExperimental = GL_TRUE;
	glewInit();
	glCheckError();

	// Define the viewport dimensions
	glfwGetFramebufferSize(mWindow, &width, &height);
	glViewport(0, 0, width, height);

	mTexture2D = new Texture2D();
	mTexture2D->Load("../../AppData/Sprites/icon_marker.png");
	
	//mTexture2D->SetPosition( Math::Vector2(640, 360) );
	mTexture2D->SetPosition(Math::Vector2(800, 0));

	//mTexture2D->SetSize(Math::Vector2(32, 32));
}

//---------------------------------------------------------------------------

void Renderer::CloseWindow()
{
	if (mWindow)
	{
		glfwSetWindowShouldClose(mWindow, GLFW_FALSE);
		mWindow = nullptr;
	}
}

//---------------------------------------------------------------------------

bool Renderer::IsWindowOpen() const
{
	return mWindow != nullptr;
}

//---------------------------------------------------------------------------

void Renderer::Render()
{	
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
		
	mTexture2D->Render();

	glfwSwapBuffers(mWindow);
}

//---------------------------------------------------------------------------

//===========================================================================
