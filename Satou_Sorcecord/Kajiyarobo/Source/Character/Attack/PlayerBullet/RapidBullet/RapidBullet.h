#ifndef _RAPID_BULLET_H_
#define _RAPID_BULLET_H_

#include "../../../../Base/Actor/Actor/Actor.h"

enum class WeponSpecialSkill;


class RapidBullet :public Actor
{
public:
	RapidBullet(IWorld* world, GSvector3& position, GameManager* GameManager,
		Actor* player, int& id, float& mCounter,
		const WeponSpecialSkill& skill, float& pitchSwing, float& yawSwing, int& damage);

	virtual void OnUpdate(float deltaTime)override;

	virtual void OnDraw()const override;

	virtual void OnCollide(Actor& other)override;

private:
	void SetFront();

	void HitField();

private:
	float mCounter;
	GSvector3 mVelocity;
	ActorPtr mPlayerAttack;
	WeponSpecialSkill mSkill;


};

#endif // !_RAPID_BULLET_H_
