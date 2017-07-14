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

//�X�V
void ActorManager::Update(float deltaTime)
{
	//�A�N�^�[�̍X�V
	mRoot.Update(deltaTime);

	Collide();

	mRoot.RemoveChildren();

}

//�`��
void ActorManager::Draw()const
{
	mRoot.Draw();
}

//�A�N�^�[�̒ǉ�
void ActorManager::AddActor(ActorGroup group, const ActorPtr& actor)
{
	mActors[group]->AddChild(actor);
}

//�A�N�^�[�̌���
ActorPtr ActorManager::FindActor(const std::string& name)
{
	return mRoot.FindChildren(name);
}
//����L��������߂��G�̖��O���擾
std::string ActorManager::GetNearEnemyName(GSvector3& playerPosition)
{
	float lResultDistance = 200.0f;
	std::string lResult = "None";

	//�����_��
	mActors[ActorGroup::Enemy]->EachChildren(
		[&playerPosition, &lResultDistance, &lResult](const Actor& child)
	{
		if (child.GetName() != "BossBody")
		{
			//�G�̈ʒu���R�s�[
			GSvector3 lEnemyPosition;
			lEnemyPosition = child.GetPosition();
			//�G�ƃv���C���[�̋���
			float lDistance = Math::Distance(playerPosition, lEnemyPosition);

			//�{�X��D�悷��
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

//���b�Z�[�W����
void ActorManager::HandleMessage(EventMessage message, void* param)
{
	mRoot.HandleMessage(message, param);
}

//�Փ˔���
void ActorManager::Collide()
{
	mActors[ActorGroup::Player]->CollideChildren(*mActors[ActorGroup::Enemy]);
	mActors[ActorGroup::Player]->CollideChildren(*mActors[ActorGroup::EnemyAttack]);
	mActors[ActorGroup::Player]->CollideChildren(*mActors[ActorGroup::Player]);
	mActors[ActorGroup::PlayerAttack]->CollideChildren(*mActors[ActorGroup::Enemy]);
}