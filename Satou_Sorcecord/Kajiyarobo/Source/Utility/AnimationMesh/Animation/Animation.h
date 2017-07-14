#ifndef _ANIMATION_H_
#define _ANIMATION_H

#include <array>
#include <gslib.h>

class Animation
{
public:
	using Matrices = std::array<GSmatrix4, 256>;

public:
	Animation(GSuint animation, GSuint motion);

	void Update(float time);

	//���[�V�����̕ύX
	void ChangeMotion(GSuint motion);
	//�Đ����̃��[�V����
	GSuint GetMotion()const;
	//�{�[���̐�
	GSuint GetBornCount()const;
	//�I������
	GSuint GetEndTime()const;
	//�ϊ��s���Ԃ�
	const Animation::Matrices& GetMatrices()const;

private:
	//��ԃt���[����
	const GSfloat LERP_TIME = 10.0f;
	//�A�j���[�V�����ԍ�
	GSuint mAnimationID;
	//�Đ����̃��[�V�����ԍ�
	GSuint mMotion;
	//�Đ����̃��[�V�����^�C�}�[
	GSfloat mMotionTimer;
	//�O��Đ��������[�V�����ԍ�
	GSuint mPrevMotion;
	//�O��Đ������ŏI���[�V�����^�C�}�[
	GSfloat mPrevMotionTimer;
	//��ԃA�j���[�V�����^�C�}�[
	GSfloat lerpTimer;
	//�A�j���[�V�����ϊ��s��
	Matrices mMatrices;
};

#endif // !_ANIMATION_H_
