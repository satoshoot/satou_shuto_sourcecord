#ifndef _ABSTRACT_PLAYER_H_
#define _ABSTRACT_PLAYER_H_
#include <gslib.h>
class IWorld;
enum class PlayerStateName;
class AttackID;
class Player;
class Actor;
class GameManager;
class AnimationMesh;
class Move;
class Menu;
class PlayerHP;
class Shield;

class AbstractPlayer
{
public:
	AbstractPlayer(
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

	virtual void Update(float deltaTime) = 0;

	virtual void HoldDraw()const = 0;

	virtual void Collide(Actor& other) = 0;

	virtual void Shutdown() = 0;

	//���̏��
	PlayerStateName ChangeState();

	GSvector3 GetVelocity()const;

	GSmatrix4 GetRotate()const;

protected:
	virtual void OnInitialize() = 0;

	void WeponDraw()const;

	void CollideDamage(Actor& other);

	bool Dead();

	//�ړ����̓v���C���[�̌������ړ������ɕς���
	void RotateMove(int reverse);

	//�^�[�Q�b�g�̂ق�������
	void RotateTarget();

	void RotateAttack();
	
	//��L�̂��̂𗼕��s��
	void Rotate();


protected:
	IWorld* pWorld;
	float mCounter;
	PlayerStateName mNextState;
	AttackID* pID;
	Player* pPlayer;
	AnimationMesh* pAnimation;
	Move* pMove;
	Menu* pMenu;
	GameManager* pGameManager;
	GSvector3 mVelocity;
	PlayerHP* pHP;
	Shield* pShield;
	GSmatrix4 mRotate;

};

#endif // !_ABSTRACT_PLAYER_H_
