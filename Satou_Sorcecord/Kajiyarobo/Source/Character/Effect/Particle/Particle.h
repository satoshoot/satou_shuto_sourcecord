#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "../../../Base/Actor/Actor/Actor.h"

class Particle :public Actor
{
public:
	Particle(IWorld* world, GSvector3& position, GameManager* gameManager);

	virtual void OnUpdate(float deltaTime)override;

	virtual void OnDraw()const override;

private:
	GSvector3 mVelocity;
	float mGravity;
	float mCounter;

};

#endif // !_PARTICLE_H_
