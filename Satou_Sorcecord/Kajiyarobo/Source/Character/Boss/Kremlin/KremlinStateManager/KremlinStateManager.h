#ifndef _KREMLIN_STATE_MANAGER_H_
#define _KREMLIN_STATE_MANAGER_H_
#include <unordered_map>
#include <gslib.h>
#include "../../Boss/AbstractBoss/AbstractBossPtr.h"

class IWorld;
class Actor;
class AnimationMesh;
class BossHP;
class AttackID;
enum class BossStateName;

class KremlinStateManager
{
public:
	KremlinStateManager();

	void Initialize(IWorld& world, Actor& boss, AnimationMesh& animation,
		BossHP& hp, AttackID& id);

	void Update(float deltaTime);

	void ChangeState();

	void Change();

	void Move(GSvector3& position);

	void RotateY(GSmatrix4& rotate);

private:
	void AddState(IWorld& world, Actor& boss, AnimationMesh& animation,
		BossHP& hp, AttackID& id);

private:
	using StateMap = std::unordered_map<BossStateName, AbstractBossPtr>;
	StateMap m_StateMap;

	BossStateName m_CurrentState;
	AbstractBossPtr m_CurrendBoss;
};

#endif // !_KREMLIN_STATE_MANAGER_H_
