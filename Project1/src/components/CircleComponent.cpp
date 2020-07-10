#include "CircleComponent.h"
#include "../actor/Actor.h"

CircleComponent::CircleComponent(class Actor* owner)
	:Component(owner),
	mRadius(0.0f)
{
}

float CircleComponent::GetRadius() const
{
	return mOwner->GetScale() * mRadius;
}

const Vector3& CircleComponent::GetCenter() const
{
	return mOwner->GetPosition();
}

//Ô²ÐÎÅö×²¼ì²â
bool Intersect(const CircleComponent& a, const CircleComponent& b)
{
	Vector3 diff = a.GetCenter() - b.GetCenter();
	float distSq = diff.LengthSq();
	
	float radiiSq = a.GetRadius() + b.GetRadius();
	radiiSq *= radiiSq;

	return distSq <= radiiSq;

}
