#ifndef _MENU_GUN_SELECT_H_
#define _MENU_GUN_SELECT_H_
#include "../../AbstractMenu/AbstractMenu.h"


class MenuGunSelect :public AbstractMenu
{
public:
	MenuGunSelect(SetMenuResult* result, MenuChar& menuChar);

	virtual void OnInitialize()override;

	virtual void Update(float deltaTime)override;

	virtual void Decision()override;
	virtual void Before()override;

};


#endif // !_MENU_GUN_SELECT_H_
