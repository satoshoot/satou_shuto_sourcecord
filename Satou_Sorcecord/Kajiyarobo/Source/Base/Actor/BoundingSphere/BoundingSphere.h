#ifndef _BOUNDING_SPHERE_H_
#define _BOUNDING_SPHERE_H_
#include <gslib.h>

//���̏Փ˔���N���X
class BoundingSphere
{
public:
	//�R���X�g���N�^
	BoundingSphere(const GSvector3& center, float radius);

	//�R���X�g���N�^
	//explicit:�Öق̕ϊ����ł��Ȃ��Ȃ�
	explicit BoundingSphere(float radius = 0.0f);

	//���s�ړ�
	BoundingSphere translate(const GSvector3& position)const;

	//���W�ϊ�
	BoundingSphere transform(const GSmatrix4& matrix)const;

	//�������Ă��邩
	bool intersects(const BoundingSphere& other)const;

	//�f�o�b�N�\��
	void Draw()const;

public:
	//���S���W
	GSvector3 mCenter;
	//���a
	float mRadius;
};

#endif // !_BOUNDING_SPHERE_H_
