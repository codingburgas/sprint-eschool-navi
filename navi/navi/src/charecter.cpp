#include "charecter.h"
Charecter::Charecter()
{
	charecter = LoadTexture("Graphics/scarfy.png");
	Background = LoadTexture("Graphics/tester.png");
	position = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
	speed = 10;
	frameSpeed = 8;
	currentFrame = 0;
	frameCounter = 0;
	frames = 6;
	frameRec = { 0.0f, 0.0f, (float)charecter.width / frames, (float)charecter.height };
}
void Charecter::Draw()
{
	ClearBackground(RAYWHITE);
	DrawTexture(Background, 0, 0, WHITE);
	PlayerMoving();
	DrawTextureRec(charecter, frameRec, position, WHITE);
}
void Charecter::PlayerMoving()
{
	if (IsKeyDown(KEY_RIGHT)) position.x+=speed;
	if(IsKeyDown(KEY_LEFT))	position.x -= speed;
	if (IsKeyDown(KEY_UP))	position.y -= speed;
	if (IsKeyDown(KEY_DOWN)) position.y += speed;
}
void Charecter::FrameChecker()
{
}