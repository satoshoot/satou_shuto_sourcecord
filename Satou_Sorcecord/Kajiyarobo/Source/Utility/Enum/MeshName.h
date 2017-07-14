#ifndef MESHNAME_H_
#define MESHNAME_H_


//メッシュID
enum class MeshName
{
	Player = 0,            //ロボットのプレイヤー
	Dog,                   //犬

	/***剣***/
	IronSword,
	LongSword,
	Flamberge,
	GreatSword,

	/***槍***/
	IronSpear,
	Partisan,
	Otegine,
	Vajyuranda,

	/***銃***/
	IronGun,
	Vulcan,
	LaserGun,
	Cannon,

	/***弾***/
	SpeedBullet,
	RapidBullet,
	Laser,

	/***敵の弾***/
	DogShot,               //犬の投げる骨
	MeteorBullet,          //上から落ちる弾

	Hummer,                //武器を作る金槌
	MakeWepon,             //作っている武器
	Helmet,                //味方キャラのヘルメット
	Kremlin,               //ボス
	Ground,                //地面
	SkyBox,                //スカイボックス
	Wall,                  //壁
	Shield,                //シールド

	FireEffect,            //爆発エフェクト
	SlashEffect,           //斬撃エフェクト
	SpeedBulletEffect,     //速射弾エフェクト

	None                   //なし
};


#endif // !MESHNAME_H_
