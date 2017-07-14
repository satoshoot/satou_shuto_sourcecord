#ifndef _ABSTRACT_MENU_H_
#define _ABSTRACT_MENU_H_

enum class TextureName;
enum class MenuStateName;
class SetMenuResult;
class GameManager;
class MenuChar;

class AbstractMenu
{
public:
	AbstractMenu(SetMenuResult* result, GameManager* gameManager, MenuChar& menuChar);

	//������
	void Initialize();
	//�X�V
	virtual void Update(float deltaTime);
	//���肵��
	virtual void Decision() = 0;
	//�߂�
	virtual void Before() = 0;

	//�J�[�\���̈ʒu
	void SetCursor(int cursor);
	//���̏��
	MenuStateName GetNextState()const;
	//�A�C�R���̉摜
	TextureName GetFirstIcon()const;
	TextureName GetSecondIcon()const;
	TextureName GetThirdIcon()const;
	TextureName GetFourthIcon()const;

protected:
	//�h���̏�����
	virtual void OnInitialize() = 0;

	//�����Ă��镐���\��
	void SortWeponTexture(int& first, int& second, int& third, int& fourth);


protected:
	TextureName m_FirstIcon;
	TextureName m_SecondIcon;
	TextureName m_ThirdIcon;
	TextureName m_FourthIcon;
	MenuStateName m_NextState;
	int m_Cursor;
	float m_Counter;

	SetMenuResult* p_MenuResult;
	GameManager* p_GameManager;
	MenuChar* p_Char;
};

#endif // !1
