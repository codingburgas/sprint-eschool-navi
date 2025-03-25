#include "../src/pch.h"
#include "../src/game.h"

Game::Game()
{
	ExitGame = 0;
	MenuClosed = 0;
	SettingsOpen = 0;
	EnglishGameOpen = 0;
	SaveLoaded = 0;
	IsPaused = 0;
}
void Game::Draw()
{
	if (map.playerInRoom)
	{
		EnglishGameOpen = 1;
	}
	if (!MenuClosed && !SettingsOpen)
	{
		menu.Draw();
	}
	else if (SettingsOpen)
	{
		menu.DrawSettings();

	}
	else if (!SaveLoaded)
	{
		save.GetName();
	}
	else if (IsPaused)
	{
		menu.DrawPauseMenu();
	}
	else if (EnglishGameOpen)
	{
		EN.Draw();
	}
	else
	{
		map.Draw();
		Character.Draw();
		Character.draw_health_bar();
	}
}
void Game::Update()
{
	if (!MenuClosed || IsPaused)
	{
		MenuClosed = menu.IsStartClicked();
		IsPaused = !menu.IsStartClicked();
		if (SettingsOpen)
			SettingsOpen = menu.IsExitSettingsClicked();
		else
			SettingsOpen = menu.IsSettingsClicked(SettingsOpen);

		ExitGame = menu.IsExitClicked();
	}
	else if (!SaveLoaded)
	{
		if (save.fileExists(save.fileName)) save.Save();
		else save.Load();
		SaveLoaded = 1;
	}
	else if (IsKeyPressed(KEY_P))IsPaused = 1;
	else if (EnglishGameOpen)
	{
		EN.Update();
		EnglishGameOpen = EN.CheckIfExitPressed();

	}
	else {
		map.Update();
		Character.Update();
		Character.iscolliding = map.colliding;
		Character.update = map.playerInHall;
		if (EN.pass)
		{
			Character.health--;
			EN.pass = 0;
		}
	}
}