#include "MenuChar.h"
#include "../../../Utility/Enum/TextureName.h"
#include "../../../Screen/Screen.h"
#include "../../MenuStateName/MenuStateName.h"
#include "../../../Utility/Number/Number.h"
#include "../../../Base/GameManager/GameManager.h"
#include "../../../Wepon/Wepon/Wepon.h"
#include <gslib.h>

MenuChar::MenuChar() :
	m_Name(TextureName::None),
	m_Menu(MenuStateName::None)
{
}

void MenuChar::SetTexture(
	const TextureName& first, const TextureName& second,
	const TextureName& third, const TextureName& fourth, int& count)
{
	switch (count)
	{
	case 0:
		m_Name = first;
		break;
	case 1:
		m_Name = second;
		break;
	case 2:
		m_Name = third;
		break;
	case 3:
		m_Name = fourth;
		break;
	}
}

void MenuChar::SetWeapon(int& first, int& second,
	int& third, int& fourth, int& count, GameManager& gameManager)
{
	switch (count)
	{
	case 0:
		m_Lv = gameManager.GetWepon(first)->GetLv();
		m_Power = gameManager.GetWepon(first)->GetPower();
		break;
	case 1:
		m_Lv = gameManager.GetWepon(second)->GetLv();
		m_Power = gameManager.GetWepon(second)->GetPower();
		break;
	case 2:
		m_Lv = gameManager.GetWepon(third)->GetLv();
		m_Power = gameManager.GetWepon(third)->GetPower();
		break;
	case 3:
		m_Lv = gameManager.GetWepon(fourth)->GetLv();
		m_Power = gameManager.GetWepon(fourth)->GetPower();
		break;
	}
}

void MenuChar::SetMakeWeapon(const int & first, const int & second, const int & third,
	const int & fourth, int & count)
{
	m_Lv = 1;
	switch (count)
	{
	case 0:
		m_Power = first;
		break;
	case 1:
		m_Power = second;
		break;
	case 2:
		m_Power = third;
		break;
	case 3:
		m_Power = fourth;
		break;
	}
}


void MenuChar::Draw() const
{
	CharDraw();

	if (m_Menu == MenuStateName::SwordSelect ||
		m_Menu == MenuStateName::SpearSelect ||
		m_Menu == MenuStateName::GunSelect ||
		m_Menu == MenuStateName::Upgrade ||
		m_Menu == MenuStateName::Change)
	{
		//•Ší‚ª‚È‚¢‚Æ‚«‚ÍƒŠƒ^[ƒ“
		if (m_Power <= 0)
			return;

		LvDraw();
		PowerDraw();
	}
}

void MenuChar::SetCurrentMenu(MenuStateName& name)
{
	m_Menu = name;
}

void MenuChar::CharDraw() const
{
	GSvector2 l_Position(150.0f, HEIGHT - 230.0f);
	GSrect l_Rect(0.0f, 0.0f, 200.0f, 200.0f);
	GSvector2 l_Center(100.0f, 100.0f);

	gsDrawSprite2D(
		(GSuint)m_Name,
		&l_Position,
		&l_Rect,
		&l_Center,
		NULL,
		NULL,
		0.0f);
}

void MenuChar::LvDraw() const
{
	static const Number l_Number(TextureName::Number, 20.0f, 20.0f);
	l_Number.Draw(GSvector2(100.0f, HEIGHT - 280.0f), m_Lv);
}

void MenuChar::PowerDraw() const
{
	static const Number l_Number(TextureName::AbilityNumber, 13.0f, 13.0f);
	l_Number.Draw(GSvector2(170.0f, HEIGHT - 240.0f), m_Power);
}
