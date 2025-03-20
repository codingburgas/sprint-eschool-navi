#pragma once
#include "../src/menu.h"
#include "../src/pch.h"
#include "../src/Charecter.h"
#include "../src/map.h"
#include "../src/EnglishG.h"
#include "../src/save.h"
class Game {
public:
	Game();
	bool ExitGame;
	bool MenuClosed;
	bool SettingsOpen;
	bool EnglishGameOpen;
	bool SaveLoaded;
	bool IsPaused;
	void Draw();
	void Update();
private:
	Menu menu;
	Character Character;
	Map map;
	EnglishGame EN;
	SaveSystem save;
};