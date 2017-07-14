#ifndef _ITEM_INFO_H_
#define _ITEM_INFO_H_

enum class ItemName;
enum class TextureName;

//typedefでstructをメンバにする
typedef struct ItemInfo
{
	ItemName m_Item;        //所持しているアイテム
	TextureName m_Texture;  //アイテムのアイコン画像
	TextureName m_Ability;  //アイテムの説明画像

}ItemInfo_t;

#endif // !_ITEM_INFO_H_
