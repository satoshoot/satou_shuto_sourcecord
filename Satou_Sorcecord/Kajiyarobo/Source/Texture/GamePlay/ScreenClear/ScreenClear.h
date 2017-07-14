#ifndef _SCREEN_CLEAR_H_
#define _SCREEN_CLEAR_H_
#include "../../../Base/Actor/Actor/Actor.h"

class ScreenClear :public Actor
{
public:
	ScreenClear();

private:
	virtual void OnUpdate(float deltaTime)override;
	virtual void OnDraw()const override;

private:
	float m_Alpha;
};


#endif // !_SCREEN_CLEAR_H_
