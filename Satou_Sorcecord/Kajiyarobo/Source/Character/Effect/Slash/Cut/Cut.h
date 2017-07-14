#ifndef _CUT_H_
#define _CUT_H_

#include "../../../../Base/Actor/Actor/Actor.h"

class Cut :public Actor
{
public:
	Cut(IWorld* world, GSvector3 position, GameManager* gameManager, float set);

private:
	virtual void OnUpdate(float deltaTime)override;
	virtual void OnDraw()const override;

private:
	float mTimer;
	GSvector3 mVelocity;

};


#endif // !_CUT_H_
