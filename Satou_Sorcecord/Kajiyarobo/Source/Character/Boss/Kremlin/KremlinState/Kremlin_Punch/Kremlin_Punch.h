#ifndef _KREMLIM_PUNCH_H_
#define _KREMLIN_PUNCH_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_Punch :public AbstractBoss
{
public:
	Kremlin_Punch(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp,AttackID& id);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

private:
	float mAngle;

};

#endif // !_KREMLIM_PUNCH_H_
