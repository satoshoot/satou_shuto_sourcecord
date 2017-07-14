#include "GameFrameh.h"
#include "../../Screen/Screen.h"
#include "../../Character/Player/Player/Player.h"
#include "../../Utility/Enum/MeshName.h"
#include "../GameManager/GameManager.h"
#include "../Actor/Scene/Scene.h"
#include "../Actor/Scene/GameTitleScene/GameTitleScene.h"
#include "../Actor/Scene/GamePlayScene/GamePlayScene.h"
#include <gslib.h>
#include <GSeffect.h>


GameFrame::GameFrame()
	: Game(WIDTH, HEIGHT, FULLSCREEN, FPS)
	, p_GameManager(new GameManager())
	, sceneManager_(new SceneManager(p_GameManager))
	, m_Timer(0)
{
}

GameFrame::~GameFrame()
{}

void GameFrame::start()
{
	//�G�t�F�N�g�̏�����
	gsInitEffect();

	/*NowLoading�`��*/
	p_GameManager->Draw();

	sceneManager_->Add(Scene::GameTitle, std::make_shared<GameTitleScene>(*p_GameManager));
	sceneManager_->Add(Scene::GamePlay, std::make_shared<GamePlayScene>(p_GameManager));
	sceneManager_->Change(Scene::GameTitle);
}

void GameFrame::update(float time)
{
	sceneManager_->Update(time);


	/*NowLoading��\�����Ă���ǂݍ��݂��s���i�v���P�j*/
	if (m_Timer > 1)
		return;
	if (m_Timer == 1)
	/*�R���e���c�̓ǂݍ���*/
	p_GameManager->LoadContent();

	m_Timer += time;
}

void GameFrame::draw()
{
	sceneManager_->Draw();
}

void GameFrame::end()
{
	sceneManager_->End();

	/*�G�t�F�N�g�̍폜*/
	p_GameManager->UnLoadContent();
	/*�G�t�F�N�g�̏I��*/
	gsFinishEffect();
}