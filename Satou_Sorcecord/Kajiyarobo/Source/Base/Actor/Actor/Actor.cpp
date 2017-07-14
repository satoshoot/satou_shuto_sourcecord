#include "Actor.h"
//#include "../World/IWorld.h"
#include <algorithm>

//コンストラクタ
Actor::Actor(
	IWorld* world,
	const std::string& name,
	const GSvector3& position,
	const BoundingSphere& body,
	GameManager* gameManager
	)
	: m_World{ world }
	, m_Name{ name }
	, m_Position{ position }
	, m_Body{ body }
	, p_GameManager{ gameManager }
	, m_ID{ 0 }
{ }

//コンストラクタ 動きがないアクター用
Actor::Actor(const std::string& name)
	:Actor(nullptr, name, { 0.0f,0.0f,0.0f }, BoundingSphere(), p_GameManager)
{ }

//更新
void Actor::Update(float deltaTime)
{
	OnUpdate(deltaTime);
	EachChildren(
		[&](Actor& child)
	{child.Update(deltaTime); }
	);
}

//描画
void Actor::Draw()const
{
	OnDraw();
	EachChildren(
		[](const Actor& child)
	{child.Draw(); }
	);
}

//衝突判定
void Actor::Collide(Actor& other)
{
	if (IsCollide(other))
	{
		OnCollide(other);
		other.OnCollide(*this);
	}
	EachChildren(
		[&](Actor& child)
	{child.Collide(other); }
	);
}

//死亡しているか
bool Actor::IsDead()const
{
	return m_Dead;
}

//死亡する
void Actor::Dead()
{
	m_Dead = true;
}

//名前を返す
const std::string& Actor::GetName()const
{
	return m_Name;
}
//座標を返す
GSvector3 Actor::GetPosition()const
{
	return m_Position;
}
//回転変換行列を返す
GSmatrix4 Actor::GetRotate()const
{
	return m_Rotate;
}

//回転行列を返す
GSmatrix4 Actor::GetPose()const
{
	return GSmatrix4(m_Rotate).setPosition(m_Position);
}
//当たり判定クラスを返す
BoundingSphere Actor::GetBody()const
{
	return m_Body.transform(GetPose());
}

//子の検索
ActorPtr Actor::FindChildren(const std::string& name)
{
	return FindChildren(
		[&](const Actor& actor)
	{return actor.GetName() == name; }
	);
}

//子の検索
ActorPtr Actor::FindChildren(std::function<bool(const Actor&)>fn)
{
	const std::forward_list<ActorPtr>::iterator& i = std::find_if(mChildren.begin(), mChildren.end(),
		[&](const ActorPtr& child)
	{return fn(*child); });
	if (i != mChildren.end())
	{
		return *i;
	}
	for (const ActorPtr& child : mChildren)//foreach 
	{
		const ActorPtr actor = child->FindChildren(fn);
		if (actor != nullptr)
		{
			return actor;
		}
	}
	return nullptr;
}

//子同士の衝突判定
void Actor::CollideChildren(Actor& other)
{
	EachChildren([&](Actor& my)
	{
		other.EachChildren([&](Actor& target)
		{
			my.Collide(target);
		});
	});
}

//兄弟同士の衝突判定
void Actor::CollideSibling()
{
	for (auto i = mChildren.begin(); i != mChildren.end(); i++)
	{
		std::for_each(std::next(i), mChildren.end(),
			[&](const ActorPtr& actor)
		{(*i)->Collide(*actor); }
		);
	}
}

//子の追加
void Actor::AddChild(const ActorPtr& child)
{
	mChildren.push_front(child);
}

//子の巡回
void Actor::EachChildren(std::function<void(Actor&)>fn)
{
	std::for_each(mChildren.begin(), mChildren.end(),
		[&](const ActorPtr& child) {fn(*child); });
}

//子の巡回(const版)
void Actor::EachChildren(std::function<void(const Actor&)>fn)const
{
	std::for_each(mChildren.begin(), mChildren.end(),
		[&](const ActorPtr& child)
	{fn(*child); }
	);
}

//子の削除
void Actor::RemoveChildren(std::function<bool(Actor& actor)>fn)
{
	//remove_ifでアクターの削除
	mChildren.remove_if(
		[&](const ActorPtr& child)
	{return fn(*child); }
	);
}

//子の削除
void Actor::RemoveChildren()
{
	RemoveChildren([](Actor& child)
	{return child.IsDead(); }
	);

	EachChildren([](Actor& child)
	{child.RemoveChildren(); }
	);
}

//子の消去
void Actor::ClearChildren()
{
	mChildren.clear();
}
//メッセージ処理
void Actor::HandleMessage(EventMessage message, void* param)
{
	OnMessage(message, param);
	EachChildren(
		[&](Actor& child) {child.HandleMessage(message, param); });
}
//メッセージ処理
void Actor::OnMessage(EventMessage, void*) {}

//更新
void Actor::OnUpdate(float)
{ }

//描画
void Actor::OnDraw()const
{ }

//衝突した
void Actor::OnCollide(Actor&)
{ }

//衝突判定
bool Actor::IsCollide(const Actor& other)const
{
	return m_Body.transform(GetPose())
		.intersects(other.m_Body.transform(other.GetPose()));
}



