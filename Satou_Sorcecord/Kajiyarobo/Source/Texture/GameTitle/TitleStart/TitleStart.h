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
	/*�{�^���̕\��*/
	bool DrawButton(float& count);
	/*���Ɉړ�*/
	bool MoveDown(float& count);
	/*�E�Ɉړ�*/
	bool MoveRight(float deltaTime, float& count, float time, float max, float velocity);
	/*�X�^�[�g��\��*/
	bool DrawStart(float& count);
	/*�^�C�g���̉��o�I��*/
	void TitleEnd();

	/*�{�^���݂̂̏�Ԃɖ߂�*/
	bool ReturnButton(float& count);
	/*�E��Ɉړ�*/
	bool MoveTopRight(float deltaTime, float& count);
	/*�����x��ύX����*/
	void Alpha();

private:
	GSvector2 mPosition;
	GSvector2 mSize;
	float mAlpha;
	float mAlphaPlus;

};
#endif // !_TITLE_START_H_
