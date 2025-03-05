#include "../src/pch.h"
#include "../src/game.h"
int main()
{
    const int screenWidth = 1000;
    const int screenHeight = 650;
    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Game game;
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        game.Draw();
        game.Update();
        cout << game.SettingsOpen;
        if (game.ExitGame)
        {
            break;
        }
        EndDrawing();
    }
}