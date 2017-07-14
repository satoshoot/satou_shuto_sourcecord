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
	//�R���X�g���N�^
	World();

	//�X�V
	void Update(float deltaTime);
	//�`��
	void Draw()const;
	//���b�Z�[�W����
	void HandleMessage(EventMessage message, void* param);
	//�t�B�[���h�̒ǉ�
	void AddField(const FieldPtr& field);
	//�J�����̒ǉ�
	void AddCamera(const ActorPtr& camera);
	//���C�g�̒ǉ�
	void AddLight(const ActorPtr& light);
	//
	void AddEventMessageListener(EventMessageListener listener);
	//�t�B�[���h�̎擾
	FieldPtr GetField()const override;
	//�J�����̎擾
	Camera* GetCamera()const override;
	//�A�N�^�[�̒ǉ�
	void AddActor(ActorGroup group, const ActorPtr& actor)override;
	//�A�N�^�[�̌���
	ActorPtr FindActor(const std::string& name)override;
	//�^�[�Q�b�g�����G�̈ʒu
	std::string GetTargetEnemyName(GSvector3& playerPosition)override;
	//���b�Z�[�W�̑��M
	void sendMessage(EventMessage message, void* param = nullptr)override;

	//�R�s�[�֎~
	World(const World& other) = delete;
	World& operator = (const World& other) = delete;

private:
	//�A�N�^�[�}�l�[�W���[
	ActorManager mActors;

	//���C�g
	ActorPtr mLight;
	//�J����
	ActorPtr mCamera;
	//�t�B�[���h
	FieldPtr mField;
	//���b�Z�[�W���X�i
	EventMessageListener mListener;
};


#endif // !_WORLD_H_
