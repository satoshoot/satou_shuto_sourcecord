#ifndef _MENU_MANAGER_H_
#define _MENU_MANAGER_H_

#include "../MenuIcon/MenuIcon.h"
#include "../MenuCursor/MenuCursor.h"
#include "../SetMenuResult/SetMenuResult.h"
#include "../AbstractMenu/AbstractMenuPtr.h"
#include "../MenuSupport/MenuSupport.h"
#include "../MenuSupport/MenuChar/MenuChar.h"
#include "../MenuPushR/MenuPushR.h"

#include <unordered_map>
#include <gslib.h>

enum class MenuStateName;
class GameManager;
class Item;


class MenuManager
{
public:
	MenuManager(GameManager& gameManager, Item& item);

	void Update(float deltaTime);

	void Draw()const;

	MenuStateName GetCurrentState()const;

	float GetCounter()const;

private:
	void Initialize(GameManager& gameManager, SetMenuResult& result);

	//���j���[���J���A����
	void OpenMenu();

	//A��B�{�^�����������Ƃ��̏���
	void PushButton();

	/*���j���[����Ă���Ƃ��̕`��*/
	void DrawMenuClose()const;
	/*�A�C�R���ƃJ�[�\���̕`��*/
	void DrawIcon()const;

private:
	std::unordered_map<MenuStateName, AbstractMenuPtr> m_StateMap;
	AbstractMenuPtr m_CurrentMenu;
	MenuStateName m_CurrentState;
	MenuCursor m_MenuCursor;
	SetMenuResult m_MenuResult;
	MenuIcon m_MenuIcon;
	MenuSupport m_MenuSupport;
	MenuChar m_Char;
	MenuPushR m_PushR;

	float m_Counter;
};

#endif // !_MENU_MANAGER_H_
