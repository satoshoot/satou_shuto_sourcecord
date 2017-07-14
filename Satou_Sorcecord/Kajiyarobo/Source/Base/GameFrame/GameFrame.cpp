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
	//エフェクトの初期化
	gsInitEffect();

	/*NowLoading描画*/
	p_GameManager->Draw();

	sceneManager_->Add(Scene::GameTitle, std::make_shared<GameTitleScene>(*p_GameManager));
	sceneManager_->Add(Scene::GamePlay, std::make_shared<GamePlayScene>(p_GameManager));
	sceneManager_->Change(Scene::GameTitle);
}

void GameFrame::update(float time)
{
	sceneManager_->Update(time);


	/*NowLoadingを表示してから読み込みを行う（要改善）*/
	if (m_Timer > 1)
		return;
	if (m_Timer == 1)
	/*コンテンツの読み込み*/
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

	/*エフェクトの削除*/
	p_GameManager->UnLoadContent();
	/*エフェクトの終了*/
	gsFinishEffect();
}