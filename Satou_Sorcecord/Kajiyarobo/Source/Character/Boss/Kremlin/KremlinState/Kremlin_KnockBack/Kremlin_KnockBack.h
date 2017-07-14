#ifndef _KREMLIN_KNOCKBACK_H_
#define _KREMLIN_KNOCKBACK_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_KnockBack :public AbstractBoss
{
public:
	Kremlin_KnockBack(IWorld& world, AnimationMesh& animation, BossHP& hp);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

};


#endif // !_KREMLIN_KNOCKBACK_H_
