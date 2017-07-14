#include "Kremlin.h"
#include "../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../../Utility/Enum/MeshName.h"
#include "../../../Base/Actor/World/IWorld.h"
#include "../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../Boss/BossBody/BossBody.h"
#include "../Boss/BossBody/BossHitID.h"
#include "../Boss/BossStateName/BossStateName.h"
#include "../../../Base/Actor/Field/Field.h"




Kremlin::Kremlin(IWorld& world, GSvector3& position, GameManager& gameManager,
	BossHP& hp, AttackID& id)
	: Actor(&world, "Boss", position,
		BoundingSphere(GSvector3(0.0f, 30.0f, 0.0f), 30.0f), &gameManager)
	, mAnimation(new AnimationMesh(
		(GSuint)MeshName::Kremlin, (GSuint)MeshName::Kremlin, (GSuint)MeshName::Kremlin, 0))
	, mBossHitID(nullptr)
	, m_Manager()
{
	m_Rotate.rotateY(0.0f);

	m_Manager.Initialize(world, *this, *mAnimation, hp, id);

	mBossHitID = new BossHitID();

	m_World->AddActor(ActorGroup::Enemy, new_Actor<BossBody>(
		m_World, p_GameManager, &hp, 18.0f, mAnimation, 3, mBossHitID, &id));
	m_World->AddActor(ActorGroup::Enemy, new_Actor<BossBody>(
		m_World, p_GameManager, &hp, 8.0f, mAnimation, 15, mBossHitID, &id));
	m_World->AddActor(ActorGroup::Enemy, new_Actor<BossBody>(
		m_World, p_GameManager, &hp, 8.0f, mAnimation, 16, mBossHitID, &id));
	m_World->AddActor(ActorGroup::Enemy, new_Actor<BossBody>(
		m_World, p_GameManager, &hp, 8.0f, mAnimation, 17, mBossHitID, &id));
	m_World->AddActor(ActorGroup::Enemy, new_Actor<BossBody>(
		m_World, p_GameManager, &hp, 8.0f, mAnimation, 18, mBossHitID, &id));
	m_World->AddActor(ActorGroup::Enemy, new_Actor<BossBody>(
		m_World, p_GameManager, &hp, 4.0f, mAnimation, 19, mBossHitID, &id));

}

Kremlin::~Kremlin()
{
	delete mAnimation;
}

void Kremlin::OnUpdate(float deltaTime)
{
	m_Manager.Update(deltaTime);

	m_Manager.ChangeState();


	mBossHitID->DeletePop();
	m_Manager.Move(m_Position);
	m_Manager.RotateY(m_Rotate);

	HitField();

	mAnimation->Update(deltaTime);
	mAnimation->Calculate(GetPose());
	m_Manager.Change();
}

void Kremlin::OnDraw()const
{
	mAnimation->Draw();

	//GetBody().Draw();
}

void Kremlin::OnCollide(Actor& other)
{

}

void Kremlin::HitField()
{
	GSvector3 wallIntersect;
	if (m_World->GetField()->Collision(GetBody(), &wallIntersect))
	{
		m_Position.x = wallIntersect.x;
		m_Position.z = wallIntersect.z;
	}
}