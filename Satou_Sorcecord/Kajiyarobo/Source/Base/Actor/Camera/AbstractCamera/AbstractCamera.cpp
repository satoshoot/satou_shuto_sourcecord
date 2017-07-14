#include "AbstractCamera.h"
#include "../CameraStateName/CameraStateName.h"
#include "../../../../Utility/Math/Math.h"
#include "../Camera.h"
#include "../../../../Character/Boss/Boss/BossHP/BossHP.h"

AbstractCamera::AbstractCamera(IWorld* world, Camera* camera, BossHP* hp)
	: pWorld(world)
	, pCamera(camera)
	, pBossHP(hp)
	, mVelocity(0.0f, 0.0f, 0.0f)
	, mNextState(CameraStateName::None)
	, mZoom(50.0f)
	, mSpeedX(0.0f)
	, mSpeedY(0.0f)
	, mLookX(0.0f)
	, mLookY(0.0f)
	, mLerpTimer(0.0f)
	, mPrevLookX(0.0f)
	, mPrevLookY(0.0f)
{

}

void AbstractCamera::Initialize()
{
	mNextState = CameraStateName::None;
	mLerpTimer = 0.0f;
	OnInitialize();
}

void AbstractCamera::Update(float deltaTime)
{
	OnUpdate(deltaTime);
}

float AbstractCamera::GetPitchAngle()const
{
	return mLookX;
}

float AbstractCamera::GetYawAngle()const
{
	return mLookY;
}

bool AbstractCamera::BossDead()
{
	if (pBossHP->Dead() == true)
	{
		mNextState = CameraStateName::GameClear;
		return true;
	}
	return false;
}

void AbstractCamera::SetCurrentAngle(float& pitch, float& yaw)
{
	mPrevLookX = pitch;
	mPrevLookY = yaw;
	mLookX = pitch;
	mLookY = yaw;
}

GSvector3 AbstractCamera::GetVelocity()const
{
	return mVelocity;
}

void AbstractCamera::Rotate()
{
	GSvector2 right_Stick;
	gsXBoxPadGetRightAxis(0, &right_Stick);

	float lStickDistance;
	lStickDistance = Math::Distance(GSvector2(0.0f, 0.0f), right_Stick);

	if (right_Stick.x == 0.0f)
	{
		if (mSpeedY <= 0.1f && mSpeedY >= -0.1f)
		{
			mSpeedY = 0.0f;
		}
		else if (mSpeedY >= 0.1f)
		{
			mSpeedY -= 0.2f;
		}
		else if (mSpeedY <= 0.1f)
		{
			mSpeedY += 0.2f;
		}
	}
	else if (mSpeedY >= lStickDistance * 1.7f)
	{
		mSpeedY = lStickDistance*1.7f;
	}
	else if (mSpeedY <= -lStickDistance * 1.7f)
	{
		mSpeedY = -lStickDistance * 1.7f;
	}
	else if (right_Stick.x > 0)
	{
		mSpeedY -= 0.2f;
	}
	else if (right_Stick.x < 0)
	{
		mSpeedY += 0.2f;
	}


	if (right_Stick.y == 0.0f)
	{
		if (mSpeedX <= 0.1f && mSpeedX >= -0.1f)
		{
			mSpeedX = 0.0f;
		}
		else if (mSpeedX <= 0.1f)
		{
			mSpeedX += 0.2f;
		}
		else if (mSpeedX >= 0.1f)
		{
			mSpeedX -= 0.2f;
		}
	}
	else if (mSpeedX >= lStickDistance)
	{
		mSpeedX = lStickDistance;
	}
	else if (mSpeedX <= -lStickDistance)
	{
		mSpeedX = -lStickDistance;
	}
	else if (right_Stick.y > 0)
	{
		mSpeedX -= 0.2f;
	}
	else if (right_Stick.y < 0)
	{
		mSpeedX += 0.2f;
	}

	mLookX += mSpeedX;
	mLookY += mSpeedY;

	mLookX = CLAMP(mLookX, -30, 70);


	float LOOKX_MIN = 20.0f;
	float SPEED = 0.7f;
	float ZOOM_MAX = 50.0f;

	if (mLookX <= LOOKX_MIN)
		mZoom = ZOOM_MAX + (mLookX - LOOKX_MIN) * SPEED;
	else
		mZoom = ZOOM_MAX;


}

void AbstractCamera::Spring(
	const GSvector3& restPosition,
	float stiffness,
	float friction,
	float mass)
{
	//‚Î‚Ë‚ÌL‚Ñ‹ï‡
	const GSvector3 stretch = pCamera->GetPosition() - restPosition;
	//‚Î‚Ë‚Ì—Í‚ÌŒvŽZ
	const GSvector3 force = -stiffness * stretch;
	//‰Á‘¬“x‚ð’Ç‰Á(—Í/Ž¿—Ê)
	const GSvector3 accelaration = force / mass;
	//ˆÚ“®‘¬“x‚ðŒvŽZ
	mVelocity = friction * (mVelocity + accelaration);

}

void AbstractCamera::LerpAngle(float deltaTime)
{
	if (mLerpTimer < 7.0f)
	{
		float lLerpX = (mLookX - mPrevLookX) / (7.0f - mLerpTimer);
		float lLerpY = (mLookY - mPrevLookY) / (7.0f - mLerpTimer);


		mPrevLookX += lLerpX;
		mLookX = mPrevLookX;
		mPrevLookY += lLerpY;
		mLookY = mPrevLookY;

		mLerpTimer += deltaTime;
	}
}

CameraStateName AbstractCamera::NextState()const
{
	return mNextState;
}
