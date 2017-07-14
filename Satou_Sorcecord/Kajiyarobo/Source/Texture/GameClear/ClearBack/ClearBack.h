#ifndef _CLEAR_BACK_H_
#define _CLEAR_BACK_H_
#include <gslib.h>

class ClearBack
{
public:
	ClearBack();

	void Update(float deltaTime, const float& count);

	void Draw()const;

private:
	GSvector2 mSize;

};

#endif // !_CLEAR_BACK_H_