#pragma once
#include "../src/menu.h"
#include "../src/pch.h"

class Game {
public:
	Game();
	bool ExitGame;
	bool MenuClosed;
	bool SettingsOpen;
	void Draw();
	void Update();
private:
	Menu menu;
};