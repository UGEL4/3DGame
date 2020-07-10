#pragma once
#include "Component.h"
#include "SDL.h"
class SpriteComponent : public Component
{
public:
	SpriteComponent(class Actor* owner, int drawOrder = 100);
	~SpriteComponent();

	virtual void Draw(class Shader* shader);
	virtual void SetTexture(class Texture* texture);

	int GetDrawOrder() const { return mDrawOrder; }
	int GetTextureHeight() const { return mTextureHeight; }
	int GetTextureWidth() const { return mTextureWidth; }

protected:
	int mDrawOrder;
	int mTextureHeight;
	int mTextureWidth;
	class Texture* mTexture;
};