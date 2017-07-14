#include "PlayerHP.h"
#include <gslib.h>
#include "../../../../Utility/Enum/TextureName.h"
#include "../../../../Utility/Enum/SoundName.h"
#include "../../../../Texture/GameOver/GameOver.h"

PlayerHP::PlayerHP()
	: mHP(1000)
	, mHPGauge(1000)
	, mIsGameOver(false)
	, mGameOver(new GameOver(this))
{
	mIDList.clear();
}

PlayerHP::~PlayerHP()
{
	delete mGameOver;
}

void PlayerHP::Update(float deltaTime)
{
	GaugeLength();

	mHP = CLAMP(mHP, 0, 1000);
	mHPGauge = CLAMP(mHPGauge, 0, 1000);

	if (Dead() == true)
		mGameOver->Update(deltaTime);

	if (mIDList.size() >= 10)
		mIDList.pop_front();
}

void PlayerHP::Draw()const
{
	const GSvector2 lPosition(50.0f, 50.0f);
	const GSrect lRect(0.0f, 0.0f, 350.0f, 60.0f);
	gsDrawSprite2D(
		(GSuint)TextureName::PlayerIcon, &lPosition, &lRect, NULL, NULL, NULL, 0.0f);

	const GSvector2 lGaugePosition = lPosition + GSvector2(93.0f, 15.0f);
	const GSrect lGaugeRect(0.0f, 0.0f, mHPGauge / 4, 30.0f);
	gsDrawSprite2D(
		(GSuint)TextureName::HPGauge, &lGaugePosition, &lGaugeRect, NULL, NULL, NULL, 0.0f);

	mGameOver->Draw();
}

bool PlayerHP::Damage(const int& damage, const int& id)
{
	for (IDList::iterator i = mIDList.begin(); i != mIDList.end(); i++)
	{
		if (*i == id)
			return false;
	}

	gsPlaySE((GSuint)SoundName::Damage);

	mIDList.push_back(id);
	mHP -= damage;
	return true;
}

void PlayerHP::Recovery()
{
	mHP += 700;
	gsPlaySE((GSuint)SoundName::RecoverySE);
}

bool PlayerHP::Dead()
{
	if (mHPGauge <= 0)
		return true;

	return false;
}

void PlayerHP::GaugeLength()
{
	int lHP = mHP - mHPGauge;
	if (lHP <= 10 && lHP >= -10)
	{
		mHPGauge = mHP;
		return;
	}
	if (mHPGauge <= mHP)
	{
		mHPGauge += 5;
		return;
	}
	if (mHPGauge >= mHP)
	{
		mHPGauge -= 5;
		return;
	}
}

void PlayerHP::GameOverEnd()
{
	mIsGameOver = true;
}

bool PlayerHP::IsGameOver()
{
	return mIsGameOver;
}