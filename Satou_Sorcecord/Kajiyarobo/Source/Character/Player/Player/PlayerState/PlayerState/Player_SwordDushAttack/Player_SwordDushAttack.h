#ifndef _PLAYER_SWORD_DUSHATTACK_H_
#define _PLAYER_SWORD_DUSHATTACK_H_

#include "../../../../AbstractPlayer/AbstractPlayer.h"

class Player_SwordDushAttack :public AbstractPlayer
{
public:
	Player_SwordDushAttack(
		IWorld* world,
		AttackID* id,
		Player* player,
		AnimationMesh* animation,
		PlayerHP* hp,
		Shield* shield,
		GameManager* gameManager);

	virtual void OnInitialize()override;

	virtual void Update(float deltaTime)override;

	virtual void HoldDraw()const override;

	virtual void Collide(Actor& other)override;

	virtual void Shutdown()override;


};

#endif // !_PLAYER_SWORD_DUSHATTACK_H_