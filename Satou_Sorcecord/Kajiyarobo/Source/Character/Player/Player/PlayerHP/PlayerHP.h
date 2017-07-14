#ifndef _PLAYER_HP_H_
#define _PLAYER_HP_H_
#include <list>

class GameOver;

class PlayerHP
{
public:
	PlayerHP();
	~PlayerHP();
	/*更新*/
	void Update(float deltaTime);
	/*描画*/
	void Draw()const;
	/*HPを減らす*/
	bool Damage(const int& damage, const int& id);

	/*HP回復*/
	void Recovery();
	/*死亡した*/
	bool Dead();

	/*ゲームオーバーにする*/
	void GameOverEnd();
	/*ゲームオーバーか？*/
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
