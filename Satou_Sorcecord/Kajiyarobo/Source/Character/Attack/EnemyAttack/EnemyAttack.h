#ifndef _ENEMY_ATTACK_H_
#define _ENEMY_ATTACK_H_
#include "../../../Base/Actor/Actor/Actor.h"
#include <list>

class EnemyAttack :public Actor
{
public:
	EnemyAttack(IWorld* world, Actor* enemy,
		float front, float count, float radius, int& id, int& damage);

	virtual void OnUpdate(float deltaTime)override;

	virtual void OnDraw()const override;

	virtual void OnCollide(Actor& other)override;

	virtual void OnMessage(EventMessage message, void* param)override;

	int Damage()const;

	int GetID()const;

private:
	Actor* pEnemy;

	float mFront;
	float mCounter;

	using IDList = std::list<int>;
	IDList mIDList;
	int m_ID;
	int mDamageID;
	int mDamage;

};

#endif // !_ENEMY_ATTACK_H_
