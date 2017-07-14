#include"GameManager.h"
#include "../../Utility/Math/Math.h"
#include "../../Wepon/Wepon/Wepon.h"
#include "../../Utility/Enum/MeshName.h"
#include "../../Wepon/WeponName/WeponName.h"
#include "../../Wepon/WeponType/WeponType.h"
#include "../../Utility/Renderer/Renderer.h"
#include "../../Utility/Enum/TextureName.h"
#include "../../Menu/Menu/Menu.h"
#include "../../Menu/MenuStateName/MenuStateName.h"
#include "../../Utility/Music/Music.h"
#include "../../Utility/Enum/SoundName.h"
#include "../../Utility/Enum/EffectName.h"
#include "../../Screen/Screen.h"
#include <GSeffect.h>


GameManager::GameManager()
	: mRenderer(new Renderer())
	, mMusic(new Music())
	, mPlayerWepon(0)
{
	NewWepon();
}

GameManager::~GameManager()
{
	delete mRenderer;
	delete mMusic;
}

//リソースの読み込み
void GameManager::LoadContent()
{
	//モデルの読み込み
	mRenderer->LoadModel(MeshName::Player, "Resource/Player/Robot.msh", "Resource/Player/Robot.skl");
	mRenderer->LoadModel(MeshName::Dog, "Resource/Dog/Dog.msh", "Resource/Dog/Dog.skl");
	mRenderer->LoadModel(MeshName::Kremlin, "Resource/Boss/Kremlin/Kremlin.msh", "Resource/Boss/Kremlin/Kremlin.skl");

	//メッシュの読み込み
	mRenderer->LoadMesh(MeshName::SkyBox, "Resource/SkyBox/SkyBox.msh");
	mRenderer->LoadMesh(MeshName::Wall, "Resource/Floor/Sea.msh");
	mRenderer->LoadMesh(MeshName::Helmet, "Resource/Ally/pikopiko.msh");
	mRenderer->LoadMesh(MeshName::Hummer, "Resource/MakeItem/Hammer.msh");
	mRenderer->LoadMesh(MeshName::MakeWepon, "Resource/MakeItem/MakeWepon.msh");
	mRenderer->LoadMesh(MeshName::Shield, "Resource/Item/Shield.msh");



	/***敵の弾***/
	mRenderer->LoadMesh(MeshName::DogShot, "Resource/Dog/DogShot.msh");
	mRenderer->LoadMesh(MeshName::MeteorBullet, "Resource/EnemyAttack/KremlinShot.msh");

	/***剣***/
	mRenderer->LoadMesh(MeshName::IronSword, "Resource/Weapon/Sword/IronSword.msh");
	mRenderer->LoadMesh(MeshName::LongSword, "Resource/Weapon/Sword/LongSword.msh");
	mRenderer->LoadMesh(MeshName::Flamberge, "Resource/Weapon/Sword/Flamberge.msh");
	mRenderer->LoadMesh(MeshName::GreatSword, "Resource/Weapon/Sword/GreatSword.msh");

	/***槍***/
	mRenderer->LoadMesh(MeshName::IronSpear, "Resource/Weapon/Spear/IronSpear.msh");
	mRenderer->LoadMesh(MeshName::Partisan, "Resource/Weapon/Spear/Partisan.msh");
	mRenderer->LoadMesh(MeshName::Otegine, "Resource/Weapon/Spear/Otegine.msh");
	mRenderer->LoadMesh(MeshName::Vajyuranda, "Resource/Weapon/Spear/Vajyuranda.msh");

	/***銃***/
	mRenderer->LoadMesh(MeshName::IronGun, "Resource/Weapon/Gun/IronCannon.msh");
	mRenderer->LoadMesh(MeshName::Vulcan, "Resource/Weapon/Gun/Vulcan.msh");
	mRenderer->LoadMesh(MeshName::LaserGun, "Resource/Weapon/Gun/LaserGun.msh");
	mRenderer->LoadMesh(MeshName::Cannon, "Resource/Weapon/Gun/Cannon.msh");

	/***弾***/
	mRenderer->LoadMesh(MeshName::SpeedBullet, "Resource/Weapon/Bullet/SpeedBullet.msh");
	mRenderer->LoadMesh(MeshName::Laser, "Resource/Weapon/Bullet/Laser.msh");
	mRenderer->LoadMesh(MeshName::RapidBullet, "Resource/Weapon/Bullet/RapidBullet.msh");

	//アニメーションの読み込み
	mRenderer->LoadAnimation(MeshName::Player, "Resource/Player/Robot.anm");
	mRenderer->LoadAnimation(MeshName::Dog, "Resource/Dog/Dog.anm");
	mRenderer->LoadAnimation(MeshName::Kremlin, "Resource/Boss/Kremlin/Kremlin.anm");

	//２Dリソースの読み込み
	mRenderer->LoadTexture(TextureName::Target, "Resource/Sprite/Target.png");
	mRenderer->LoadTexture(TextureName::Fire, "Resource/Sprite/Fire.png");
	mRenderer->LoadTexture(TextureName::Particle, "Resource/Sprite/Particle.png");

	mRenderer->LoadTexture(TextureName::Make, "Resource/Texture/Make/Make.png");
	mRenderer->LoadTexture(TextureName::MakeBack, "Resource/Texture/Make/MakeBack.png");
	mRenderer->LoadTexture(TextureName::MenuSupport, "Resource/Texture/Make/MenuSupport.png");

	mRenderer->LoadTexture(TextureName::CharMake, "Resource/Texture/MakeSupport/CharMake.png");
	mRenderer->LoadTexture(TextureName::CharUpGrade, "Resource/Texture/MakeSupport/CharUpgrade.png");
	mRenderer->LoadTexture(TextureName::CharChange, "Resource/Texture/MakeSupport/CharChange.png");
	mRenderer->LoadTexture(TextureName::CharUse, "Resource/Texture/MakeSupport/CharUse.png");
	mRenderer->LoadTexture(TextureName::CharMakeSword, "Resource/Texture/MakeSupport/CharMakeSword.png");
	mRenderer->LoadTexture(TextureName::CharMakeSpear, "Resource/Texture/MakeSupport/CharMakeSpear.png");
	mRenderer->LoadTexture(TextureName::CharMakeGun, "Resource/Texture/MakeSupport/CharMakeGun.png");
	mRenderer->LoadTexture(TextureName::CharMakeItem, "Resource/Texture/MakeSupport/CharMakeItem.png");
	mRenderer->LoadTexture(TextureName::CharLost, "Resource/Texture/MakeSupport/CharLost.png");
	mRenderer->LoadTexture(TextureName::CharUpGradeSelect, "Resource/Texture/MakeSupport/CharUpGradeSelect.png");
	mRenderer->LoadTexture(TextureName::CharWeaponChange, "Resource/Texture/MakeSupport/CharWeponChange.png");
	mRenderer->LoadTexture(TextureName::CharItemSelect, "Resource/Texture/MakeSupport/CharItemSelect.png");

	mRenderer->LoadTexture(TextureName::CharCannon, "Resource/Texture/MakeSupport/CharCannon.png");
	mRenderer->LoadTexture(TextureName::CharFlamberge, "Resource/Texture/MakeSupport/CharFlamberge.png");
	mRenderer->LoadTexture(TextureName::CharGreatSword, "Resource/Texture/MakeSupport/CharGreatSword.png");
	mRenderer->LoadTexture(TextureName::CharIronGun, "Resource/Texture/MakeSupport/CharIronGun.png");
	mRenderer->LoadTexture(TextureName::CharIronSpear, "Resource/Texture/MakeSupport/CharIronSpear.png");
	mRenderer->LoadTexture(TextureName::CharIronSword, "Resource/Texture/MakeSupport/CharIronSword.png");
	mRenderer->LoadTexture(TextureName::CharLaserGun, "Resource/Texture/MakeSupport/CharLaserGun.png");
	mRenderer->LoadTexture(TextureName::CharLongSword, "Resource/Texture/MakeSupport/CharLongSword.png");
	mRenderer->LoadTexture(TextureName::CharOtegine, "Resource/Texture/MakeSupport/CharOtegine.png");
	mRenderer->LoadTexture(TextureName::CharPartisan, "Resource/Texture/MakeSupport/CharPartisan.png");
	mRenderer->LoadTexture(TextureName::CharVajyuranda, "Resource/Texture/MakeSupport/CharVajyuranda.png");
	mRenderer->LoadTexture(TextureName::CharVulcan, "Resource/Texture/MakeSupport/CharVulcan.png");
	mRenderer->LoadTexture(TextureName::CharRecovery, "Resource/Texture/MakeSupport/CharRecovery.png");
	mRenderer->LoadTexture(TextureName::CharShield, "Resource/Texture/MakeSupport/CharShield.png");
	mRenderer->LoadTexture(TextureName::CharPowerUp, "Resource/Texture/MakeSupport/CharPowerUp.png");


	mRenderer->LoadTexture(TextureName::SelectCursor, "Resource/Texture/Icon/Select.png");

	mRenderer->LoadTexture(TextureName::ChangeIcon, "Resource/Texture/Icon/ChangeIcon.png");
	mRenderer->LoadTexture(TextureName::GunIcon, "Resource/Texture/Icon/GunIcon.png");
	mRenderer->LoadTexture(TextureName::ItemIcon, "Resource/Texture/Icon/ItemIcon.png");
	mRenderer->LoadTexture(TextureName::MakeIcon, "Resource/Texture/Icon/MakeIcon.png");
	mRenderer->LoadTexture(TextureName::Select, "Resource/Texture/Icon/Select.png");
	mRenderer->LoadTexture(TextureName::SpearIcon, "Resource/Texture/Icon/SpearIcon.png");
	mRenderer->LoadTexture(TextureName::SwordIcon, "Resource/Texture/Icon/SwordIcon.png");
	mRenderer->LoadTexture(TextureName::UpgradeIcon, "Resource/Texture/Icon/UpGradeIcon.png");
	mRenderer->LoadTexture(TextureName::UseIcon, "Resource/Texture/Icon/UseIcon.png");

	mRenderer->LoadTexture(TextureName::IronSword, "Resource/Texture/Sword/IronSwordIcon.png");
	mRenderer->LoadTexture(TextureName::LongSword, "Resource/Texture/Sword/LongSwordIcon.png");
	mRenderer->LoadTexture(TextureName::Flamberge, "Resource/Texture/Sword/FlambergeIcon.png");
	mRenderer->LoadTexture(TextureName::GreatSword, "Resource/Texture/Sword/GreatSwordIcon.png");

	mRenderer->LoadTexture(TextureName::IronSpear, "Resource/Texture/Spear/IronSpearIcon.png");
	mRenderer->LoadTexture(TextureName::Partisan, "Resource/Texture/Spear/PartisanIcon.png");
	mRenderer->LoadTexture(TextureName::Otegine, "Resource/Texture/Spear/OtegineIcon.png");
	mRenderer->LoadTexture(TextureName::Vajyuranda, "Resource/Texture/Spear/VajyurandaIcon.png");

	mRenderer->LoadTexture(TextureName::IronGun, "Resource/Texture/Gun/IronGunIcon.png");
	mRenderer->LoadTexture(TextureName::LaserGun, "Resource/Texture/Gun/LaserGunIcon.png");
	mRenderer->LoadTexture(TextureName::Vulcan, "Resource/Texture/Gun/VulcanIcon.png");
	mRenderer->LoadTexture(TextureName::Cannon, "Resource/Texture/Gun/CannonIcon.png");

	mRenderer->LoadTexture(TextureName::Recovery, "Resource/Texture/Icon/RecoveryIcon.png");
	mRenderer->LoadTexture(TextureName::Shield, "Resource/Texture/Icon/ShieldIcon.png");
	mRenderer->LoadTexture(TextureName::PowerUP, "Resource/Texture/Icon/PowerUPIcon.png");

	mRenderer->LoadTexture(TextureName::Icon, "Resource/Texture/Icon/icon.png");

	mRenderer->LoadTexture(TextureName::TitleBack, "Resource/Texture/GameTitle/TitleBack.png");
	mRenderer->LoadTexture(TextureName::TitleFrame, "Resource/Texture/GameTitle/TitleFrame.png");
	mRenderer->LoadTexture(TextureName::Start, "Resource/Texture/GameTitle/Start.png");
	mRenderer->LoadTexture(TextureName::TitleLogo, "Resource/Texture/GameTitle/TitleLogo.png");
	mRenderer->LoadTexture(TextureName::TitleScale, "Resource/Texture/GameTitle/TitleScale.png");
	mRenderer->LoadTexture(TextureName::TitleBigCursor, "Resource/Texture/GameTitle/TitleBigCursor.png");
	mRenderer->LoadTexture(TextureName::TitleSubCursor, "Resource/Texture/GameTitle/TitleSubCursor.png");

	mRenderer->LoadTexture(TextureName::GameClear, "Resource/Texture/GameOver/GameClear.png");
	mRenderer->LoadTexture(TextureName::CharClear, "Resource/Texture/GameOver/Clear.png");
	mRenderer->LoadTexture(TextureName::Rank, "Resource/Texture/GameOver/Rank.png");
	mRenderer->LoadTexture(TextureName::RankA, "Resource/Texture/GameOver/A.png");
	mRenderer->LoadTexture(TextureName::RankB, "Resource/Texture/GameOver/B.png");
	mRenderer->LoadTexture(TextureName::RankC, "Resource/Texture/GameOver/C.png");
	mRenderer->LoadTexture(TextureName::RankS, "Resource/Texture/GameOver/S.png");

	mRenderer->LoadTexture(TextureName::GameOver, "Resource/Texture/GameOver/GameOver.png");

	mRenderer->LoadTexture(TextureName::PlayerIcon, "Resource/Texture/UI/PlayerIcon.png");
	mRenderer->LoadTexture(TextureName::HPGauge, "Resource/Texture/UI/HPGauge.png");

	mRenderer->LoadTexture(TextureName::Number, "Resource/Texture/UI/Number.png");
	mRenderer->LoadTexture(TextureName::AbilityNumber, "Resource/Texture/UI/AbilityNumber.png");
	mRenderer->LoadTexture(TextureName::ScreenHide, "Resource/Texture/Debug/ScreenHide.png");

	mRenderer->LoadTexture(TextureName::None, "Resource/Texture/Debug/None.png");

	//オクツリーの読み込み
	mRenderer->LoadOctree(MeshName::Ground, "Resource/Floor/Field_oct.msh", "Resource/Floor/Field.oct");

	/*BGMの読み込み*/
	mMusic->LoadBGM(SoundName::TitleBGM, "Resource/Music/BGM/TitleBGM.mp3", GMIDI_LOOP);
	mMusic->LoadBGM(SoundName::PlayBGM, "Resource/Music/BGM/KremlinBGM.mp3", GMIDI_LOOP);
	mMusic->LoadBGM(SoundName::GameOverBGM, "Resource/Music/BGM/GameOver.mp3", GMIDI_DEFAULT);

	/*SEの読み込み*/
	mMusic->LoadSE(SoundName::GameClearSE, "Resource/Music/SE/GameClear.wav");
	mMusic->LoadSE(SoundName::SwordSE, "Resource/Music/SE/SwordSE.wav");
	mMusic->LoadSE(SoundName::SpearSE, "Resource/Music/SE/SpearSE.wav");
	mMusic->LoadSE(SoundName::LaserSE, "Resource/Music/SE/LaserSE.wav");
	mMusic->LoadSE(SoundName::GuardSE, "Resource/Music/SE/GuardSE.wav");
	mMusic->LoadSE(SoundName::ChangeWeponSE, "Resource/Music/SE/ChangeWeponSE.wav");
	mMusic->LoadSE(SoundName::ExplotionSE, "Resource/Music/SE/Explosion.wav");
	mMusic->LoadSE(SoundName::Damage, "Resource/Music/SE/Damage.wav");
	mMusic->LoadSE(SoundName::RecoverySE, "Resource/Music/SE/RecoverySE.wav");
	mMusic->LoadSE(SoundName::HitSE, "Resource/Music/SE/HitSE.wav");
	mMusic->LoadSE(SoundName::ShieldSE, "Resource/Music/SE/ShieldSE.wav");
	mMusic->LoadSE(SoundName::PowerUPSE, "Resource/Music/SE/PowerUPSE.wav");
	mMusic->LoadSE(SoundName::Decision, "Resource/Music/SE/Decision.wav");
	mMusic->LoadSE(SoundName::Cancel, "Resource/Music/SE/Cancel.wav");
	mMusic->LoadSE(SoundName::Cursor, "Resource/Music/SE/Cursor.wav");
	mMusic->LoadSE(SoundName::OpenMenu, "Resource/Music/SE/OpenMenu.wav");
	mMusic->LoadSE(SoundName::CloseMenu, "Resource/Music/SE/CloseMenu.wav");
	mMusic->LoadSE(SoundName::TitleStart, "Resource/Music/SE/TitleStartSE.wav");

	/*エフェクトの読み込み*/
	gsLoadEffect((GSuint)EffectName::Slash, "Resource/Effect/Slash.efk");
	gsLoadEffect((GSuint)EffectName::SpearEffect, "Resource/Effect/SpearEffect.efk");
	gsLoadEffect((GSuint)EffectName::GunEffect, "Resource/Effect/GunEffect.efk");
}

