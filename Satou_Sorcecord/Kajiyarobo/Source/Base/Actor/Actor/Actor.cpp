#include "Actor.h"
//#include "../World/IWorld.h"
#include <algorithm>

//�R���X�g���N�^
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

//�R���X�g���N�^ �������Ȃ��A�N�^�[�p
Actor::Actor(const std::string& name)
	:Actor(nullptr, name, { 0.0f,0.0f,0.0f }, BoundingSphere(), p_GameManager)
{ }

//�X�V
void Actor::Update(float deltaTime)
{
	OnUpdate(deltaTime);
	EachChildren(
		[&](Actor& child)
	{child.Update(deltaTime); }
	);
}

//�`��
void Actor::Draw()const
{
	OnDraw();
	EachChildren(
		[](const Actor& child)
	{child.Draw(); }
	);
}

//�Փ˔���
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

//���S���Ă��邩
bool Actor::IsDead()const
{
	return m_Dead;
}

//���S����
void Actor::Dead()
{
	m_Dead = true;
}

//���O��Ԃ�
const std::string& Actor::GetName()const
{
	return m_Name;
}
//���W��Ԃ�
GSvector3 Actor::GetPosition()const
{
	return m_Position;
}
//��]�ϊ��s���Ԃ�
GSmatrix4 Actor::GetRotate()const
{
	return m_Rotate;
}

//��]�s���Ԃ�
GSmatrix4 Actor::GetPose()const
{
	return GSmatrix4(m_Rotate).setPosition(m_Position);
}
//�����蔻��N���X��Ԃ�
BoundingSphere Actor::GetBody()const
{
	return m_Body.transform(GetPose());
}

//�q�̌���
ActorPtr Actor::FindChildren(const std::string& name)
{
	return FindChildren(
		[&](const Actor& actor)
	{return actor.GetName() == name; }
	);
}

//�q�̌���
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

//�q���m�̏Փ˔���
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

//�Z�퓯�m�̏Փ˔���
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

//�q�̒ǉ�
void Actor::AddChild(const ActorPtr& child)
{
	mChildren.push_front(child);
}

//�q�̏���
void Actor::EachChildren(std::function<void(Actor&)>fn)
{
	std::for_each(mChildren.begin(), mChildren.end(),
		[&](const ActorPtr& child) {fn(*child); });
}

//�q�̏���(const��)
void Actor::EachChildren(std::function<void(const Actor&)>fn)const
{
	std::for_each(mChildren.begin(), mChildren.end(),
		[&](const ActorPtr& child)
	{fn(*child); }
	);
}

//�q�̍폜
void Actor::RemoveChildren(std::function<bool(Actor& actor)>fn)
{
	//remove_if�ŃA�N�^�[�̍폜
	mChildren.remove_if(
		[&](const ActorPtr& child)
	{return fn(*child); }
	);
}

//�q�̍폜
void Actor::RemoveChildren()
{
	RemoveChildren([](Actor& child)
	{return child.IsDead(); }
	);

	EachChildren([](Actor& child)
	{child.RemoveChildren(); }
	);
}

//�q�̏���
void Actor::ClearChildren()
{
	mChildren.clear();
}
//���b�Z�[�W����
void Actor::HandleMessage(EventMessage message, void* param)
{
	OnMessage(message, param);
	EachChildren(
		[&](Actor& child) {child.HandleMessage(message, param); });
}
//���b�Z�[�W����
void Actor::OnMessage(EventMessage, void*) {}

//�X�V
void Actor::OnUpdate(float)
{ }

//�`��
void Actor::OnDraw()const
{ }

//�Փ˂���
void Actor::OnCollide(Actor&)
{ }

//�Փ˔���
bool Actor::IsCollide(const Actor& other)const
{
	return m_Body.transform(GetPose())
		.intersects(other.m_Body.transform(other.GetPose()));
}



