#ifndef _ABSTRACT_BOSS_H_
#define _ABSTRACT_BOSS_H_
#include <gslib.h>

enum class BossStateName;
enum class BossTarget;
class Actor;
class AnimationMesh;
class IWorld;
class BossHP;
class AttackID;

class AbstractBoss
{
public:
	AbstractBoss(IWorld* world, Actor* boss, AnimationMesh* animation, BossHP* hp, AttackID* id);

	void Initialize();

	void Update(float deltaTime);

	virtual void Change() = 0;

	virtual void Shutdown() = 0;

	BossStateName NextState()const;

	GSvector3 GetVelocity()const;

	float GetRotateAngle()const;

	BossTarget GetTarget()const;

	void SetTarget(BossTarget& target);

private:
	/*�{�X���v���C���[�Ɍ����܂ł̊p�x*/
	float PlayerAngle()const;
	/*�ړ�����ʒu�܂ł̊p�x*/
	float MovePositionAngle()const;

protected:
	virtual void OnInitialize() = 0;

	virtual void OnUpdate(float deltaTime) = 0;

	/*�{�X���^�[�Q�b�g�����L�����������܂ł̊p�x*/
	float TargetAngle()const;

	bool BossKnockBack()const;
	bool BossDown();

	bool Dead();

	GSvector3 TargetPosition();

protected:
	IWorld* pWorld;
	Actor* pBoss;
	AnimationMesh* pAnimation;
	BossHP* pBossHP;
	AttackID* pID;

	BossStateName mNextState;
	GSvector3 mVelocity;
	float mCounter;
	BossTarget mTarget;
	float mRotateAngle;
	GSvector3 mMovePosition;   //�ړ�����ʒu

};

#endif // !_ABSTRACT_BOSS_H_