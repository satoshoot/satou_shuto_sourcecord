#ifndef _GAME_OVER_H_
#define _GAME_OVER_H_

class PlayerHP;

class GameOver
{
public:
	GameOver(PlayerHP* hp);

	void Update(float deltaTime);

	void Draw()const;

private:
	float mAlpha;
	float mCounter;

	PlayerHP* pHP;

};

#endif // !_GAME_OVER_H_
