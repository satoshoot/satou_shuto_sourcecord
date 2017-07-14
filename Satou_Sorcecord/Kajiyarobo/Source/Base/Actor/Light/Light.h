#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "../Actor/Actor.h"

class Light :public Actor
{
public:
	Light(IWorld* world, const GSvector3 position, GameManager* gameManager);

private:
	virtual void OnDraw()const override;
};

#endif // !_LIGHT_H_
