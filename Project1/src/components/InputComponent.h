#pragma once
#include "MoveComponent.h"
#include <cstdint>
class InputComponent : public MoveComponent
{
public:
	InputComponent(class Actor* owner);
	void ProcessInput(const uint8_t* state) override;

	void SetMaxForwardSpeed(float speed) { mMaxForwardSpeed = speed; }
	void SetMaxAngularSpeed(float speed) { mMaxAngularSpeed = speed; }
	void SetForwardKey(int key) { mForwardKey = key; }
	void SetBackKey(int key) { mBackKey = key; }
	void SetClockwiseKey(int key) { mClockwiseKey = key; }
	void SetCounterClockwiseKey(int key) { mCounterClockwiseKey = key; }

	float GetMaxForwardSpeed() const { return mMaxForwardSpeed; }
	float GetMaxAngularSpeed() const { return mMaxAngularSpeed; }
	int GetForwardKey() const { return mForwardKey; }
	int GetBackKey() const { return mBackKey; }
	int GetClockwiseKey() const { return mClockwiseKey; }
	int GetCounterClockwiseKey() const { mCounterClockwiseKey; }
private:
	float mMaxForwardSpeed;
	float mMaxAngularSpeed;

	int mForwardKey;
	int mBackKey;

	int mClockwiseKey;	//À≥ ±’Î
	int mCounterClockwiseKey; //ƒÊ ±’Î
};

