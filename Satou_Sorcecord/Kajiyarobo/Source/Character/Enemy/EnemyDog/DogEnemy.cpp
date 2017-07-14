#include "DogEnemy.h"
#include "../../Attack/DogShot/DogShot.h"
#include "../../../Utility/Enum/MeshName.h"
#include "../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../Base/Actor/World/IWorld.h"
#include "../../../Base/GameManager/GameManager.h"
#include "../../../Utility/Math/Math.h"
#include "../../../Base/Actor/Actor/Actor.h"
#include "../../../Base/Actor/EventMessage/EventMessage.h"
#include "../../Attack/AttackID/AttackID.h"
#include "../../../Base/Actor/Ray.Line/Line.h"
#include "../../../Base/Actor/Field/Field.h"
#include "../../Attack/PlayerAttack/PlayerAttack.h"


DogEnemy::DogEnemy(
	int hp,
	float angle,
	IWorld& world,
	std::string& name,
	GSvector3 position,
	GameManager& gameManager,
	AttackID& id)
	: Actor(&world, name, position, BoundingSphere(GSvector3(0.0f, 1.5f, 0.0f), 3.0f), &gameManager)
	, mAction(DogAction::Wait)
	, mStateCount(0)
	, hp(hp)
	, mAnimation((GSuint)MeshName::Dog, (GSuint)MeshName::Dog, (GSuint)MeshName::Dog, 0)
	, mBornDraw(false)
	, m_ID(0)
	, mAttackID(&id)
{
	m_Rotate.rotateY(angle);
	mIDList.clear();
	mIDList.push_back(0);
}

void DogEnemy::OnUpdate(float time)
{
	GSvector3 velocity = GSvector3(0.0f, 0.0f, 0.0f);

	float mDistance;
	GSvector3 l_PlayerPosition = m_World->FindActor("Player")->GetPosition();
	mDistance = Math::Distance(l_PlayerPosition, m_Position);
	Line l_PlayerLine(m_Position, l_PlayerPosition);

	const GSvector3& up = GSvector3(0.0f, 1.0f, 0.0f);

	GSvector3& front = GSvector3(l_PlayerPosition - m_Position);
	front.y = 0.0f;
	front.normalize();
	const GSvector3& left = GSvector3(up).cross(GSvector3(front));

	GSuint mAnimationNo = 0;

	switch (mAction)
	{
	case DogDie:
		mAnimationNo = 5;
		mBornDraw = false;
		if (mStateCount <= 0)
			Dead();
		break;
	case Wait:
		if (200.0f >= mDistance &&
			m_World->GetField()->Collision(l_PlayerLine) == false)
		{
			mAction = DogAction::Run;
			mStateCount = gsRandf(3 * 60, 8 * 60);
		}

		break;
	case Run:
		mAnimationNo = 3;
		if (100.0f >= mDistance)
		{
			mAction = DogAction::Near;
			mStateCount = gsRandf(60, 3 * 60);
			mAnimationNo = 0;
		}
		else if (mStateCount <= 0)
		{
			velocity = m_World->FindActor("Player")->GetPosition() - m_Position;
			velocity.normalize();
			mAnimationNo = 1;

			m_Position += velocity * 2.0f;
		}
		else
		{
			velocity += left;
			velocity.normalize();
			m_Position += velocity / 6.0f;
		}
		m_Rotate.setAxisX(left);
		m_Rotate.setAxisY(up);
		m_Rotate.setAxisZ(front);
		break;
	case Near:
		mAnimationNo = 0;

		if (mStateCount >= 90)
		{
			velocity += left;
			velocity.normalize();
			m_Position += velocity / 8.0f;
			mAnimationNo = 3;
		}
		else if (mStateCount <= 0)
		{
			int next = gsRandf(0, 4);
			if (next <= 1)
			{
				mAction = DogAction::Attack;
				mBornDraw = true;
				mStateCount = 60;
			}
			else if (next <= 3)
			{
				mAction = DogAction::Near;
				mStateCount = gsRandf(60, 3 * 60);
				mAnimationNo = 0;

			}
			else
			{
				mAction = DogAction::Leave;
				mStateCount = gsRandf(10, 40);
				mAnimationNo = 0;
			}
		}
		//m_Position += velocity / 5;
		m_Rotate.setAxisX(left);
		m_Rotate.setAxisY(up);
		m_Rotate.setAxisZ(front);
		break;
	case Attack:
		mAnimationNo = 2;
		if (mStateCount == 20)
		{
			int lID = mAttackID->GetID();
			m_World->AddActor(
				ActorGroup::EnemyAttack,
				std::make_shared<DogShot>(front, m_World,
					m_Position + GSvector3(0.0f, 4.0f, 0.0f), lID, p_GameManager));
			mBornDraw = false;
		}
		else if (mStateCount <= 0)
		{
			mAction = DogAction::Leave;
			mStateCount = gsRandf(60, 2 * 60);
			mAnimationNo = 0;
		}
		m_Rotate.setAxisX(left);
		m_Rotate.setAxisY(up);
		m_Rotate.setAxisZ(front);
		break;
	case Leave:
		if (mStateCount <= 0)
		{
			mAction = DogAction::Run;
			mStateCount = gsRandf(3 * 60, 5 * 60);
			mAnimationNo = 3;
		}
		else if (mStateCount <= 30)
		{
			mAnimationNo = 1;
			velocity += -front;
			velocity.normalize();
			m_Position += velocity * 2;
			m_Rotate.setAxisX(left);
			m_Rotate.setAxisY(up);
			m_Rotate.setAxisZ(front);
		}
		break;
	case Hit:
		mAnimationNo = 4;
		mBornDraw = false;
		if (mStateCount <= 0)
			mAction = DogAction::Run;

		break;
	}

	m_Rotate.setPosition(m_Position);

	mAnimation.ChangeMotion(mAnimationNo);
	mAnimation.Update(time);
	mAnimation.Calculate((m_Rotate).setPosition(m_Position));

	//IDが10個以上になったら先頭を削除
	if (mIDList.size() >= 10)
		mIDList.pop_front();
	if (hp <= 0 && mAction != DogAction::DogDie)
	{
		mAction = DogAction::DogDie;
		mStateCount = 200;
		m_Body.mRadius = 0.0f;
	}


	Line l_FieldLine(m_Position + GSvector3(0.0f, GetBody().mRadius * 2, 0.0f),
		m_Position + GSvector3(0.0f, -GetBody().mRadius * 2, 0.0f));
	GSvector3 intersect;
	if (m_World->GetField()->Collision(l_FieldLine, &intersect))
		if (m_Position.y <= intersect.y)
			m_Position.y = intersect.y;

	GSvector3 wallIntersect;
	if (m_World->GetField()->Collision(GetBody(), &wallIntersect))
	{
		m_Position.x = wallIntersect.x;
		m_Position.z = wallIntersect.z;
	}

	mStateCount--;
}

