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
	//�R���X�g���N�^
	Actor(
		IWorld* world,
		const std::string& name,
		const GSvector3& position,
		const BoundingSphere& body,
		GameManager* gameManager
		);

	explicit Actor(const std::string& name = "none");

	//�f�X�g���N�^
	virtual ~Actor() {}

	//�X�V
	void Update(float deltaTime);

	//�`��
	void Draw()const;

	//�Փ˔���
	void Collide(Actor& other);

	//���S���Ă��邩
	bool IsDead()const;

	//���S����
	void Dead();

	//���O��Ԃ�
	const std::string& GetName()const;

	//���W��Ԃ�
	GSvector3 GetPosition()const;

	//��]�ϊ��s���Ԃ�
	GSmatrix4 GetRotate()const;

	//�ϊ��s���Ԃ�
	GSmatrix4 GetPose()const;

	//�Փ˔���f�[�^���擾
	BoundingSphere GetBody()const;

	//�q�̌���
	ActorPtr FindChildren(const std::string& name);
	//�q�̌���
	ActorPtr FindChildren(std::function<bool(const Actor&)>fn);
	//�q���m�̏Փ˔���
	void CollideChildren(Actor& other);
	//�Z�퓯�m�̏Փ˔���
	void CollideSibling();
	//�q�̒ǉ�
	void AddChild(const ActorPtr& child);
	//�q�̏���
	void EachChildren(std::function<void(Actor&)>fn);
	//�q�̏���(const��)
	void EachChildren(std::function<void(const Actor&)>fn)const;
	//�q���폜����
	void RemoveChildren(std::function<bool(Actor& actor)>fn);
	//�q���폜����
	void RemoveChildren();
	//�q������
	void ClearChildren();
	//���b�Z�[�W�����@�֐���n����
	void HandleMessage(EventMessage message, void* param);


	//�R�s�[�֎~
	Actor(const Actor& other) = delete;
	Actor& operator = (const Actor&other) = delete;

private:
	//���b�Z�[�W����
	virtual void OnMessage(EventMessage message, void* param);
	//�X�V
	virtual void OnUpdate(float deltaTime);
	//�`��
	virtual void OnDraw()const;
	//�Փ˂���
	virtual void OnCollide(Actor& other);
	//�Փ˔���
	bool IsCollide(const Actor& other)const;

protected:
	//IWorld���g����
	IWorld* m_World{ nullptr };

	//���O
	std::string m_Name{};

	//���W
	GSvector3 m_Position{ 0.0f,0.0f,0.0f };

	//��]
	GSmatrix4 m_Rotate{ GS_MATRIX4_IDENTITY };

	//�Փ˔���
	BoundingSphere m_Body{};

	//���S�t���O
	bool m_Dead{ false };

	//���d�q�b�g�h�~ID
	int m_ID;

	GameManager* p_GameManager{ nullptr };

private:
	//�q�A�N�^�[
	std::forward_list<ActorPtr> mChildren;

};

#endif // !_ACTOR_H_
