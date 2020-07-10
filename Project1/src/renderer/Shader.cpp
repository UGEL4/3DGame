#define GLEW_STATIC
#include "GL/glew.h"
#include "Shader.h"
#include <fstream>
#include <sstream>
#include "SDL.h"
void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}
bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << "): " << function << " " << file << ":" <<
			line << "\n";
		return false;
	}

	return true;
}
//#include "Math.h"
Shader::Shader()
	:mVertexShader(0),
	mFragmentShader(0),
	mShaderProgram(0)
{

}

Shader::~Shader()
{

}

bool Shader::Load(const std::string& vertName, const std::string& fragName)
{
	if (!CompileShader(vertName, GL_VERTEX_SHADER, mVertexShader) ||
		!CompileShader(fragName, GL_FRAGMENT_SHADER, mFragmentShader))
	{
		return false;
	}

	mShaderProgram = glCreateProgram();
	GLCALL(glAttachShader(mShaderProgram, mVertexShader));
	GLCALL(glAttachShader(mShaderProgram, mFragmentShader));
	GLCALL(glLinkProgram(mShaderProgram));

	if (!IsValidProgram())
	{
		return false;
	}

	return true;
}

void Shader::UnLoad()
{
	glDeleteProgram(mShaderProgram);
	glDeleteShader(mVertexShader);
	glDeleteShader(mFragmentShader);
}

void Shader::SetActive()
{
	GLCALL(glUseProgram(mShaderProgram));
}

void Shader::SetMatrixUniform(const char* name, const Matrix4& mat)
{
	GLuint location = glGetUniformLocation(mShaderProgram, name);
	GLCALL(glUniformMatrix4fv(location, 1, GL_TRUE, mat.GetAsFloatPtr()));
}

void Shader::SetVectorUniform(const char* name, const Vector3& vector)
{
	GLuint loc = glGetUniformLocation(mShaderProgram, name);
	// Send the vector data
	glUniform3fv(loc, 1, vector.GetAsFloatPtr());
}

void Shader::SetFloatUniform(const char* name, float value)
{
	GLuint loc = glGetUniformLocation(mShaderProgram, name);
	// Send the float data
	glUniform1f(loc, value);
}

bool Shader::CompileShader(const std::string& fileName, GLenum shaderType, GLuint& outShader)
{
	std::ifstream shaderFile(fileName);
	if (shaderFile.is_open())
	{
		std::stringstream sstream;
		sstream << shaderFile.rdbuf();
		std::string contents = sstream.str();
		const char* contentsChar = contents.c_str();

		outShader = glCreateShader(shaderType);
		GLCALL(glShaderSource(outShader, 1, &(contentsChar), nullptr));
		GLCALL(glCompileShader(outShader));

		if (!IsCompiled(outShader))
		{
			SDL_Log("Failed to compile shader: %s", fileName.c_str());
			return false;
		}
	}
	else
	{
		SDL_Log("Shader file not found: %s", fileName.c_str());
		return false;
	}

	return true;
}

bool Shader::IsCompiled(GLuint shader)
{
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		char buffer[512];
		memset(buffer, 0, 512);
		glGetShaderInfoLog(shader, 511, nullptr, buffer);
		SDL_Log("GLSL Compile Failed: \n%s", buffer);
		return false;
	}
	return true;
}

bool Shader::IsValidProgram()
{
	GLint status;
	glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &status);
	if (status != GL_TRUE)
	{
		char buffer[512];
		memset(buffer, 0, 512);
		glGetProgramInfoLog(mShaderProgram, 511, nullptr, buffer);
		SDL_Log("GLSL Link Status:\n%s", buffer);
		return false;
	}

	return true;
}
