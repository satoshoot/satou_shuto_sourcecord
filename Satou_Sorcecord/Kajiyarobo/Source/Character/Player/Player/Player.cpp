#include"Player.h"
#include "../../../Utility/Enum/MeshName.h"
#include "../../../Utility/Move/Move.h"
#include "../../../Base/GameManager/GameManager.h"
#include "../../../Base/Actor/World/IWorld.h"
#include "../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../Attack/PlayerAttack/PlayerAttack.h"
#include "../../../Utility/Math/Math.h"
#include "../../../Utility/AnimationMesh/AnimationMesh.h"
#include "../../Attack/AttackID/AttackID.h"
#include "../../../Wepon/Wepon/Wepon.h"
#include "../../../Base/Actor/Field/Field.h"
#include "../../../Base/Actor/Camera/Camera.h"
#include "../../../Base/Actor/Camera/CameraStateName/CameraStateName.h"
#include "../../../Menu/Menu/Menu.h"
#include "../PlayerStateName/PlayerStateName.h"
#include "../../../Item/Shield/Shield.h"
#include "../../../Menu/MenuStateName/MenuStateName.h"
#include "../../../Base/Actor/Ray.Line/Line.h"

#include<iostream>


Player::Player(IWorld& world, GSvector3 position, GameManager& gameManager,
	Move& move, AttackID& id, Menu& menu, PlayerHP* hp)
	:Actor(&world, "Player", position, BoundingSphere(GSvector3(0.0f, 1.5f, 0.0f), 3.0f), &gameManager)
	, mAnimation(std::make_shared<AnimationMesh>(
		(GSuint)MeshName::Player, (GSuint)MeshName::Player, (GSuint)MeshName::Player, 0))
	, p_Move(&move)
	, p_Menu(&menu)
	, m_State()
	, m_Item()
{
	/*シールドクラスの生成*/
	ActorPtr l_ActorShield = new_Actor<Shield>(this);
	m_World->AddActor(ActorGroup::Player, l_ActorShield);
	Shield* l_Shield = dynamic_cast<Shield*>(l_ActorShield.get());
	m_Item = Item(hp, l_Shield);
	m_State = PlayerStateManager(&world, &id, this, mAnimation.get(),
		&move, &menu, hp, l_Shield, &gameManager);
	p_Menu->NewMenuManager(gameManager, m_Item);
}

Player::~Player()
{}

void Player::OnUpdate(float deltaTime)
{
	GSvector3& lLeft = m_World->GetCamera()->GetRotate().getAxisX().normalize();
	const GSvector3& lUp = m_Rotate.getAxisY().normalize();
	GSvector3& lFront = lLeft.cross(lUp);

	m_State.ChangeState();

	//プレイヤーの行動
	m_State.Update(deltaTime);

	//移動力を代入
	GSvector3 velocity = m_State.GetVelocity();

	m_Rotate = m_State.GetRotate();

	velocity.y += -0.1f;
	m_Position += velocity * deltaTime;


	HitField();

	m_Item.Update(deltaTime);
	mAnimation->Update(deltaTime);
	//ボーンの変換行列を計算
	mAnimation->Calculate(GetPose());
}

void Player::OnDraw() const
{
	mAnimation->Draw();

	m_State.HoldDraw();

	//GetBody().Draw();
}

void Player::OnCollide(Actor& other)
{
	if (other.GetName() == "Boss")
		return;

	if (other.GetName() == m_World->GetTargetEnemyName(m_Position) ||
		other.GetName() == "BossBody")
	{
		GSvector3 intersect;

		gsCollisionSphereAndLine(
			&other.GetPosition(),
			other.GetBody().mRadius + GetBody().mRadius + (other.GetBody().mRadius / 10.0f),
			&m_Position,
			&other.GetPosition(),
			&intersect
			);

		m_Position.x = intersect.x;
		m_Position.z = intersect.z;
		/*敵と衝突して壁にめり込むのを防止*/
		HitField();
	}

	m_State.Collide(other);
}

void Player::HitField()
{
	Line l_Line(m_Position + GSvector3(0.0f, GetBody().mRadius * 2, 0.0f),
		m_Position + GSvector3(0.0f, -GetBody().mRadius * 2, 0.0f));

	GSvector3 intersect;

	if (m_World->GetField()->Collision(l_Line, &intersect))
		if (m_Position.y <= intersect.y)
			m_Position.y = intersect.y;

	GSvector3 wallIntersect;
	if (m_World->GetField()->Collision(GetBody(), &wallIntersect))
	{
		m_Position.x = wallIntersect.x;
		m_Position.z = wallIntersect.z;
	}
}

int Player::Damage()const
{
	return p_GameManager->GetPlayerWepon()->GetPower() * m_Item.PowerUp();
}