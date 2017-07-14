#ifndef _PLAYER_DEAD_H_
#define _PLAYER_DEAD_H_
#include "../../../../AbstractPlayer/AbstractPlayer.h"


class Player_Dead :public AbstractPlayer
{
public:
	Player_Dead(Player* player, AnimationMesh* mesh, GameManager* gameManager);

	virtual void OnInitialize()override;

	virtual void Update(float deltaTime)override;

	virtual void HoldDraw()const override;

	virtual void Collide(Actor& other)override;

	virtual void Shutdown()override;


};


#endif // !_PLAYER_DEAD_H_
