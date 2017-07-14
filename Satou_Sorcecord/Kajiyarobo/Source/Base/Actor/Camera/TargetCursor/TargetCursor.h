#ifndef _TARGET_CURSOR_H_
#define _TARGET_CURSOR_H_
#include <gslib.h>

#include "../../Actor/Actor.h"
class Camera;
enum class CameraStateName;

class TargetCursor :public Actor
{
public:
	TargetCursor(IWorld* world, GameManager* gameManager, Camera* camera);

	void Initialize();

	void Update(float deltaTime);

	virtual void OnDraw()const override;

	void SetState(CameraStateName& state);

private:
	Camera* pCamera;
	float mAngle;
	CameraStateName mCameraState;
	float mSize;

};

#endif // !_TARGET_CURSOR_H_
