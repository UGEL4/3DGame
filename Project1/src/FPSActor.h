#pragma once
#include "actor/Actor.h"

class FPSActor : public Actor
{
public:
	FPSActor(class Game* game);
	void UpdateActor(float deltaTime) override;
	void ActorInput(const uint8_t* skeys) override;
private:
	class MoveComponent* mMoveComp;
	class FPSCamera* mCamera;
	class Actor* mFPSModel;
	class MeshComponent* mMesh;
};