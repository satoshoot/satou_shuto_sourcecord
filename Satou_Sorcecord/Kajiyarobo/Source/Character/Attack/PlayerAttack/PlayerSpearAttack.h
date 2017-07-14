#ifndef _PLAYER_SPEAR_ATTACK_H_
#define _PLAYER_SPEAR_ATTACK_H_
#include "PlayerAttack.h"

class PlayerSpearAttack :public PlayerAttack
{
public:
	PlayerSpearAttack(IWorld* world, GameManager* gameManaer, Actor* player,
		float front, float timer, float radius, int id, int& damage);

private:
	virtual void Effect(Actor& other, GSvector3& front)override;

};


#endif // !_PLAYER_SPEAR_ATTACK_H_
