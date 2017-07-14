#include "Renderer.h"
#include "../Enum/MeshName.h"
#include "../Enum/TextureName.h"

Renderer::Renderer()
{ }

Renderer::~Renderer()
{ }

void Renderer::LoadMesh(const MeshName& meshName, const std::string& name)
{
	gsLoadMesh((GSuint)meshName, name.c_str());
	m_MeshList.push_back(meshName);
}

void Renderer::LoadModel(const MeshName& meshName,
	const std::string& name, const std::string& sklName)
{
	gsLoadMesh((GSuint)meshName, name.c_str());
	gsLoadSkeleton((GSuint)meshName, sklName.c_str());
	m_ModelList.push_back(meshName);
}

void Renderer::LoadAnimation(const MeshName& animationName, const std::string& anmName)
{
	gsLoadAnimation((GSuint)animationName, anmName.c_str());
	m_AnimationList.push_back(animationName);
}

void Renderer::LoadOctree(const MeshName& meshName, const std::string& name,
	const std::string& octName)
{
	gsLoadMesh((GSuint)meshName, name.c_str());
	gsLoadOctree((GSuint)meshName, octName.c_str());
}

void Renderer::LoadTexture(const TextureName& textureName, const std::string& name)
{
	gsLoadTexture((GSuint)textureName, name.c_str());
	m_TextureList.push_back(textureName);
}

void Renderer::DeleteMesh()
{
	for (NameList::iterator i = m_MeshList.begin(); i != m_MeshList.end(); i++)
	{
		gsDeleteMesh((GSuint)*i);
	}
	m_MeshList.clear();
}

void Renderer::DeleteModel()
{
	for (NameList::iterator i = m_ModelList.begin(); i != m_ModelList.end(); i++)
	{
		gsDeleteMesh((GSuint)*i);
		gsDeleteSkeleton((GSuint)*i);
	}
	m_ModelList.clear();
}

void Renderer::DeleteAnimation()
{
	for (NameList::iterator i = m_AnimationList.begin(); i != m_AnimationList.end(); i++)
	{
		gsDeleteAnimation((GSuint)*i);
	}
	m_AnimationList.clear();
}

void Renderer::DeleteOctree(const MeshName& meshName)
{
	gsDeleteMesh((GSuint)meshName);
	gsDeleteOctree((GSuint)meshName);
}

void Renderer::DeleteTexture()
{
	for (TextureList::iterator i = m_TextureList.begin(); i != m_TextureList.end(); i++)
	{
		gsDeleteTexture((GSuint)*i);
	}
	m_TextureList.clear();
}
