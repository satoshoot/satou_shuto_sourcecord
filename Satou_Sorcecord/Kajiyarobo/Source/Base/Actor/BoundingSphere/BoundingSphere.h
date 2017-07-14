#ifndef _BOUNDING_SPHERE_H_
#define _BOUNDING_SPHERE_H_
#include <gslib.h>

//球の衝突判定クラス
class BoundingSphere
{
public:
	//コンストラクタ
	BoundingSphere(const GSvector3& center, float radius);

	//コンストラクタ
	//explicit:暗黙の変換ができなくなる
	explicit BoundingSphere(float radius = 0.0f);

	//平行移動
	BoundingSphere translate(const GSvector3& position)const;

	//座標変換
	BoundingSphere transform(const GSmatrix4& matrix)const;

	//交差しているか
	bool intersects(const BoundingSphere& other)const;

	//デバック表示
	void Draw()const;

public:
	//中心座標
	GSvector3 mCenter;
	//半径
	float mRadius;
};

#endif // !_BOUNDING_SPHERE_H_
