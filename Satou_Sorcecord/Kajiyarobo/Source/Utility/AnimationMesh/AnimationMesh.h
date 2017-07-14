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
	//メッシュ
	GSuint mMesh;
	//スケルトン
	GSuint mSkeleton;
	//アニメーション
	Animation mAnimation;
	//スケルトン変換行列
	Matrices mMatrices;
};

#endif // !_ANIMATION_MESH_H_
