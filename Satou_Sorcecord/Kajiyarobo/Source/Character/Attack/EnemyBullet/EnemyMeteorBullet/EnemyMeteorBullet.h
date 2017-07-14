#ifndef _ENEMY_METEOR_BULLET_H_
#define _ENEMY_METEOR_BULLET_H_
#include "../../../../Base/Actor/Actor/Actor.h"

class EnemyMeteorBullet :public Actor
{
public:
	EnemyMeteorBullet(IWorld* world, GSvector3& position,
		float count, float radius,int& id, int& damage);

	virtual void OnUpdate(float deltaTime)override;

	virtual void OnDraw()const override;

	virtual void OnCollide(Actor& other)override;

private:
	bool mHitGround;
	float mCounter;
	float mRadius;
	int mDamage;
	int m_ID;

};


#endif // !_ENEMY_METEOR_BULLET_H_
