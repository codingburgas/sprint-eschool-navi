#include "../src/pch.h"
#include "../src/game.h"

Game::Game()
{
	ExitGame = 0;
	MenuClosed = 0;
	SettingsOpen = 0;
}
void Game::Draw()
{
	if (!MenuClosed && !SettingsOpen)
	{
		menu.Draw();
	}
	else if(SettingsOpen)
	{
		menu.DrawSettings();
	}
	else 
	{
		DrawText("GG bro", 500, 300, 40, GREEN);
	}

}
void Game::Update()
{
	if (!MenuClosed)
	{
		MenuClosed = menu.IsStartClicked();
		SettingsOpen = menu.IsSettingsClicked(SettingsOpen);
		ExitGame = menu.IsExitClicked();
	}
}
