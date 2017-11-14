#ifndef RENDER_TEXTURE_H__
#define RENDER_TEXTURE_H__
//==================================================================================
// File: Texture.h
// Desc: 
//==================================================================================

//==================================================================================
// INCLUDES
//==================================================================================
#include "Common.h"

#include <Vector2.h>
#include <string>

class Shader;
//==================================================================================

//ToDo: SetPosition
//ToDo: SetSize (TopLeft, BottomRight) (Width, Height)
//ToDo: SetPivotPoint
//ToDo: Rotate( angle or quaternion )

//==================================================================================
// CLASS TEXTURE
//==================================================================================
class Texture2D
{
public:
	Texture2D();
	Texture2D(const Texture2D& other);
	Texture2D(const Texture2D&& other);
	Texture2D operator=(const Texture2D& other);
	Texture2D operator=(const Texture2D&& other);

	void Load(char* img);
	void Unload();

	void SetPosition( Math::Vector2& pos );
	const Math::Vector2& GetPosition() const;

	void Render();

private:
	void CreateTexture();
	
private:
	char* mPath;
	Math::Vector2 mPos;
	s32 mWidth, mHeight;
	Shader* mShader = nullptr;
	u32 mVBO, mVAO, mEBO;
	u32 mTexture;
};
//==================================================================================

//==================================================================================
#endif //RENDER_TEXTURE_H__