#ifndef _RANK_H_
#define _RANK_H_
#include <gslib.h>

class Rank
{
public:
	Rank();

	void Update(float deltaTime, const float& count);

	void Draw()const;

private:
	GSvector2 mSize;
	float mAlpha;
	float mAlphaPlus;
};

#endif // !_RANK_H_