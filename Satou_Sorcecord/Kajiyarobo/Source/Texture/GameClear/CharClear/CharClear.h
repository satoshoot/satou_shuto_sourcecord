#ifndef _CHAR_CLEAR_H_
#define _CHAR_CLEAR_H_
#include <gslib.h>

class CharClear
{
public:
	CharClear();

	void Update(float deltaTime, float& count);

	void Draw()const;

private:
	GSvector2 mSize;
	GSvector2 mPosition;
	float mAlpha;
	float mAlphaPlus;
};

#endif // !_CHAR_CLEAR_H_
