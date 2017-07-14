#include "MenuManager.h"
#include "../../Utility/Enum/TextureName.h"
#include "../../Utility/Enum/SoundName.h"
#include "../MenuStateName/MenuStateName.h"
#include "../MenuState/MenuClose/MenuClose.h"
#include "../MenuState/MenuSelect/MenuSelect.h"
#include "../MenuState/MenuMake/MenuMake.h"
#include "../MenuState/MenuSwordSelect/MenuSwordSelect.h"
#include "../MenuState/MenuGunSelect/MenuGunSelect.h"
#include "../MenuState/MenuSpearSelect/MenuSpearSelect.h"
#include "../MenuState/MenuPutWepon/MenuPutWepon.h"
#include "../MenuState/MenuMakeTime/MenuMakeTime.h"
#include "../MenuState/MenuChange/MenuChange.h"
#include "../MenuState/MenuUpgrade/MeunUpgrade.h"
#include "../MenuState/MenuItemSelect/MenuItemSelect.h"
#include "../MenuState/MenuUse/MenuUse.h"


MenuManager::MenuManager(GameManager& gameManager, Item& item)
	: m_CurrentMenu(nullptr)
	, m_CurrentState(MenuStateName::None)
	, m_Counter(0.0f)
	, m_MenuResult(&gameManager, &item)
	, m_MenuCursor()
	, m_MenuIcon()
	, m_Char()
	, m_MenuSupport(m_Char)
	, m_PushR()
{
	m_StateMap.clear();
	Initialize(gameManager, m_MenuResult);
}

void MenuManager::Initialize(GameManager& gameManager, SetMenuResult& result)
{
	m_StateMap[MenuStateName::Close] = std::make_shared<MenuClose>(m_Char);
	m_StateMap[MenuStateName::Select] = std::make_shared <MenuSelect>(gameManager, m_Char);
	m_StateMap[MenuStateName::Make] = std::make_shared <MenuMake>(m_Char);
	m_StateMap[MenuStateName::SwordSelect] = std::make_shared<MenuSwordSelect>(&result, m_Char);
	m_StateMap[MenuStateName::GunSelect] = std::make_shared<MenuGunSelect>(&result, m_Char);
	m_StateMap[MenuStateName::SpearSelect] = std::make_shared<MenuSpearSelect>(&result, m_Char);
	m_StateMap[MenuStateName::PutWepon] = std::make_shared <MenuPutWepon>(&result, &gameManager, m_Char);
	m_StateMap[MenuStateName::MakeTime] = std::make_shared<MenuMakeTime>(m_Char);
	m_StateMap[MenuStateName::Change] = std::make_shared<MenuChange>(&gameManager, m_Char);
	m_StateMap[MenuStateName::Upgrade] = std::make_shared <MenuUpgrade>(&result, &gameManager, m_Char);
	m_StateMap[MenuStateName::ItemSelect] = std::make_shared<MenuItemSelect>(&result, m_Char);
	m_StateMap[MenuStateName::Use] = std::make_shared<MenuUse>(&result, m_Char);

	m_CurrentState = MenuStateName::Close;
	m_CurrentMenu = m_StateMap[m_CurrentState];
	m_CurrentMenu->Initialize();
}

void MenuManager::Update(float deltaTime)
{
	m_CurrentMenu->Update(deltaTime);
	m_MenuSupport.Update(deltaTime, m_CurrentState);
	m_Char.SetCurrentMenu(m_CurrentState);

	if (m_CurrentMenu->GetNextState() != MenuStateName::None)
	{
		m_CurrentState = m_CurrentMenu->GetNextState();
		m_CurrentMenu = m_StateMap[m_CurrentState];
		m_CurrentMenu->Initialize();
		m_Counter = 30;
	}

	OpenMenu();
	m_PushR.MenuSize(deltaTime, m_Counter, m_CurrentState, m_MenuIcon);

	if (m_CurrentState != MenuStateName::Close &&
		m_CurrentState != MenuStateName::MakeTime)
	{
		//カーソルの更新
		m_MenuCursor.Update(deltaTime);
		m_CurrentMenu->SetCursor(m_MenuCursor.GetSelectCount());
		PushButton();
	}
	m_Counter -= deltaTime;
}

void MenuManager::Draw()const
{
	m_MenuSupport.Draw();

	DrawMenuClose();
}

MenuStateName MenuManager::GetCurrentState()const
{
	return m_CurrentState;
}

float MenuManager::GetCounter()const
{
	return m_Counter;
}

//メニューを開く、閉じる
void MenuManager::OpenMenu()
{
	if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_RIGHT_SHOULDER) &&
		m_Counter <= 0 &&
		m_CurrentState != MenuStateName::MakeTime)
	{
		if (m_CurrentState == MenuStateName::Close)
		{
			gsPlaySE((GSuint)SoundName::OpenMenu);
			m_CurrentState = MenuStateName::Select;
		}
		else
		{
			gsPlaySE((GSuint)SoundName::Cancel);
			m_CurrentState = MenuStateName::Close;
		}

		m_CurrentMenu = m_StateMap[m_CurrentState];
		m_CurrentMenu->Initialize();
		m_Counter = 40;
	}
}

void MenuManager::PushButton()
{
	if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_A) && m_Counter <= 0)
	{
		gsPlaySE((GSuint)SoundName::Decision);
		m_CurrentMenu->Decision();
		m_MenuCursor.ResetCursor();
		return;
	}
	if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_B) && m_Counter <= 0)
	{
		gsPlaySE((GSuint)SoundName::Cancel);
		m_CurrentMenu->Before();
		m_MenuCursor.ResetCursor();
	}
}
/*メニューを閉じているときの描画*/
void MenuManager::DrawMenuClose() const
{
	if (m_CurrentState == MenuStateName::Close ||
		m_CurrentState == MenuStateName::MakeTime)
	{
		m_PushR.Draw();
		return;
	}
	DrawIcon();
}
/*アイコンとカーソルの描画*/
void MenuManager::DrawIcon() const
{
	if (m_Counter <= 20)
	{
		m_MenuIcon.Draw(
			m_CurrentMenu->GetFirstIcon(),
			m_CurrentMenu->GetSecondIcon(),
			m_CurrentMenu->GetThirdIcon(),
			m_CurrentMenu->GetFourthIcon());

		//カーソルの描画
		if (m_Counter <= 5)
			m_MenuCursor.Draw();
	}
}
