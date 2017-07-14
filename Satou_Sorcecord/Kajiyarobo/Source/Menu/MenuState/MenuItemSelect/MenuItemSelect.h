#ifndef _MENU_ITEM_SELECT_H_
#define _MENU_ITEM_SELECT_H_
#include "../../AbstractMenu/AbstractMenu.h"


class MenuItemSelect :public AbstractMenu
{
public:
	MenuItemSelect(SetMenuResult* result, MenuChar& menuChar);

	virtual void OnInitialize()override;

	virtual void Update(float deltaTime)override;

	virtual void Decision()override;
	virtual void Before()override;

};

#endif // !_MENU_ITEM_SELECT_H_
