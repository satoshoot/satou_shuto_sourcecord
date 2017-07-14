#ifndef _FIRE_H_
#define _FIRE_H_

#include "../../../../Base/Actor/Actor/Actor.h"

class Fire : public Actor
{
public:
	Fire(IWorld* world, Actor* enemy, float front);

	Fire(IWorld* world, GSvector3& position);


private:
	virtual void OnUpdate(float deltaTime)override;
	virtual void OnDraw()const override;

private:
	//���Ń^�C�}�[
	float mTimer;
	//�ړ���
	GSvector3 mVelocity;

};

#endif // !_FIRE_H_
