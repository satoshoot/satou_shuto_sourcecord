#ifndef CAMERA_H_
#define CAMERA_H_
#include "../Actor/Actor.h"
#include "../../Actor/World/IWorld.h"
#include <unordered_map>

class AbstractCamera;
enum class CameraStateName;
class TargetCursor;
class BossHP;

class Camera : public Actor
{
public:
	Camera(IWorld* world, GameManager* gameManager, BossHP* hp);

	virtual void OnUpdate(float deltaTime) override;
	virtual void OnDraw()const override;
	virtual void OnCollide(Actor& other)override;

	GSvector3 GetTargetPosition()const;
	CameraStateName GetCameraState()const;

private:
	std::unordered_map<CameraStateName, AbstractCamera*> mStateMap;
	AbstractCamera* mCurrentCamera;
	CameraStateName mCurrentState;
	TargetCursor* mTargetCursor;

};

#endif // !CAMERA

