#ifndef _RANK_CHAR_H_
#define _RANK_CHAR_H_

class RankCharBase;

class RankChar
{
public:
	RankChar();
	~RankChar();

	void ClearTime(float& time);

	void Update(float deltaTime, const float& count);

	void Draw()const;

private:
	RankCharBase* nRankChar;

};

#endif // !_RANK_CHAR_H_
