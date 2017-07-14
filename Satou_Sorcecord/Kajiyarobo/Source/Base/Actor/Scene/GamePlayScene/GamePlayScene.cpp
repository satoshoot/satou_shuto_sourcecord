#include "GamePlayScene.h"
#include "../Scene.h"
#include "../../../Actor/Field/Field.h"
#include "../../../../Character/Player/Player/Player.h"
#include "../../Camera/Camera.h"
#include "../../Light/Light.h"
#include "../../../../Character/Enemy/EnemyDog/DogEnemy.h"
#include "../../../../Character/Enemy/EnemyGenerator/EnemyGenerator.h"
#include "../../../../Utility/Enum/MeshName.h"
#include "../../World/World.h"
#include "../../Actor/ActorManager/ActorGroup.h"
#include "../../EventMessage/EventMessage.h"
#include "../../../../Character/Boss/Kremlin/Kremlin.h"
#include "../../../../Utility/Enum/SoundName.h"
#include "../../../../Menu/MenuStateName/MenuStateName.h"
#include "../../../../Texture/GamePlay/ScreenClear/ScreenClear.h"


#include <gslib.h>
#include<GSmusic.h>
#include <string>

GamePlayScene::GamePlayScene(GameManager* gameManager)
	: m_GameManager(gameManager)
	, isEnd_(false)
	, m_Move()
	, m_ID()
	, m_Menu()
	, m_BossHP()
	, n_PlayerHP(nullptr)
{
}

GamePlayScene::~GamePlayScene() {
}

void GamePlayScene::Start()
{
	gsBindMusic((GSuint)SoundName::PlayBGM);

	isEnd_ = false;

	m_BossHP.Start(15000);

	n_PlayerHP = new PlayerHP();

	m_WorldPtr = std::make_shared<World>();
	//フィールドの追加
	m_WorldPtr->AddField(new_Field<Field>(
		(GSuint)MeshName::Wall, (GSuint)MeshName::SkyBox, (GSuint)MeshName::Ground));
	//カメラの追加
	ActorPtr l_Camera = new_Actor<Camera>(m_WorldPtr.get(), m_GameManager, &m_BossHP);
	m_WorldPtr->AddCamera(l_Camera);
	//ライトの追加
	m_WorldPtr->AddLight(
		new_Actor<Light>(m_WorldPtr.get(), GSvector3(100.0f, 150.0f, 0.0f), m_GameManager));

	//敵の追加
	m_WorldPtr->AddActor(ActorGroup::Enemy,
		new_Actor<Kremlin>(*m_WorldPtr.get(), GSvector3(0.0f, 0.0f, 250.0f),
			*m_GameManager, m_BossHP, m_ID));

	m_WorldPtr->AddActor(ActorGroup::Enemy, new_Actor<DogEnemy>(1500, 180.0f,
		*m_WorldPtr.get(), (std::string)"FourthEnemy", GSvector3(30.0f, 0.0f, -50.0f),
		*m_GameManager, m_ID));

	m_WorldPtr->AddActor(ActorGroup::Effect, new_Actor<EnemyGenerator>(
		*m_WorldPtr.get(), *m_GameManager, m_ID));

	//プレイヤーの追加
	m_WorldPtr->AddActor(ActorGroup::Player, new_Actor<Player>(
		*m_WorldPtr.get(), GSvector3(0.0f, 0.0f, -370.0f),
		*m_GameManager, m_Move, m_ID, m_Menu, n_PlayerHP));

	m_WorldPtr->AddActor(ActorGroup::Effect, new_Actor<ScreenClear>());

	//
	m_WorldPtr->AddEventMessageListener(
		[=](EventMessage message, void* param)
	{HandleMessage(message, param); });
}

void GamePlayScene::Update(float time) {
	gsPlayMusic();
	///*メニューを開いたときはキャラを停止する*/
	//if (m_Menu->GetCurrentState() == MenuStateName::Close ||
	//	m_Menu->GetCurrentState() == MenuStateName::MakeTime)

	if (m_BossHP.IsBossEnd() == false && n_PlayerHP->IsGameOver() == false)
		m_WorldPtr->Update(time);

	n_PlayerHP->Update(time);
	m_BossHP.Update(time);
	if (n_PlayerHP->Dead() == false)
	{
		m_Move.Update(time);
		m_Menu.Update(time);
	}

	if (gsGetKeyTrigger(GKEY_A) ||
		gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_A))
	{
		if (m_BossHP.QuestClear() == true ||
			n_PlayerHP->IsGameOver() == true)
			isEnd_ = true;
	}
}

void GamePlayScene::Draw()const {
	m_WorldPtr->Draw();

	if (m_BossHP.Dead() == false)
	{
		m_Menu.Draw();
		n_PlayerHP->Draw();
	}
	m_BossHP.Draw();
}

bool GamePlayScene::isEnd()const {
	return isEnd_;
}

Scene GamePlayScene::Next()const {
	return Scene::GameTitle;
}

void GamePlayScene::End() {
	m_WorldPtr = nullptr;
	n_PlayerHP = nullptr;
	m_BossHP.End();
	gsStopMusic();
}

void GamePlayScene::HandleMessage(EventMessage message, void* param)
{
	switch (message)
	{
	case EventMessage::EnemyDamageID:

		break;
	default:
		break;
	}
}