#ifndef _KREMLIN_DOWN_H_
#define _KREMLIN_DOWN_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_Down :public AbstractBoss
{
public:
	Kremlin_Down(IWorld& world, AnimationMesh& animation, BossHP& hp);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

private:
	bool mDownState;

};

#endif // !_KREMLIN_DOWN_H_
