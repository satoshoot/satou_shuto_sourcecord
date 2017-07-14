#ifndef _PLAYER_ATTACK_H_
#define _PLAYER_ATTACK_H_
#include "../../../Base/Actor/Actor/Actor.h"
#include <list>

class IWorld;
enum class WeponType;

class PlayerAttack :public Actor
{
public:
	PlayerAttack(IWorld* world, GameManager* gameManaer, Actor* player,
		float front, float timer, float radius, int id, int& damage);

	virtual void OnUpdate(float time)override;
	virtual void OnDraw()const override;
	virtual void OnCollide(Actor& other)override;
	virtual void OnMessage(EventMessage message, void* param)override;

	virtual int Damage()const;

protected:
	virtual void Effect(Actor& other, GSvector3& front) = 0;
	virtual void AddParticle(int num, GSvector3& front);

private:
	int mCounter;
	Actor* pPlayer;
	float mFront;

	using IntList = std::list<int>;
	IntList mIDList;
	int m_ID;

protected:
	int mDamage;

};

#endif // !_PLAYER_ATTACK_H_
