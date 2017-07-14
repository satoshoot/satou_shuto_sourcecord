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

	//X���̉�]����傫�����擾
	float GetPitchAngle()const;

	//Y���̉�]����傫�����擾
	float GetYawAngle()const;

	//�O�̏�Ԃ̊p�x��ݒ�
	void SetCurrentAngle(float& pitch, float& yaw);

	//�ړ��͂��擾
	GSvector3 GetVelocity()const;

	//���̏�Ԃ��擾
	CameraStateName NextState()const;

protected:
	//�J��������]������
	void Rotate();

	//�΂�
	void Spring(
		const GSvector3& restPosition,
		float stiffness,
		float friction,
		float mass
		);

	//�J������ύX�����Ƃ��ɏ��X�Ɏ��̈ʒu�Ɉړ�������
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
	float mLookY;  //y���̉�]
	float mLookX;  //x���̉�]
	float mPrevLookX;
	float mPrevLookY;


private:
	float mSpeedY;//y���̉�]����傫��
	float mSpeedX;//x���̉�]����傫��
	float mLerpTimer;//���̈ʒu�Ɉړ�����܂ł̎���

};

#endif // !_ABSTRACT_CAMERA_H_
