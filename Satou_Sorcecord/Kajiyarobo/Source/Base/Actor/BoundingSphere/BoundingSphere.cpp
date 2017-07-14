#include "BoundingSphere.h"

//�R���X�g���N�^
BoundingSphere::BoundingSphere(const GSvector3& center, float radius)
	: mCenter{ center }
	, mRadius{ radius }
{

}

//�R���X�g���N�^
BoundingSphere::BoundingSphere(float radius)
	:BoundingSphere({ 0.0f,0.0f,0.0f }, radius)
{

}

//�V�������̂̕��s�ړ�
BoundingSphere BoundingSphere::translate(const GSvector3& position)const
{
	return{ mCenter + position,mRadius };
}

//���W�ϊ�
BoundingSphere BoundingSphere::transform(const GSmatrix4& matrix)const
{
	return{ matrix.transform(mCenter),mRadius * matrix.getScale().y };
}

//�������Ă��邩�H
bool BoundingSphere::intersects(const BoundingSphere& other)const
{
	return gsCollisionSphereAndSphere(
		&mCenter, mRadius, &other.mCenter, other.mRadius) == GS_TRUE;
}
//�f�o�b�N�\���A����̕\��
void BoundingSphere::Draw()const
{
	glPushMatrix();
	glTranslatef(mCenter.x, mCenter.y, mCenter.z);
	glutWireSphere(mRadius, 16, 16);//( ���̔��a, ���̕�����, �c�̕�����)
	glPopMatrix();
}
