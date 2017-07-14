#include <gslib.h>
#include "BossThinkResult.h"
#include "../Boss/BossStateName/BossStateName.h"

BossStateName BossThinkResult::HideResult()
{
	int lRand = gsRand(0, 3);

	switch (lRand)
	{
	case 0:
		return BossStateName::Shoot;
		break;
	case 1:
		return BossStateName::MoveLeft;
		break;
	case 2:
		return BossStateName::MoveRight;
		break;
	case 3:
		return BossStateName::Idle;
		break;
	}
	return BossStateName::Idle;
}

BossStateName BossThinkResult::NearResult()
{
	int lRand = gsRand(0, 18);

	if (lRand <= 4)
		return BossStateName::Fire;
	if (lRand <= 8)
		return BossStateName::Punch;
	if (lRand <= 9)
		return BossStateName::Look;
	if (lRand <= 13)
		return BossStateName::Shoot;
	if (lRand <= 14)
		return BossStateName::Roar;
	if (lRand <= 16)
		return BossStateName::Rush;
	if (lRand <= 17)
		return BossStateName::MoveLeft;
	if (lRand <= 18)
		return BossStateName::MoveRight;


	return BossStateName::Idle;
}

BossStateName BossThinkResult::LeaveResult()
{
	int lRand = gsRand(0, 13);

	if (lRand <= 0)
		return BossStateName::Idle;
	else if (lRand <= 1)
		return BossStateName::Look;
	else if (lRand <= 4)
		return BossStateName::Jump;
	else if (lRand <= 6)
		return BossStateName::Walk;
	else if (lRand <= 9)
		return BossStateName::Shoot;
	else if (lRand <= 10)
		return BossStateName::Rush;
	else if (lRand <= 13)
		return BossStateName::Fire;

	return BossStateName::Idle;
}

BossStateName BossThinkResult::LookResult()
{
	int lRand = gsRand(0, 14);

	if (lRand <= 0)
		return BossStateName::Idle;
	else if (lRand <= 4)
		return BossStateName::Dush;
	else if (lRand <= 8)
		return BossStateName::Jump;
	else if (lRand <= 9)
		return BossStateName::Walk;
	else if (lRand <= 10)
		return BossStateName::Shoot;
	else if (lRand <= 12)
		return BossStateName::Rush;
	else if (lRand <= 14)
		return BossStateName::Fire;

	return BossStateName::Idle;
}