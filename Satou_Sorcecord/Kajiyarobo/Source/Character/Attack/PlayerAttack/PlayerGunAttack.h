#ifndef _PLAYER_GUN_ATTACK_H_
#define _PLAYER_GUN_ATTACK_H_
#include "PlayerAttack.h"

class PlayerGunAttack :public PlayerAttack
{
public:
	PlayerGunAttack(IWorld* world, GameManager* gameManaer, Actor* player,
		float front, float timer, float radius, int id, int& damage);

private:
	virtual void Effect(Actor& other, GSvector3& front)override;

	virtual int Damage()const override;
};


#endif // !_PLAYER_GUN_ATTACK_H_
