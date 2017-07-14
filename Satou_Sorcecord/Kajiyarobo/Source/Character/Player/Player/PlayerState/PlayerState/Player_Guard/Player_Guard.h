#ifndef _PLAYER_GUARD_H_
#define _PLAYER_GUARD_H_
#include "../../../../AbstractPlayer/AbstractPlayer.h"

class Player_Guard :public AbstractPlayer
{
public:
	Player_Guard(
		Player* player,
		AnimationMesh* animation,
		Menu* menu,
		PlayerHP* hp,
		GameManager* gameManager);

	virtual void OnInitialize()override;

	virtual void Update(float deltaTime)override;

	virtual void HoldDraw()const override;

	virtual void Collide(Actor& other)override;

	virtual void Shutdown()override;

};


#endif // !_PLAYER_GUARD_H_
