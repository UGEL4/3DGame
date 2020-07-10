#include "VertexArray.h"
#include "GL/glew.h"
#include "Shader.h"
VertexArray::VertexArray(const float* verts, unsigned int numVerts, const unsigned int* indices, unsigned int numIndices)
	:mNumVerts(numVerts),
	mNumIndices(numIndices)
{
	GLCALL(glGenVertexArrays(1, &mVertexArray));
	GLCALL(glBindVertexArray(mVertexArray));

	GLCALL(glGenBuffers(1, &mVertexBuffer));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer));

	GLCALL(glBufferData(GL_ARRAY_BUFFER, numVerts * 8 * sizeof(float), verts, GL_STATIC_DRAW));

	GLCALL(glGenBuffers(1, &mIndexBuffer));
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer));
	GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(unsigned int), indices, GL_STATIC_DRAW));

	GLCALL(glEnableVertexAttribArray(0));
	GLCALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, 0));

	GLCALL(glEnableVertexAttribArray(1));
	GLCALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
		sizeof(float) * 8, 
		reinterpret_cast<void*>(sizeof(float) * 3)		//offset pointer
	));

	GLCALL(glEnableVertexAttribArray(2));
	GLCALL(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
		sizeof(float) * 8,
		reinterpret_cast<void*>(sizeof(float) * 6)		//offset pointer
	));
}

VertexArray::~VertexArray()
{
	glDeleteBuffers(1, &mVertexBuffer);
	glDeleteBuffers(1, &mIndexBuffer);
	glDeleteVertexArrays(1, &mVertexArray);
}

void VertexArray::SetActive()
{
	GLCALL(glBindVertexArray(mVertexArray));
}
