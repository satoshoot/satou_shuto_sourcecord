#include "DogShot.h"
#include "../../../Utility/Enum/MeshName.h"
#include "../EnemyAttack/EnemyAttack.h"	
#include "../../../Base/Actor/World/IWorld.h"
#include "../../../Base/Actor/Actor/ActorManager/ActorGroup.h"
#include "../../../Base/Actor/Field/Field.h"

DogShot::DogShot(
	const GSvector3& direction,
	IWorld* world,
	GSvector3 position,
	int& id,
	GameManager* gameManager)
	:Actor(world, "EnemyShot", position, BoundingSphere(1.0f), gameManager)
	, mPlayerRotate(GS_MATRIX4_IDENTITY)
	, deadCount(0)
	, up({ 0.0f,0.0f,0.0f })
	, front({ 0.0f,0.0f,0.0f })
	, left({ 0.0f,0.0f,0.0f })
{
	up = m_Rotate.getAxisY().normalize();
	front = direction;
	left = up.cross(front);

	m_Rotate.setAxisZ(front);
	m_Rotate.setAxisX(left);
	m_Rotate.setAxisY(up);
	front = left.cross(up);

	m_World->AddActor(ActorGroup::EnemyAttack, new_Actor<EnemyAttack>(
		world, this, 1.0f, 60, 1.5f, id, 50));
}

void DogShot::OnUpdate(float time)
{
	if (deadCount > 60 || m_World->GetField()->Collision(GetBody()))
	{
		Dead();
	}

	front.normalize();
	GSvector3 velocity(front);

	m_Position += velocity * 3.5f;

	m_Rotate.rotateY(-12.0f);

	m_Rotate.setPosition(m_Position);
	HitGround();
	deadCount += time;

}

void DogShot::OnDraw()const
{
	GSmatrix4 projection(m_Rotate);
	projection.setPosition(m_Position);

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glMultMatrixf(projection);
	gsDrawMesh((GSuint)MeshName::DogShot);
	glPopMatrix();

	//GetBody().Draw();
}

void DogShot::OnCollide(Actor& other)
{
	if (other.GetName() == "Player")
		Dead();
}

void DogShot::SetPlayerRotate(const GSmatrix4 matrix)
{
	mPlayerRotate = matrix;
}


void DogShot::HitGround()
{
	//è’ìÀèÍèä
	GSvector3 intersect;

	//OctreeÇ∆ìñÇΩÇ¡ÇƒÇ¢ÇΩÇÁ
	if (gsOctreeCollisionRay
		(
			gsGetOctree(
				(GSuint)MeshName::Ground),
			&m_Position,
			&GSvector3(0.0f, 1.0f, 0.0f),
			&intersect,
			NULL
			))
	{
		if (m_Position.y < intersect.y + 2.0f)
		{
			//ç¿ïWÇè’ìÀèÍèäÇ…Ç∑ÇÈ
			m_Position = intersect;
			m_Position += GSvector3(0.0f, 2.0f, 0.0f);
		}
	}
}