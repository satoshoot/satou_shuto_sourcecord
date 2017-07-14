#include "Item.h"
#include "../ItemName/ItemName.h"
#include "../../Character/Player/Player/PlayerHP/PlayerHP.h"
#include "../Shield/Shield.h"
#include "../../Utility/Enum/SoundName.h"

Item::Item(PlayerHP* hp, Shield* shield)
	: pHP(hp)
	, pShield(shield)
	, mCurrentItem()
	, mCounter(0)
{

}

void Item::Update(float deltaTime)
{
	if (mCounter <= 0)
		mCurrentItem = ItemName::None;

	mCounter -= deltaTime;
}

float Item::PowerUp()const
{
	if (mCurrentItem == ItemName::PowerUp)
		return 1.5f;

	return 1.0f;
}

void Item::ItemEffect(const ItemName& name)
{
	if (name == ItemName::Recovery)
	{
		pHP->Recovery();
		return;
	}
	if (name == ItemName::Shield)
	{
		pShield->UseItem();
		gsPlaySE((GSuint)SoundName::ShieldSE);
		return;
	}
	if (name == ItemName::None)
		return;

	gsPlaySE((GSuint)SoundName::PowerUPSE);
	mCurrentItem = name;
	mCounter = 60 * 60;
}