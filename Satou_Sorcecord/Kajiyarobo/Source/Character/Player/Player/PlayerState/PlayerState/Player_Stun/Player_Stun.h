#ifndef _PLAYER_STUN_H_
#define _PLAYER_STUN_H_
#include "../../../../AbstractPlayer/AbstractPlayer.h"

class Player_Stun :public AbstractPlayer
{
public:
	Player_Stun(
		Player* player,
		AnimationMesh* animation,
		Menu* menu,
		Shield* shield,
		GameManager* gameManager);

	virtual void OnInitialize()override;

	virtual void Update(float deltaTime)override;

	virtual void HoldDraw()const override;

	virtual void Collide(Actor& other)override;

	virtual void Shutdown()override;

};


#endif // !_PLAYER_STUN_H_
