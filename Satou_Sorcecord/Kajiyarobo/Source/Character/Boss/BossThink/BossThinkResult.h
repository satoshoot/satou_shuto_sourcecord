#ifndef _BOSS_THINK_RESULT_H_
#define _BOSS_THINK_RESULT_H_

enum class BossStateName;

class BossThinkResult
{
public:
	static BossStateName HideResult();

	static BossStateName NearResult();

	static BossStateName LeaveResult();

	static BossStateName LookResult();
};

#endif // !_BOSS_THINK_RESULT_H_
