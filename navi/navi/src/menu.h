#pragma once
#include "../src/pch.h"

class Menu {
public:
	Menu();
	void Draw();
	bool IsStartClicked();
	bool IsExitSettingsClicked();
	bool IsExitClicked();
	bool IsSettingsClicked(bool check);
	void DrawSettings();
private:
	Rectangle StartButton;
	Rectangle SettingsButton;
	Rectangle ExitButton;
	Rectangle SettingsExitButton;
	Texture2D Background;
};
