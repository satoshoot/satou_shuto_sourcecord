#ifndef _MENU_ICON_H_
#define _MENU_ICON_H_

enum class TextureName;

class MenuIcon
{
public:

	MenuIcon();

	//�A�C�R���𓮂���
	void SizeUpdate(float deltaTime, float& counter);

	void Draw(
		const TextureName& first,
		const TextureName& second,
		const TextureName& third,
		const TextureName& fourth)const;

private:
	//�A�C�R���̃T�C�Y�ύX
	void SizeChange(float& counter);

private:
	float m_IconSizeY; //�A�C�R���̃T�C�Y
};

#endif // !_MENU_ICON_H_
