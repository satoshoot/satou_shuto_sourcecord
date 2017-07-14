#ifndef _SPEED_BULLET_H_
#define _SPEED_BULLET_H_

#include "../../../../Base/Actor/Actor/Actor.h"

class Player;

class SpeedBullet :public Actor
{
public:
	SpeedBullet(IWorld* world, GSvector3 position, GameManager* gameManager, 
		Actor* player,const float& range, int id, int& damage);

	virtual void OnUpdate(float deltaTime)override;

	virtual void OnDraw()const override;

	virtual void OnCollide(Actor& other)override;

private:
	void HitField();

private:
	GSvector3 mVelocity;
	float mCounter;
	ActorPtr mPlayerAttack;


};

#endif // !_SPEED_BULLET_H_
