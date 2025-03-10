#include "../src/pch.h"
#include "../src/menu.h"

Menu::Menu()
{
	StartButton = { 350, 275, 150.f, 50.f };
	SettingsButton = { 350, 375, 150, 50 };
	ExitButton = { 350, 475, 150, 50 };
	SettingsExitButton = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2, 150, 50 };
	Background = LoadTexture("Graphics/tester.png");
}
void Menu::Draw()
{
	ClearBackground(RAYWHITE);
	DrawTexture(Background, 0, 0, WHITE);
	DrawRectangleRec(StartButton, GREEN);
	DrawRectangleRec(SettingsButton, GRAY);
	DrawRectangleRec(ExitButton, RED);
	DrawText("START", 380, 290, 25, WHITE);
	DrawText("OPTION", 380, 390, 20, WHITE);
	DrawText("EXIT", 395, 490, 20, WHITE);
}

bool Menu::IsStartClicked()
{
	if (CheckCollisionPointRec(GetMousePosition(), StartButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		return 1;
	else 
		return 0;
}
bool Menu::IsSettingsClicked(bool check)
{
	if (CheckCollisionPointRec(GetMousePosition(), SettingsButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || check)
		return 1;
	else
		return 0;
}
bool Menu::IsExitClicked()
{
	if (CheckCollisionPointRec(GetMousePosition(), ExitButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		return 1;
	else
		return 0;
}
bool Menu::IsExitSettingsClicked()
{
	if (CheckCollisionPointRec(GetMousePosition(), SettingsExitButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		return 0;
	else 
		return 1;
}
void Menu::DrawSettings()
{
	ClearBackground(RAYWHITE);
	DrawTexture(Background, 0, 0, WHITE);
	DrawRectangleRec(SettingsExitButton, RED);

}