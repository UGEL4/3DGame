#include "SpriteComponent.h"
#include "../actor/Actor.h"
#include "../Game.h"
#include "../renderer/Shader.h"
#include "../renderer/Texture.h"
#include "../renderer/Renderer.h"

SpriteComponent::SpriteComponent(class Actor* owner, int drawOrder /*= 100*/)
	:Component(owner), mDrawOrder(drawOrder), mTextureHeight(0), mTextureWidth(0), mTexture(nullptr)
{
	mOwner->GetGame()->GetRenderer()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
	mOwner->GetGame()->GetRenderer()->RemoveSprite(this);
}

void SpriteComponent::Draw(Shader* shader)
{
	if (mTexture)
	{
		Matrix4 scale = Matrix4::CreateScale(static_cast<float>(mTextureWidth),
			static_cast<float>(mTextureHeight), 1.0f);
		//SDL_Log("w:%f", mTextureWidth);

		Matrix4 world = scale * mOwner->GetWorldTransform();
		shader->SetMatrixUniform("uWorldTransform", world);

		mTexture->SetActive();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}
}

void SpriteComponent::SetTexture(Texture* texture)
{
	mTexture = texture;
	mTextureWidth = texture->GetWidth();
	mTextureHeight = texture->GetHeight();
}
