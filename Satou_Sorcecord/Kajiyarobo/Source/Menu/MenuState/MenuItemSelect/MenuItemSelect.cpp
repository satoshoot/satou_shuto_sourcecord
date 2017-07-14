#include "MenuItemSelect.h"
#include "../../../Utility/Enum/TextureName.h"
#include "../../SetMenuResult/SetMenuResult.h"
#include "../../../Item/ItemName/ItemName.h"
#include "../../MenuStateName/MenuStateName.h"
#include "../../MenuSupport/MenuChar/MenuChar.h"

MenuItemSelect::MenuItemSelect(SetMenuResult* result, MenuChar& menuChar)
	: AbstractMenu(result, nullptr, menuChar)
{

}

void MenuItemSelect::OnInitialize()
{
	m_FirstIcon = TextureName::Recovery;
	m_SecondIcon = TextureName::Shield;
	m_ThirdIcon = TextureName::PowerUP;
	m_FourthIcon = TextureName::Icon;
}

void MenuItemSelect::Update(float deltaTime)
{
	p_Char->SetTexture(
		TextureName::CharRecovery,
		TextureName::CharShield,
		TextureName::CharPowerUp,
		TextureName::None,
		m_Cursor);
}

void MenuItemSelect::Decision()
{
	switch (m_Cursor)
	{
	case 0:
		if (p_MenuResult->SetItem(m_Cursor,
			ItemName::Recovery, TextureName::Recovery, TextureName::CharRecovery) == true)
			m_NextState = MenuStateName::MakeTime;
		break;
	case 1:
		if (p_MenuResult->SetItem(m_Cursor,
			ItemName::Shield, TextureName::Shield, TextureName::CharShield) == true)
			m_NextState = MenuStateName::MakeTime;
		break;
	case 2:
		if (p_MenuResult->SetItem(m_Cursor,
			ItemName::PowerUp, TextureName::PowerUP, TextureName::CharPowerUp) == true)
			m_NextState = MenuStateName::MakeTime;
		break;
	case 3:
		m_NextState = MenuStateName::ItemSelect;
		break;
	}
}

void MenuItemSelect::Before()
{
	m_NextState = MenuStateName::Make;
}