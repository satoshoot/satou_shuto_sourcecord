#ifndef _KREMLIN_ROAR_H_
#define _KREMLIN_ROAR_H_

#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_Roar :public AbstractBoss
{
public:
	Kremlin_Roar(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

};

#endif // !_KREMLIN_ROAR_H_
