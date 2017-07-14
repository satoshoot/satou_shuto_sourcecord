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
	/*タイトルの出撃を表示*/
	bool TitleDraw(float& count);
	/*左に移動*/
	bool MoveLeft(float deltaTime, float& count);
	/*左上に移動*/
	bool MoveTopLeft(float deltaTime, float& count);
	/*左下に移動*/
	bool MoveBottomLeft(float deltaTime, float& count);
	/*文字を回転*/
	bool Rotate(float& count);
	/*文字をすべて表示*/
	bool TitleLogoDraw(float& count);
	/*タイトルの演出終了*/
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
