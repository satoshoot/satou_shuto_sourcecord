#ifndef _CAMERA_PLAYER_LOCKON_H_
#define _CAMERA_PLAYER_LOCKOM_H_

#include "../../AbstractCamera/AbstractCamera.h"
#include <string>


class Camera_PlayerLockon :public AbstractCamera
{
public:
	Camera_PlayerLockon(IWorld* world, Camera* camera, BossHP* hp);


	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual GSvector3 GetTargetPosition()const override;

	virtual void Shutdown()override;

protected:
	virtual void OnInitialize()override;

private:
	std::string mTargetName;

};

#endif // !_CAMERA_PLAYER_LOCKON_H_
