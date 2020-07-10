#pragma once

class VertexArray
{
public:
	VertexArray(const float* verts, unsigned int numVerts, 
		const unsigned int* indices, unsigned int numIndices);
	~VertexArray();

	//设置这个顶点数组为活跃状态（我们要绘制它）
	void SetActive();

	unsigned int GetNumVerts() const { return mNumVerts; }
	unsigned int GetNumIndices() const { return mNumIndices; }
private:
	unsigned int mNumVerts;
	unsigned int mNumIndices;

	unsigned int mVertexBuffer;
	unsigned int mIndexBuffer;

	unsigned int mVertexArray;
};