#ifndef _MATH_H_
#define _MATH_H_
#include <gslib.h>

class Math
{
public:
	//static

	static float Distance(GSvector3 start, GSvector3 end);

	static float Distance(GSvector2 start, GSvector2 end);

	static GSvector3 Cross(const GSvector3& left, const GSvector3& up);

	static float Vec2_Dot(GSvector2 first_vec2, GSvector2 second_vec2);

	static float ArcTangent(const float& x, const float& y);

	static float Angle(const GSvector2& first_vec2, const GSvector2& second_vec2);

	static bool TurnLeft(GSvector2 first, GSvector2 second);

	static GSvector2 Vec2_Turn(GSvector2 vec2, float angle);


	static float Sqrt(float square);
	//static float EPSILON();

	static const float EPSILON;


};

#endif // !_ENEMYSUPPORT_H_
