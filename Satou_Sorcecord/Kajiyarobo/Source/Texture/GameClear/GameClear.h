#ifndef _GAME_CLEAR_H_
#define _GAME_CLEAR_H_
#include <gslib.h>
class BossHP;
class ClearBack;
class CharClear;
class Rank;
class RankChar;

class GameClear
{
public:
	GameClear(BossHP* hp);
	~GameClear();

	void Initialize();

	void Update(float deltaTime, bool dead);

	void Draw()const;

	void End();

private:
	BossHP* pBossHP;

	ClearBack* nClearBack;
	CharClear* nCharClear;
	Rank* nRank;
	RankChar* nRankChar;

	GSvector2 mSize;
	float mCounter;
	float mPlayTime;
};

#endif // !_GAME_CLEAR_H_
