#ifndef _SHIELD_H_
#define _SHIELD_H_

#include "../../Base/Actor/Actor/Actor.h"

class Player;

class Shield :public Actor
{
public:
	Shield(Player* player);

	virtual void OnUpdate(float deltaTime)override;

	virtual void OnDraw()const override;

	virtual void OnCollide(Actor& other)override;

	//シールドを使う
	void UseItem();

	//防御しているか
	bool Guard()const;

	void Hit();

private:
	Player* pPlayer;

	bool mGuard;
	float mAngle;

};

#endif // !_SHIELD_H_
