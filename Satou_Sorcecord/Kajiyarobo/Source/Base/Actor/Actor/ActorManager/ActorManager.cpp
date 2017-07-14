#include "ActorManager.h"
#include "ActorGroup.h"
#include "../../../../Utility/Math/Math.h"

ActorManager::ActorManager()
{
	Initialize();
}

void ActorManager::Initialize()
{
	mActors[ActorGroup::Player] = std::make_shared<Actor>();
	mActors[ActorGroup::PlayerAttack] = std::make_shared<Actor>();
	mActors[ActorGroup::Enemy] = std::make_shared<Actor>();
	mActors[ActorGroup::EnemyAttack] = std::make_shared<Actor>();
	mActors[ActorGroup::Effect] = std::make_shared<Actor>();
	mRoot.ClearChildren();
	mRoot.AddChild(mActors[ActorGroup::Effect]);
	mRoot.AddChild(mActors[ActorGroup::EnemyAttack]);
	mRoot.AddChild(mActors[ActorGroup::PlayerAttack]);
	mRoot.AddChild(mActors[ActorGroup::Enemy]);
	mRoot.AddChild(mActors[ActorGroup::Player]);
}

//更新
void ActorManager::Update(float deltaTime)
{
	//アクターの更新
	mRoot.Update(deltaTime);

	Collide();

	mRoot.RemoveChildren();

}

//描画
void ActorManager::Draw()const
{
	mRoot.Draw();
}

//アクターの追加
void ActorManager::AddActor(ActorGroup group, const ActorPtr& actor)
{
	mActors[group]->AddChild(actor);
}

//アクターの検索
ActorPtr ActorManager::FindActor(const std::string& name)
{
	return mRoot.FindChildren(name);
}
//操作キャラから近い敵の名前を取得
std::string ActorManager::GetNearEnemyName(GSvector3& playerPosition)
{
	float lResultDistance = 200.0f;
	std::string lResult = "None";

	//ラムダ式
	mActors[ActorGroup::Enemy]->EachChildren(
		[&playerPosition, &lResultDistance, &lResult](const Actor& child)
	{
		if (child.GetName() != "BossBody")
		{
			//敵の位置をコピー
			GSvector3 lEnemyPosition;
			lEnemyPosition = child.GetPosition();
			//敵とプレイヤーの距離
			float lDistance = Math::Distance(playerPosition, lEnemyPosition);

			//ボスを優先する
			float lCorrection = 0.0f;
			if (child.GetName() == "Boss")
				lCorrection = 10.0f;

			if (lResultDistance >= lDistance - lCorrection)
			{
				lResultDistance = lDistance;
				lResult = child.GetName();
			}
		}
	});

	return lResult;
}

//メッセージ処理
void ActorManager::HandleMessage(EventMessage message, void* param)
{
	mRoot.HandleMessage(message, param);
}

//衝突判定
void ActorManager::Collide()
{
	mActors[ActorGroup::Player]->CollideChildren(*mActors[ActorGroup::Enemy]);
	mActors[ActorGroup::Player]->CollideChildren(*mActors[ActorGroup::EnemyAttack]);
	mActors[ActorGroup::Player]->CollideChildren(*mActors[ActorGroup::Player]);
	mActors[ActorGroup::PlayerAttack]->CollideChildren(*mActors[ActorGroup::Enemy]);
}