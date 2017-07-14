#include "Animation.h"

Animation::Animation(GSuint animation, GSuint motion)
	: mAnimationID(animation)
	, mMotion(motion)
	, mMotionTimer(0.0f)
	, mPrevMotion(motion)
	, mPrevMotionTimer(0.0f)
	, lerpTimer(0.0f)
{
	Update(0.0f);
}

void Animation::Update(float time)
{
	mMotionTimer += time;
	//lerpTimer + time �� LERP_TIME�̏������ق���Ԃ�
	lerpTimer = std::min(lerpTimer + time, LERP_TIME);
	//���̃A�j���[�V�����ƑO�̃A�j���[�V��������������
	gsCalculateAnimationLerp(
		mAnimationID, mPrevMotion, mPrevMotionTimer,
		mAnimationID, mMotion, mMotionTimer,
		lerpTimer / LERP_TIME,
		mMatrices.data()
		);

}

void Animation::ChangeMotion(GSuint motion)
{
	//�������[�V�����̎��͉������Ȃ�
	if (motion == mMotion)
		return;
	//���̃��[�V�������R�s�[
	mPrevMotion = mMotion;
	mPrevMotionTimer = mMotionTimer;
	//�V�������[�V����������
	mMotion = motion;
	mMotionTimer = 0.0f;
	lerpTimer = 0.0f;
}

GSuint Animation::GetMotion()const
{
	return mMotion;
}

GSuint Animation::GetBornCount()const
{
	return gsGetAnimationNumBones(mAnimationID, mMotion);
}

GSuint Animation::GetEndTime()const
{
	return gsGetEndAnimationTime(mAnimationID, mMotion);
}

const Animation::Matrices& Animation::GetMatrices()const
{
	return mMatrices;
}