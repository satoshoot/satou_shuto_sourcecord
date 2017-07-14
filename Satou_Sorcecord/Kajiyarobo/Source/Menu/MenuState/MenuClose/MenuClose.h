#ifndef _MENU_CLOSE_H_
#define _MENU_CLOSE_H_
#include "../../AbstractMenu/AbstractMenu.h"

class MenuClose :public AbstractMenu
{
public:
	MenuClose(MenuChar& menuChar);

	virtual void OnInitialize()override;

	virtual void Decision()override;
	virtual void Before()override;

};


#endif // !_MENU_CLOSE_H_
