#include "PlayerSwordAttack.h"
#include "../../../Utility/Enum/EffectName.h"
#include "../../../Utility/Enum/SoundName.h"
#include <GSeffect.h>


PlayerSwordAttack::PlayerSwordAttack(IWorld* world, GameManager* gameManaer, Actor* player,
	float front, float timer, float radius, int id, int& damage)
	: PlayerAttack(world, gameManaer, player, front, timer, radius, id, damage)
{
}

void PlayerSwordAttack::Effect(Actor& other, GSvector3& front)
{
	GSvector3 l_Position = m_Position + (front * 4) + GSvector3(0.0f, 8.0f, 0.0f);
	//斬撃エフェクトを出す
	//m_World->AddActor(ActorGroup::Effect, new_Actor<Slash>(
	//	m_World, l_Position, p_GameManager));

	gsPlayEffect((GSuint)EffectName::Slash, &l_Position);

	AddParticle(10, front);
	gsPlaySE((GSuint)SoundName::HitSE);
}
