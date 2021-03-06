#ifndef _MENU_SELECT_H_
#define _MENU_SELECT_H_
#include "../../AbstractMenu/AbstractMenu.h"

class MenuSelect :public AbstractMenu
{
public:
	MenuSelect(GameManager& gameManager, MenuChar& menuChar);

	//初期化
	virtual void OnInitialize()override;

	virtual void Update(float deltaTime)override;
	//状態変化
	virtual void Decision()override;
	virtual void Before()override;

};

#endif // !_MENU_SELECT_H_
