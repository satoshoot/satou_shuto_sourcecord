#ifndef _ENEMY_BODY_ATTACK_H_
#define _ENEMY_BODY_ATTACK_H_
#include "../../../../Base/Actor/Actor/Actor.h"

class AnimationMesh;

class EnemyBodyAttack :public Actor
{
public:
	EnemyBodyAttack(IWorld* world, AnimationMesh* animation,
		int born, float front, float count, float radius,int& id, int& damage);

	virtual void OnUpdate(float deltaTime)override;

	virtual void OnDraw()const override;

	virtual void OnCollide(Actor& other)override;

private:
	AnimationMesh* pAnimation;

	float mCounter;
	int mBornID;

};


#endif // !_ENEMY_BODY_ATTACK_H_
