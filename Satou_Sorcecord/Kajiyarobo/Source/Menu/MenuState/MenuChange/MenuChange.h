#ifndef _MENU_CHANGE_H_
#define _MENU_CHANGE_H_
#include "../../AbstractMenu/AbstractMenu.h"

class MenuChange :public AbstractMenu
{
public:
	MenuChange(GameManager* gameManager, MenuChar& menuChar);

	virtual void OnInitialize()override;

	virtual void Update(float deltaTime)override;

	virtual void Decision()override;
	virtual void Before()override;

private:
	int mFirstWeponID;
	int mSecondWeponID;
	int mThirdWeponID;
	int mFourthWeponID;

};


#endif // !_MENU_CHANGE_H_
