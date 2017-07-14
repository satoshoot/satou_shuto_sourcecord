#ifndef _PLAYER_SHOOT_H_
#define _PLAYER_SHOOT_H_

#include "../../../../AbstractPlayer/AbstractPlayer.h"

class Player_Shoot :public AbstractPlayer
{
public:
	Player_Shoot(
		IWorld* world,
		AttackID* id,
		Player* player,
		AnimationMesh* animation,
		Move* move,
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

#endif // !_PLAYER_SHOOT_H_
