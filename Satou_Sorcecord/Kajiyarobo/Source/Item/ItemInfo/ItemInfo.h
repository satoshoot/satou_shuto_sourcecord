#ifndef _ITEM_INFO_H_
#define _ITEM_INFO_H_

enum class ItemName;
enum class TextureName;

//typedef��struct�������o�ɂ���
typedef struct ItemInfo
{
	ItemName m_Item;        //�������Ă���A�C�e��
	TextureName m_Texture;  //�A�C�e���̃A�C�R���摜
	TextureName m_Ability;  //�A�C�e���̐����摜

}ItemInfo_t;

#endif // !_ITEM_INFO_H_
