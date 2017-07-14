#include "ItemManager.h"
#include "../ItemName/ItemName.h"
#include "../../Utility/Enum/TextureName.h"

ItemManager::ItemManager()
{
	mItems.clear();
	mItems.push_back({ ItemName::Recovery, TextureName::Recovery, TextureName::CharRecovery });
	mItems.push_back({ ItemName::None, TextureName::Icon, TextureName::None });
	mItems.push_back({ ItemName::None, TextureName::Icon, TextureName::None });
	mItems.push_back({ ItemName::None, TextureName::Icon, TextureName::None });
}

void ItemManager::SetItem(const int& weponID,
	const ItemName& name, const TextureName& icon, const TextureName& ability)
{
	mItems[weponID].m_Item = name;
	mItems[weponID].m_Texture = icon;
	mItems[weponID].m_Ability = ability;
}

ItemName ItemManager::GetEffect(const int& weponID)
{
	ItemName lName = mItems[weponID].m_Item;
	mItems[weponID].m_Item = ItemName::None;
	mItems[weponID].m_Texture = TextureName::Icon;
	mItems[weponID].m_Ability = TextureName::None;
	return lName;
}

ItemInfo_t ItemManager::GetItem(const int& weponID)
{
	return mItems[weponID];
}

TextureName ItemManager::GetAbility(const int& weponID)
{
	return mItems[weponID].m_Ability;
}
