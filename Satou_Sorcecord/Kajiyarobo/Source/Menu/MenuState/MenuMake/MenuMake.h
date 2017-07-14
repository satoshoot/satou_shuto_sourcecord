#ifndef _MENU_MAKE_H_
#define _MENU_MAKE_H_
#include "../../AbstractMenu/AbstractMenu.h"

class MenuMake :public AbstractMenu
{
public:
	MenuMake(MenuChar& menuChar);

	virtual void OnInitialize()override;

	virtual void Update(float deltaTime)override;

	virtual void Decision()override;
	virtual void Before()override;


};


#endif // !_MENU_MAKE_H_

