#ifndef _KREMLIN_DEAD_H_
#define _KREMLIN_DEAD_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_Dead :public AbstractBoss
{
public:
	Kremlin_Dead(AnimationMesh& mesh, BossHP& hp);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

};

#endif // !_KREMLIN_DEAD_H_
