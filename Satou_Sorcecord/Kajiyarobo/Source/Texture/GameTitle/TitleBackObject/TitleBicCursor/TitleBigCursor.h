#ifndef _TITLE_BIG_CURSOR_H_
#define _TITLE_BIG_CURSOR_H_
#include "../../ITitleTextureBase/ITitleTextureBase.h"

class BigCursorPosition;

class TitleBigCursor :public ITitleTextureBase
{
public:
	TitleBigCursor(BigCursorPosition& basePosition);

private:
	virtual void StartUpdate(float deltaTime, float& counter)override;
	virtual void EndUpdate(float deltaTime, float& counter)override;
	virtual void Draw()const override;

	//カーソル出現
	bool OpenCursor(float deltaTime, float& counter);
	//カーソルの回転
	void Rotate(float deltaTime, float& counter);

private:
	BigCursorPosition* p_CursorPosition;
	GSvector2 m_Position;
	GSvector2 m_Scale;
	float m_Angle;
	float m_AngleMax;
	int m_RandomTime;

};


#endif // !_TITLE_BIG_CURSOR_H_
