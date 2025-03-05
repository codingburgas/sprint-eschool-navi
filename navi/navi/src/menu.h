#pragma once
#include "../src/pch.h"

class Menu {
public:
	Menu();
	void Draw();
	bool IsStartClicked();
	bool IsExitClicked();
	bool IsSettingsClicked(bool check);
	void DrawSettings();
private:
	Rectangle StartButton;
	Rectangle SettingsButton;
	Rectangle ExitButton;
	Texture2D Background;
};
