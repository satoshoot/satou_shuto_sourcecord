#include "Cut.h"
#include "../../../../Utility/Enum/TextureName.h"
#include "../../../../Base/Actor/World/IWorld.h"
#include "../../../../Base/Actor/Camera/Camera.h"

Cut::Cut(IWorld* world, GSvector3 position, GameManager* gameManager, float set)
	: Actor(world, "Cut", position, BoundingSphere(0.0f), gameManager)
	, mTimer(15.0f)
{

	mVelocity =
		m_World->GetCamera()->GetPose().getAxisX().normalize() * (set - 30) * 0.035f;
	mVelocity.y = -(set - 50) * 0.015f;

}

void Cut::OnUpdate(float deltaTime)
{
	m_Position += mVelocity;
	mVelocity *= 0.8f*deltaTime;

	if (mTimer <= 0)
		Dead();
	mTimer--;
}

void Cut::OnDraw()const
{
	//各種レンダリングモードの退避
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//ライティングをオフにする
	glDisable(GL_LIGHTING);
	//zバッファに書き込みを行わない
	glDepthMask(GL_FALSE);
	//加算ブレンドを有効にする
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glEnable(GL_BLEND);
	//３Dスプライトを表示
	static const GSrect rect(-0.3f, 0.3f, 0.3f, -0.3f);
	const GScolor color(0.5f, 0.6f, 1.0f, mTimer / 50.0f);
	gsDrawSprite3D((GSuint)TextureName::Effect, &m_Position, &rect, NULL, &color, NULL, -30.0f);
	//各種レンダリングモードの復帰
	glPopAttrib();

}