#pragma once
#include "../src/menu.h"
#include "../src/pch.h"
#include "../src/Charecter.h"
#include "../src/map.h"
#include "../src/bulgarianG.h"
class Game {
public:
	Game();
	bool ExitGame;
	bool MenuClosed;
	bool SettingsOpen;
	bool BulgarianGameOpen;
	void Draw();
	void Update();
private:
	Menu menu;
	Character Character;
	Map map;
	BulgarianGame BG;
};