#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_
#include <vector>
#include "../../Wepon/Weponptr/Weponptr.h"

class Renderer;
class Menu;
class Music;

using Wepons = std::vector<WeponPtr>;

class GameManager
{
public:
	GameManager();
	virtual~GameManager();

	void LoadContent();
	void Draw()const;
	void UnLoadContent();

	WeponPtr GetPlayerWepon()const;

	WeponPtr GetWepon(int& weponID);

	void SetPlayerWepon(int& weponID);

	void NewWepon();

public:
	Renderer* mRenderer;
	Music* mMusic;
	Wepons mWepons;
	int mPlayerWepon;
};

#endif // !_GAMEMANAGER_H_
