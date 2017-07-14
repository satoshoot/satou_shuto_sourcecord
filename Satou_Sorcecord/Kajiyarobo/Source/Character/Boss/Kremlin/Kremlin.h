#ifndef _KREMKIN_H_
#define _KREMLIN_H_
#include <unordered_map>
#include "../../../Base/Actor/Actor/Actor.h"
#include "KremlinStateManager/KremlinStateManager.h"

class AnimationMesh;
enum class BossStateName;
enum class BossTarget;
class BossHP;
class BossHitID;
class AttackID;

class Kremlin :public Actor
{
public:
	Kremlin(IWorld& world, GSvector3& position, GameManager& gameManager, BossHP& hp, AttackID& id);
	~Kremlin();

	virtual void OnUpdate(float deltaTime)override;
	virtual void OnDraw()const override;
	virtual void OnCollide(Actor& other)override;

private:
	void HitField();

private:
	KremlinStateManager m_Manager;
	AnimationMesh* mAnimation;
	BossHitID* mBossHitID;

};

#endif // !_KREMKIN_H_
