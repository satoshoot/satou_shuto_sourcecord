#include "MenuSpearSelect.h"
#include "../../../Utility/Enum/TextureName.h"
#include "../../SetMenuResult/SetMenuResult.h"
#include "../../../Wepon/WeponName/WeponName.h"
#include "../../MenuStateName/MenuStateName.h"
#include "../../MenuSupport/MenuChar/MenuChar.h"
#include "../../../Wepon/WeponParameter/WeponParameter.h"

MenuSpearSelect::MenuSpearSelect(SetMenuResult* result, MenuChar& menuChar)
	: AbstractMenu(result, nullptr, menuChar)
{

}

void MenuSpearSelect::OnInitialize()
{
	m_FirstIcon = TextureName::IronSpear;
	m_SecondIcon = TextureName::Partisan;
	m_ThirdIcon = TextureName::Otegine;
	m_FourthIcon = TextureName::Vajyuranda;
	p_MenuResult->SetSelectWepon(WeponName::None);
}

void MenuSpearSelect::Update(float deltaTime)
{
	p_Char->SetTexture(
		WeponParameter::GetAbillity(WeponName::IronSpear),
		WeponParameter::GetAbillity(WeponName::Partisan),
		WeponParameter::GetAbillity(WeponName::Otegine),
		WeponParameter::GetAbillity(WeponName::Vajyuranda),
		m_Cursor);

	p_Char->SetMakeWeapon(
		WeponParameter::GetPower(WeponName::IronSpear),
		WeponParameter::GetPower(WeponName::Partisan),
		WeponParameter::GetPower(WeponName::Otegine),
		WeponParameter::GetPower(WeponName::Vajyuranda),
		m_Cursor);
}

void MenuSpearSelect::Decision()
{
	switch (m_Cursor)
	{
	case 0:
		p_MenuResult->SetSelectWepon(WeponName::IronSpear);
		break;
	case 1:
		p_MenuResult->SetSelectWepon(WeponName::Partisan);
		break;
	case 2:
		p_MenuResult->SetSelectWepon(WeponName::Otegine);
		break;
	case 3:
		p_MenuResult->SetSelectWepon(WeponName::Vajyuranda);
		break;
	}
	m_NextState = MenuStateName::PutWepon;
}

void MenuSpearSelect::Before()
{
	m_NextState = MenuStateName::Make;
}