#ifndef _WORLD_H_
#define _WORLD_H_

#include "IWorld.h"
#include "../Actor/ActorPtr/ActorPtr.h"
#include "../Actor/ActorManager/ActorManager.h"
#include "../Field/FieldPtr.h"

enum class EventMessage;

class World :public IWorld
{
public:
	using EventMessageListener = std::function<void(EventMessage, void*)>;
public:
	//コンストラクタ
	World();

	//更新
	void Update(float deltaTime);
	//描画
	void Draw()const;
	//メッセージ処理
	void HandleMessage(EventMessage message, void* param);
	//フィールドの追加
	void AddField(const FieldPtr& field);
	//カメラの追加
	void AddCamera(const ActorPtr& camera);
	//ライトの追加
	void AddLight(const ActorPtr& light);
	//
	void AddEventMessageListener(EventMessageListener listener);
	//フィールドの取得
	FieldPtr GetField()const override;
	//カメラの取得
	Camera* GetCamera()const override;
	//アクターの追加
	void AddActor(ActorGroup group, const ActorPtr& actor)override;
	//アクターの検索
	ActorPtr FindActor(const std::string& name)override;
	//ターゲットした敵の位置
	std::string GetTargetEnemyName(GSvector3& playerPosition)override;
	//メッセージの送信
	void sendMessage(EventMessage message, void* param = nullptr)override;

	//コピー禁止
	World(const World& other) = delete;
	World& operator = (const World& other) = delete;

private:
	//アクターマネージャー
	ActorManager mActors;

	//ライト
	ActorPtr mLight;
	//カメラ
	ActorPtr mCamera;
	//フィールド
	FieldPtr mField;
	//メッセージリスナ
	EventMessageListener mListener;
};


#endif // !_WORLD_H_
