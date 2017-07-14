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

	//X²‚Ì‰ñ“]‚·‚é‘å‚«‚³‚ğæ“¾
	float GetPitchAngle()const;

	//Y²‚Ì‰ñ“]‚·‚é‘å‚«‚³‚ğæ“¾
	float GetYawAngle()const;

	//‘O‚Ìó‘Ô‚ÌŠp“x‚ğİ’è
	void SetCurrentAngle(float& pitch, float& yaw);

	//ˆÚ“®—Í‚ğæ“¾
	GSvector3 GetVelocity()const;

	//Ÿ‚Ìó‘Ô‚ğæ“¾
	CameraStateName NextState()const;

protected:
	//ƒJƒƒ‰‚ğ‰ñ“]‚³‚¹‚é
	void Rotate();

	//‚Î‚Ë
	void Spring(
		const GSvector3& restPosition,
		float stiffness,
		float friction,
		float mass
		);

	//ƒJƒƒ‰‚ğ•ÏX‚µ‚½‚Æ‚«‚É™X‚ÉŸ‚ÌˆÊ’u‚ÉˆÚ“®‚³‚¹‚é
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
	float mLookY;  //y²‚Ì‰ñ“]
	float mLookX;  //x²‚Ì‰ñ“]
	float mPrevLookX;
	float mPrevLookY;


private:
	float mSpeedY;//y²‚Ì‰ñ“]‚·‚é‘å‚«‚³
	float mSpeedX;//x²‚Ì‰ñ“]‚·‚é‘å‚«‚³
	float mLerpTimer;//Ÿ‚ÌˆÊ’u‚ÉˆÚ“®‚·‚é‚Ü‚Å‚ÌŠÔ

};

#endif // !_ABSTRACT_CAMERA_H_
