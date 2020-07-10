#include "FPSActor.h"
#include "Game.h"
#include "components/MoveComponent.h"
#include "components/FPSCamera.h"
#include "components/MeshComponent.h"
#include "renderer/Renderer.h"
FPSActor::FPSActor(class Game* game)
	:Actor(game)
{
	mCamera		= new FPSCamera(this);
	mMoveComp	= new MoveComponent(this);
	mFPSModel = new Actor(game);
	mFPSModel->SetScale(0.75f);
	mMesh = new MeshComponent(mFPSModel);
	mMesh->SetMesh(game->GetRenderer()->GetMesh("res/Rifle.gpmesh"));
}

void FPSActor::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);

	const Vector3 modelOffset(Vector3(10.0f, 10.0f, -10.0f));
	Vector3 modelPos = GetPosition();
	modelPos += GetForward() * modelOffset.x;
	modelPos += GetRight() * modelOffset.y;
	modelPos.z += modelOffset.z;
	mFPSModel->SetPosition(modelPos);

	Quaternion q = GetRotation();
	q = Quaternion::Concatenate(q,Quaternion(GetRight(), mCamera->GetPitch()));
	mFPSModel->SetRotation(q);
}

void FPSActor::ActorInput(const uint8_t* keys)
{
	float forwardSpeed = 0.0f;
	float angularSpeed = 0.0f;
	float rightSpeed = 0.0f;
	// wasd movement
	if (keys[SDL_SCANCODE_W])
	{
		forwardSpeed += 300.0f;
	}
	if (keys[SDL_SCANCODE_S])
	{
		forwardSpeed -= 300.0f;
	}
	if (keys[SDL_SCANCODE_A])
	{
		rightSpeed -= 300.0f;
	}
	if (keys[SDL_SCANCODE_D])
	{
		rightSpeed += 300.0f;
	}
	mMoveComp->SetForwardSpeed(forwardSpeed);
	mMoveComp->SetRightSpeed(rightSpeed);

	int x, y;
	Uint32 buttons = SDL_GetRelativeMouseState(&x, &y);
	const int maxMouseSpeed = 500;
	const float maxAngularSpeed = Math::Pi * 8.0f;
	if (x != 0)
	{
		angularSpeed = static_cast<float>(x) / maxMouseSpeed;
		angularSpeed *= maxAngularSpeed;
	}
	mMoveComp->SetAngularSpeed(angularSpeed);
	
	const float maxPitchSpeed = Math::Pi * 8.0f;
	float pitchSpeed = 0.0f;
	if (y != 0)
	{
		pitchSpeed = static_cast<float>(y) / maxMouseSpeed;
		pitchSpeed *= maxPitchSpeed;
	}
	mCamera->SetPitchSpeed(pitchSpeed);
}
