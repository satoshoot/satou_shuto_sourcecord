#ifndef _IWORLD_H_
#define _IWORLD_H_

#include "../Actor/ActorPtr/ActorPtr.h"
#include "../Field/FieldPtr.h"
#include <string>
#include <gslib.h>

enum class ActorGroup;
enum class EventMessage;
class Camera;

class IWorld
{
public:
	//���z�f�X�g���N�^
	virtual ~IWorld() {}

	//�A�N�^�[�̒ǉ�
	virtual void AddActor(ActorGroup group, const ActorPtr& actor) = 0;

	//�A�N�^�[�̌���
	virtual ActorPtr FindActor(const std::string& name) = 0;

	//�^�[�Q�b�g�����G�̈ʒu
	virtual std::string GetTargetEnemyName(GSvector3& playerPosition) = 0;

	//�t�B�[���h�̎擾
	virtual FieldPtr GetField()const = 0;

	//�J�����̎擾
	virtual Camera* GetCamera()const = 0;

	//���b�Z�[�W�̑��M
	virtual void sendMessage(EventMessage message, void* param = nullptr) = 0;

};


#endif // !_WORLD_H_