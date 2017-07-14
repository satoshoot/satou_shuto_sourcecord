#include "AbstractMenu.h"
#include "../../Utility/Enum/TextureName.h"
#include "../MenuStateName/MenuStateName.h"
#include "../../Base/GameManager/GameManager.h"
#include "../../Wepon/Wepon/Wepon.h"

AbstractMenu::AbstractMenu(SetMenuResult* result, GameManager* gameManager, MenuChar& menuChar)
	: m_FirstIcon(TextureName::None)
	, m_SecondIcon(TextureName::None)
	, m_ThirdIcon(TextureName::None)
	, m_FourthIcon(TextureName::None)
	, m_NextState(MenuStateName::None)
	, m_Cursor(0)
	, p_MenuResult(result)
	, p_GameManager(gameManager)
	, p_Char(&menuChar)
{

}

void AbstractMenu::Initialize()
{
	m_NextState = MenuStateName::None;
	OnInitialize();
}

void AbstractMenu::Update(float deltaTime)
{ }

void AbstractMenu::SetCursor(int cursor)
{
	m_Cursor = cursor;
}

MenuStateName AbstractMenu::GetNextState()const
{
	return m_NextState;
}


TextureName AbstractMenu::GetFirstIcon()const
{
	return m_FirstIcon;
}

TextureName AbstractMenu::GetSecondIcon()const
{
	return m_SecondIcon;
}

TextureName AbstractMenu::GetThirdIcon()const
{
	return m_ThirdIcon;
}

TextureName AbstractMenu::GetFourthIcon()const
{
	return m_FourthIcon;
}

void AbstractMenu::SortWeponTexture(int& first, int& second, int& third, int& fourth)
{
	int lCount = 0;
	int lWeponID = 0;
	for (int i = 0; i < 5; i++)
	{
		if (p_GameManager->GetWepon(i) != p_GameManager->GetPlayerWepon())
		{
			if (lCount == 0)
			{
				m_FirstIcon = p_GameManager->GetWepon(i)->GetTextureName();
				first = lWeponID;
			}
			else if (lCount == 1)
			{
				m_SecondIcon = p_GameManager->GetWepon(i)->GetTextureName();
				second = lWeponID;
			}
			else if (lCount == 2)
			{
				m_ThirdIcon = p_GameManager->GetWepon(i)->GetTextureName();
				third = lWeponID;
			}
			else if (lCount == 3)
			{
				m_FourthIcon = p_GameManager->GetWepon(i)->GetTextureName();
				fourth = lWeponID;
			}
			lCount++;
		}
		lWeponID++;
	}
}

