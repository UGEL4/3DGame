#pragma once
#include "actor/Actor.h"

class FollowActor : public Actor
{
public:
	FollowActor(class Game* game);
	void ActorInput(const uint8_t* skeys) override;
private:
	class MoveComponent* mMoveComp;
	class FollowCamera* mCamera;
	//class Actor* mModel;
	class MeshComponent* mMesh;
};