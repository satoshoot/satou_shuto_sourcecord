#ifndef _PLAYER_SWORD_ATTACK_H_
#define _PLAYER_SWORD_ATTACK_H_
#include "PlayerAttack.h"

class PlayerSwordAttack :public PlayerAttack
{
public:
	PlayerSwordAttack(IWorld* world, GameManager* gameManaer, Actor* player,
		float front, float timer, float radius, int id, int& damage);

private:
	virtual void Effect(Actor& other, GSvector3& front)override;

};


#endif // !_PLAYER_SWORD_ATTACK_H_
