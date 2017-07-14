#ifndef _BOSS_STATE_NAME_H_
#define _BOSS_STATE_NAME_H_

enum class BossStateName
{
	Idle,         //�������Ă��Ȃ�
	Roar,         //�Њd���[�V����
	RightRotate,  //�E�ɉ��
	LeftRotate,   //���ɉ��
	Look,         //�v���C���[�̂ق�������
	Landing,      //�W�����v��̒��n
	Jump,         //�W�����v�ړ�
	Down,         //�_�E������
	DownState,    //�_�E����
	Walk,         //�����Ă���
	KnockBack,    //�̂�����
	Wait,         //�������Ȃ�
	Dush,         //�_�b�V��
	MoveRight,    //�E�Ɉړ�
	MoveLeft,     //���Ɉړ�

	/*�U��*/
	Shoot,        //�������U��
	Punch,        //�ߐڍU��
	Fire,         //�L�͈͍U��
	Rush,         //�ːi�U��

	Dead,         //���S

	None,         //�Ȃ�

};

#endif // !_BOSS_STATE_NAME_H_