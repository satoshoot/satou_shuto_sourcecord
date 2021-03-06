#ifndef _MENU_H_
#define _MENU_H_
#include <gslib.h>

class MenuManager;
enum class MenuStateName;
class GameManager;
class Item;

class Menu
{
public:
	Menu();
	~Menu();

	void NewMenuManager(GameManager& gameManager, Item& item);

	//更新
	void Update(float deltaTime);
	//描画
	void Draw()const;
	//今の状態を取得
	MenuStateName GetCurrentState()const;


private:
	MenuManager* mMenuManager;
	GSvector2 mMenuBackSize;

};

#endif // !_MENU_H_
