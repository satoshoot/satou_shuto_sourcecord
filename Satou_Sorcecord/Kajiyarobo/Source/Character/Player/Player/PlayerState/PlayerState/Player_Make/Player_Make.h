#ifndef _PLAYER_MAKE_H_
#define _PLAYER_MAKE_H_
#include "../../../../AbstractPlayer/AbstractPlayer.h"

class Player_Make :public AbstractPlayer
{
public:
	Player_Make(
		IWorld* world,
		Player* player,
		AnimationMesh* animation,
		Menu* menu,
		PlayerHP* hp,
		Shield* shield,
		GameManager* gameManager);

	virtual void OnInitialize()override;

	virtual void Update(float deltaTime)override;

	virtual void HoldDraw()const override;

	virtual void Collide(Actor& other)override;

	virtual void Shutdown()override;

};

#endif // !_PLAYER_MAKE_H_