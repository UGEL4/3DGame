#include "FollowCamera.h"
#include "../actor/Actor.h"

FollowCamera::FollowCamera(class Actor* owner)
	:CameraComponent(owner),
	mHDist(400.0f),
	mVDist(150.0f),
	mTargetDist(100.0f)
{

}

Vector3 FollowCamera::ComputeCameraPos() const
{
	Vector3 cameraPos = mOwner->GetPosition();
	cameraPos -= mOwner->GetForward() * mHDist;
	cameraPos += Vector3::UnitZ * mVDist;
	return cameraPos;
}

void FollowCamera::Update(float deltaTime)
{
	CameraComponent::Update(deltaTime);
	mCameraPos = ComputeCameraPos();
	Vector3 target = mOwner->GetPosition() + mOwner->GetForward() * mTargetDist;
	
	Matrix4 view = Matrix4::CreateLookAt(mCameraPos, target, Vector3::UnitZ);
	SetViewMatrix(view);
}
