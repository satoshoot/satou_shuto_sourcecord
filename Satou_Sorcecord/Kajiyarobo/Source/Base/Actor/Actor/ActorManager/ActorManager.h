#ifndef _ACTOR_MANAGER_H_
#define _ACTOR_MANAGER_H_
#include "../Actor.h"
#include "../ActorPtr/ActorPtr.h"
#include <unordered_map>

enum class ActorGroup;

class ActorManager
{
public:
	//コンストラクタ
	ActorManager();
	//初期化
	void Initialize();
	//更新
	void Update(float deltaTime);
	//描画
	void Draw()const;
	//アクターの追加
	void AddActor(ActorGroup group, const ActorPtr& actor);
	//アクターの検索
	ActorPtr FindActor(const std::string& name);
	//近い敵の位置を取得
	std::string GetNearEnemyName(GSvector3& playerPosition);
	//メッセージ処理
	void HandleMessage(EventMessage message, void* param);

	//コピー禁止
	ActorManager(const ActorManager& other) = delete;
	ActorManager& operator = (const ActorManager& other) = delete;

private:
	//衝突判定
	void Collide();

private:
	//ルートノード、アクターの一番上
	Actor mRoot;
	//アクターグループ
	std::unordered_map<ActorGroup, ActorPtr> mActors;

};


#endif // !_ACTOR_MANAGER_H_
