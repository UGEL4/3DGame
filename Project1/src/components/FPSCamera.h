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
	//�������ٶ�
	float mPitchSpeed;
	//�������ƫ��ֵ
	float maxPitch;
	//��ǰ������ֵ
	float mPitch;
};