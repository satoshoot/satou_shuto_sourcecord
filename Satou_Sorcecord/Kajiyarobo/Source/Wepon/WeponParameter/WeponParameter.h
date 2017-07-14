#ifndef _WEPON_PARAMETER_H_
#define _WEPON_PARAMETER_H_

/*パラメータについて*/
//レベル：武器の攻撃力を変化させる
//攻撃力：相手に与えるダメージ数
//防御力：防御したときのはじかれにくさ
//攻撃範囲：攻撃の判定の大きさ
//防御力、攻撃範囲は５段階で設定する

enum class WeponName;
enum class MeshName;
enum class WeponType;
enum class TextureName;
enum class WeponSpecialSkill;


class WeponParameter
{
public:
	//武器をセット
	static void SetWepon(
		WeponName& name, MeshName& mesh, WeponType& type, TextureName& texture, TextureName& ability,
		WeponSpecialSkill& special, int& power, int& skill, int& range);

	static TextureName GetAbillity(WeponName weponName);
	static int GetPower(WeponName weponName);

};

#endif // !_WEPON_ID_H_
