#include "Camera_GameClear.h"
#include "../../../World/IWorld.h"
#include "../../Camera.h"

Camera_GameClear::Camera_GameClear(IWorld* world, Camera* camera)
	: AbstractCamera(world, camera, nullptr)
{

}

void Camera_GameClear::OnInitialize()
{

}

void Camera_GameClear::OnUpdate(float deltaTime)
{
	GSvector3 lVector = -(pWorld->FindActor("Boss")->GetRotate().getAxisZ().normalize());

	//ƒˆ[Šp‚ğİ’è
	if (lVector.x < 0.0f)
		mLookY =
		GSvector2(0.0f, -1.0f).innerDegree(
			-GSvector2((lVector).x, -lVector.z)) - 180;
	else
		mLookY =
		GSvector2(0.0f, -1.0f).innerDegree(
			GSvector2(lVector.x, -lVector.z));

	mLookY += 35.0f;
	mLookX = 35.0f;

	const GSvector3 lBack = -(pCamera->GetRotate().getAxisZ().getNormalized()) * 90.0f;
	const GSvector3 lUp = pCamera->GetRotate().getAxisY().getNormalized() * 5.0f;

	GSvector3 lTarget =
		pWorld->FindActor("Boss")->GetPosition() + lBack + lUp;

	//ƒoƒl
	Spring(lTarget, 1.5f, 0.2f, 0.2f);

}

void Camera_GameClear::Change()
{ }

GSvector3 Camera_GameClear::GetTargetPosition()const
{
	return GSvector3(0.0f, 0.0f, 0.0f);
}

void Camera_GameClear::Shutdown()
{

}