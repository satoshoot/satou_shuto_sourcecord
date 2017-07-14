#ifndef _MENU_CHAR_H_
#define _MENU_CHAR_H_

#include "../../../Utility/Enum/TextureName.h"
enum class MenuStateName;
class GameManager;

class MenuChar
{
public:
	MenuChar();

	/*�\�����镶�����Z�b�g*/
	void SetTexture(
		const TextureName& first,
		const TextureName& second,
		const TextureName& third,
		const TextureName& fourth,
		int& count);

	/*�����Ă��镐��̏����Z�b�g*/
	void SetWeapon(
		int& first,
		int& second,
		int& third,
		int& fourth,
		int& count,
		GameManager& gameManager);

	/*��������Ƃ��̍U���͂��Z�b�g*/
	void SetMakeWeapon(
		const int& first,
		const int& second,
		const int& third,
		const int& fourth,
		int& count);

	void Draw()const;

	void SetCurrentMenu(MenuStateName& name);

private:
	void CharDraw()const;
	void LvDraw()const;
	void PowerDraw()const;


private:
	TextureName m_Name;
	MenuStateName m_Menu;
	int m_Lv;
	int m_Power;
};

#endif // !_MENU_CHAR_H_
