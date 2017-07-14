#ifndef _ENEMYSHOT_H_
#define _ENEMYSHOT_H_
#include "../../../Base/Actor/Actor/Actor.h"

class IWorld;

class DogShot :public Actor
{
public:
	DogShot(
		const GSvector3& direction,
		IWorld* world,
		GSvector3 position,
		int& id,
		GameManager* gameManager);

	virtual void OnUpdate(float time)override;

	virtual void OnDraw() const override;
	virtual void OnCollide(Actor& other)override;


public:
	void SetPlayerRotate(const GSmatrix4 matrix);

private:
	void HitGround();

private:
	GSmatrix4 mPlayerRotate;
	float mAnimationTimer;
	int deadCount;
	GSvector3 left;
	GSvector3 up;
	GSvector3 front;

};

#endif // !_ENEMYSHOT_H_
