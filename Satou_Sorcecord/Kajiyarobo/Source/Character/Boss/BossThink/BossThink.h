#ifndef _BOSS_THINK_H_
#define _BOSS_THINK_H_
#include <gslib.h>
#include <string>

enum class BossStateName;
class IWorld;
class Actor;


class BossThink
{
public:
	static BossStateName Think(Actor* boss, GSvector3& targetPosition, IWorld* world);

	static BossStateName LookThink(Actor* boss, GSvector3& targetPosition, IWorld* world);

	static bool PlayerHidden(Actor* boss, GSvector3& targetPosition, IWorld* world);

private:

	static bool TargetNear(Actor* boss, GSvector3& targetPosition);


};

#endif // !_BOSS_THINK_H_
