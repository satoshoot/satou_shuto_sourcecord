#ifndef _PLAYER_HP_H_
#define _PLAYER_HP_H_
#include <list>

class GameOver;

class PlayerHP
{
public:
	PlayerHP();
	~PlayerHP();
	/*�X�V*/
	void Update(float deltaTime);
	/*�`��*/
	void Draw()const;
	/*HP�����炷*/
	bool Damage(const int& damage, const int& id);

	/*HP��*/
	void Recovery();
	/*���S����*/
	bool Dead();

	/*�Q�[���I�[�o�[�ɂ���*/
	void GameOverEnd();
	/*�Q�[���I�[�o�[���H*/
	bool IsGameOver();

private:
	void GaugeLength();

private:
	using IDList = std::list<int>;
	IDList mIDList;

	GameOver* mGameOver;
	int mHP;
	int mHPGauge;
	bool mIsGameOver;

};

#endif // !_PLAYER_HP_H_
