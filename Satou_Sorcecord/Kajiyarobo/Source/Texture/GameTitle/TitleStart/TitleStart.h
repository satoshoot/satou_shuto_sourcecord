#ifndef _TITLE_START_H_
#define _TITLE_START_H_
#include "../ITitleTextureBase/ITitleTextureBase.h"

class TitleStart :public ITitleTextureBase
{
public:
	TitleStart();

	virtual void StartUpdate(float deltaTime, float& count);

	virtual void EndUpdate(float deltaTime, float& count);

	virtual void Draw()const;

private:
	/*ボタンの表示*/
	bool DrawButton(float& count);
	/*下に移動*/
	bool MoveDown(float& count);
	/*右に移動*/
	bool MoveRight(float deltaTime, float& count, float time, float max, float velocity);
	/*スタートを表示*/
	bool DrawStart(float& count);
	/*タイトルの演出終了*/
	void TitleEnd();

	/*ボタンのみの状態に戻す*/
	bool ReturnButton(float& count);
	/*右上に移動*/
	bool MoveTopRight(float deltaTime, float& count);
	/*透明度を変更する*/
	void Alpha();

private:
	GSvector2 mPosition;
	GSvector2 mSize;
	float mAlpha;
	float mAlphaPlus;

};
#endif // !_TITLE_START_H_
