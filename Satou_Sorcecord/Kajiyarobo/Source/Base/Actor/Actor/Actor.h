#ifndef _ACTOR_H_
#define _ACTOR_H_

#include"ActorPtr/ActorPtr.h"
#include"../BoundingSphere/BoundingSphere.h"
#include<gslib.h>
#include<string>
#include<functional>
#include<forward_list>


class GameManager;
class IWorld;
enum class EventMessage;

class Actor
{
public:
	//コンストラクタ
	Actor(
		IWorld* world,
		const std::string& name,
		const GSvector3& position,
		const BoundingSphere& body,
		GameManager* gameManager
		);

	explicit Actor(const std::string& name = "none");

	//デストラクタ
	virtual ~Actor() {}

	//更新
	void Update(float deltaTime);

	//描画
	void Draw()const;

	//衝突判定
	void Collide(Actor& other);

	//死亡しているか
	bool IsDead()const;

	//死亡する
	void Dead();

	//名前を返す
	const std::string& GetName()const;

	//座標を返す
	GSvector3 GetPosition()const;

	//回転変換行列を返す
	GSmatrix4 GetRotate()const;

	//変換行列を返す
	GSmatrix4 GetPose()const;

	//衝突判定データを取得
	BoundingSphere GetBody()const;

	//子の検索
	ActorPtr FindChildren(const std::string& name);
	//子の検索
	ActorPtr FindChildren(std::function<bool(const Actor&)>fn);
	//子同士の衝突判定
	void CollideChildren(Actor& other);
	//兄弟同士の衝突判定
	void CollideSibling();
	//子の追加
	void AddChild(const ActorPtr& child);
	//子の巡回
	void EachChildren(std::function<void(Actor&)>fn);
	//子の巡回(const版)
	void EachChildren(std::function<void(const Actor&)>fn)const;
	//子を削除する
	void RemoveChildren(std::function<bool(Actor& actor)>fn);
	//子を削除する
	void RemoveChildren();
	//子を消去
	void ClearChildren();
	//メッセージ処理　関数を渡せる
	void HandleMessage(EventMessage message, void* param);


	//コピー禁止
	Actor(const Actor& other) = delete;
	Actor& operator = (const Actor&other) = delete;

private:
	//メッセージ処理
	virtual void OnMessage(EventMessage message, void* param);
	//更新
	virtual void OnUpdate(float deltaTime);
	//描画
	virtual void OnDraw()const;
	//衝突した
	virtual void OnCollide(Actor& other);
	//衝突判定
	bool IsCollide(const Actor& other)const;

protected:
	//IWorldが使える
	IWorld* m_World{ nullptr };

	//名前
	std::string m_Name{};

	//座標
	GSvector3 m_Position{ 0.0f,0.0f,0.0f };

	//回転
	GSmatrix4 m_Rotate{ GS_MATRIX4_IDENTITY };

	//衝突判定
	BoundingSphere m_Body{};

	//死亡フラグ
	bool m_Dead{ false };

	//多重ヒット防止ID
	int m_ID;

	GameManager* p_GameManager{ nullptr };

private:
	//子アクター
	std::forward_list<ActorPtr> mChildren;

};

#endif // !_ACTOR_H_
