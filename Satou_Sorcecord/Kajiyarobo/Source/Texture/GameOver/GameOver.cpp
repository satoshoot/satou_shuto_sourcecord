#include "GameOver.h"
#include "../../Utility/Enum/TextureName.h"
#include "../../Character/Player/Player/PlayerHP/PlayerHP.h"
#include "../../Utility/Enum/SoundName.h"
#include <gslib.h>
#include <GSmusic.h>

GameOver::GameOver(PlayerHP* hp)
	: mAlpha(0)
	, mCounter(60 * 7)
	, pHP(hp)
{

}

void GameOver::Update(float deltaTime)
{
	if (mCounter == 60 * 4)
	{
		gsStopMusic();
		gsBindMusic((GSuint)SoundName::GameOverBGM);
	}

	if (mCounter <= 60 * 4)
		mAlpha += 0.008f * deltaTime;
	if (mCounter <= 0)
		pHP->GameOverEnd();

	mCounter -= deltaTime;
}

void GameOver::Draw()const
{
	GSrect lRect(0.0f, 0.0f, 1400.0f, 960.0f);
	GScolor lColor(1.0f, 1.0f, 1.0f, mAlpha);

	gsDrawSprite2D(
		(GSuint)TextureName::GameOver,
		&GSvector2(0.0f, 0.0f),
		&lRect,
		NULL,
		&lColor,
		NULL,
		0.0f
		);
}