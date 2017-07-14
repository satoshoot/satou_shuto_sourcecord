#include "MenuChange.h"
#include "../../../Base/GameManager/GameManager.h"
#include "../../../Wepon/Wepon/Wepon.h"
#include "../../MenuStateName/MenuStateName.h"
#include "../../../Utility/Enum/SoundName.h"
#include "../../MenuSupport/MenuChar/MenuChar.h"
#include "../../../Utility/Enum/TextureName.h"
#include <gslib.h>

MenuChange::MenuChange(GameManager* gameManager, MenuChar& menuChar)
	: AbstractMenu(nullptr, gameManager, menuChar)
	, mFirstWeponID(0)
	, mSecondWeponID(0)
	, mThirdWeponID(0)
	, mFourthWeponID(0)
{

}

void MenuChange::OnInitialize()
{
	SortWeponTexture(mFirstWeponID, mSecondWeponID, mThirdWeponID, mFourthWeponID);
}

void MenuChange::Update(float deltaTime)
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

void MenuChange::Decision()
{
	switch (m_Cursor)
	{
	case 0:
		p_GameManager->SetPlayerWepon(mFirstWeponID);
		break;
	case 1:
		p_GameManager->SetPlayerWepon(mSecondWeponID);
		break;
	case 2:
		p_GameManager->SetPlayerWepon(mThirdWeponID);

		break;
	case 3:
		p_GameManager->SetPlayerWepon(mFourthWeponID);
		break;
	}
	gsPlaySE((GSuint)SoundName::ChangeWeponSE);
	m_NextState = MenuStateName::Close;
}

void MenuChange::Before()
{
	m_NextState = MenuStateName::Select;
}