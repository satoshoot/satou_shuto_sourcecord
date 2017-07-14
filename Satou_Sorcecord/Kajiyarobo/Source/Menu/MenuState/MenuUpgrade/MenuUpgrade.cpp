#include "MeunUpgrade.h"
#include "../../MenuStateName/MenuStateName.h"
#include "../../SetMenuResult/SetMenuResult.h"
#include "../../MenuSupport/MenuChar/MenuChar.h"
#include "../../../Base/GameManager/GameManager.h"
#include "../../../Wepon/Wepon/Wepon.h"
#include "../../../Wepon/WeponType/WeponType.h"

MenuUpgrade::MenuUpgrade(SetMenuResult* result, GameManager* gameManager, MenuChar& menuChar)
	: AbstractMenu(result, gameManager, menuChar)
	, mFirstWeponID(0)
	, mSecondWeponID(0)
	, mThirdWeponID(0)
	, mFourthWeponID(0)
{

}

void MenuUpgrade::OnInitialize()
{
	SortWeponTexture(mFirstWeponID, mSecondWeponID, mThirdWeponID, mFourthWeponID);
}

void MenuUpgrade::Update(float deltaTime)
{
	p_Char->SetTexture(
		p_GameManager->GetWepon(mFirstWeponID)->GetAbilityTexture(),
		p_GameManager->GetWepon(mSecondWeponID)->GetAbilityTexture(),
		p_GameManager->GetWepon(mThirdWeponID)->GetAbilityTexture(),
		p_GameManager->GetWepon(mFourthWeponID)->GetAbilityTexture(),
		m_Cursor);

	p_Char->SetWeapon(mFirstWeponID, mSecondWeponID, mThirdWeponID, mFourthWeponID,
		m_Cursor, *p_GameManager);
}

void MenuUpgrade::Decision()
{
	switch (m_Cursor)
	{
	case 0:
		NextState(mFirstWeponID);
		p_MenuResult->LvUP(mFirstWeponID);
		break;
	case 1:
		NextState(mSecondWeponID);
		p_MenuResult->LvUP(mSecondWeponID);
		break;
	case 2:
		NextState(mThirdWeponID);
		p_MenuResult->LvUP(mThirdWeponID);
		break;
	case 3:
		NextState(mFourthWeponID);
		p_MenuResult->LvUP(mFourthWeponID);
		break;
	}
}

void MenuUpgrade::Before()
{
	m_NextState = MenuStateName::Select;
}

void MenuUpgrade::NextState(int& id)
{
	if (p_MenuResult->LvMax(id) ||
		p_GameManager->GetWepon(id)->GetWeponType() == WeponType::None)
	{
		m_NextState = MenuStateName::Upgrade;
		return;
	}
	m_NextState = MenuStateName::MakeTime;
}