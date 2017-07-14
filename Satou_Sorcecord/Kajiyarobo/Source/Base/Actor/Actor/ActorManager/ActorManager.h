#ifndef _ACTOR_MANAGER_H_
#define _ACTOR_MANAGER_H_
#include "../Actor.h"
#include "../ActorPtr/ActorPtr.h"
#include <unordered_map>

enum class ActorGroup;

class ActorManager
{
public:
	//�R���X�g���N�^
	ActorManager();
	//������
	void Initialize();
	//�X�V
	void Update(float deltaTime);
	//�`��
	void Draw()const;
	//�A�N�^�[�̒ǉ�
	void AddActor(ActorGroup group, const ActorPtr& actor);
	//�A�N�^�[�̌���
	ActorPtr FindActor(const std::string& name);
	//�߂��G�̈ʒu���擾
	std::string GetNearEnemyName(GSvector3& playerPosition);
	//���b�Z�[�W����
	void HandleMessage(EventMessage message, void* param);

	//�R�s�[�֎~
	ActorManager(const ActorManager& other) = delete;
	ActorManager& operator = (const ActorManager& other) = delete;

private:
	//�Փ˔���
	void Collide();

private:
	//���[�g�m�[�h�A�A�N�^�[�̈�ԏ�
	Actor mRoot;
	//�A�N�^�[�O���[�v
	std::unordered_map<ActorGroup, ActorPtr> mActors;

};


#endif // !_ACTOR_MANAGER_H_
