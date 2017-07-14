#include "MenuPushR.h"
#include "../../Utility/Enum/TextureName.h"
#include "../MenuIcon/MenuIcon.h"
#include "../MenuStateName/MenuStateName.h"

MenuPushR::MenuPushR() :
	m_Size(0.0f, 0.0f),
	m_Alpha(1.0f),
	m_AlphaPlus(0.002f)
{

}

void MenuPushR::MenuSize(float deltaTime, float counter, MenuStateName& name, MenuIcon& icon)
{
	AlphaPlus();
	if (name == MenuStateName::Close ||
		name == MenuStateName::MakeTime)
	{
		if (counter <= 0)
			m_Size += GSvector2(0.1f, 0.1f);
		ClampSize();

		return;
	}
	icon.SizeUpdate(deltaTime, counter);
	m_Size -= GSvector2(0.2f, 0.2f);

	ClampSize();
}

void MenuPushR::Draw() const
{
	const GSrect l_Rect(0.0f, 0.0f, 250.0f, 250.0f);
	const GScolor l_Color(1.0f, 1.0f, 1.0f, m_Alpha);
	gsDrawSprite2D(
		(GSuint)TextureName::Make,
		&GSvector2(1400.0f, 900.0f),
		&l_Rect,
		&GSvector2(250.0f, 250.0f),
		&l_Color,
		&m_Size,
		0.0f
		);
}

void MenuPushR::ClampSize()
{
	m_Size.x = CLAMP(m_Size.x, 0.0f, 1.0f);
	m_Size.y = CLAMP(m_Size.y, 0.0f, 1.0f);
}

//アルファ値の変更
void MenuPushR::AlphaPlus()
{
	if (m_Alpha >= 1.0f || m_Alpha <= 0.7f)
		m_AlphaPlus *= -1;

	m_Alpha += m_AlphaPlus;
}