#ifndef _MENU_SWORD_SELECT_H_
#define _MENU_SWORD_SELECT_H_
#include "../../AbstractMenu/AbstractMenu.h"

class MenuSwordSelect :public AbstractMenu
{
public:
	MenuSwordSelect(SetMenuResult* result, MenuChar& menuChar);

private:
	virtual void OnInitialize()override;

	virtual void Update(float deltaTime)override;

	virtual void Decision()override;
	virtual void Before()override;

};


#endif // !_MENU_SWORD_SELECT_H_
