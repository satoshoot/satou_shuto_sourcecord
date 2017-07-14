#ifndef _KREMLIN_LOOK_H_
#define _KREMLIN_LOOK_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_Look :public AbstractBoss
{
public:
	Kremlin_Look(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

private:
	float mAngle;

};

#endif // !_KREMLIN_LOOK_H_
