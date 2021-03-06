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
	//íÌx
	int GetLv()const;
	//^¦é_[Wæ¾
	int GetPower()const;

	//häÍðæ¾
	int GetDefenseLv()const;

	//eÌU¬x
	int GetShotSpeed()const;

	//UÍÍLVðæ¾
	int GetRangeLv()const;

	TextureName GetTextureName()const;

	TextureName GetAbilityTexture()const;

	//íÌíÞðæ¾
	WeponType GetWeponType()const;

	//íÌ¼Oðæ¾
	WeponName GetWeponName()const;

	//íÌÁZðæ¾
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
