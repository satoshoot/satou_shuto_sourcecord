#ifndef _KREMLIN_IDOL_H_
#define _KREMLIN_IDOL_H_

#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_Idle :public AbstractBoss
{
public:
	Kremlin_Idle(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

private:
	void IdleNextState();

private:
	int m_PrevHP;

};


#endif // !_KREMLIN_IDOL_H_
