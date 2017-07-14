#ifndef _KREMLIN_RIGHT_ROTATE_H_
#define _KREMLIN_RIGHT_ROTATE_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_RightRotate :public AbstractBoss
{
public:
	Kremlin_RightRotate(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;


};

#endif // ! 
