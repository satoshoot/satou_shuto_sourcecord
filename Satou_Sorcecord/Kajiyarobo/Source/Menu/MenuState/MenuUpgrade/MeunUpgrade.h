#ifndef _MENU_UPGRADE_H_
#define _MENU_UPGRADE_H_
#include "../../AbstractMenu/AbstractMenu.h"

class MenuUpgrade :public AbstractMenu
{
public:
	MenuUpgrade(SetMenuResult* result, GameManager* gameManager, MenuChar& manuChar);

	virtual void OnInitialize()override;

	virtual void Update(float deltaTime)override;

	virtual void Decision()override;

	virtual void Before()override;

private:
	void NextState(int& id);

private:
	int mFirstWeponID;
	int mSecondWeponID;
	int mThirdWeponID;
	int mFourthWeponID;

};


#endif // ! _MENU_UPGRADE_H_
