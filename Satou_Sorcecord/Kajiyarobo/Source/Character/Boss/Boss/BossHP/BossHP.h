#ifndef _BOSS_HP_H_
#define _BOSS_HP_H_

#include "../../../../Texture/GameClear/GameClear.h"

//�{�X��HP���Ǘ�����
class BossHP
{
public:
	BossHP();
	~BossHP();

	void Start(int hp);

	void Update(float deltaTime);

	void Draw()const;

	void End();

	//�^����ꂽ�_���[�W
	void Damage(int damage);

	//����HP��Ԃ�
	int GetHP()const;

	bool KnockBack();
	//�X�^��������
	bool Stun();
	//���S������
	bool Dead()const;
	//�Q�[���N���A
	bool QuestClear();
	//�Q�[���N���A������
	void QuestEnd();
	//�{�X�̎��S���o�̏I�����擾
	bool IsBossEnd();
	//�{�X�̎��S���o�̏I��
	void BossEnd();

private:
	GameClear m_GameClear;

	int  m_HP;
	int  m_MaxHP;
	bool m_StunEnd;
	bool m_KnockBack;
	bool m_BossEnd;
	bool m_QuestClear;

};

#endif // !_BOSS_HP_H_