void DogEnemy::OnDraw()const
{
	if (mBornDraw == true)
		DrawWepon();

	mAnimation.Draw();
	//GetBody().Draw();
}

void DogEnemy::OnCollide(Actor& other)
{
	if (other.GetName() == "PlayerAttack" && mAction != DogAction::DogDie)
	{
		//IDListに同じ数字がないか調べる
		for (IntList::iterator i = mIDList.begin(); i != mIDList.end(); i++)
		{
			if (*i == m_ID)
				return;
		}
		//武器の攻撃力だけHPを減らす
		PlayerAttack& lAttack = dynamic_cast<PlayerAttack&>(other);
		hp -= lAttack.Damage();

		//IDをListに入れる
		mIDList.push_back(m_ID);

		int lID = mAttackID->GetID();
		m_World->sendMessage(EventMessage::PlayerHitStopID, &lID);

		//確率でノックバック
		int knockBack = gsRand(0, 9);
		if (knockBack <= 3)
		{
			mAction = DogAction::Hit;
			mStateCount = 60;
		}

	}
}

void DogEnemy::OnMessage(EventMessage message, void* param)
{
	switch (message)
	{
	case EventMessage::EnemyDamageID:
		int* id = (int*)param;

		m_ID = *id;
		break;
	}
}

void DogEnemy::DrawWepon()const
{
	//ボーンの４番目にくっつく(右手)
	const GSmatrix4& wepon = mAnimation.GetMatrices().at(6);
	gsDisable(GS_SKIN_MESH);

	glPushMatrix();
	glMultMatrixf(wepon);
	gsDrawMesh((GSuint)MeshName::DogShot);
	glPopMatrix();
}


