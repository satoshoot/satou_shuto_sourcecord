#ifndef _MENU_USE_H_
#define _MENU_USE_H_
#include "../../AbstractMenu/AbstractMenu.h"

class MenuUse :public AbstractMenu
{
public:
	MenuUse(SetMenuResult* result,MenuChar& menuChar);

	virtual void OnInitialize()override;

	virtual void Update(float deltaTime)override;

	virtual void Decision()override;

	virtual void Before()override;

};

#endif // !_MENU_USE_H_
