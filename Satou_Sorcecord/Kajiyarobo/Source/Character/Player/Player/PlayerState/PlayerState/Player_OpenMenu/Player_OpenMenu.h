#ifndef _PLAYER_OPEN_MENU_H_
#define _PLAYER_OPEN_MENU_H_
#include "../../../../AbstractPlayer/AbstractPlayer.h"

class Player_OpenMenu :public AbstractPlayer
{
public:
	Player_OpenMenu(
		IWorld* world,
		Player* player,
		AnimationMesh* animation,
		Move* move,
		Menu* menu,
		PlayerHP* hp,
		Shield* shield,
		GameManager* gameManager);

	virtual void OnInitialize()override;

	virtual void Update(float deltaTime)override;

	virtual void HoldDraw()const override;

	virtual void Collide(Actor& other)override;

	virtual void Shutdown()override;

};

#endif // !_PLAYER_OPEN_MENU_H_
