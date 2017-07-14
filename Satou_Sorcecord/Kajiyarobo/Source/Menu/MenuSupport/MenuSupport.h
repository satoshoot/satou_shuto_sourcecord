#ifndef _MENU_SUPPORT_H_
#define _MENU_SUPPORT_H_
#include <gslib.h>

enum class MenuStateName;
class MenuChar;

class MenuSupport
{
public:
	MenuSupport(MenuChar& menuChar);

	void Update(float deltaTime, MenuStateName& name);

	void Draw()const;


private:
	void ClampSize();


private:
	GSvector2 m_Size;
	MenuChar* p_Char;

};

#endif // !_MENU_SUPPORT_H_
