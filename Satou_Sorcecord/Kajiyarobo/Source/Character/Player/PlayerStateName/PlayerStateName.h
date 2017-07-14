#ifndef _PLAYER_STATE_NAME_H_
#define _PLAYER_STATE_NAME_H_


enum class PlayerStateName
{
	Normal,             //’Êíó‘Ô
	LockOn,             //ƒƒbƒNƒIƒ“ó‘Ô

	SwordDushAttack,    //Œ•ƒ_ƒbƒVƒ…UŒ‚
	SwordFirstAttack,   //Œ•UŒ‚1
	SwordSecondAttack,  //Œ•UŒ‚2
	SwordThirdAttack,   //Œ•UŒ‚3
	SwordFourthAttack,  //Œ•UŒ‚4
	SwordFifthAttack,   //Œ•UŒ‚5

	SpearDushAttack,    //‘„ƒ_ƒbƒVƒ…UŒ‚
	SpearFirstAttack,   //‘„UŒ‚1
	SpearSecondAttack,  //‘„UŒ‚2
	SpearThirdAttack,   //‘„UŒ‚3
	SpearFourthAttack,  //‘„UŒ‚4

	ShootNormal,        //e‚ğ‚Á‚Ä‚¢‚éó‘Ô‚Ì’Êíó‘Ô
	ShootLockOn,        //e‚Å‚ÌƒƒbƒNƒIƒ“ó‘Ô
	Shoot,              //’e‚ğŒ‚‚Â
	ShootRapid,         //e‚ğ\‚¦‚È‚ª‚çˆÚ“®
	ShootCannon,        //e‚Ì–CŒ‚
	ShootKnockBack,     //e‚ğŒ‚‚Á‚½‚Ìd’¼

	Guard,              //–hŒäó‘Ô
	GuardBreak,         //–hŒäŒã‚Ìd’¼
	Stun,               //UŒ‚‚ğó‚¯‚½ó‘Ô
	Fly,                //UŒ‚‚ğó‚¯‚Ä‚«”ò‚Î‚³‚ê‚½ó‘Ô
	OpenMenu,           //ƒƒjƒ…[‚ğŠJ‚¢‚Ä‚¢‚éó‘Ô
	Make,               //•Ší‚ğì‚Á‚Ä‚¢‚éó‘Ô
	Ally,               //–¡•ûƒLƒƒƒ‰‚ğ‘€ì‚µ‚Ä‚¢‚éó‘Ô
	Dead,               //€‚ñ‚¾ó‘Ô


	None,               //‚È‚µ
};

#endif // !_PLAYER_STATE_NAME_H_