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

	//初期化
	void Initialize();
	//更新
	virtual void Update(float deltaTime);
	//決定した
	virtual void Decision() = 0;
	//戻る
	virtual void Before() = 0;

	//カーソルの位置
	void SetCursor(int cursor);
	//次の状態
	MenuStateName GetNextState()const;
	//アイコンの画像
	TextureName GetFirstIcon()const;
	TextureName GetSecondIcon()const;
	TextureName GetThirdIcon()const;
	TextureName GetFourthIcon()const;

protected:
	//派生の初期化
	virtual void OnInitialize() = 0;

	//持っている武器を表示
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
