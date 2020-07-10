#pragma once
#include <string>
#include "GL/glew.h"
#include "../Math.h"
#include <iostream>
#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCALL(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x,__FILE__,__LINE__))

bool GLLogCall(const char* function, const char* file, int line);

void GLClearError();


//class Matrix4;
class Shader
{
public:
	Shader();
	~Shader();

	bool Load(const std::string& vertName, const std::string& fragName);
	void UnLoad();

	void SetActive();
	void SetMatrixUniform(const char* name, const Matrix4& mat);
	// Sets a Vector3 uniform
	void SetVectorUniform(const char* name, const Vector3& vector);

	// Sets a float uniform
	void SetFloatUniform(const char* name, float value);

private:
	bool CompileShader(const std::string& fileName, GLenum shaderType, GLuint& outShader);
	bool IsCompiled(GLuint shader);
	bool IsValidProgram();

	GLuint mVertexShader;
	GLuint mFragmentShader;
	GLuint mShaderProgram;
};