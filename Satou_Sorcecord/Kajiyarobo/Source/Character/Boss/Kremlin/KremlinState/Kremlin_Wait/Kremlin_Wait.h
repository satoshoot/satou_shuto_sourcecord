#ifndef _KREMLIN_WAIT_H_
#define _KREMLIN_WAIT_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_Wait :public AbstractBoss
{
public:
	Kremlin_Wait(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

};

#endif // !_KREMLIN_WAIT_H_
