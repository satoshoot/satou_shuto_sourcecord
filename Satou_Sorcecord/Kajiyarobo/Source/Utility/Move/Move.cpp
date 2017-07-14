#include "Move.h"
#include "../Enum/MeshName.h"
#include "../Math/Math.h"
#include "../../Base/Actor/World/IWorld.h"

Move::Move()
	: mVelocity(0.0f, 0.0f, 0.0f)
	, mSpeed(0.0f)
	, left_Stick(0.0f, 0.0f)
{

}

void Move::Update(float time)
{
	gsXBoxPadGetLeftAxis(0, &left_Stick);
	if (InputVelocity() == 0.0f)
	{
		//�p�b�h�̍��X�e�B�b�N�����͂���Ă��Ȃ��Ƃ��X�s�[�h��������
		mSpeed -= 0.04f;
		if (mSpeed <= 0.0f)
		{
			mSpeed = 0;
		}
	}
	else if (mSpeed >= InputVelocity())
	{
		mSpeed = InputVelocity();
	}
	else
	{
		mSpeed += 0.05f;
	}
}

//�ړ���
GSvector3 Move::Velocity(GSvector3& left)
{
	const GSvector3& up = GSvector3(0.0f, 1.0f, 0.0f);
	GSvector3 &front = Math::Cross(left, up);

	GSvector3 frontVelocity = left_Stick.y * front;
	GSvector3 leftVelocity = -left_Stick.x * left;

	mVelocity = frontVelocity + leftVelocity;

	mVelocity.normalize();


	return mVelocity;
}

//����L�����̑��x
float Move::Speed()
{
	return mSpeed;
}
//�W���C�X�e�B�b�N�̌X���̑傫��
float Move::InputVelocity()
{
	float result;
	result = Math::Distance(GSvector2(0.0f, 0.0f), left_Stick);

	return result;
}

