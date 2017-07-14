#ifndef _ANIMATION_MESH_H_
#define _ANIMATION_MESH_H_

#include "Animation/Animation.h"
class AnimationMesh
{
public:
	using Matrices = std::array<GSmatrix4, 256>;

public:
	AnimationMesh(GSuint mesh, GSuint skeleton, GSuint animation, GSuint motion);
	
	void Update(float deltaTime);

	void Draw()const;

	void ChangeMotion(GSuint motion);

	void Calculate(const GSmatrix4& world);

	GSuint GetMotionEndTime()const;

	const Animation::Matrices& GetMatrices()const;

private:
	//���b�V��
	GSuint mMesh;
	//�X�P���g��
	GSuint mSkeleton;
	//�A�j���[�V����
	Animation mAnimation;
	//�X�P���g���ϊ��s��
	Matrices mMatrices;
};

#endif // !_ANIMATION_MESH_H_
