#include "PlayerSpearAttack.h"
#include "../../../Utility/Enum/EffectName.h"
#include "../../../Utility/Enum/SoundName.h"
#include <GSeffect.h>

PlayerSpearAttack::PlayerSpearAttack(IWorld* world, GameManager* gameManaer, Actor* player,
	float front, float timer, float radius, int id, int& damage)
	: PlayerAttack(world, gameManaer, player, front, timer, radius, id, damage)
{
}

void PlayerSpearAttack::Effect(Actor & other, GSvector3& front)
{
	GSvector3 l_Position = m_Position + (front * 4) + GSvector3(0.0f, 3.0f, 0.0f);

	gsPlayEffect((GSuint)EffectName::SpearEffect, &l_Position);

	AddParticle(5, front);
	gsPlaySE((GSuint)SoundName::HitSE);
}
