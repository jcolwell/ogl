//==================================================================================
// File: Texture2D.cpp
// Desc: 
//==================================================================================

//==================================================================================
// INCLUDES
//==================================================================================
#include "Texture2D.h"
#include "Common.h"

#include "Shader.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
//==================================================================================

//==================================================================================
// CLASS FUNCTIONS
//==================================================================================

Texture2D::Texture2D()
	: mPath(nullptr)
	, mPos()
	, mShader(nullptr)
	, mVBO(0)
	, mVAO(0)
	, mEBO(0)
	, mTexture(0)
{
}

//----------------------------------------------------------------------------------

Texture2D::Texture2D(const Texture2D& other)
{
	if (this != &other)
	{
		mPath    = other.mPath;
		mPos     = other.mPos;
		mShader  = other.mShader;
		mVBO     = other.mVBO;
		mVAO     = other.mVAO;
		mEBO     = other.mEBO;
		mTexture = other.mTexture;
	}
}

//----------------------------------------------------------------------------------

Texture2D::Texture2D(const Texture2D&& other)
{
	if (this != &other)
	{
		mPath = other.mPath;
		mPos = other.mPos;
		mShader = other.mShader;
		mVBO = other.mVBO;
		mVAO = other.mVAO;
		mEBO = other.mEBO;
		mTexture = other.mTexture;
	}
}

//----------------------------------------------------------------------------------

Texture2D Texture2D::operator=(const Texture2D& other)
{
	if (this != &other)
	{
		mPath = other.mPath;
		mPos = other.mPos;
		mShader = other.mShader;
		mVBO = other.mVBO;
		mVAO = other.mVAO;
		mEBO = other.mEBO;
		mTexture = other.mTexture;
	}
	return *this;
}

//----------------------------------------------------------------------------------

Texture2D Texture2D::operator=(const Texture2D&& other)
{
	if (this != &other)
	{
		mPath = other.mPath;
		mPos = other.mPos;
		mShader = other.mShader;
		mVBO = other.mVBO;
		mVAO = other.mVAO;
		mEBO = other.mEBO;
		mTexture = other.mTexture;
	}
	return *this;
}

//----------------------------------------------------------------------------------

void Texture2D::Load( char* imgPath )
{
	mPath = imgPath;
	const char* img = Util::ReadFile(imgPath);

	CreateTexture();
	
}

//----------------------------------------------------------------------------------

void Texture2D::Unload()
{
	SAVE_DELETE(mShader);
	glDeleteVertexArrays(1, &mVAO);
	glDeleteBuffers(1, &mVBO);
	glDeleteBuffers(1, &mEBO);
}

//----------------------------------------------------------------------------------

void Texture2D::SetPosition(Math::Vector2& pos)
{
	mPos.x = pos.x; 
	mPos.y = pos.y;
	
	
}

//----------------------------------------------------------------------------------

const Math::Vector2& Texture2D::GetPosition() const
{
	return mPos;
}

//----------------------------------------------------------------------------------

void Texture2D::Render()
{
	glBindTexture(GL_TEXTURE_2D, mTexture);
	mShader->Use();

	glBindTexture(GL_TEXTURE_2D, mTexture);
	glBindVertexArray(mVAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

//----------------------------------------------------------------------------------

void Texture2D::CreateTexture()
{
	mShader = new Shader("../../AppData/Shaders/default.vs", "../../AppData/Shaders/default.fs");

	//TODO: Take into account the desired size & position of this Texture2D...
	float vertices[] =
	{
		 // positions           // colors           // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   1.0f, 1.0f, // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // top left 
	};

	unsigned int indices[] =
	{
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mVBO);
	glGenBuffers(1, &mEBO);

	glBindVertexArray(mVAO);

	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	// load and create a texture 
	// -------------------------
	glGenTextures(1, &mTexture);
	glBindTexture(GL_TEXTURE_2D, mTexture);

	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//Enable Ap
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// load image, create texture and generate mipmaps
	s32 nrChannels;

	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.	
	unsigned char *data = stbi_load(mPath, &mWidth, &mHeight, &nrChannels, 0);
	ASSERT(nullptr != data, "[Renderer] STBI failed to load sprite: %s", stbi_failure_reason());

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);

}

//----------------------------------------------------------------------------------
