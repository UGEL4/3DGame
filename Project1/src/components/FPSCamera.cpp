#include "FPSCamera.h"
#include "../actor/Actor.h"

FPSCamera::FPSCamera(class Actor* owner)
	:CameraComponent(owner),
	mPitchSpeed(0.0f),
	maxPitch(Math::Pi / 3),
	mPitch(0.0f)
{

}

void FPSCamera::Update(float deltaTime)
{
	CameraComponent::Update(deltaTime);//现在不做任何事
	Vector3 pos = mOwner->GetPosition();
	
	mPitch += mPitchSpeed * deltaTime;
	mPitch = Math::Clamp(mPitch, -maxPitch, maxPitch);
	Quaternion pitchRota(mOwner->GetRight(), mPitch);
	
	Vector3 viewForward		= Vector3::Transform(mOwner->GetForward(), pitchRota);
	Vector3 target			= pos + viewForward * 100.0f;
	Vector3 up				= Vector3::Transform(Vector3::UnitZ, pitchRota);
	Matrix4 view			= Matrix4::CreateLookAt(pos, target, up);
	SetViewMatrix(view);
}
