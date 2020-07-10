#include "AnimSpriteComponent.h"
#include "../renderer/Texture.h"

AnimSpriteComponent::AnimSpriteComponent(class Actor* owner, int drawOrder /*= 100*/)
	:SpriteComponent(owner,drawOrder),
	mCurrFrame(0.0f),
	mCurrWAFrame(0.0f),
	mAnimFPS(24.0f),
	isIdle(true),
	isAir(false)
{
}

void AnimSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);
	//std::cout << "Anim Update func" << std::endl;
	if (mAnimTextures.size() > 0)
	{
		mCurrFrame += mAnimFPS * deltaTime;
		while (mCurrFrame >= mAnimTextures.size())
		{
			mCurrFrame -= mAnimTextures.size();
		}

		SetTexture(mAnimTextures[static_cast<int>(mCurrFrame)]);
	}
	if (isIdle)
	{
		if (mIdleAnimTextures.size() > 0)
		{
			mCurrFrame += mAnimFPS * deltaTime;
			while (mCurrFrame >= mIdleAnimTextures.size())
			{
				mCurrFrame -= mIdleAnimTextures.size();
			}

			SetTexture(mIdleAnimTextures[static_cast<int>(mCurrFrame)]);
		}
	}
	else
	{
		if (mWalkAnimTextures.size() > 0)
		{
			mCurrWAFrame += mAnimFPS * deltaTime;
			while (mCurrWAFrame >= mWalkAnimTextures.size())
			{
				mCurrWAFrame -= mWalkAnimTextures.size();
			}
			SetTexture(mWalkAnimTextures[static_cast<int>(mCurrWAFrame)]);
			isIdle = true;
		}
	}
}

void AnimSpriteComponent::SetAnimTextures(const std::vector<Texture*>& textures)
{
	mAnimTextures = textures;
	if (mAnimTextures.size() > 0)
	{
		mCurrFrame = 0.0f;
		SetTexture(mAnimTextures[0]);
	}
}

void AnimSpriteComponent::SetWalkAnimTextures(const std::vector<Texture*>& textures)
{
	mWalkAnimTextures = textures;
	if (mWalkAnimTextures.size() > 0)
	{
		mCurrWAFrame = 0.0f;
		//SetTexture(mWalkAnimTextures[0]);
	}
}

void AnimSpriteComponent::SetIdleAnimTextures(const std::vector<Texture*>& textures)
{
	mIdleAnimTextures = textures;
	if (mIdleAnimTextures.size() > 0)
	{
		mCurrFrame = 0.0f;
		SetTexture(mIdleAnimTextures[0]);
	}
}
