#include "AnimationMesh.h"

AnimationMesh::AnimationMesh(GSuint mesh, GSuint skeleton, GSuint animation, GSuint motion = 0)
	: mMesh(mesh)
	, mSkeleton(skeleton)
	, mAnimation(animation, motion)
{

}

void AnimationMesh::Update(float deltaTime)
{
	//モーションクラスを更新
	mAnimation.Update(deltaTime);
}

void AnimationMesh::Draw()const
{
	//スケルトン自動計算
	gsDisable(GS_CALC_SKELETON);
	//ボーンの動きをメッシュの頂点に合わせる機能を有効にする
	gsEnable(GS_SKIN_MESH);
	//ボーンを結びつける
	gsBindSkeleton(mSkeleton);
	//変換行列をmMatricesに読み込む
	gsSetMatrixSkeleton(mMatrices.data());
	//描画
	gsDrawMesh(mMesh);
}

void AnimationMesh::ChangeMotion(GSuint motion)
{
	mAnimation.ChangeMotion(motion);
}
//スケルトンの変換行列を計算
void AnimationMesh::Calculate(const GSmatrix4& world)
{
	gsBindSkeleton(mSkeleton);
	gsCalculateSkeleton(
		&world, //回転変換行列
		mAnimation.GetMatrices().data(),//アニメーション変換行列配列
		mMatrices.data() //姿勢変換行列配列
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