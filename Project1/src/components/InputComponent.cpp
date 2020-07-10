#include "InputComponent.h"
#include "../actor/Actor.h"


InputComponent::InputComponent(class Actor* owner)
	:MoveComponent(owner),
	mForwardKey(0),
	mBackKey(0),
	mClockwiseKey(0),
	mCounterClockwiseKey(0)
{
}


void InputComponent::ProcessInput(const uint8_t* state)
{
	float forwardSpeed = 0.0f;
	if (state[mForwardKey])
	{
		forwardSpeed += mMaxForwardSpeed;
	}
	if (state[mBackKey])
	{
		forwardSpeed -= mMaxForwardSpeed;
	}
	SetForwardSpeed(forwardSpeed);

	float angularSpeed = 0.0f;
	if (state[mClockwiseKey])
	{
		angularSpeed += mMaxAngularSpeed;
	}
	if (state[mCounterClockwiseKey])
	{
		angularSpeed -= mMaxAngularSpeed;
	}
	SetAngularSpeed(angularSpeed);
}
