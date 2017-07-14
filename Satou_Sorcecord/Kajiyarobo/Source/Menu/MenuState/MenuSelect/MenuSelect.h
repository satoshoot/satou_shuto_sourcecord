#ifndef _MENU_SELECT_H_
#define _MENU_SELECT_H_
#include "../../AbstractMenu/AbstractMenu.h"

class MenuSelect :public AbstractMenu
{
public:
	MenuSelect(GameManager& gameManager, MenuChar& menuChar);

	//‰Šú‰»
	virtual void OnInitialize()override;

	virtual void Update(float deltaTime)override;
	//ó‘Ô•Ï‰»
	virtual void Decision()override;
	virtual void Before()override;

};

#endif // !_MENU_SELECT_H_
