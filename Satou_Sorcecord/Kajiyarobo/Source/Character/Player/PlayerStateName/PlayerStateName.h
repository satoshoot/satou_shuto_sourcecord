#ifndef _PLAYER_STATE_NAME_H_
#define _PLAYER_STATE_NAME_H_


enum class PlayerStateName
{
	Normal,             //�ʏ���
	LockOn,             //���b�N�I�����

	SwordDushAttack,    //���_�b�V���U��
	SwordFirstAttack,   //���U��1
	SwordSecondAttack,  //���U��2
	SwordThirdAttack,   //���U��3
	SwordFourthAttack,  //���U��4
	SwordFifthAttack,   //���U��5

	SpearDushAttack,    //���_�b�V���U��
	SpearFirstAttack,   //���U��1
	SpearSecondAttack,  //���U��2
	SpearThirdAttack,   //���U��3
	SpearFourthAttack,  //���U��4

	ShootNormal,        //�e�������Ă����Ԃ̒ʏ���
	ShootLockOn,        //�e�ł̃��b�N�I�����
	Shoot,              //�e������
	ShootRapid,         //�e���\���Ȃ���ړ�
	ShootCannon,        //�e�̖C��
	ShootKnockBack,     //�e�����������̍d��

	Guard,              //�h����
	GuardBreak,         //�h���̍d��
	Stun,               //�U�����󂯂����
	Fly,                //�U�����󂯂Đ�����΂��ꂽ���
	OpenMenu,           //���j���[���J���Ă�����
	Make,               //���������Ă�����
	Ally,               //�����L�����𑀍삵�Ă�����
	Dead,               //���񂾏��


	None,               //�Ȃ�
};

#endif // !_PLAYER_STATE_NAME_H_