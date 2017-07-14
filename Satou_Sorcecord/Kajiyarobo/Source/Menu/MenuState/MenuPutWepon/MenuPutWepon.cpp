#include "MenuPutWepon.h"
#include "../../../Base/GameManager/GameManager.h"
#include "../../../Wepon/Wepon/Wepon.h"
#include "../../SetMenuResult/SetMenuResult.h"
#include "../../MenuStateName/MenuStateName.h"
#include "../../MenuSupport/MenuChar/MenuChar.h"

MenuPutWepon::MenuPutWepon(SetMenuResult* result, GameManager* gameManager, MenuChar& menuChar)
	: AbstractMenu(result, gameManager, menuChar)
	, mFirstWeponID(0)
	, mSecondWeponID(0)
	, mThirdWeponID(0)
	, mFourthWeponID(0)
{

}

void MenuPutWepon::OnInitialize()
{
	SortWeponTexture(mFirstWeponID, mSecondWeponID, mThirdWeponID, mFourthWeponID);
}

void MenuPutWepon::Update(float deltaTime)
{
	p_Char->SetTexture(
		TextureName::CharLost,
		TextureName::CharLost,
		TextureName::CharLost,
		TextureName::CharLost,
		m_Cursor);
}

void MenuPutWepon::Decision()
{
	switch (m_Cursor)
	{
	case 0:
		p_MenuResult->SetWepon(mFirstWeponID);
		p_GameManager->SetPlayerWepon(mFirstWeponID);
		break;
	case 1:
		p_MenuResult->SetWepon(mSecondWeponID);
		p_GameManager->SetPlayerWepon(mSecondWeponID);
		break;
	case 2:
		p_MenuResult->SetWepon(mThirdWeponID);
		p_GameManager->SetPlayerWepon(mThirdWeponID);
		break;
	case 3:
		p_MenuResult->SetWepon(mFourthWeponID);
		p_GameManager->SetPlayerWepon(mFourthWeponID);
		break;
	}
	m_NextState = MenuStateName::MakeTime;
}

void MenuPutWepon::Before()
{
	m_NextState = MenuStateName::Make;
}