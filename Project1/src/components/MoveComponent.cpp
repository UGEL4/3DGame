#include "MoveComponent.h"
#include "../Math.h"
#include "../actor/Actor.h"

MoveComponent::MoveComponent(class Actor* owner, int updateOrder /*= 10*/)
	:Component(owner,updateOrder),
	mForwardSpeed(0.0f),
	mAngularSpeed(0.0f),
	mRightSpeed(0.0f)
{

}

void MoveComponent::Update(float deltaTime)
{
	if (!Math::NearZero(mAngularSpeed))
	{
		Quaternion rota = mOwner->GetRotation();
		float angle = deltaTime * mAngularSpeed;
		Quaternion incremental(Vector3::UnitZ, angle);
		rota = Quaternion::Concatenate(rota, incremental);
		mOwner->SetRotation(rota);
	}

	/*if (!Math::NearZero(mForwardSpeed))
	{
		Vector3 pos = mOwner->GetPosition();
		pos += mOwner->GetForward() * mForwardSpeed * deltaTime;
		mOwner->SetPosition(pos);
	}

	if (!Math::NearZero(mRightSpeed))
	{
		Vector3 pos = mOwner->GetPosition();
		pos += mOwner->GetRight() * mRightSpeed * deltaTime;
		mOwner->SetPosition(pos);
	}*/
	if (!Math::NearZero(mForwardSpeed) || !Math::NearZero(mRightSpeed))
	{
		Vector3 pos = mOwner->GetPosition();
		pos += mOwner->GetForward() * mForwardSpeed * deltaTime;
		pos += mOwner->GetRight() * mRightSpeed * deltaTime;
		mOwner->SetPosition(pos);
	}
}
