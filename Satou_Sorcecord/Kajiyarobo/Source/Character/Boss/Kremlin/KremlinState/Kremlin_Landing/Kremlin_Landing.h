#ifndef _KREMLIN_LANDING_H_
#define _KREMLIN_LANDING_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_Landing :public AbstractBoss
{
public:
	Kremlin_Landing(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

};


#endif // !_KREMLIN_LANDING_H_
