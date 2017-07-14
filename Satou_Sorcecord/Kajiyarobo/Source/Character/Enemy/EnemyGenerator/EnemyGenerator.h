#ifndef _ENEMY_GENERATOR_H_
#define _ENEMY_GENERATOR_H_
#include "../../../Base/Actor/Actor/Actor.h"
#include <list>

class AttackID;


class EnemyGenerator :public Actor
{
public:
	EnemyGenerator(IWorld& world, GameManager& gameManager, AttackID& id);

	virtual void OnUpdate(float deltaTime)override;

private:
	void AddEnemy();
	void RemoveEnemy();

private:
	float m_Timer;
	AttackID* p_ID;

	using EnemyList = std::list<ActorPtr>;
	EnemyList m_List;


};


#endif // !_ENEMY_GENERATOR_H_
