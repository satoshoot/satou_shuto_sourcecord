#include "MenuMake.h"
#include "../../../Utility/Enum/TextureName.h"
#include "../../MenuStateName/MenuStateName.h"
#include "../../MenuSupport/MenuChar/MenuChar.h"

MenuMake::MenuMake(MenuChar& menuChar)
	: AbstractMenu(nullptr, nullptr, menuChar)
{

}

void MenuMake::OnInitialize()
{
	m_FirstIcon = TextureName::SwordIcon;
	m_SecondIcon = TextureName::SpearIcon;
	m_ThirdIcon = TextureName::GunIcon;
	m_FourthIcon = TextureName::ItemIcon;
}

void MenuMake::Update(float deltaTime)
{
	p_Char->SetTexture(
		TextureName::CharMakeSword,
		TextureName::CharMakeSpear,
		TextureName::CharMakeGun,
		TextureName::CharMakeItem,
		m_Cursor);
}

void MenuMake::Decision()
{
	switch (m_Cursor)
	{
	case 0:
		m_NextState = MenuStateName::SwordSelect;
		break;
	case 1:
		m_NextState = MenuStateName::SpearSelect;
		break;
	case 2:
		m_NextState = MenuStateName::GunSelect;
		break;
	case 3:
		m_NextState = MenuStateName::ItemSelect;
		break;
	}
}

void MenuMake::Before()
{
	m_NextState = MenuStateName::Select;
}