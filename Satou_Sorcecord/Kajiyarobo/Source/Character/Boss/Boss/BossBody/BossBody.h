#ifndef _BOSS_BODY_H_
#define _BOSS_BODY_H_

#include "../../../../Base/Actor/Actor/Actor.h"

class BossHP;
class AnimationMesh;
class BossHitID;
class AttackID;

class BossBody :public Actor
{
public:
	BossBody(IWorld* world, GameManager* gameManager, BossHP* hp,
		float& radius, AnimationMesh* animation, int& born, BossHitID* hitID, AttackID* id);

	virtual void OnUpdate(float deltaTime)override;

	virtual void OnDraw()const override;

	virtual void OnCollide(Actor& other)override;

	virtual void OnMessage(EventMessage message, void* param)override;


private:
	BossHP* pBossHP;
	AnimationMesh* pAnimation;
	int mBorn;
	BossHitID* pBossHitID;
	AttackID* pAttackID;

};

#endif // !_KREMLIN_BODY_H_


