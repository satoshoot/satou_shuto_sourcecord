#ifndef _KREMLIN_DUSH_H_
#define _KREMLIN_DUSH_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_Dush :public AbstractBoss
{
public:
	Kremlin_Dush(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

private:
	GSvector3 mTargetVelocity;   //ターゲット方向の移動力
	GSvector3 mTargetPosition;     //ターゲット方向のベクトル

};

#endif // !_KREMLIN_DUSH_H_
