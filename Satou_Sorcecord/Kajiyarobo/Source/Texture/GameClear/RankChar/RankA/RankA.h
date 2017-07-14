#ifndef _RANK_A_H_
#define _RANK_A_H_
#include "../../RankCharBase/RankCharBase.h"

class RankA :public RankCharBase
{
public:
	RankA();

	virtual void Update(float deltaTime)override;

};

#endif // !_RANK_A_H_
