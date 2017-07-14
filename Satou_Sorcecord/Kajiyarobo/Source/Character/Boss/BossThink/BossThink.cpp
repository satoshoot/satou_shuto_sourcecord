#include "BossThink.h"
#include "../../../Base/Actor/World/IWorld.h"
#include "../../../Base/Actor/Actor/Actor.h"
#include "../../../Base/Actor/Ray.Line/Line.h"
#include "../../../Utility/Math/Math.h"
#include "../../../Base/Actor/Field/Field.h"
#include "../Boss/BossStateName/BossStateName.h"
#include "BossThinkResult.h"

BossStateName BossThink::Think(Actor* boss, GSvector3& targetPosition, IWorld* world)
{
	if (PlayerHidden(boss, targetPosition, world) == true)
		return BossThinkResult::HideResult();
	else if (TargetNear(boss, targetPosition))
		return BossThinkResult::NearResult();
	else
		return BossThinkResult::LeaveResult();

	return BossStateName::None;
}

BossStateName BossThink::LookThink(Actor* boss, GSvector3& targetPosition, IWorld* world)
{
	if (PlayerHidden(boss, targetPosition, world) == true)
		return BossThinkResult::HideResult();
	else if (TargetNear(boss, targetPosition))
		return BossThinkResult::NearResult();
	else
		return BossThinkResult::LookResult();

	return BossStateName::None;
}

bool BossThink::PlayerHidden(Actor* boss, GSvector3& targetPosition, IWorld* world)
{
	Line lTargetLine(boss->GetPosition(), targetPosition);
	bool lResult = world->GetField()->Collision(lTargetLine);

	return lResult;
}

bool BossThink::TargetNear(Actor* boss, GSvector3& targetPosition)
{
	if (Math::Distance(boss->GetPosition(), targetPosition) <= 150)
		return true;

	return false;
}