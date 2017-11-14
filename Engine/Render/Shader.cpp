//==================================================================================
// File: Common.h
// Desc: 
//==================================================================================
#include "Shader.h"
#include "Common.h"
//==================================================================================

//==================================================================================
// COMMON FUNCTIONS
//==================================================================================

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
	//Open files
	char* vShaderCode = Util::ReadFile(vertexPath);
	char* fShaderCode = Util::ReadFile(fragmentPath);
	
	//Compile Vertex Shader Code...
	unsigned int vert = 0;
	unsigned int frag = 0;
	
	//vertex shader
	// ...shaders won't compile... :(
	ComipleShader(vert, vShaderCode, GL_VERTEX_SHADER);
	ComipleShader(frag, fShaderCode, GL_FRAGMENT_SHADER);

	// Create the shader program and link it to gl
	Id = glCreateProgram();
	glAttachShader(Id, vert);
	glAttachShader(Id, frag); 
	glLinkProgram(Id);

	int success;
	glGetProgramiv(Id, GL_LINK_STATUS, &success);
	if (!success)
	{
		char log[512];
		glGetProgramInfoLog(Id, 512, NULL, log);
		ASSERT(success, "[Shader::Shader()] Failed to link programs");
	}

	// Shaders are linked so we don't need to carry them around 
	glDeleteShader(vert);
	glDeleteShader(frag);
}

//----------------------------------------------------------------------------------

Shader::Shader(const Shader& other)
{
	if (this != &other)
	{
		Id = other.Id;
	}
}

//----------------------------------------------------------------------------------

Shader::Shader(const Shader&& other)
{
	if (this != &other)
	{
		Id = other.Id;
	}
}

//----------------------------------------------------------------------------------

Shader Shader::operator=(const Shader& other)
{
	if (this != &other)
	{
		Id = other.Id;
	}
	return *this;
}

//----------------------------------------------------------------------------------

Shader Shader::operator=(const Shader&& other)
{
	if (this != &other)
	{
		Id = other.Id;
	}
	return *this;
}

//----------------------------------------------------------------------------------

void Shader::Use()
{
	glUseProgram(Id);
}

//----------------------------------------------------------------------------------

void Shader::SetBool(std::string& name, bool value)
{
	glUniform1i(glGetUniformLocation(Id, name.c_str()), (int)value);
}

//----------------------------------------------------------------------------------

void Shader::SetInt(std::string& name, int  value)
{
	glUniform1i(glGetUniformLocation(Id, name.c_str()), value);
}

//----------------------------------------------------------------------------------

void Shader::SetFloat(std::string& name, float value)
{
	glUniform1f(glGetUniformLocation(Id, name.c_str()), value);
}

//----------------------------------------------------------------------------------

void Shader::ComipleShader(unsigned int& shader, char* shaderCode, unsigned int glShader )
{

	shader = glCreateShader(glShader);
	GLchar* source = static_cast<GLchar*>(shaderCode);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (GL_FALSE == success)
	{
		//Log...
		char infoLog[512];

		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		ASSERT(success, "[Shader::Shader()] Failed to compile shader: %s", infoLog);
	}
}