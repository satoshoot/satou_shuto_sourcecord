#include "MenuMakeTime.h"
#include "../../MenuStateName/MenuStateName.h"

MenuMakeTime::MenuMakeTime(MenuChar& menuChar)
	: AbstractMenu(nullptr, nullptr, menuChar)
	, mCounter(0)
{

}

void MenuMakeTime::OnInitialize()
{
	mCounter = 10 * 60;
}

void MenuMakeTime::Update(float deltaTime)
{
	if (mCounter <= 0)
		m_NextState = MenuStateName::Close;

	mCounter -= deltaTime;
}

void MenuMakeTime::Decision()
{ }

void MenuMakeTime::Before()
{ }