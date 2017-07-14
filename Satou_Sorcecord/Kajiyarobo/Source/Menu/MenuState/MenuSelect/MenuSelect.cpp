#include "MenuSelect.h"
#include "../../../Utility/Enum/TextureName.h"
#include "../../MenuStateName/MenuStateName.h"
#include "../../MenuSupport/MenuChar/MenuChar.h"
#include "../../../Base/GameManager/GameManager.h"
#include "../../../Wepon/Wepon/Wepon.h"

MenuSelect::MenuSelect(GameManager& gameManager, MenuChar& menuChar)
	: AbstractMenu(nullptr, &gameManager, menuChar)
{

}

void MenuSelect::OnInitialize()
{
	m_FirstIcon = TextureName::MakeIcon;
	m_SecondIcon = TextureName::UpgradeIcon;
	m_ThirdIcon = TextureName::ChangeIcon;
	m_FourthIcon = TextureName::UseIcon;
}

void MenuSelect::Update(float deltaTime)
{
	p_Char->SetTexture(
		TextureName::CharMake,
		TextureName::CharUpGrade,
		TextureName::CharChange,
		TextureName::CharUse,
		m_Cursor);
}

void MenuSelect::Decision()
{
	switch (m_Cursor)
	{
	case 0:
		m_NextState = MenuStateName::Make;
		break;
	case 1:
		//m_NextState = MenuStateName::Upgrade;
		m_NextState = MenuStateName::MakeTime;
		p_GameManager->GetPlayerWepon()->LvUP();
		break;
	case 2:
		m_NextState = MenuStateName::Change;
		break;
	case 3:
		m_NextState = MenuStateName::Use;
		break;
	}
}
void MenuSelect::Before()
{
	m_NextState = MenuStateName::Close;
}
