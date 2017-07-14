#ifndef _BIG_CURSOR_POSITION_H_
#define _BIG_CURSOR_POSITION_H_
#include "../../ITitleTextureBase/ITitleTextureBase.h"

enum CursorPosition
{
	Right = 0,
	Up = 1,
	Down = 2,
};

class BigCursorPosition :public ITitleTextureBase
{
public:
	BigCursorPosition();

	GSvector2 GetPosition()const;

private:
	virtual void StartUpdate(float deltaTime, float& counter)override;
	virtual void EndUpdate(float deltaTime, float& counter)override;
	virtual void Draw()const override;

	/*�w�肵���ʒu�Ɉړ�*/
	void TargetMove(float deltaTime, const GSvector2& targetPosition);
	/*3�̎w�肵���ʒu�Ɉړ�����*/
	void ChangeTargetPosition(float& counter);

private:
	const GSvector2 DOWN_POSITION;
	const GSvector2	UP_POSITION;
	const GSvector2	RIGHT_POSITION;

	GSvector2 m_Position;
	GSvector2 m_TargetPosition;
	int m_RandomTime;
	int m_Target;
	int m_TargetPlus;
};


#endif // !_BIG_CURSOR_POSITION_H_
