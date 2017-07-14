#include "Wepon.h"
#include "../WeponParameter/WeponParameter.h"
#include "../WeponName/WeponName.h"
#include "../WeponType/WeponType.h"
#include "../../Utility/Enum/TextureName.h"
#include "../../Wepon/WeponSpecialSkill/WeponSpecialSkill.h"
#include "../../Utility/Enum/MeshName.h"

Wepon::Wepon()
	: mMesh(MeshName::None)
	, mLv(1)
	, mWeponType(WeponType::Sword)
	, mWeponName(WeponName::None)
	, mTexture(TextureName::None)
	, m_AbilityTexture(TextureName::None)
	, mSpecial(WeponSpecialSkill::None)
	, mPower(1)
	, mSkillLv(1)
	, mRangeLv(1)
{

}
//レベル、武器の種類、武器の名前、武器のパラメータをセット
void Wepon::SetWepon(WeponName name)
{
	mLv = 1;
	mWeponName = name;
	WeponParameter::SetWepon(mWeponName, mMesh, mWeponType, mTexture, m_AbilityTexture,
		mSpecial, mPower, mSkillLv, mRangeLv);
}
//武器のレベル
int Wepon::GetLv()const
{
	return mLv;
}

//攻撃力
int Wepon::GetPower()const
{
	//レベルアップしても攻撃が上がるようにする
	float l_PowerUp = (mPower / 10 <= 1) ? 1 : mPower / 10;
	return mPower + l_PowerUp * (mLv - 1);
}
//防御力
int Wepon::GetDefenseLv()const
{
	return mSkillLv;
}
//銃の攻撃速度
int Wepon::GetShotSpeed()const
{
	return mSkillLv;
}

//攻撃範囲
int Wepon::GetRangeLv()const
{
	return mRangeLv;
}
//武器の種類
WeponType Wepon::GetWeponType()const
{
	return mWeponType;
}
//武器の名前
WeponName Wepon::GetWeponName()const
{
	return mWeponName;
}

//メッシュIDを取得
GSuint Wepon::GetMeshID()const
{
	GSuint result = (GSuint)mMesh;
	return result;
}

//武器の画像を返す
TextureName Wepon::GetTextureName()const
{
	return mTexture;
}

TextureName Wepon::GetAbilityTexture() const
{
	return m_AbilityTexture;
}

//武器の特技を返す
WeponSpecialSkill Wepon::GetSpecialSkill()const
{
	return mSpecial;
}

void Wepon::LvUP()
{
	mLv++;
}