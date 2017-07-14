#include "GameTitleScene.h"
#include "../Scene.h"
#include "../../Field/Field.h"
#include "../../../../Utility/Enum/TextureName.h"
#include "../../../../Utility/Enum/SoundName.h"
#include "../../../../Texture/GameTitle/BackGround/BackGround.h"
#include "../../../../Texture/GameTitle/TitleLogo/TitleLogo.h"
#include "../../../../Texture/GameTitle/TitleStart/TitleStart.h"
#include "../../../GameManager/GameManager.h"
#include <GSmusic.h>

GameTitleScene::GameTitleScene(GameManager& gameManager)
	: p_GameManager(&gameManager)
	, isEnd_(false)
	, m_Timer(0)
	, nBackGround()
	, m_TextureManager()
	, mTitleEnd(false)
{

}

GameTitleScene::~GameTitleScene()
{ }

void GameTitleScene::Start()
{
	gsBindMusic((GSuint)SoundName::TitleBGM);

	isEnd_ = false;
	mTitleEnd = false;
	m_TextureManager.Initialize();

	m_Timer = 0;
}

void GameTitleScene::Update(float time)
{
	(void)time;
	gsPlayMusic();
	m_Timer += time;

	if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_LEFT_SHOULDER))
		p_GameManager->NewWepon();

	if (m_Timer >= 60 * 3 + 30)
	{
		if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_A) &&
			mTitleEnd == false)
		{
			gsPlaySE((GSuint)SoundName::TitleStart);
			mTitleEnd = true;
			m_Timer = 0;
			return;
		}
		if (mTitleEnd == true)
			isEnd_ = true;
	}
	if (mTitleEnd == false)
	{
		nBackGround.StartUpdate(m_Timer);
		m_TextureManager.StartUpdate(time, m_Timer);

		if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_A))
			m_Timer = 60 * 3 + 30;

		return;
	}

	nBackGround.EndUpdate(m_Timer);
	m_TextureManager.EndUpdate(time, m_Timer);
}

void GameTitleScene::Draw()const
{
	nBackGround.BackDraw();
	m_TextureManager.Draw();
	nBackGround.FrameDraw();
}

bool GameTitleScene::isEnd() const
{
	return isEnd_;
}

Scene GameTitleScene::Next()const
{
	return Scene::GamePlay;
}

void GameTitleScene::End()
{
	m_TextureManager.End();
	gsStopMusic();
}