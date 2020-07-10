#include "Actor.h"
#include "../components/Component.h"
#include <algorithm>
#include "../Game.h"


Actor::Actor(class Game* game)
	:mState(EActive),
	mPosition(Vector3::Zero),
	mRecomputeWorldTransform(true),
	mScale(1.0f),
	mRotation(Quaternion::Identity),
	mGame(game)
{
	mGame->AddActor(this);
}


Actor::~Actor()
{
	mGame->RemoveActor(this);
	while (!mComponents.empty())
	{
		delete mComponents.back();
	}
}

void Actor::Update(float deltaTime)
{
	if (mState == EActive)
	{
		ComputeWorldTransform();
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
		ComputeWorldTransform();
	}
}

void Actor::UpdateComponents(float deltaTime)
{
	for (auto comp : mComponents)
	{
		comp->Update(deltaTime);
	}
}

void Actor::UpdateActor(float deltaTime)
{
}

void Actor::ProcessInput(const uint8_t* state)
{
	if (mState == EActive)
	{
		for (auto comp : mComponents)
		{
			comp->ProcessInput(state);
		}

		ActorInput(state);
	}
}

void Actor::ActorInput(const uint8_t* state)
{

}

void Actor::AddComponent(class Component* comp)
{
	// Find the insertion point in the sorted vector
// (The first element with a order higher than me)
	int myOrder = comp->GetUpdateOrder();
	auto iter = mComponents.begin();
	for (; iter != mComponents.end(); ++iter)
	{
		if (myOrder < (*iter)->GetUpdateOrder())
		{
			break;
		}
	}

	// Inserts element before position of iterator
	mComponents.insert(iter, comp);
}

void Actor::RemoveComponent(class Component* comp)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), comp);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}
}

void Actor::ComputeWorldTransform()
{
	if (mRecomputeWorldTransform)
	{
		mRecomputeWorldTransform = false;
		mWorldTransform = Matrix4::CreateScale(mScale);
		mWorldTransform *= Matrix4::CreateFromQuaternion(mRotation);
		mWorldTransform *= Matrix4::CreateTranslation(mPosition);

		for (auto comp : mComponents)
		{
			comp->OnUpdateWorldTransform();
		}
	}
}
