#ifndef _MENU_PUSH_R_
#define _MENU_PUSH_R_
#include <gslib.h>

class MenuIcon;
enum class MenuStateName;

class MenuPushR
{
public:
	MenuPushR();

	void MenuSize(float deltaTime, float counter, MenuStateName& name, MenuIcon& icon);

	void Draw()const;

private:
	void ClampSize();
	void AlphaPlus();

private:
	GSvector2 m_Size;
	float m_Alpha;
	float m_AlphaPlus;
};

#endif // !_MENU_PUSH_R_
