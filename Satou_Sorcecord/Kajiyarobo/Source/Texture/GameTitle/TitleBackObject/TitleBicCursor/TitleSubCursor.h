#ifndef _TITLE_SUB_CURSOR_H_
#define _TITLE_SUB_CURSOR_H_
#include "../../ITitleTextureBase/ITitleTextureBase.h"

class BigCursorPosition;

class TitleSubCursor :public ITitleTextureBase
{
public:
	TitleSubCursor(BigCursorPosition& cursorPosition);

private:
	virtual void StartUpdate(float deltaTime, float& counter)override;
	virtual void EndUpdate(float deltaTime, float& counter)override;
	virtual void Draw()const override;

	bool OpenCursor(float deltaTime, float& counter);
	void Rotate(float deltaTime, float& counter);

private:
	BigCursorPosition* p_CursorPosition;
	GSvector2 m_Position;
	float m_Angle;
	GSvector2 m_Scale;
	int m_RandomTime;
	float m_AngleMax;

};
#endif // !_TITLE_SUB_CURSOR_H_