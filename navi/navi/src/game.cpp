#include "../src/pch.h"
#include "../src/game.h"

Game::Game()
{
	ExitGame = 0;
	MenuClosed = 0;
	SettingsOpen = 0;
	BulgarianGameOpen = 0;
	SaveLoaded = 0;
	IsPaused = 0;
}
void Game::Draw()
{
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
	else if (BulgarianGameOpen)
	{
		BG.Draw();
	}
	else
	{
		map.Draw();
		Character.Draw();
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
	else if (BulgarianGameOpen)
	{
		BG.Update();
		BulgarianGameOpen = BG.CheckIfExitPressed();
	}
	else {
		map.Update();
		Character.iscolliding = map.colliding;
		Character.update = map.playerInHall;
		Character.Update();
	}
}