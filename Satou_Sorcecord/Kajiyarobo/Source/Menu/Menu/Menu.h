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

	//�X�V
	void Update(float deltaTime);
	//�`��
	void Draw()const;
	//���̏�Ԃ��擾
	MenuStateName GetCurrentState()const;


private:
	MenuManager* mMenuManager;
	GSvector2 mMenuBackSize;

};

#endif // !_MENU_H_
