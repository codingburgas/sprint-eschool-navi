#pragma once
#include "../src/menu.h"
#include "../src/pch.h"
#include "../src/Charecter.h"
#include "../src/map.h"
#include "../src/EnglishG.h"
#include "../src/save.h"
<<<<<<< HEAD
#include <../src/NPC.h>
=======
#include "../src/MathG.h"
>>>>>>> 15a183cf2ff8c20ccd5923045c39b32e92e1a375
class Game {
public:
	Game();
	bool ExitGame;
	bool MenuClosed;
	bool SettingsOpen;
	bool EnglishGameOpen;
	bool MathGameOpen;
	bool SaveLoaded;
	bool IsPaused;
	void Draw();
	void Update();
private:
	Menu menu;
	Character Character;
	Map map;
	EnglishGame EN;
	MathGame EN;
	SaveSystem save;
	NPC NPC;
};