#ifndef _MENU_SPEAR_SELECT_H_
#define _MENU_SPEAR_SELECT_H_
#include "../../AbstractMenu/AbstractMenu.h"

class MenuSpearSelect :public AbstractMenu
{
public:
	MenuSpearSelect(SetMenuResult* result, MenuChar& menuChar);

	virtual void OnInitialize()override;

	virtual void Update(float deltaTime)override;

	virtual void Decision()override;
	virtual void Before()override;

};


#endif // !_MENU_SPEAR_SELECT_H_
