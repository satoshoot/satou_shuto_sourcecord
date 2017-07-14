#include "WeponParameter.h"
#include "../WeponName/WeponName.h"
#include "../../Utility/Enum/MeshName.h"
#include "../WeponType/WeponType.h"
#include "../../Utility/Enum/TextureName.h"
#include "../WeponSpecialSkill/WeponSpecialSkill.h"
#include "../Wepon/Wepon.h"

//武器をセット
void WeponParameter::SetWepon(
	WeponName& name, MeshName& mesh, WeponType& type, TextureName& texture, TextureName& ability,
	WeponSpecialSkill& special, int& power, int& skill, int& range)
{
	switch (name)
	{
		/*******  剣　*******/
	case WeponName::IronSword:
		mesh = MeshName::IronSword;
		type = WeponType::Sword;
		texture = TextureName::IronSword;
		ability = TextureName::CharIronSword;
		special = WeponSpecialSkill::None;
		power = 100;
		skill = 2;
		range = 2;
		break;
	case WeponName::LongSword:
		mesh = MeshName::LongSword;
		type = WeponType::Sword;
		texture = TextureName::LongSword;
		ability = TextureName::CharLongSword;
		special = WeponSpecialSkill::None;
		power = 120;
		skill = 1;
		range = 4;
		break;
	case WeponName::Flamberge:
		mesh = MeshName::Flamberge;
		type = WeponType::Sword;
		texture = TextureName::Flamberge;
		ability = TextureName::CharFlamberge;
		special = WeponSpecialSkill::None;
		power = 150;
		skill = 2;
		range = 3;
		break;
	case WeponName::GreatSword:
		mesh = MeshName::GreatSword;
		type = WeponType::Sword;
		texture = TextureName::GreatSword;
		ability = TextureName::CharGreatSword;
		special = WeponSpecialSkill::None;
		power = 110;
		skill = 5;
		range = 3;
		break;

		/*******  槍  *******/
	case WeponName::IronSpear:
		mesh = MeshName::IronSpear;
		type = WeponType::Spear;
		texture = TextureName::IronSpear;
		ability = TextureName::CharIronSpear;
		special = WeponSpecialSkill::None;
		power = 60;
		skill = 1;
		range = 3;
		break;
	case WeponName::Partisan:
		mesh = MeshName::Partisan;
		type = WeponType::Spear;
		texture = TextureName::Partisan;
		ability = TextureName::CharPartisan;
		special = WeponSpecialSkill::None;
		power = 100;
		skill = 1;
		range = 5;
		break;
	case WeponName::Otegine:
		mesh = MeshName::Otegine;
		type = WeponType::Spear;
		texture = TextureName::Otegine;
		ability = TextureName::CharOtegine;
		special = WeponSpecialSkill::None;
		power = 120;
		skill = 2;
		range = 3;
		break;
	case WeponName::Vajyuranda:
		mesh = MeshName::Vajyuranda;
		type = WeponType::Spear;
		texture = TextureName::Vajyuranda;
		ability = TextureName::CharVajyuranda;
		special = WeponSpecialSkill::None;
		power = 90;
		skill = 3;
		range = 2;
		break;

		/*******  銃  *******/
	case WeponName::IronGun:
		mesh = MeshName::IronGun;
		type = WeponType::Gun;
		texture = TextureName::IronGun;
		ability = TextureName::CharIronGun;
		special = WeponSpecialSkill::None;
		power = 14;
		skill = 3;
		range = 3;
		break;
	case WeponName::Vulcan:
		mesh = MeshName::Vulcan;
		type = WeponType::Gun;
		texture = TextureName::Vulcan;
		ability = TextureName::CharVulcan;
		special = WeponSpecialSkill::None;
		power = 14;
		skill = 4;
		range = 1;
		break;
	case WeponName::LaserGun:
		mesh = MeshName::LaserGun;
		type = WeponType::Gun;
		texture = TextureName::LaserGun;
		ability = TextureName::CharLaserGun;
		special = WeponSpecialSkill::IceLaser;
		power = 4;
		skill = 5;
		range = 1;
		break;
	case WeponName::Cannon:
		mesh = MeshName::Cannon;
		type = WeponType::Gun;
		texture = TextureName::Cannon;
		ability = TextureName::CharCannon;
		special = WeponSpecialSkill::None;
		power = 20;
		skill = 3;
		range = 2;
		break;
	case WeponName::None:
		mesh = MeshName::None;
		type = WeponType::None;
		texture = TextureName::Icon;
		ability = TextureName::None;
		special = WeponSpecialSkill::None;
		power = 0;
		skill = 0;
		range = 0;
		break;
	}
}

TextureName WeponParameter::GetAbillity(WeponName weponName)
{
	Wepon l_Result;
	l_Result.SetWepon(weponName);
	return l_Result.GetAbilityTexture();
}

int WeponParameter::GetPower(WeponName weponName)
{
	Wepon l_Result;
	l_Result.SetWepon(weponName);
	return l_Result.GetPower();
}
