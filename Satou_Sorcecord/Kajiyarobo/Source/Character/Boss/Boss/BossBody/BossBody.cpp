#include "BossBody.h"
#include "../BossHP/BossHP.h"
#include "../../../../Base/Actor/EventMessage/EventMessage.h"
#include "../../../../Base/Actor/World/IWorld.h"
#include "../../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../Attack/PlayerAttack/PlayerAttack.h"
#include "BossHitID.h"
#include "../../../Attack/AttackID/AttackID.h"


BossBody::BossBody(IWorld* world, GameManager* gameManager, BossHP* hp,
	float& radius, AnimationMesh* animation, int& born, BossHitID* hitID, AttackID* id)
	: Actor(world, "BossBody", GSvector3(0.0f, 0.0f, 0.0f), BoundingSphere(radius), gameManager)
	, pBossHP(hp)
	, pAnimation(animation)
	, mBorn(born)
	, pBossHitID(hitID)
	, pAttackID(id)
{

}

void BossBody::OnUpdate(float deltaTime)
{
	const GSmatrix4& position = pAnimation->GetMatrices().at(mBorn);
	m_Position = position.getPosition();

}

void BossBody::OnDraw()const
{
	//GetBody().Draw();
}

void BossBody::OnCollide(Actor& other)
{
	if (other.GetName() == "PlayerAttack" && pBossHP->Dead() != true)
	{
		if (pBossHitID->HitStop(m_ID) == true)
			return;

		//•Ší‚ÌUŒ‚—Í‚¾‚¯HP‚ğŒ¸‚ç‚·
		PlayerAttack& lAttack = dynamic_cast<PlayerAttack&>(other);
		pBossHP->Damage(lAttack.Damage());
		pBossHitID->Add(m_ID);
		int lID = pAttackID->GetID();
		m_World->sendMessage(EventMessage::PlayerHitStopID, &lID);

	}
}

void BossBody::OnMessage(EventMessage message, void* param)
{
	switch (message)
	{
	case EventMessage::EnemyDamageID:
		int* id = (int*)param;

		m_ID = *id;
		break;

	}

}


