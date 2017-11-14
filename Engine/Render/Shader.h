#ifndef RENDERER_SHADER_H__
#define RENDERER_SHADER_H__
//===========================================================================
// FILE: main.cpp
// DESC: App Entry point for testing
//===========================================================================

//===========================================================================
// INCLUDE
//===========================================================================
#include "Common.h"

#include <string>
//===========================================================================

//===========================================================================
// CLASS Shader
//===========================================================================
class Shader
{
public:
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	Shader(const Shader& other);
	Shader(const Shader&& other);
	Shader operator=(const Shader& other);
	Shader operator=(const Shader&& other);


	void Use();
	
	void SetBool(std::string& name, bool value);
	void SetInt(std::string& name, int  value);
	void SetFloat(std::string& name, float value);

private:
	void ComipleShader(unsigned int& shader, char* shaderCode, unsigned int glShader);

private:
	unsigned int Id;

};
//===========================================================================


//===========================================================================
#endif //RENDERER_SHADER_H__
