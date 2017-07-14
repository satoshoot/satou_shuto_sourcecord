#ifndef _WEPOM_H_
#define _WEPON_H_
#include <gslib.h>

enum class WeponName;
enum class WeponType;
enum class MeshName;
enum class TextureName;
enum class WeponSpecialSkill;

class Wepon
{
public:
	Wepon();
	~Wepon() {};

	void SetWepon(WeponName name);
	//•Ší‚ÌƒŒƒxƒ‹
	int GetLv()const;
	//—^‚¦‚éƒ_ƒ[ƒWæ“¾
	int GetPower()const;

	//–hŒä—Í‚ğæ“¾
	int GetDefenseLv()const;

	//e‚ÌUŒ‚‘¬“x
	int GetShotSpeed()const;

	//UŒ‚”ÍˆÍLV‚ğæ“¾
	int GetRangeLv()const;

	TextureName GetTextureName()const;

	TextureName GetAbilityTexture()const;

	//•Ší‚Ìí—Ş‚ğæ“¾
	WeponType GetWeponType()const;

	//•Ší‚Ì–¼‘O‚ğæ“¾
	WeponName GetWeponName()const;

	//•Ší‚Ì“Á‹Z‚ğæ“¾
	WeponSpecialSkill GetSpecialSkill()const;

	GSuint GetMeshID()const;

	void LvUP();

private:
	WeponType mWeponType;
	WeponName mWeponName;
	MeshName mMesh;
	TextureName mTexture;
	TextureName m_AbilityTexture;
	WeponSpecialSkill mSpecial;
	int mLv;
	int mPower;
	int mSkillLv;
	int mRangeLv;

};

#endif // !_WEPOM_H_
