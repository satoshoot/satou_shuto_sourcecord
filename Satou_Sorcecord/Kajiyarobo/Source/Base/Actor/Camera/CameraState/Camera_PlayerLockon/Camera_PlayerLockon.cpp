#include "Camera_PlayerLockon.h"
#include "../../../../../Utility/Math/Math.h"
#include "../../Camera.h"
#include "../../CameraStateName/CameraStateName.h"
#include "../../../../GameManager/GameManager.h"


Camera_PlayerLockon::Camera_PlayerLockon(IWorld* world, Camera* camera, BossHP* hp)
	: AbstractCamera(world, camera, hp)
	, mTargetName("None")
{
}


void Camera_PlayerLockon::OnInitialize()
{
	mTargetName = pWorld->GetTargetEnemyName(pWorld->FindActor("Player")->GetPosition());
	mZoom = 40.0f;
}

void Camera_PlayerLockon::OnUpdate(float deltaTime)
{
	if (pWorld->FindActor(mTargetName) == nullptr)
		return;

	float lDistance = Math::Distance(
		pWorld->FindActor("Player")->GetPosition(), pWorld->FindActor(mTargetName)->GetPosition());

	//ピッチ角を設定
	mLookX = Math::ArcTangent(lDistance + 10.0f, 8.0f);

	/*2つのベクトルの角度は0～180しかできないため、-180～180で扱うための処理*/
	GSvector3 lVector =
		pWorld->FindActor(mTargetName)->GetPosition() - pWorld->FindActor("Player")->GetPosition();

	//ヨー角を設定
	if (lVector.x < 0.0f)
		mLookY =
		GSvector2(0.0f, -1.0f).innerDegree(
			-GSvector2((lVector).x, -lVector.z)) - 180;
	else
		mLookY =
		GSvector2(0.0f, -1.0f).innerDegree(
			GSvector2(lVector.x, -lVector.z));


	const GSvector3 lBack = -(pCamera->GetRotate().getAxisZ().getNormalized()) * mZoom;
	const GSvector3 lUp = pCamera->GetRotate().getAxisY().getNormalized() * 10.0f;

	GSvector3 lTarget =
		pWorld->FindActor("Player")->GetPosition() + lBack + lUp;

	//バネ
	float lStiffness = (200 - lDistance) / 80;
	lStiffness = CLAMP(lStiffness, 0.6f, 10.0f);
	Spring(lTarget, lStiffness, 0.05f, 0.2f);

	LerpAngle(deltaTime);

}

void Camera_PlayerLockon::Change()
{
	if (BossDead() == true)
		return;
	if (pWorld->FindActor(mTargetName) == nullptr)
	{
		mNextState = CameraStateName::PlayerNormal;
		return;
	}

	float lDistance = Math::Distance(
		pWorld->FindActor("Player")->GetPosition(), pWorld->FindActor(mTargetName)->GetPosition());

	if (gsXBoxPadButtonState(0, GS_XBOX_PAD_LEFT_SHOULDER) == false ||
		lDistance > 200.0f)
		mNextState = CameraStateName::PlayerNormal;

}

GSvector3 Camera_PlayerLockon::GetTargetPosition()const
{
	if (pWorld->FindActor(mTargetName) == nullptr)
		return GSvector3(0.0f, 0.0f, 0.0f);

	return pWorld->FindActor(mTargetName)->GetPosition();
}

void Camera_PlayerLockon::Shutdown()
{

}
