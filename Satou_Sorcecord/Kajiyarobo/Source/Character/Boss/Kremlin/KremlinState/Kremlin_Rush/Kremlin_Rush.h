#ifndef _KREMLIN_RUSH_H_
#define _KREMLIN_RUSH_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_Rush :public AbstractBoss
{
public:
	Kremlin_Rush(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp,AttackID& id);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

};


#endif // !_KREMLIN_RUSH_H_
