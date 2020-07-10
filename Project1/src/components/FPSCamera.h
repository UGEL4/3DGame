#pragma once
#include "CameraComponent.h"
class FPSCamera : public CameraComponent
{
public:
	FPSCamera(class Actor* owner);

	void Update(float deltaTime) override;

	void SetPitchSpeed(float speed) { mPitchSpeed = speed; }
	void SetMaxPitch(float max) { maxPitch = max; }

	float GetPitchSpeed() const { return mPitchSpeed; }
	float GetMaxPitch() const { return maxPitch; }
	float GetPitch() const { return mPitch; }
private:
	//俯仰角速度
	float mPitchSpeed;
	//最大俯仰角偏离值
	float maxPitch;
	//当前俯仰角值
	float mPitch;
};