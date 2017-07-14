#include "MenuIcon.h"
#include <gslib.h>

MenuIcon::MenuIcon() :
	m_IconSizeY(0.0f)
{
}

void MenuIcon::SizeUpdate(float deltaTime, float & counter)
{
	SizeChange(counter);

	m_IconSizeY = CLAMP(m_IconSizeY, 0.0f, 1.0f);
}

void MenuIcon::Draw(const TextureName & first, const TextureName & second, const TextureName & third, const TextureName & fourth) const
{
	const GSrect rect(0.0f, 0.0f, 190.0f, 180.0f);
	const GSvector2 lSize(1.0f, m_IconSizeY);

	gsDrawSprite2D(
		(GSuint)first,
		&GSvector2(460.0f, 760.0f),
		&rect,
		&GSvector2(95.0f, 90.0f),
		NULL,
		&lSize,
		0.0f
		);
	gsDrawSprite2D(
		(GSuint)second,
		&GSvector2(710.0f, 760.0f),
		&rect,
		&GSvector2(95.0f, 90.0f),
		NULL,
		&lSize,
		0.0f
		);
	gsDrawSprite2D(
		(GSuint)third,
		&GSvector2(960.0f, 760.0f),
		&rect,
		&GSvector2(95.0f, 90.0f),
		NULL,
		&lSize,
		0.0f
		);
	gsDrawSprite2D(
		(GSuint)fourth,
		&GSvector2(1210.0f, 760.0f),
		&rect,
		&GSvector2(95.0f, 90.0f),
		NULL,
		&lSize,
		0.0f
		);
}

void MenuIcon::SizeChange(float& counter)
{
	if (counter < 20)
	{
		m_IconSizeY += 0.2f;
		return;
	}
	m_IconSizeY -= 0.2f;
}
