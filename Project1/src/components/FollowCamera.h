#pragma once
#include "CameraComponent.h"

class FollowCamera : public CameraComponent
{
public:
	FollowCamera(class Actor* owner);

	Vector3 ComputeCameraPos() const;
	void Update(float deltaTime) override;

	const Vector3& GetCameraPos() const { return mCameraPos; }
	float GetHorzDist() const { return mHDist; }
	float GetVertDist() const { return mVDist; }
	float GetTargetDist() const { return mTargetDist; }
	void SetCameraPos(const Vector3& pos) { mCameraPos = pos; }
	void SetHorzDist(float dist) { mHDist = dist; }
	void SetVertDist(float dist) { mVDist = dist; }
	void SetTargerDist(float dist) { mTargetDist = dist; }
private:
	Vector3 mCameraPos;
	float mHDist;
	float mVDist;
	float mTargetDist;
};