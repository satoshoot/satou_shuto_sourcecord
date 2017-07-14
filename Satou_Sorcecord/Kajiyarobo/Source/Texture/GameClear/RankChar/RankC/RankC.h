#ifndef _RANK_C_H_
#define _RANK_C_H_
#include "../../RankCharBase/RankCharBase.h"

class RankC :public RankCharBase
{
public:
	RankC();

	virtual void Update(float deltaTime)override;

};


#endif // !_RANK_C_H_
