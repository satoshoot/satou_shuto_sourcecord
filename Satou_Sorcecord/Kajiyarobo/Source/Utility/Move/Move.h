#ifndef _MOVE_H_
#define _MOVE_H_
#include <gslib.h>

class Move
{
public:
	Move();
	void Update(float time);

	GSvector3 Velocity(GSvector3& left);

	float Speed();

	float InputVelocity();


private:
	GSvector3 mVelocity;
	float mSpeed;
	GSvector2 left_Stick;

};

#endif // !_INPUT_H_
