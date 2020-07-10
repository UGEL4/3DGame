#include "Component.h"
#include "../actor/Actor.h"

Component::Component(class Actor* owner, int updateOrder /*= 100*/)
	:mOwner(owner), mUpdateOrder(updateOrder)
{
	mOwner->AddComponent(this);
}

Component::~Component()
{
	mOwner->RemoveComponent(this);
}

void Component::Update(float deltaTime)
{
	//std::cout << "Component Update FNUC" << std::endl;
}
