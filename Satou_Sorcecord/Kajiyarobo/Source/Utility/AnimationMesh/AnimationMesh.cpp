#include "AnimationMesh.h"

AnimationMesh::AnimationMesh(GSuint mesh, GSuint skeleton, GSuint animation, GSuint motion = 0)
	: mMesh(mesh)
	, mSkeleton(skeleton)
	, mAnimation(animation, motion)
{

}

void AnimationMesh::Update(float deltaTime)
{
	//���[�V�����N���X���X�V
	mAnimation.Update(deltaTime);
}

void AnimationMesh::Draw()const
{
	//�X�P���g�������v�Z
	gsDisable(GS_CALC_SKELETON);
	//�{�[���̓��������b�V���̒��_�ɍ��킹��@�\��L���ɂ���
	gsEnable(GS_SKIN_MESH);
	//�{�[�������т���
	gsBindSkeleton(mSkeleton);
	//�ϊ��s���mMatrices�ɓǂݍ���
	gsSetMatrixSkeleton(mMatrices.data());
	//�`��
	gsDrawMesh(mMesh);
}

void AnimationMesh::ChangeMotion(GSuint motion)
{
	mAnimation.ChangeMotion(motion);
}
//�X�P���g���̕ϊ��s����v�Z
void AnimationMesh::Calculate(const GSmatrix4& world)
{
	gsBindSkeleton(mSkeleton);
	gsCalculateSkeleton(
		&world, //��]�ϊ��s��
		mAnimation.GetMatrices().data(),//�A�j���[�V�����ϊ��s��z��
		mMatrices.data() //�p���ϊ��s��z��
		);
}

GSuint AnimationMesh::GetMotionEndTime()const
{
	return mAnimation.GetEndTime();
}

const AnimationMesh::Matrices& AnimationMesh::GetMatrices()const
{
	return mMatrices;
}