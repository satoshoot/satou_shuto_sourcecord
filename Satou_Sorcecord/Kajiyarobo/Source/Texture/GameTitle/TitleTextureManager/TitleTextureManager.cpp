#include "TitleTextureManager.h"
#include "../ITitleTextureBase/ITitleTextureBase.h"
#include "../TitleLogo/TitleLogo.h"
#include "../TitleStart/TitleStart.h"
#include "../TitleBackObject/TitleIcon/TitleIcon.h"
#include "../TitleBackObject/TitleIcon/TitleCursor.h"
#include "../TitleBackObject/TitleBicCursor/TitleScale.h"
#include "../TitleBackObject/TitleBicCursor/TitleBigCursor.h"
#include "../TitleBackObject/TitleBicCursor/BigCursorPosition.h"
#include "../TitleBackObject/TitleBicCursor/TitleSubCursor.h"
#include "../../../Screen/Screen.h"

TitleTextureManager::TitleTextureManager()
{
	m_TextureList.clear();
}

TitleTextureManager::~TitleTextureManager()
{
	m_TextureList.clear();
}

void TitleTextureManager::Initialize()
{
	Add();
}

void TitleTextureManager::StartUpdate(float deltaTime, float& counter)
{
	for (TextureList::iterator i = m_TextureList.begin(); i != m_TextureList.end(); i++)
	{
		(*i)->StartUpdate(deltaTime, counter);
	}
}

void TitleTextureManager::EndUpdate(float deltaTime, float& counter)
{
	for (TextureList::iterator i = m_TextureList.begin(); i != m_TextureList.end(); i++)
	{
		(*i)->EndUpdate(deltaTime, counter);
	}
}

void TitleTextureManager::Draw() const
{
	for (TextureList::const_iterator i = m_TextureList.begin(); i != m_TextureList.end(); i++)
	{
		(*i)->Draw();
	}
}

void TitleTextureManager::End()
{
	m_TextureList.clear();
}

void TitleTextureManager::Add()
{
	m_TextureList.push_back(new TitleScale());
	m_TextureList.push_back(new TitleIcon(GSvector2(WIDTH - 200.0f, 550.0f), TextureName::SwordIcon));
	m_TextureList.push_back(new TitleIcon(GSvector2(WIDTH - 200.0f, 750.0f), TextureName::SpearIcon));
	m_TextureList.push_back(new TitleCursor());

	BigCursorPosition* l_CursorPosition = new BigCursorPosition();
	m_TextureList.push_back(new TitleBigCursor(*l_CursorPosition));
	m_TextureList.push_back(new TitleSubCursor(*l_CursorPosition));
	m_TextureList.push_back(l_CursorPosition);


	m_TextureList.push_back(new TitleLogo());
	m_TextureList.push_back(new TitleStart());
}