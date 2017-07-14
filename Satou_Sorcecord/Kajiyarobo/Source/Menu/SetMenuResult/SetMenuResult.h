#ifndef _SET_MENU_RESULT_H_
#define _SET_MENU_RESULT_H_
#include "../../Item/ItemInfo/ItemInfo.h"

class GameManager;
class ItemManager;
class Item;
enum class WeponName;
enum class ItemName;
enum class TextureName;

class SetMenuResult
{
public:
	SetMenuResult(GameManager* gameManager, Item* item);

	void SetSelectWepon(WeponName name);
	void SetWepon(int& weponID);

	void LvUP(int& weponID);
	bool LvMax(int& weponID)const;

	bool SetItem(int& weponID,
		const ItemName& name, const TextureName& icon, const TextureName& ability);

	ItemInfo_t GetItem(const int& itemID);
	void UseItem(const int& itemID);


private:
	WeponName mSelectWepon;
	GameManager* pGameManager;
	ItemManager* mItemManager;
	Item* pItem;

};


#endif // !_SET_MENU_RESULT_H_
