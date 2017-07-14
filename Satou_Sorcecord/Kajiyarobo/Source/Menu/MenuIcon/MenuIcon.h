#ifndef _MENU_ICON_H_
#define _MENU_ICON_H_

enum class TextureName;

class MenuIcon
{
public:

	MenuIcon();

	//アイコンを動かす
	void SizeUpdate(float deltaTime, float& counter);

	void Draw(
		const TextureName& first,
		const TextureName& second,
		const TextureName& third,
		const TextureName& fourth)const;

private:
	//アイコンのサイズ変更
	void SizeChange(float& counter);

private:
	float m_IconSizeY; //アイコンのサイズ
};

#endif // !_MENU_ICON_H_
