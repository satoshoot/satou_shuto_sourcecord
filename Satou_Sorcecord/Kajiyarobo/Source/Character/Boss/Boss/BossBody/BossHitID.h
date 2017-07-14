#ifndef _BOSS_HIT_ID_H_
#define _BOSS_HIT_ID_H_
#include <list>

class BossHitID
{
public:
	BossHitID();


	void Add(int& id);

	void DeletePop();

	bool HitStop(int& id);

private:
	using IDList = std::list<int>;

	IDList mIDList;

};

#endif // !_BOSS_HIT_ID_H_
