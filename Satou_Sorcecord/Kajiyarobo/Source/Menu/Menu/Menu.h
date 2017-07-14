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

	//XV
	void Update(float deltaTime);
	//•`‰æ
	void Draw()const;
	//¡‚Ìó‘Ô‚ğæ“¾
	MenuStateName GetCurrentState()const;


private:
	MenuManager* mMenuManager;
	GSvector2 mMenuBackSize;

};

#endif // !_MENU_H_
