#pragma once
#include <cstdint>
class Component
{
public:
	Component(class Actor* owner, int updateOrder = 100);
	virtual ~Component();
	virtual void Update(float deltaTime);
	virtual void ProcessInput(const uint8_t* state) {}
	virtual void OnUpdateWorldTransform() {}

	int GetUpdateOrder() const { return mUpdateOrder; }
	class Actor* GetOwner() const { return mOwner; }

protected:
	class Actor* mOwner;
	int mUpdateOrder;	//ֵԽ��Խ�����
};