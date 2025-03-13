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
		map.Draw();
		Character.Draw();
	}

}
void Game::Update()
{
	if (!MenuClosed)
	{
		MenuClosed = menu.IsStartClicked();

		if (SettingsOpen)
			SettingsOpen = menu.IsExitSettingsClicked();
		else
			SettingsOpen = menu.IsSettingsClicked(SettingsOpen);

		ExitGame = menu.IsExitClicked();
	}
	else {
		map.Update();
		Character.iscolliding = map.colliding;
		Character.Update();
	}
}