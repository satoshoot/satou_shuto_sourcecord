#ifndef _MENU_CURSOR_H_
#define _MENU_CURSOR_H_
#include <gslib.h>

class MenuCursor
{
public:
	MenuCursor();

	void Update(float deltaTime);

	void Draw()const;

	int GetSelectCount()const;

	void ResetCursor();

private:
	GSvector2 mPosition;
	int mSelectCount;
	bool mChangePage;

};

#endif // !_MENU_CURSOR_H_
