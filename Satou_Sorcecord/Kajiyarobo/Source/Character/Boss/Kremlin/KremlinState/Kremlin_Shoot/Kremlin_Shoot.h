#ifndef _KREMLIN_SHOOT_H_
#define _KREMLIN_SHOOT_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_Shoot :public AbstractBoss
{
public:
	Kremlin_Shoot(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp, AttackID& id);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

};


#endif // !_KREMLIN_SHOOT_H_
