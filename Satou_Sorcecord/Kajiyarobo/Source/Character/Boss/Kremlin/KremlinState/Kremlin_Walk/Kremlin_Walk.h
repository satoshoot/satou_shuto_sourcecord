#ifndef _KREMLIN_WALK_H_
#define _KREMLIN_WALK_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_Walk :public AbstractBoss
{
public:
	Kremlin_Walk(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

};


#endif // !_KREMLIN_WALK_H_
