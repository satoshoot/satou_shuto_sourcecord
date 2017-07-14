#ifndef PLAYER_H_
#define PLAYER_H_
#include "../../../Base/Actor/Actor/Actor.h"
#include "PlayerState/PlayerStateManager/PlayerStateManager.h"
#include "../../../Item/Item/Item.h"

#include <memory>

class AnimationMesh;
class Move;
class Menu;
class PlayerStateManager;
class AttackID;
class PlayerHP;
class Item;
class Shield;

class Player : public Actor
{
public:
	Player(IWorld& world, GSvector3 position, GameManager& gameManager,
		Move& move, AttackID& id, Menu& menu, PlayerHP* hp);

	~Player();

	virtual void OnUpdate(float time) override;
	virtual void OnDraw() const override;
	virtual void OnCollide(Actor& other)override;

	int Damage()const;

private:
	void HitField();

private:
	using AnimationPtr = std::shared_ptr<AnimationMesh>;
	AnimationPtr mAnimation;
	PlayerStateManager m_State;

	Menu* p_Menu;
	Move* p_Move;
	Item  m_Item;

	const float CENTER = 1.5f;
};

#endif // !PLAYER_H_