#ifndef GAMEFRAME_H_
#define GAMEFRAME_H_
//#include<GSgame.h>
#include "Game.h"
#include "../Actor/Scene/SceneManager/SceneManager.h"
#include "../Actor/Actor/ActorManager/ActorManager.h"

class GameManager;

class GameFrame : public gslib::Game
{
public:
	GameFrame();
	~GameFrame();

private:
	// 開始
	virtual void start() override;
	// 更新
	virtual void update(float time) override;
	// 描画
	virtual void draw() override;
	// 終了
	virtual void end() override;

private:
	SceneManager* sceneManager_;
	GameManager* p_GameManager;
	int m_Timer;
};

#endif // ! GAMEFRAME_H_

