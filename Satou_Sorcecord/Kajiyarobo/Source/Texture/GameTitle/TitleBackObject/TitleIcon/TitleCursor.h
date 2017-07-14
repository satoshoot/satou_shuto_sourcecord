#ifndef _TITLE_CURSOR_H_
#define _TITLE_CURSOR_H_
#include "../../ITitleTextureBase/ITitleTextureBase.h"
#include "../../../../Screen/Screen.h"

class TitleCursor :public ITitleTextureBase
{
public:
	TitleCursor();

	virtual void StartUpdate(float deltaTime, float& counter);
	virtual void EndUpdate(float deltaTime, float& counter);
	virtual void Draw()const;

private:
	//カーソルを表示
	bool OpenCursor(float deltaTime, float& counter);
	bool ChangeTargetPosition(float& counter);
	void Move(float deltaTime, float& counter);

private:
	/*アイコンの位置*/
	const GSvector2 UP_ICON_POSITION;
	const GSvector2 UNDER_ICON_POSITION;
	const float SCALE;

	GSvector2 m_Position;
	GSvector2 m_Center;
	float m_Angle;
	GSvector2 m_Size;
	GSvector2 m_TargetPosition;
	bool m_PositionDown;
	int m_RandomTime;

};


#endif // !_TITLE_CURSOR_H_
