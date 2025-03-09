#include "charecter.h" 
Charecter::Charecter()
{
	charecter = LoadTexture("Graphics/scarfy.png");
	position = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
	speed = 10;
	frameSpeed = 10;
	currentFrame = 0;
	frameCounter = 0;
	frames = 6;
	frameRec = { 0.0f, 0.0f, (float)charecter.width / frames, (float)charecter.height };
}
void Charecter::Draw()
{
	ClearBackground(RAYWHITE);
	DrawTextureRec(charecter, frameRec, position, WHITE);
}
void Charecter::Update()
{
	if (IsKeyDown(KEY_RIGHT) && iscolliding[0]) position.x += speed;
	if (IsKeyDown(KEY_LEFT) && iscolliding[1]) position.x -= speed;
	if (IsKeyDown(KEY_UP) && iscolliding[2])	position.y -= speed;
	if (IsKeyDown(KEY_DOWN) && iscolliding[3]) position.y += speed;
	frame_update();
}
void Charecter::frame_update()
{
	frameCounter++;
	if (frameCounter > (60 / frameSpeed))
	{
		frameCounter = 0;
		currentFrame++;
		if (currentFrame > 5)
		{
			currentFrame = 0;
		}
		frameRec.x = (float)currentFrame * (float)charecter.width / 6;
	}
}