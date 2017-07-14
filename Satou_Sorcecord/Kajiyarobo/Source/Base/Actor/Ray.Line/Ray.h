#ifndef _RAY_H_
#define _RAY_H_
#include <gslib.h>

class Ray
{
public:
	//�f�t�H���g�R���X�g���N�^
	Ray() = default;

	//11���� �R���X�g���N�^
	/*1,���W�@2,����*/
	Ray(const GSvector3& position, const GSvector3& direction)
		:mPosition{ position }, mDirection{ direction } {}

public:
	GSvector3 mPosition{ 0.0f,0.0f,0.0f };
	GSvector3 mDirection{ 0.0f,0.0f,0.0f };
};

#endif // !_RAY_H_
