#pragma once
#include <vector>
#include "../Math.h"
#include <cstdint>

class Actor
{
public:
	//ÓÃÀ´¸ú×ÙactorµÄ×´Ì¬
	enum State
	{
		EActive,
		EPasued,
		EDead
	};
	Actor(class Game* game);
	virtual ~Actor();
	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);
	virtual void UpdateActor(float deltaTime);

	void ProcessInput(const uint8_t* state);
	virtual void ActorInput(const uint8_t* state);

	void AddComponent(class Component* comp);
	void RemoveComponent(class Component* comp);

	void ComputeWorldTransform();
	const Matrix4& GetWorldTransform() const { return mWorldTransform; }

	State GetState() const { return mState; }
	void SetState(State state) { mState = state; }
	class Game* GetGame() { return mGame; }
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; mRecomputeWorldTransform = true; }
	const Quaternion& GetRotation() const { return mRotation; }
	void SetRotation(const Quaternion& rotation) { mRotation = rotation; mRecomputeWorldTransform = true; }
	const Vector3& GetPosition() const { return mPosition; }
	void SetPosition(const Vector3& position) { mPosition = position; mRecomputeWorldTransform = true; }
	Vector3 GetForward() const { return Vector3::Transform(Vector3::UnitX,mRotation); }
	Vector3 GetRight() const { return Vector3::Transform(Vector3::UnitY, mRotation); }

private:
	State mState;
	Vector3 mPosition;
	Matrix4 mWorldTransform;
	Quaternion mRotation;
	bool mRecomputeWorldTransform;
	float mScale;
	std::vector<class Component*> mComponents;
	class Game* mGame;
};

