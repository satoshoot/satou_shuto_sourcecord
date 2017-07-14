#ifndef _PLAYER_SPEAR_DUSH_ATTACK_H_
#define _PLAYER_SPEAR_DUSH_ATTACK_H_

#include "../../../../AbstractPlayer/AbstractPlayer.h"

class Player_SpearDushAttack :public AbstractPlayer
{
public:
	Player_SpearDushAttack(
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

private:
	float mGravity;


};

#endif // !_PLAYER_SPEAR_DUSH_ATTACK_H_