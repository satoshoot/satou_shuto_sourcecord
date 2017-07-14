#include "Menu.h"
#include "../MenuManager/MenuManager.h"
#include "../MenuStateName/MenuStateName.h"
#include "../../Utility/Enum/TextureName.h"

Menu::Menu()
	: mMenuManager(nullptr)
	, mMenuBackSize(0.0f, 0.0f)
{

}

Menu::~Menu()
{
	delete mMenuManager;
}

void Menu::NewMenuManager(GameManager& gameManager, Item& item)
{
	mMenuManager = new MenuManager(gameManager, item);
}

void Menu::Update(float deltaTime)
{
	if (mMenuManager->GetCurrentState() == MenuStateName::Close ||
		mMenuManager->GetCurrentState() == MenuStateName::MakeTime)
	{
		//ƒƒjƒ…[‚ğ•Â‚¶‚é
		if (mMenuManager->GetCounter() <= 20)
			mMenuBackSize -= GSvector2(0.0f, 0.2f);
		else if (mMenuManager->GetCounter() <= 25)
			mMenuBackSize -= GSvector2(0.196f, 0.0f);
	}
	else
	{
		if (mMenuManager->GetCounter() <= 30)
			mMenuBackSize += GSvector2(0.2f, 0.0f);
		else if (mMenuManager->GetCounter() <= 40)
		{
			mMenuBackSize.x = 0.05f;
			mMenuBackSize += GSvector2(0.0f, 0.1f);
		}
	}
	mMenuBackSize.x = CLAMP(mMenuBackSize.x, 0.0f, 1.0f);
	mMenuBackSize.y = CLAMP(mMenuBackSize.y, 0.0f, 1.0f);

	mMenuManager->Update(deltaTime);
}

void Menu::Draw()const
{
	const GSrect rect(0.0f, 0.0f, 1200.0f, 250.0f);

	gsDrawSprite2D(
		(GSuint)TextureName::MakeBack,
		&GSvector2(830.0f, 760.0f),
		&rect,
		&GSvector2(600.0f, 125.0f),
		NULL,
		&mMenuBackSize,
		0.0f
		);

	mMenuManager->Draw();
}

MenuStateName Menu::GetCurrentState()const
{
	return mMenuManager->GetCurrentState();
}