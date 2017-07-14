#ifndef _SPEED_BULLET_EFFECT_H_
#define _SPEED_BULLET_EFFECT_H_

#include "../../../Base/Actor/Actor/Actor.h"

class SpeedBulletEffect :public Actor
{
public:
	SpeedBulletEffect(
		IWorld* world, const GSvector3 position, GameManager* gameManager, GSvector3& velocity,float count);

	virtual void OnUpdate(float deltaTime)override;

private:
	GSvector3 mVelocity;
	float mCounter;

};

#endif // !_SPEED_BULLET_EFFECT_H_
