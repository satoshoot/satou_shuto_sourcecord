#include "MenuGunSelect.h"
#include "../../MenuStateName/MenuStateName.h"
#include "../../SetMenuResult/SetMenuResult.h"
#include "../../../Utility/Enum/TextureName.h"
#include "../../../Wepon/WeponName/WeponName.h"
#include "../../MenuSupport/MenuChar/MenuChar.h"
#include "../../../Wepon/WeponParameter/WeponParameter.h"

MenuGunSelect::MenuGunSelect(SetMenuResult* result, MenuChar& menuChar)
	: AbstractMenu(result, nullptr, menuChar)
{

}

void MenuGunSelect::OnInitialize()
{
	m_FirstIcon = TextureName::IronGun;
	m_SecondIcon = TextureName::Vulcan;
	m_ThirdIcon = TextureName::LaserGun;
	m_FourthIcon = TextureName::Cannon;
	p_MenuResult->SetSelectWepon(WeponName::None);
}

void MenuGunSelect::Update(float deltaTime)
{
	p_Char->SetTexture(
		WeponParameter::GetAbillity(WeponName::IronGun),
		WeponParameter::GetAbillity(WeponName::Vulcan),
		WeponParameter::GetAbillity(WeponName::LaserGun),
		WeponParameter::GetAbillity(WeponName::Cannon),
		m_Cursor);

	p_Char->SetMakeWeapon(
		WeponParameter::GetPower(WeponName::IronGun),
		WeponParameter::GetPower(WeponName::Vulcan),
		WeponParameter::GetPower(WeponName::LaserGun),
		WeponParameter::GetPower(WeponName::Cannon),
		m_Cursor);
}

void MenuGunSelect::Decision()
{
	switch (m_Cursor)
	{
	case 0:
		p_MenuResult->SetSelectWepon(WeponName::IronGun);
		break;
	case 1:
		p_MenuResult->SetSelectWepon(WeponName::Vulcan);
		break;
	case 2:
		p_MenuResult->SetSelectWepon(WeponName::LaserGun);
		break;
	case 3:
		p_MenuResult->SetSelectWepon(WeponName::Cannon);
		break;
	}
	m_NextState = MenuStateName::PutWepon;
}

void MenuGunSelect::Before()
{
	m_NextState = MenuStateName::Make;
}