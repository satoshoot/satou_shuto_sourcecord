#ifndef _TITLE_SCALE_H_
#define _TITLE_SCALE_H_
#include "../../ITitleTextureBase/ITitleTextureBase.h"

class TitleScale :public ITitleTextureBase
{
public:
	TitleScale();

	virtual void StartUpdate(float deltaTime, float& counter);
	virtual void EndUpdate(float deltaTime, float& counter);
	virtual void Draw()const;


private:
	const GSvector2 TEXTURE_SIZE;

	GSvector2 m_Size;
	float m_Alpha;

};
#endif // !_TITLE_SCALE_H_