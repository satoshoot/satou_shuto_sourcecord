#ifndef _LASER_H_
#define _LASER_H_

#include "../../../../Base/Actor/Actor/Actor.h"

class Laser :public Actor
{
public:
	Laser(
		IWorld* world, const GSvector3 position, GameManager* gameManager,
		GSvector3& velocity,float speed, float count);

	virtual void OnUpdate(float deltaTime)override;

	virtual void OnDraw()const override;

	virtual void OnCollide(Actor& other)override;

private:
	float mCounter;
	GSvector3 mVelocity;
	float mSpeed;

};

#endif // !_LASER_H_
