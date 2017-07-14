#ifndef _NUMBER_H_
#define _NUMBER_H_
#include "../Enum/TextureName.h"
#include <string>
#include <gslib.h>

class Number
{
public:
	Number(const TextureName& name, float width, float height);

	/*
	  ‹ó”’‚ğ–„‚ß‚é”š•`‰æ
	  dight:•¶š”
	@fill :‹ó—“‚É–„‚ß‚é”š*/
	void Draw(const GSvector2& position, int num, int dight, char fill = '0')const;

	void Draw(const GSvector2& position, int num)const;

	void Draw(const GSvector2& position, const std::string& num)const;

private:
	TextureName m_Name;
	float m_Width;
	float m_Height;

};

#endif // !_NUMBER_H_
