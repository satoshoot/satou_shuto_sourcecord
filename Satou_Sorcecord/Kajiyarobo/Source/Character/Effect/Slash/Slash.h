#ifndef _SLASH_H_
#define _SLASH_H_

#include "../../../Base/Actor/Actor/Actor.h"

class Slash : public Actor
{
public:
	Slash(IWorld* world, GSvector3 position, GameManager* gameManager);

private:
	virtual void OnUpdate(float deltaTime)override;
};

#endif // !_SLASH_H_
