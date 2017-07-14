#ifndef _BACK_GROUND_H_
#define _BACK_GROUND_H_
#include <gslib.h>

class BackGround
{
public:
	BackGround();


	void StartUpdate(float& count);

	void EndUpdate(float& count);

	void BackDraw()const;

	void FrameDraw()const;

private:
	GSvector2 mSize;
	float mAlpha;
	float mAlphaPlus;
};

#endif // !_BACK_GROUND_H_
