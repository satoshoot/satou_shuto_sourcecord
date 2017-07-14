#include "MenuSupport.h"
#include "../../Utility/Enum/TextureName.h"
#include "../../Screen/Screen.h"
#include "../MenuStateName/MenuStateName.h"
#include "MenuChar/MenuChar.h"

MenuSupport::MenuSupport(MenuChar& menuChar) :
	m_Size(0.0f, 0.0f),
	p_Char(&menuChar)
{

}

void MenuSupport::Update(float deltaTime, MenuStateName& name)
{

	if (name == MenuStateName::Close ||
		name == MenuStateName::MakeTime)
	{
		m_Size -= GSvector2(0.18f, 0.18f);
		ClampSize();
		return;
	}
	m_Size += GSvector2(0.18f, 0.18f);
	ClampSize();

}

void MenuSupport::Draw()const
{
	GSvector2 l_Position(260.0f + 20.0f, HEIGHT - 30.0f);
	GSrect l_Rect(0.0f, 0.0f, 260.0f, 330.0f);
	GSvector2 l_Center(260.0f, 330.0f);

	gsDrawSprite2D(
		(GSuint)TextureName::MenuSupport,
		&l_Position,
		&l_Rect,
		&l_Center,
		NULL,
		&m_Size,
		0.0f);

	if (m_Size.x >= 1.0f)
		p_Char->Draw();
}

void MenuSupport::ClampSize()
{
	m_Size.x = CLAMP(m_Size.x, 0.0f, 1.0f);
	m_Size.y = CLAMP(m_Size.y, 0.0f, 1.0f);
}
