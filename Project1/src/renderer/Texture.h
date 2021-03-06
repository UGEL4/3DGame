#pragma once
#include <string>
class Texture
{
public:
	Texture();
	~Texture();

	bool Load(const std::string& fileName);
	void UnLoad();

	void SetActive();
	int GetWidth() const { return mWidth; }
	int GetHeight() const { return mHeight; }
private:
	int mWidth;
	int mHeight;
	unsigned int mTextureID;
};