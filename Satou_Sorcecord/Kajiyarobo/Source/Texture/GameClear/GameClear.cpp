#include "GameClear.h"
#include "../../Utility/Enum/TextureName.h"
#include "../../Character/Boss/Boss/BossHP/BossHP.h"
#include "ClearBack/ClearBack.h"
#include "CharClear/CharClear.h"
#include "Rank/Rank.h"
#include "RankChar/RankChar.h"
#include "../../Utility/Enum/SoundName.h"

GameClear::GameClear(BossHP* hp)
	: pBossHP(hp)
	, nClearBack(new ClearBack())
	, nCharClear(new CharClear())
	, nRank(new Rank())
	, nRankChar(new RankChar())
	, mSize(0.0f, 0.0f)
	, mCounter(0.0f)
	, mPlayTime(0.0f)
{

}

GameClear::~GameClear()
{
	delete nClearBack;
	delete nCharClear;
	delete nRank;
	delete nRankChar;
}

void GameClear::Initialize()
{
	mSize = GSvector2(0.0f, 0.0f);
	mCounter = 60 * 13;
	mPlayTime = 0.0f;
	nClearBack = new ClearBack();
	nCharClear = new CharClear();
	nRank = new Rank();
	nRankChar = new RankChar();
}

void GameClear::Update(float deltaTime, bool dead)
{
	if (dead == false)
	{
		mPlayTime += deltaTime;
		return;
	}

	if (dead == true && mCounter == 60 * 13)
		nRankChar->ClearTime(mPlayTime);
	if (mCounter <= 0)
		pBossHP->QuestEnd();
	if (mCounter <= 60 * 7 && gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_A))
		mCounter = 0;

	if (mCounter == 60 * 7)
	{
		gsPlaySE((GSuint)SoundName::GameClearSE);
		pBossHP->BossEnd();
	}


	nClearBack->Update(deltaTime, mCounter);
	nCharClear->Update(deltaTime, mCounter);
	nRank->Update(deltaTime, mCounter);
	nRankChar->Update(deltaTime, mCounter);


	mCounter -= deltaTime;
}

void GameClear::Draw()const
{
	nClearBack->Draw();
	nCharClear->Draw();
	nRank->Draw();
	nRankChar->Draw();
}

void GameClear::End()
{
	nClearBack = nullptr;
	nCharClear = nullptr;
	nRank = nullptr;
	nRankChar = nullptr;
}