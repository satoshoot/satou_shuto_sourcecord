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
//���x���A����̎�ށA����̖��O�A����̃p�����[�^���Z�b�g
void Wepon::SetWepon(WeponName name)
{
	mLv = 1;
	mWeponName = name;
	WeponParameter::SetWepon(mWeponName, mMesh, mWeponType, mTexture, m_AbilityTexture,
		mSpecial, mPower, mSkillLv, mRangeLv);
}
//����̃��x��
int Wepon::GetLv()const
{
	return mLv;
}

//�U����
int Wepon::GetPower()const
{
	//���x���A�b�v���Ă��U�����オ��悤�ɂ���
	float l_PowerUp = (mPower / 10 <= 1) ? 1 : mPower / 10;
	return mPower + l_PowerUp * (mLv - 1);
}
//�h���
int Wepon::GetDefenseLv()const
{
	return mSkillLv;
}
//�e�̍U�����x
int Wepon::GetShotSpeed()const
{
	return mSkillLv;
}

//�U���͈�
int Wepon::GetRangeLv()const
{
	return mRangeLv;
}
//����̎��
WeponType Wepon::GetWeponType()const
{
	return mWeponType;
}
//����̖��O
WeponName Wepon::GetWeponName()const
{
	return mWeponName;
}

//���b�V��ID���擾
GSuint Wepon::GetMeshID()const
{
	GSuint result = (GSuint)mMesh;
	return result;
}

//����̉摜��Ԃ�
TextureName Wepon::GetTextureName()const
{
	return mTexture;
}

TextureName Wepon::GetAbilityTexture() const
{
	return m_AbilityTexture;
}

//����̓��Z��Ԃ�
WeponSpecialSkill Wepon::GetSpecialSkill()const
{
	return mSpecial;
}

void Wepon::LvUP()
{
	mLv++;
}