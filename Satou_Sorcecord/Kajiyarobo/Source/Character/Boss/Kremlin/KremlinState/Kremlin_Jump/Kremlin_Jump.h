#ifndef _KREMLIN_JUMP_H_
#define _KREMLIN_JUMP_H_
#include "../../../Boss/AbstractBoss/AbstractBoss.h"

class Kremlin_Jump :public AbstractBoss
{
public:
	Kremlin_Jump(IWorld& world, Actor& boss, AnimationMesh& animation, BossHP& hp);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual void Shutdown()override;

private:
	GSvector3 mTargetPosition; //�^�[�Q�b�g�̈ʒu
	GSvector3 mTargetVelocity; //�^�[�Q�b�g�����̃x�N�g��

};


#endif // !_KREMLIN_JUMP_H_
