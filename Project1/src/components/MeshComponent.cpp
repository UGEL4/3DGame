#include "MeshComponent.h"
#include "../actor/Actor.h"
#include "../renderer/Renderer.h"
#include "../Game.h"
#include "../renderer/Shader.h"
#include "../renderer/Texture.h"
#include "../mesh/Mesh.h"
#include "../renderer/VertexArray.h"

MeshComponent::MeshComponent(class Actor* owner)
	:Component(owner),
	mMesh(nullptr),
	mTextureIndex(0)
{
	mOwner->GetGame()->GetRenderer()->AddMeshComp(this);
}

MeshComponent::~MeshComponent()
{
	mOwner->GetGame()->GetRenderer()->RemoveMeshComp(this);
}

void MeshComponent::Draw(class Shader* shader)
{
	if (mMesh)
	{
		shader->SetMatrixUniform("uWorldTransform", mOwner->GetWorldTransform());
		// Set specular power
		shader->SetFloatUniform("uSpecPower", mMesh->GetSpecPower());
		//SDL_Log("SpacePower:%f", mMesh->GetSpecPower());
		Texture* t = mMesh->GetTexture(mTextureIndex);
		if (t)
		{
			t->SetActive();
		}
		VertexArray* v = mMesh->GetVertexArray();
		v->SetActive();

		glDrawElements(GL_TRIANGLES, v->GetNumIndices(), GL_UNSIGNED_INT, nullptr);
	}
}

void MeshComponent::SetMesh(class Mesh* mesh)
{
	mMesh = mesh;
}

void MeshComponent::SetTextureIndex(size_t index)
{
	mTextureIndex = index;
}
