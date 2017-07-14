#ifndef _CAMERA_PLAYER_NORMAL_H_
#define _CAMERA_PLAYER_NORMAL_H_

#include "../../AbstractCamera/AbstractCamera.h"

class Camera_PlayerNormal :public AbstractCamera
{
public:
	Camera_PlayerNormal(IWorld* world, Camera* camera, BossHP* hp);

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual GSvector3 GetTargetPosition()const override;

	virtual void Shutdown()override;

protected:
	virtual void OnInitialize()override;


};

#endif // !_CAMERA_PLAYER_NORMAL_H_
