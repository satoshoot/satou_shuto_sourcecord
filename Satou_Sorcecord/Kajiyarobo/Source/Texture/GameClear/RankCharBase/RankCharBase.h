#ifndef _RANK_CHAR_BASE_H_
#define _RANK_CHAR_BASE_H_

enum class TextureName;

class RankCharBase
{
public:
	RankCharBase(TextureName name, float count);

	virtual void Update(float deltaTime) = 0;

	void Draw()const;

protected:
	TextureName mName;
	float mSize;
	float mCounter;

};

#endif // !_RANK_CHAR_BASE_H_
