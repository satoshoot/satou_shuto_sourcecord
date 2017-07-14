#ifndef _RAY_H_
#define _RAY_H_
#include <gslib.h>

class Ray
{
public:
	//デフォルトコンストラクタ
	Ray() = default;

	//11から コンストラクタ
	/*1,座標　2,方向*/
	Ray(const GSvector3& position, const GSvector3& direction)
		:mPosition{ position }, mDirection{ direction } {}

public:
	GSvector3 mPosition{ 0.0f,0.0f,0.0f };
	GSvector3 mDirection{ 0.0f,0.0f,0.0f };
};

#endif // !_RAY_H_
