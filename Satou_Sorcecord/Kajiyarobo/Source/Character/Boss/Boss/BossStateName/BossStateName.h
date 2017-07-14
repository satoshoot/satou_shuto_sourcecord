#ifndef _BOSS_STATE_NAME_H_
#define _BOSS_STATE_NAME_H_

enum class BossStateName
{
	Idle,         //何もしていない
	Roar,         //威嚇モーション
	RightRotate,  //右に回る
	LeftRotate,   //左に回る
	Look,         //プレイヤーのほうを向く
	Landing,      //ジャンプ後の着地
	Jump,         //ジャンプ移動
	Down,         //ダウンする
	DownState,    //ダウン中
	Walk,         //歩いている
	KnockBack,    //のけ反る
	Wait,         //何もしない
	Dush,         //ダッシュ
	MoveRight,    //右に移動
	MoveLeft,     //左に移動

	/*攻撃*/
	Shoot,        //遠距離攻撃
	Punch,        //近接攻撃
	Fire,         //広範囲攻撃
	Rush,         //突進攻撃

	Dead,         //死亡

	None,         //なし

};

#endif // !_BOSS_STATE_NAME_H_