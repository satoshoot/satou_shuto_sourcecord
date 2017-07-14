#ifndef _TITLE_LOGO_H_
#define _TITLE_LOGO_H_
#include "../ITitleTextureBase/ITitleTextureBase.h"

class TitleLogo :public ITitleTextureBase
{
public:
	TitleLogo();

	virtual void StartUpdate(float deltaTime, float& count);

	virtual void EndUpdate(float deltaTime, float& count);

	virtual void Draw()const;

private:
	/*�^�C�g���̏o����\��*/
	bool TitleDraw(float& count);
	/*���Ɉړ�*/
	bool MoveLeft(float deltaTime, float& count);
	/*����Ɉړ�*/
	bool MoveTopLeft(float deltaTime, float& count);
	/*�����Ɉړ�*/
	bool MoveBottomLeft(float deltaTime, float& count);
	/*��������]*/
	bool Rotate(float& count);
	/*���������ׂĕ\��*/
	bool TitleLogoDraw(float& count);
	/*�^�C�g���̉��o�I��*/
	bool TitleEnd(float& count);
private:
	float mAlpha;
	float mAlphaPlus;
	GSvector2 mSize;
	float mAngle;
	GSvector2 mPosition;
	GSvector2 mScale;

};

#endif // !_TITLE_LOGO_H_
