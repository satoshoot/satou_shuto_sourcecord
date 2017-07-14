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

/*�X�e�[�g�f�U�C���p�^�[��
�@�v���C���[�̏�Ԃ��Ǘ�����*/

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
	//��Ԃ�Map�ł܂Ƃ߂�
	std::unordered_map<PlayerStateName, AbstractPlayer*> mStateMap;
	//���̏��
	AbstractPlayer* mCurrentPlayer;
	//���̏�Ԃ̖��O
	PlayerStateName mCurrentState;

};

#endif // !_PLAYER_STATE_MANAGER_H_
