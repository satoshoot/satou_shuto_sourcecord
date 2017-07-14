#ifndef _DOGENEMY_H_
#define _DOGENEMY_H_
#include "../../../Base/Actor/Actor/Actor.h"
#include "../../../Utility/AnimationMesh/AnimationMesh.h"
#include <list>


class AttackID;
enum DogAction
{
	DogDie,
	Hit,
	Wait,
	Run,
	Near,
	Attack,
	Leave
};

class DogEnemy :public Actor
{
public:

	DogEnemy(
		int hp,
		float angle,
		IWorld& world,
		std::string& name,
		GSvector3 position,
		GameManager& gameManager, 
		AttackID& id);

	virtual void OnUpdate(float time)override;

	virtual void OnDraw() const override;
	virtual void OnCollide(Actor& other)override;
	virtual void OnMessage(EventMessage message, void* param)override;

private:
	void DrawWepon()const;

private:
	DogAction mAction;
	int mStateCount;
	int hp;
	AnimationMesh mAnimation;
	bool mBornDraw;
	//çUåÇÇÃëΩèdÉqÉbÉgñhé~
	using IntList = std::list<int>;
	IntList mIDList;
	int m_ID;
	AttackID* mAttackID;
};

#endif // !_SHOTENEMY_H_
