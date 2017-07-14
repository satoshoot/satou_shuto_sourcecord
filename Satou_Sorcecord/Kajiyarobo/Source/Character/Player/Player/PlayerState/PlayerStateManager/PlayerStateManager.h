#ifndef _PLAYER_STATE_MANAGER_H_
#define _PLAYER_STATE_MANAGER_H_

#include <unordered_map>
#include <gslib.h>

class IWorld;
class AttackID;
class Player;
class Actor;
class GameManager;
class AnimationMesh;
class Move;
class Menu;
enum class PlayerStateName;
class AbstractPlayer;
class PlayerHP;
class Shield;

/*ステートデザインパターン
　プレイヤーの状態を管理する*/

class PlayerStateManager
{
public:
	PlayerStateManager() = default;

	PlayerStateManager(
		IWorld* world,
		AttackID* id,
		Player* player,
		AnimationMesh* animation,
		Move* move,
		Menu* menu,
		PlayerHP* hp,
		Shield* shield,
		GameManager* gameManager);

	void Initialize();

	void Update(float deltaTime);

	void HoldDraw()const;

	void Collide(Actor& other);

	void Shutdown();

	void ChangeState();

	GSvector3 GetVelocity()const;

	GSmatrix4 GetRotate()const;

	PlayerStateName GetCurrentState()const;

private:
	//状態をMapでまとめる
	std::unordered_map<PlayerStateName, AbstractPlayer*> mStateMap;
	//今の状態
	AbstractPlayer* mCurrentPlayer;
	//今の状態の名前
	PlayerStateName mCurrentState;

};

#endif // !_PLAYER_STATE_MANAGER_H_
