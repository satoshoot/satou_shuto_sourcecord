#include "Number.h"
#include <iomanip>
#include <sstream>

Number::Number(const TextureName & name, float width, float height) :
	m_Name(name),
	m_Width(width),
	m_Height(height)
{}

void Number::Draw(const GSvector2 & position, int num, int dight, char fill) const
{
	std::stringstream ss;
	ss << std::setw(dight) << std::setfill(fill) << num;
	Draw(position, ss.str());
}

void Number::Draw(const GSvector2 & position, int num) const
{
	Draw(position, std::to_string(num));
}

void Number::Draw(const GSvector2 & position, const std::string & num) const
{
	for (int i = 0; i < num.size(); i++)
	{

		int l_Number = num[i] - '0'; //AsciiƒR[ƒh
		const GSrect l_Rect(l_Number * m_Width, 0.0f, (l_Number * m_Width) + m_Width, m_Height);
		const GSvector2 l_Position(position.x + i * m_Width, position.y);
		gsDrawSprite2D(
			(GSuint)m_Name,
			&l_Position,
			&l_Rect,
			NULL,
			NULL,
			NULL,
			0.0f);
	}
}