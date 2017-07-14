#include "Camera_PlayerNormal.h"
#include "../../../World/IWorld.h"
#include "../../Camera.h"
#include "../../CameraStateName/CameraStateName.h"
#include "../../../../GameManager/GameManager.h"

Camera_PlayerNormal::Camera_PlayerNormal(IWorld* world, Camera* camera, BossHP* hp)
	: AbstractCamera(world, camera, hp)
{

}

void Camera_PlayerNormal::OnInitialize()
{ }

void Camera_PlayerNormal::OnUpdate(float deltaTime)
{
	Rotate();

	const GSvector3 lBack = -(pCamera->GetRotate().getAxisZ().getNormalized()) * mZoom;
	const GSvector3 lUp = pCamera->GetRotate().getAxisY().getNormalized() * 10.0f;

	GSvector3 lTarget =
		pWorld->FindActor("Player")->GetPosition() + lBack + lUp;

	//ƒoƒl
	Spring(lTarget, 1.5f, 0.2f, 0.2f);

}

void Camera_PlayerNormal::Change()
{
	if (BossDead() == true)
		return;
	if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_LEFT_SHOULDER) &&
		pWorld->GetTargetEnemyName(pWorld->FindActor("Player")->GetPosition()) != "None")
	{
		mNextState = CameraStateName::PlayerLockon;
		return;
	}
}

GSvector3 Camera_PlayerNormal::GetTargetPosition()const
{
	return GSvector3(0.0f, 0.0f, 0.0f);
}

void Camera_PlayerNormal::Shutdown()
{

}
