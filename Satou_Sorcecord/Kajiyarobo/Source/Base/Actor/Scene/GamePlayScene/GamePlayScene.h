#ifndef GAME_PLAY_SCENE_H_
#define GAME_PLAY_SCENE_H_

#include "../IScene.h"
#include "../../Actor/ActorManager/ActorManager.h"

#include <memory>

class Field;
class World;
#include "../../../GameManager/GameManager.h"
#include "../../../../Utility/Move/Move.h"
#include "../../../../Character/Attack/AttackID/AttackID.h"
#include "../../../../Character/Boss/Boss/BossHP/BossHP.h"
#include "../../../../Menu/Menu/Menu.h"
#include "../../../../Character/Player/Player/PlayerHP/PlayerHP.h"

class GamePlayScene : public IScene {
public:
	GamePlayScene(GameManager* gameManager);

	virtual ~GamePlayScene();

	virtual void Start() override;

	virtual void Update(float time) override;

	virtual void Draw() const override;

	virtual bool isEnd() const override;

	virtual Scene Next() const override;

	virtual void End() override;

	void HandleMessage(EventMessage message, void* param);


private:
	GameManager* m_GameManager;

	using WorldPtr = std::shared_ptr<World>;
	//ワールドクラス
	WorldPtr m_WorldPtr;

	//移動クラス
	Move		 m_Move;
	//ID生成
	AttackID	m_ID;
	Menu		m_Menu;
	BossHP		m_BossHP;
	PlayerHP*   n_PlayerHP;

	bool isEnd_;
};

#endif // !GAME_PLAY_H_
