#ifndef _BOSS_HP_H_
#define _BOSS_HP_H_

#include "../../../../Texture/GameClear/GameClear.h"

//ボスのHPを管理する
class BossHP
{
public:
	BossHP();
	~BossHP();

	void Start(int hp);

	void Update(float deltaTime);

	void Draw()const;

	void End();

	//与えられたダメージ
	void Damage(int damage);

	//今のHPを返す
	int GetHP()const;

	bool KnockBack();
	//スタンさせる
	bool Stun();
	//死亡させる
	bool Dead()const;
	//ゲームクリア
	bool QuestClear();
	//ゲームクリアさせる
	void QuestEnd();
	//ボスの死亡演出の終了を取得
	bool IsBossEnd();
	//ボスの死亡演出の終了
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
