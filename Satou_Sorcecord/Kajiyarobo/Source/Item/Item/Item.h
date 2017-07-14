#ifndef _ITEM_H_
#define _ITEM_H_

class PlayerHP;
class Shield;
enum class ItemName;

class Item
{
public:
	Item() = default;

	Item(PlayerHP* hp, Shield* shield);

	void Update(float deltaTime);

	float PowerUp()const;

	void ItemEffect(const ItemName& name);


private:
	PlayerHP* pHP;
	Shield* pShield;

	ItemName mCurrentItem;
	float mCounter;

};

#endif // !_ITEM_H_
