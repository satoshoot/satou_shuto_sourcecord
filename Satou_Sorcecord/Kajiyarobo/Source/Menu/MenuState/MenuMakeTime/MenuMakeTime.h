#ifndef _MENU_MAKE_TIME_H_
#define _MENU_MAKE_TIME_H_
#include "../../AbstractMenu/AbstractMenu.h"

class MenuMakeTime :public AbstractMenu
{
public:
	MenuMakeTime(MenuChar& menuChar);

	virtual void OnInitialize()override;

	virtual	void Update(float deltaTime)override;

	virtual void Decision()override;
	virtual void Before()override;

private:
	float mCounter;

};


#endif // !_MENU_MAKE_TIME_H_
