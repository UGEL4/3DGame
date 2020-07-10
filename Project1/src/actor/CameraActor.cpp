// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "CameraActor.h"
#include "../components/MoveComponent.h"
#include "SDL_scancode.h"
#include "../renderer/Renderer.h"
#include "../Game.h"

CameraActor::CameraActor(Game* game)
	:Actor(game)
{
	mMoveComp = new MoveComponent(this);
	SDL_SetRelativeMouseMode(SDL_TRUE);
}

void CameraActor::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);

	// Compute new camera from this actor
	Vector3 cameraPos = GetPosition();
	Vector3 target = GetPosition() + GetForward() * 100.0f;
	Vector3 up = Vector3::UnitZ;

	Matrix4 view = Matrix4::CreateLookAt(cameraPos, target, up);
	GetGame()->GetRenderer()->SetViewMatrix(view);
}

void CameraActor::ActorInput(const uint8_t* keys)
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
	/*if (keys[SDL_SCANCODE_LEFT])
	{
		angularSpeed -= Math::PiOver2;
	}
	if (keys[SDL_SCANCODE_RIGHT])
	{
		angularSpeed += Math::PiOver2;
	}*/
	if (keys[SDL_SCANCODE_A])
	{
		rightSpeed -= 300.0f;
	}
	if (keys[SDL_SCANCODE_D])
	{
		rightSpeed += 300.0f;
	}

	int x, y;
	Uint32 buttons = SDL_GetRelativeMouseState(&x, &y);
	const int maxMouseSpeed = 500;
	const float maxAngularSpeed = Math::Pi * 8.0f;
	if (x != 0)
	{
		angularSpeed = static_cast<float>(x) / maxMouseSpeed;
		angularSpeed *= maxAngularSpeed;
	}
	mMoveComp->SetForwardSpeed(forwardSpeed);
	mMoveComp->SetAngularSpeed(angularSpeed);
	mMoveComp->SetRightSpeed(rightSpeed);
}
