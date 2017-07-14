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
	GSvector3 mTargetVelocity;   //�^�[�Q�b�g�����̈ړ���
	GSvector3 mTargetPosition;     //�^�[�Q�b�g�����̃x�N�g��

};

#endif // !_KREMLIN_DUSH_H_
