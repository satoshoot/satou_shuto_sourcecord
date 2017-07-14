#include "MenuSwordSelect.h"
#include "../../MenuStateName/MenuStateName.h"
#include "../../../Utility/Enum/TextureName.h"
#include "../../SetMenuResult/SetMenuResult.h"
#include "../../../Wepon/WeponName/WeponName.h"
#include "../../MenuSupport/MenuChar/MenuChar.h"
#include "../../../Wepon/WeponParameter/WeponParameter.h"

MenuSwordSelect::MenuSwordSelect(SetMenuResult* result, MenuChar& menuChar)
	: AbstractMenu(result, nullptr, menuChar)
{

}

void MenuSwordSelect::OnInitialize()
{
	m_FirstIcon = TextureName::IronSword;
	m_SecondIcon = TextureName::LongSword;
	m_ThirdIcon = TextureName::Flamberge;
	m_FourthIcon = TextureName::GreatSword;
	p_MenuResult->SetSelectWepon(WeponName::None);
}

void MenuSwordSelect::Update(float deltaTime)
{
	p_Char->SetTexture(
		WeponParameter::GetAbillity(WeponName::IronSword),
		WeponParameter::GetAbillity(WeponName::LongSword),
		WeponParameter::GetAbillity(WeponName::Flamberge),
		WeponParameter::GetAbillity(WeponName::GreatSword),
		m_Cursor);

	p_Char->SetMakeWeapon(
		WeponParameter::GetPower(WeponName::IronSword),
		WeponParameter::GetPower(WeponName::LongSword),
		WeponParameter::GetPower(WeponName::Flamberge),
		WeponParameter::GetPower(WeponName::GreatSword),
		m_Cursor);
}

void MenuSwordSelect::Decision()
{
	switch (m_Cursor)
	{
	case 0:
		p_MenuResult->SetSelectWepon(WeponName::IronSword);
		break;
	case 1:
		p_MenuResult->SetSelectWepon(WeponName::LongSword);
		break;
	case 2:
		p_MenuResult->SetSelectWepon(WeponName::Flamberge);
		break;
	case 3:
		p_MenuResult->SetSelectWepon(WeponName::GreatSword);
		break;
	}
	m_NextState = MenuStateName::PutWepon;
}

void MenuSwordSelect::Before()
{
	m_NextState = MenuStateName::Make;
}