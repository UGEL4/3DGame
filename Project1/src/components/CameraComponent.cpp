#include "CameraComponent.h"
#include "../actor/Actor.h"
#include "../Game.h"
#include "../renderer/Renderer.h"
CameraComponent::CameraComponent(class Actor* owner, int updateOrder)
	:Component(owner,updateOrder)
{

}

void CameraComponent::SetViewMatrix(const Matrix4& view)
{
	Game* game = mOwner->GetGame();
	game->GetRenderer()->SetViewMatrix(view);
}
