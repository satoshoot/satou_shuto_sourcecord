#include "BoundingSphere.h"

//コンストラクタ
BoundingSphere::BoundingSphere(const GSvector3& center, float radius)
	: mCenter{ center }
	, mRadius{ radius }
{

}

//コンストラクタ
BoundingSphere::BoundingSphere(float radius)
	:BoundingSphere({ 0.0f,0.0f,0.0f }, radius)
{

}

//新しい球体の平行移動
BoundingSphere BoundingSphere::translate(const GSvector3& position)const
{
	return{ mCenter + position,mRadius };
}

//座標変換
BoundingSphere BoundingSphere::transform(const GSmatrix4& matrix)const
{
	return{ matrix.transform(mCenter),mRadius * matrix.getScale().y };
}

//交差しているか？
bool BoundingSphere::intersects(const BoundingSphere& other)const
{
	return gsCollisionSphereAndSphere(
		&mCenter, mRadius, &other.mCenter, other.mRadius) == GS_TRUE;
}
//デバック表示、判定の表示
void BoundingSphere::Draw()const
{
	glPushMatrix();
	glTranslatef(mCenter.x, mCenter.y, mCenter.z);
	glutWireSphere(mRadius, 16, 16);//( 球の半径, 横の分割数, 縦の分割数)
	glPopMatrix();
}
