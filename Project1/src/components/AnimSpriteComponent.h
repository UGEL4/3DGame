#pragma once
#include "SpriteComponent.h"
#include <vector>
class AnimSpriteComponent : public SpriteComponent
{
public:
	AnimSpriteComponent(class Actor* owner, int drawOrder = 100);

	void Update(float deltaTime) override;
	void SetAnimTextures(const std::vector<class Texture*>& textures);
	void SetWalkAnimTextures(const std::vector<class Texture*>& textures);
	void SetIdleAnimTextures(const std::vector<class Texture*>& textures);

	float GetAnimFPS() const { return mAnimFPS; }
	void SetAnimFPS(float fps) { mAnimFPS = fps; }

	void SetIdle(bool idle) { isIdle = idle; }

private:
	//all textures in the animation
	std::vector<class Texture*> mAnimTextures;
	//walk animation texture
	std::vector<class Texture*> mWalkAnimTextures;
	//idle animation texture
	std::vector<class Texture*> mIdleAnimTextures;
	//current frame displayed
	float mCurrFrame;
	float mCurrWAFrame;
	//animation frame rate
	float mAnimFPS;
	bool isIdle;
	bool isAir;

};