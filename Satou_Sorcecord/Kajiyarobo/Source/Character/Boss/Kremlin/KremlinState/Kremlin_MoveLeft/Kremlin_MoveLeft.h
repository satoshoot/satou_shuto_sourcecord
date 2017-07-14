#ifndef _KREMLIN_MOVE_LEFT_H_
#define _KREMLIN_MOVE_LEFT_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_MoveLeft :public AbstractBoss
{
public:
	Kremlin_MoveLeft(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

private:
	bool mEndRotate;

};



#endif // !_KREMLIN_MOVE_LEFT_H_
