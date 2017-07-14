#ifndef _KREMLIN_LEFT_ROTATE_H_
#define _KREMLIN_LEFT_ROTATE_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_LeftRotate :public AbstractBoss
{
public:
	Kremlin_LeftRotate(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp);

	//èâä˙âª
	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

};

#endif // !_KREMLIN_LEFT_ROTATE_H_
