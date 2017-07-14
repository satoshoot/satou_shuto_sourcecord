#include "TargetCursor.h"
#include "../../../../Utility/Enum/TextureName.h"
#include "../../World/IWorld.h"
#include "../Camera.h"
#include "../CameraStateName/CameraStateName.h"
#include "../../../../Utility/Math/Math.h"

TargetCursor::TargetCursor(IWorld* world, GameManager* gameManager, Camera* camera)
	: Actor(world, "Target", { 0.0f,0.0f,0.0f }, BoundingSphere(0.0f), gameManager)
	, pCamera(camera)
	, mAngle(0.0f)
	, mCameraState(CameraStateName::None)
	, mSize(0.05f)
{

}

void TargetCursor::Initialize()
{
	mSize = 20.0f;
}

void TargetCursor::Update(float deltaTime)
{
	mAngle -= deltaTime * 2;
	mSize -= deltaTime * 0.3f;

	GSvector3 lTargetPosition = pCamera->GetTargetPosition() + GSvector3(0.0f, 3.0f, 0.0f);
	GSvector3 lVelocity = lTargetPosition - pCamera->GetPosition();
	lVelocity.normalize();

	m_Position = pCamera->GetPosition() + lVelocity * 3;

	mSize = CLAMP(mSize, 0.07f, 5.0f);

}

void TargetCursor::OnDraw()const
{
	if (mCameraState != CameraStateName::PlayerLockon)
		return;

	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_LIGHTING);

	const GSrect lRect(-mSize, mSize, mSize, -mSize);
	const GScolor lColor(1.0f, 1.0f, 1.0f, 1.0f);
	gsDrawSprite3D(
		(GSuint)TextureName::Target, &m_Position, &lRect, NULL, &lColor, NULL, mAngle);

	glPopAttrib();
}

void TargetCursor::SetState(CameraStateName& state)
{
	mCameraState = state;
}
