#ifndef _ITEM_MANAGER_H_
#define _ITEM_MANAGER_H_
#include <vector>
#include "../ItemInfo/ItemInfo.h"
class Item;
enum class ItemName;

class ItemManager
{
public:
	ItemManager();

	void SetItem(const int& weponID,
		const ItemName& name, const TextureName& icon, const TextureName& ability);

	ItemName GetEffect(const int& weponID);

	ItemInfo_t GetItem(const int& weponID);

	TextureName GetAbility(const int& weponID);

private:
	//���g���폜���Ȃ��̂�vector�ɂ��Ă݂܂���
	std::vector<ItemInfo_t> mItems;

};

#endif // !_ITEM_MANAGER_H_
