#ifndef _WEPON_PARAMETER_H_
#define _WEPON_PARAMETER_H_

/*�p�����[�^�ɂ���*/
//���x���F����̍U���͂�ω�������
//�U���́F����ɗ^����_���[�W��
//�h��́F�h�䂵���Ƃ��̂͂�����ɂ���
//�U���͈́F�U���̔���̑傫��
//�h��́A�U���͈͂͂T�i�K�Őݒ肷��

enum class WeponName;
enum class MeshName;
enum class WeponType;
enum class TextureName;
enum class WeponSpecialSkill;


class WeponParameter
{
public:
	//������Z�b�g
	static void SetWepon(
		WeponName& name, MeshName& mesh, WeponType& type, TextureName& texture, TextureName& ability,
		WeponSpecialSkill& special, int& power, int& skill, int& range);

	static TextureName GetAbillity(WeponName weponName);
	static int GetPower(WeponName weponName);

};

#endif // !_WEPON_ID_H_
