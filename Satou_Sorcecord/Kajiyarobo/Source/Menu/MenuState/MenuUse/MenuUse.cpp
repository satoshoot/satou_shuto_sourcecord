#include "MenuUse.h"
#include "../../SetMenuResult/SetMenuResult.h"
#include "../../MenuStateName/MenuStateName.h"
#include "../../MenuSupport/MenuChar/MenuChar.h"


MenuUse::MenuUse(SetMenuResult* result, MenuChar& menuChar)
	: AbstractMenu(result, nullptr, menuChar)
{

}

void MenuUse::OnInitialize()
{
	m_FirstIcon = p_MenuResult->GetItem(0).m_Texture;
	m_SecondIcon = p_MenuResult->GetItem(1).m_Texture;
	m_ThirdIcon = p_MenuResult->GetItem(2).m_Texture;
	m_FourthIcon = p_MenuResult->GetItem(3).m_Texture;
}

void MenuUse::Update(float deltaTime)
{
	p_Char->SetTexture(
		p_MenuResult->GetItem(0).m_Ability,
		p_MenuResult->GetItem(1).m_Ability,
		p_MenuResult->GetItem(2).m_Ability,
		p_MenuResult->GetItem(3).m_Ability,
		m_Cursor);
}

void MenuUse::Decision()
{
	p_MenuResult->UseItem(m_Cursor);
	m_NextState = MenuStateName::Close;
}

void MenuUse::Before()
{
	m_NextState = MenuStateName::Select;
}