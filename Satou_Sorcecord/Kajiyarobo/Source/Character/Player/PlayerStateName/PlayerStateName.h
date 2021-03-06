#ifndef _PLAYER_STATE_NAME_H_
#define _PLAYER_STATE_NAME_H_


enum class PlayerStateName
{
	Normal,             //通常状態
	LockOn,             //ロックオン状態

	SwordDushAttack,    //剣ダッシュ攻撃
	SwordFirstAttack,   //剣攻撃1
	SwordSecondAttack,  //剣攻撃2
	SwordThirdAttack,   //剣攻撃3
	SwordFourthAttack,  //剣攻撃4
	SwordFifthAttack,   //剣攻撃5

	SpearDushAttack,    //槍ダッシュ攻撃
	SpearFirstAttack,   //槍攻撃1
	SpearSecondAttack,  //槍攻撃2
	SpearThirdAttack,   //槍攻撃3
	SpearFourthAttack,  //槍攻撃4

	ShootNormal,        //銃を持っている状態の通常状態
	ShootLockOn,        //銃でのロックオン状態
	Shoot,              //弾を撃つ
	ShootRapid,         //銃を構えながら移動
	ShootCannon,        //銃の砲撃
	ShootKnockBack,     //銃を撃った時の硬直

	Guard,              //防御状態
	GuardBreak,         //防御後の硬直
	Stun,               //攻撃を受けた状態
	Fly,                //攻撃を受けて吹き飛ばされた状態
	OpenMenu,           //メニューを開いている状態
	Make,               //武器を作っている状態
	Ally,               //味方キャラを操作している状態
	Dead,               //死んだ状態


	None,               //なし
};

#endif // !_PLAYER_STATE_NAME_H_