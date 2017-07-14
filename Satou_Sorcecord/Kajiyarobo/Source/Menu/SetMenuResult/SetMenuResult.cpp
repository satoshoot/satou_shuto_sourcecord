#include "SetMenuResult.h"
#include "../../Wepon/WeponName/WeponName.h"
#include "../../Base/GameManager/GameManager.h"
#include "../../Wepon/Wepon/Wepon.h"
#include "../../Item/ItemManager/ItemManager.h"
#include "../../Item/ItemName/ItemName.h"
#include "../../Utility/Enum/TextureName.h"
#include "../../Item/Item/Item.h"
#include "../../Wepon/WeponType/WeponType.h"


SetMenuResult::SetMenuResult(GameManager* gameManager, Item* item)
	: mSelectWepon(WeponName::None)
	, pGameManager(gameManager)
	, mItemManager(new ItemManager())
	, pItem(item)
{

}

void SetMenuResult::SetSelectWepon(WeponName name)
{
	mSelectWepon = name;
}

void SetMenuResult::SetWepon(int& weponID)
{
	pGameManager->GetWepon(weponID)->SetWepon(mSelectWepon);
}

void SetMenuResult::LvUP(int& weponID)
{
	if (LvMax(weponID) == true ||
		pGameManager->GetWepon(weponID)->GetWeponType() == WeponType::None)
		return;

	pGameManager->GetWepon(weponID)->LvUP();
}

bool SetMenuResult::LvMax(int& weponID)const
{
	if (pGameManager->GetWepon(weponID)->GetLv() >= 5)
		return true;

	return false;
}

bool SetMenuResult::SetItem(int& weponID,
	const ItemName& name, const TextureName& icon, const TextureName& ability)
{
	if (mItemManager->GetItem(0).m_Item == ItemName::None)
	{
		mItemManager->SetItem(0, name, icon, ability);
		return true;
	}
	if (mItemManager->GetItem(1).m_Item == ItemName::None)
	{
		mItemManager->SetItem(1, name, icon, ability);
		return true;
	}
	if (mItemManager->GetItem(2).m_Item == ItemName::None)
	{
		mItemManager->SetItem(2, name, icon, ability);
		return true;
	}
	if (mItemManager->GetItem(3).m_Item == ItemName::None)
	{
		mItemManager->SetItem(3, name, icon, ability);
		return true;
	}

	return false;
}

ItemInfo_t SetMenuResult::GetItem(const int& itemID)
{
	return mItemManager->GetItem(itemID);
}

void SetMenuResult::UseItem(const int& itemID)
{
	return pItem->ItemEffect(mItemManager->GetEffect(itemID));
}