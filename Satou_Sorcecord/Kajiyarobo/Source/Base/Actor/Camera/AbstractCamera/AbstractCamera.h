#ifndef _ABSTRACT_CAMERA_H_
#define _ABSTRACT_CAMERA_H_

#include <gslib.h>

class IWorld;
enum class CameraStateName;
class Camera;
class BossHP;

class AbstractCamera
{
public:
	AbstractCamera(IWorld* world, Camera* camera, BossHP* hp);

	virtual void Initialize();

	virtual void Update(float deltaTime);

	virtual void Change() = 0;

	virtual GSvector3 GetTargetPosition()const = 0;

	virtual void Shutdown() = 0;

	//X軸の回転する大きさを取得
	float GetPitchAngle()const;

	//Y軸の回転する大きさを取得
	float GetYawAngle()const;

	//前の状態の角度を設定
	void SetCurrentAngle(float& pitch, float& yaw);

	//移動力を取得
	GSvector3 GetVelocity()const;

	//次の状態を取得
	CameraStateName NextState()const;

protected:
	//カメラを回転させる
	void Rotate();

	//ばね
	void Spring(
		const GSvector3& restPosition,
		float stiffness,
		float friction,
		float mass
		);

	//カメラを変更したときに徐々に次の位置に移動させる
	void LerpAngle(float deltaTime);

	bool BossDead();

	virtual void OnInitialize() = 0;

	virtual void OnUpdate(float deltaTime) = 0;

protected:
	IWorld* pWorld;
	Camera* pCamera;
	BossHP* pBossHP;

	GSvector3 mVelocity;
	CameraStateName mNextState;
	float mZoom;
	float mLookY;  //y軸の回転
	float mLookX;  //x軸の回転
	float mPrevLookX;
	float mPrevLookY;


private:
	float mSpeedY;//y軸の回転する大きさ
	float mSpeedX;//x軸の回転する大きさ
	float mLerpTimer;//次の位置に移動するまでの時間

};

#endif // !_ABSTRACT_CAMERA_H_
