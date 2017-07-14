#ifndef _RANK_S_H_
#define _RANK_S_H_
#include "../../RankCharBase/RankCharBase.h"

class RankS :public RankCharBase
{
public:
	RankS();

	virtual void Update(float deltaTime)override;
};


#endif // !_RANK_S_H_
