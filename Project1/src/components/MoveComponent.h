#pragma once
#include "Component.h"

class MoveComponent : public Component
{
public:
	MoveComponent(class Actor* owner, int updateOrder = 10);
	void Update(float deltaTime) override;

	void SetForwardSpeed(float val) { mForwardSpeed = val; }
	float GetForwardSpeed() const { return mForwardSpeed; }
	void SetAngularSpeed(float val) { mAngularSpeed = val; }
	float GetAngularSpeed() const { return mAngularSpeed; }
	void SetRightSpeed(float val) { mRightSpeed = val; }
	float GetRightSpeed() const { return mRightSpeed; }

private:
	float mForwardSpeed;
	float mAngularSpeed;
	float mRightSpeed;
};