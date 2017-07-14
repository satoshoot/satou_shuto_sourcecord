#ifndef GAME_TITLE_SCENE_H_
#define GAME_TITLE_SCENE_H_
#include "../IScene.h"
#include "../../../../Texture/GameTitle/BackGround/BackGround.h"
#include "../../../../Texture/GameTitle/TitleTextureManager/TitleTextureManager.h"
#include <list>

class GameManager;

class GameTitleScene : public IScene {
public:
	GameTitleScene(GameManager& gameManager);

	virtual ~GameTitleScene();

	virtual void Start() override;

	virtual void Update(float time) override;

	virtual void Draw() const override;

	virtual bool isEnd() const override;

	virtual Scene Next() const override;

	virtual void End() override;

private:
	GameManager* p_GameManager;
	float m_Timer;
	BackGround nBackGround;
	TitleTextureManager m_TextureManager;
	bool isEnd_;
	bool mTitleEnd;

};
#endif