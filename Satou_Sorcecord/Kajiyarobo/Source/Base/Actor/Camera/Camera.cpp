#include "Camera.h"
#include "../Actor/ActorManager/ActorGroup.h"
#include "../../GameManager/GameManager.h"
#include "../../../Utility/Math/Math.h"
#include "CameraStateName/CameraStateName.h"
#include "CameraState/Camera_PlayerNormal/Camera_PlayerNormal.h"
#include "CameraState/Camera_PlayerLockon/Camera_PlayerLockon.h"
#include "CameraState/Camera_GameClear/Camera_GameClear.h"
#include "TargetCursor/TargetCursor.h"
#include<iostream>

Camera::Camera(IWorld* world, GameManager* gameManager, BossHP* hp)
	: Actor(world, "Camera", { 0.0f,0.0f,-280.0f }, BoundingSphere(0.0f), gameManager)
	, mCurrentCamera(nullptr)
	, mCurrentState(CameraStateName::PlayerNormal)
	, mTargetCursor(nullptr)
{
	mStateMap.clear();
	mStateMap[CameraStateName::PlayerNormal] = new Camera_PlayerNormal(world, this, hp);
	mStateMap[CameraStateName::PlayerLockon] = new Camera_PlayerLockon(world, this, hp);
	mStateMap[CameraStateName::GameClear] = new Camera_GameClear(world, this);

	mCurrentCamera = mStateMap[mCurrentState];

	ActorPtr lTargetCursor = new_Actor<TargetCursor>(world, gameManager, this);
	m_World->AddActor(ActorGroup::Effect, lTargetCursor);
	mTargetCursor = dynamic_cast<TargetCursor*>(lTargetCursor.get());

}

void Camera::OnUpdate(float deltaTime)
{

	mCurrentCamera->Update(deltaTime);

	m_Rotate.identity();

	if (mCurrentCamera->NextState() != CameraStateName::None)
	{
		//今の状態の角度
		float lPitch = mCurrentCamera->GetPitchAngle();
		float lYaw = mCurrentCamera->GetYawAngle();

		mCurrentCamera->Shutdown();
		mCurrentState = mCurrentCamera->NextState();
		mCurrentCamera = mStateMap[mCurrentState];
		mCurrentCamera->Initialize();
		mTargetCursor->Initialize();
		//前の状態の角度をセット
		mCurrentCamera->SetCurrentAngle(lPitch, lYaw);
	}

	m_Rotate.rotateX(mCurrentCamera->GetPitchAngle());
	m_Rotate.rotateY(mCurrentCamera->GetYawAngle());

	m_Position += mCurrentCamera->GetVelocity();


	mTargetCursor->SetState(mCurrentState);
	mTargetCursor->Update(deltaTime);

	//状態変化受付
	mCurrentCamera->Change();

}

void Camera::OnDraw()const
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(50.0f, 640.0f / 480.0f, 0.1f, 1200.0f);

	glMatrixMode(GL_MODELVIEW);

	GSmatrix4 lPose = GSmatrix4(GetRotate().setPosition(m_Position));
	glLoadMatrixf(lPose.convertViewRH());

}

void Camera::OnCollide(Actor& other)
{

}

GSvector3 Camera::GetTargetPosition()const
{
	return mCurrentCamera->GetTargetPosition();
}

CameraStateName Camera::GetCameraState()const
{
	return mCurrentState;
}

