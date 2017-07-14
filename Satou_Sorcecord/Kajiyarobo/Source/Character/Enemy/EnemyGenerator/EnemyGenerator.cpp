#include "EnemyGenerator.h"
#include "../EnemyDog/DogEnemy.h"
#include "../../../Base/Actor/World/IWorld.h"
#include "../../../Base/Actor/Actor/ActorManager/ActorGroup.h"

EnemyGenerator::EnemyGenerator(IWorld & world, GameManager & gameManager, AttackID & id) :
	Actor(&world, "EnemyGenerator", GSvector3(-260.0f, 0.0f, 250.0f),
		BoundingSphere(0.0f), &gameManager),
	m_Timer(0),
	p_ID(&id)
{
	m_List.clear();
	AddEnemy();
}

void EnemyGenerator::OnUpdate(float deltaTime)
{
	RemoveEnemy();

	if (m_List.size() <= 0)
	{
		if (m_Timer >= 60 * 90)
		{
			AddEnemy();
			m_Timer = 0;
		}
		m_Timer += deltaTime;
	}
}

void EnemyGenerator::AddEnemy()
{
	ActorPtr l_FirstEnemy = new_Actor<DogEnemy>(1500, 180.0f, *m_World, (std::string)"FirstEnemy",
		m_Position + GSvector3(0.0f, 0.0f, 20.0f), *p_GameManager, *p_ID);
	ActorPtr l_SecondEnemy = new_Actor<DogEnemy>(1500, -30.0f, *m_World, (std::string)"SecondEnemy",
		m_Position + GSvector3(20.0f, 0.0f, -10.0f), *p_GameManager, *p_ID);
	ActorPtr l_ThirdEnemy = new_Actor<DogEnemy>(1500, 30.0f, *m_World, (std::string)"ThirdEnemy",
		m_Position + GSvector3(-20.0f, 0.0f, -10.0f), *p_GameManager, *p_ID);

	m_World->AddActor(ActorGroup::Enemy, l_FirstEnemy);
	m_World->AddActor(ActorGroup::Enemy, l_SecondEnemy);
	m_World->AddActor(ActorGroup::Enemy, l_ThirdEnemy);

	m_List.push_back(l_FirstEnemy);
	m_List.push_back(l_SecondEnemy);
	m_List.push_back(l_ThirdEnemy);

}

void EnemyGenerator::RemoveEnemy()
{
	for (EnemyList::iterator i = m_List.begin(); i != m_List.end(); i++)
	{
		if ((*i)->IsDead() || *i == nullptr)
			m_List.remove(*i);
	}
}
