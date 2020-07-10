#include "FollowActor.h"
#include "Game.h"
#include "components/MoveComponent.h"
#include "components/FollowCamera.h"
#include "components/MeshComponent.h"
#include "renderer/Renderer.h"

FollowActor::FollowActor(class Game* game)
	:Actor(game)
{
	mCamera = new FollowCamera(this);
	mMoveComp = new MoveComponent(this);
	mMesh = new MeshComponent(this);
	mMesh->SetMesh(game->GetRenderer()->GetMesh("res/RacingCar.gpmesh"));
	SetPosition(Vector3(0.0f, 0.0f, -100.0f));
}

void FollowActor::ActorInput(const uint8_t* keys)
{
	float forwardSpeed = 0.0f;
	float angularSpeed = 0.0f;
	// wasd movement
	if (keys[SDL_SCANCODE_W])
	{
		forwardSpeed += 400.0f;
	}
	if (keys[SDL_SCANCODE_S])
	{
		forwardSpeed -= 400.0f;
	}
	/*if (keys[SDL_SCANCODE_A])
	{
		angularSpeed -= Math::Pi;
	}
	if (keys[SDL_SCANCODE_D])
	{
		angularSpeed += Math::Pi;
	}*/
	if (keys[SDL_SCANCODE_UP])
	{
		mCamera->SetHorzDist(mCamera->GetHorzDist() - 10);
	}
	if(keys[SDL_SCANCODE_DOWN])
	{ 
		mCamera->SetHorzDist(mCamera->GetHorzDist() + 10);
	}
	/*if (keys[SDL_SCANCODE_Q])
	{
		mCamera->SetVertDist(mCamera->GetVertDist() - 10);
	}
	if (keys[SDL_SCANCODE_E])
	{
		mCamera->SetVertDist(mCamera->GetVertDist() + 10);
	}*/

	int x, y;
	Uint32 buttons = SDL_GetRelativeMouseState(&x, &y);
	const int maxMouseSpeed = 500;
	const float maxAngularSpeed = Math::Pi * 8.0f;
	if (x != 0)
	{
		angularSpeed = static_cast<float>(x) / maxMouseSpeed;
		angularSpeed *= maxAngularSpeed;
	}
	float speed = 0;
	if (y != 0)
	{
		speed = static_cast<float>(y) / maxMouseSpeed;
		speed *= maxAngularSpeed * 5.f;
	}

	mCamera->SetVertDist(mCamera->GetVertDist() + speed);

	mMoveComp->SetForwardSpeed(forwardSpeed);
	mMoveComp->SetAngularSpeed(angularSpeed);

	// Adjust horizontal distance of camera based on speed
	/*if (!Math::NearZero(forwardSpeed))
	{
		mCamera->SetHorzDist(500.0f);
	}
	else
	{
		mCamera->SetHorzDist(350.0f);
	}*/
}
