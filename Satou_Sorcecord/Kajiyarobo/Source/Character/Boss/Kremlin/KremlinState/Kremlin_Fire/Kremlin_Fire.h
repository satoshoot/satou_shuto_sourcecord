#ifndef _KREMLIN_FIRE_H_
#define _KREMLIN_FIRE_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_Fire :public AbstractBoss
{
public:
	Kremlin_Fire(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp, AttackID& id);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

private:
	float mAngle;

};


#endif // !_KREMLIN_FIRE_H_
