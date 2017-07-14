#ifndef _CAMERA_GAMECLEAR_H_
#define _CAMERA_GAMECLEAR_H_
#include "../../AbstractCamera/AbstractCamera.h"

class BossHP;

class Camera_GameClear :public AbstractCamera
{
public:
	Camera_GameClear(IWorld* world, Camera* camera);

	virtual void OnInitialize()override;

	virtual void OnUpdate(float deltaTime)override;

	virtual void Change()override;

	virtual GSvector3 GetTargetPosition()const override;

	virtual void Shutdown()override;

public:
	BossHP* pBossHP;

};


#endif // !_CAMERA_GAMECLEAR_H_