void GameManager::Draw()const
{
	mRenderer->LoadTexture(TextureName::NowLoading, "Resource/Texture/GameTitle/NowLoading.png");
	GSrect l_Rect(0.0f, 0.0f, WIDTH, HEIGHT);
	gsDrawSprite2D(
		(GSuint)TextureName::NowLoading,
		&GSvector2(0.0f, 0.0f),
		&l_Rect,
		NULL,
		NULL,
		NULL,
		0.0f
		);
}

//リソースの削除
void GameManager::UnLoadContent()
{
	mRenderer->DeleteOctree(MeshName::Ground);

	mRenderer->DeleteMesh();
	mRenderer->DeleteModel();
	mRenderer->DeleteAnimation();
	mRenderer->DeleteTexture();
	gsDeleteEffect(1000);

	mMusic->DeleteSE();
}

WeponPtr GameManager::GetPlayerWepon()const
{
	return mWepons[mPlayerWepon];
}

WeponPtr GameManager::GetWepon(int& weponID)
{
	return mWepons[weponID];
}

void GameManager::SetPlayerWepon(int& weponID)
{
	mPlayerWepon = weponID;
}

//武器を6個生成
void GameManager::NewWepon()
{
	mPlayerWepon = 0;
	mWepons.clear();
	mWepons.push_back(std::make_shared<Wepon>());
	mWepons.push_back(std::make_shared<Wepon>());
	mWepons.push_back(std::make_shared<Wepon>());
	mWepons.push_back(std::make_shared<Wepon>());
	mWepons.push_back(std::make_shared<Wepon>());
	//ゲームスタート時の武器をセット
	mWepons[mPlayerWepon]->SetWepon(WeponName::IronSword);
	mWepons[1]->SetWepon(WeponName::IronSpear);
	mWepons[2]->SetWepon(WeponName::IronGun);
	mWepons[3]->SetWepon(WeponName::None);
	mWepons[4]->SetWepon(WeponName::None);
}