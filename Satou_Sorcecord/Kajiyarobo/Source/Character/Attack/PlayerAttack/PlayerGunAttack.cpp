#include "PlayerGunAttack.h"
#include "../../../Utility/Enum/EffectName.h"
#include "../../../Utility/Enum/SoundName.h"
#include <GSeffect.h>

PlayerGunAttack::PlayerGunAttack(IWorld* world, GameManager* gameManaer,
	Actor* player, float front, float timer, float radius, int id, int& damage)
	: PlayerAttack(world, gameManaer, player, front, timer, radius, id, damage)
{
}

void PlayerGunAttack::Effect(Actor& other, GSvector3& front)
{
	gsPlayEffect((GSuint)EffectName::GunEffect, &m_Position);

	AddParticle(7, front);
}

int PlayerGunAttack::Damage() const
{
	return mDamage;
}
