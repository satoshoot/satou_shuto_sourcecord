#ifndef _Explosion_H_
#define _Explosion_H_

#include "../../../Base/Actor/Actor/Actor.h"

class Explosion :public Actor
{
public:
	Explosion(IWorld* world, Actor* enemy, float front);

	Explosion(IWorld* world, GSvector3& position);

};

#endif // !_Explotion_H_
