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
	//����̃��x��
	int GetLv()const;
	//�^����_���[�W�擾
	int GetPower()const;

	//�h��͂��擾
	int GetDefenseLv()const;

	//�e�̍U�����x
	int GetShotSpeed()const;

	//�U���͈�LV���擾
	int GetRangeLv()const;

	TextureName GetTextureName()const;

	TextureName GetAbilityTexture()const;

	//����̎�ނ��擾
	WeponType GetWeponType()const;

	//����̖��O���擾
	WeponName GetWeponName()const;

	//����̓��Z���擾
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
