#ifndef _MENU_PUT_WEPON_H_
#define _MENU_PUT_WEPON_H_
#include "../../AbstractMenu/AbstractMenu.h"


class MenuPutWepon :public AbstractMenu
{
public:
	MenuPutWepon(SetMenuResult* result, GameManager* gameManager, MenuChar& menuChar);

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

#endif // !_MENU_PUT_WEPON_H_
