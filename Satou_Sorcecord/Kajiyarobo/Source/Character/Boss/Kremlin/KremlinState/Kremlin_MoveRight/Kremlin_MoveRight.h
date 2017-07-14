#ifndef _KREMLIN_MOVE_RIGHT_H_
#define _KREMLIN_MOVE_RIGHT_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_MoveRight :public AbstractBoss
{
public:
	Kremlin_MoveRight(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

private:
	bool mEndRotate;

};



#endif // !_KREMLIN_MOVE_RIGHT_H_
