#include "Math.h"
#include "../../Utility/Enum/MeshName.h"
#define _USE_MATH_DEFINES
#include <cmath>

const float Math::EPSILON = 0.0000001f;

/*�Q�_�Ԃ̋��������߂�*/
float Math::Distance(GSvector3 start, GSvector3 end)
{
	float distance;
	distance =
		(end.x - start.x) * (end.x - start.x)
		+ (end.y - start.y) * (end.y - start.y)
		+ (end.z - start.z) * (end.z - start.z);

	float result = Sqrt(distance);

	return result;
}

float Math::Distance(GSvector2 start, GSvector2 end)
{
	float distance;
	distance =
		(end.x - start.x) * (end.x - start.x)
		+ (end.y - start.x) * (end.y - start.y);

	float result = Sqrt(distance);

	return result;
}

GSvector3 Math::Cross(const GSvector3& left, const GSvector3& up)
{
	GSvector3& front = (left).cross(up);

	return front;
}
//��̃x�N�g���̓��ς����߂�
float Math::Vec2_Dot(GSvector2 first_vec2, GSvector2 second_vec2)
{
	float result;
	result = (first_vec2.x * second_vec2.x) + (first_vec2.y * second_vec2.y);
	return result;
}
//��̃x�N�g���̊p�x�����߂�(360�x)
float Math::ArcTangent(const float& x, const float& y)
{
	float result;

	result = atan2f(y, x);
	result *= 180 / M_PI;
	if (result < 0)
		result += 360;


	return result;
}

float Math::Angle(const GSvector2& first_vec2, const GSvector2& second_vec2)
{
	float result = 0;
	//��ڂ̃x�N�g���̒��������߂�
	float first_Length = (first_vec2.x * first_vec2.x) + (first_vec2.y * first_vec2.y);
	first_Length = Sqrt(first_Length);
	//��ڂ̃x�N�g���̒��������߂�	
	float second_Length = (second_vec2.x * second_vec2.x) + (second_vec2.y * second_vec2.y);
	second_Length = Sqrt(second_Length);
	//�p�x�����߂�
	result = Vec2_Dot(first_vec2, second_vec2) / (first_Length * second_Length);
	//result = result * 3.14159 / 180;
	result = acos(result);
	result = result * (180 / 3.14159);

	if (result <= EPSILON)
		result = 0;
	if (result >= 180 - EPSILON)
		result = 180;

	return result;
}

//�x�N�g�����E��]������]�������߂�
bool Math::TurnLeft(GSvector2 first, GSvector2 second)
{
	float cross(first.x * second.y - first.y * second.x);

	if (cross >= 0)
		return true;
	else if (cross < 0)
		return false;

	return false;
}

//�����v���Ƀx�N�g������]
GSvector2 Math::Vec2_Turn(GSvector2 vec2, float angle)
{
	GSvector2 result;
	//���W�A�������߂�
	float radian = angle * (3.14159 / 180);

	result.x = vec2.x * cos(radian) - vec2.y * sin(radian);
	result.y = vec2.x * sin(radian) - vec2.y * cos(radian);

	return result;
}

float Math::Sqrt(float square)
{
	float result;
	result = std::sqrt(square);
	return result;
}


