#include "charecter.h" 
Charecter::Charecter()
{
	charecterRight = LoadTexture("Graphics/WalkRight.png");
	charecterLeft = LoadTexture("Graphics/WalkLeft.png");
	charecterUp = LoadTexture("Graphics/WalkUp.png");
	charecterDown = LoadTexture("Graphics/WalkDown.png");
	defaultFrame = LoadTexture("Graphics/Default.png");
	position = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
	speed = 10;
	frameSpeed = 15;
	currentFrame = 0;
	frameCounter = 0;
	frames = 4;
	frameRecRight = { 0.0f, 0.0f, (float)charecterRight.width / frames, (float)charecterRight.height };
	frameRecLeft = { 0.0f, 0.0f, (float)charecterLeft.width / frames, (float)charecterLeft.height };
	frameRecUp = { 0.0f, 0.0f, (float)charecterUp.width / frames, (float)charecterUp.height };
	frameRecDown = { 0.0f, 0.0f, (float)charecterDown.width / frames, (float)charecterDown.height };
}
void Charecter::Draw()
{
	ClearBackground(RAYWHITE);

	if (IsKeyDown(KEY_RIGHT))
	DrawTextureRec(charecterRight, frameRecRight, position, WHITE);
	else if (IsKeyDown(KEY_LEFT))
	DrawTextureRec(charecterLeft, frameRecLeft, position, WHITE);
	else if (IsKeyDown(KEY_UP))
	DrawTextureRec(charecterUp, frameRecUp, position, WHITE);
	else if (IsKeyDown(KEY_DOWN))
	DrawTextureRec(charecterDown, frameRecDown, position, WHITE);
	else DrawTexture(defaultFrame, position.x ,position.y ,WHITE);
}
void Charecter::Update()
{
	if (IsKeyDown(KEY_RIGHT) && iscolliding[0]) position.x += speed;
	if (IsKeyDown(KEY_LEFT) && iscolliding[1]) position.x -= speed;
	if (IsKeyDown(KEY_UP) && iscolliding[2])	position.y -= speed;
	if (IsKeyDown(KEY_DOWN) && iscolliding[3]) position.y += speed;
	if(IsKeyDown(KEY_RIGHT))frame_update_right();
	else frameRecRight.x=0;
	if (IsKeyDown(KEY_LEFT))frame_update_left();
	else frameRecLeft.x = 0;
	if (IsKeyDown(KEY_UP))frame_update_up();
	else frameRecUp.x = 0;
	if (IsKeyDown(KEY_DOWN))frame_update_down();
	else frameRecDown.x = 0;
}
void Charecter::frame_update_right()
{
	frameCounter++;
	if (frameCounter > (60 / frameSpeed))
	{
		frameCounter = 0;
		currentFrame++;
		if (currentFrame > 3)
		{
			currentFrame = 0;
		}
		frameRecRight.x = (float)currentFrame * (float)charecterRight.width / 4+17;
	}
}
void Charecter::frame_update_left()
{
	frameCounter++;
	if (frameCounter > (60 / frameSpeed))
	{
		frameCounter = 0;
		currentFrame++;
		if (currentFrame > 3)
		{
			currentFrame = 0;
		}
		frameRecLeft.x = (float)currentFrame * (float)charecterRight.width / 4+17;
	}
}
void Charecter::frame_update_up()
{
	frameCounter++;
	if (frameCounter > (60 / frameSpeed))
	{
		frameCounter = 0;
		currentFrame++;
		if (currentFrame > 3)
		{
			currentFrame = 0;
		}
		frameRecUp.x = (float)currentFrame * (float)charecterRight.width / 4+17;
	}
}
void Charecter::frame_update_down()
{
	frameCounter++;
	if (frameCounter > (60 / frameSpeed))
	{
		frameCounter = 0;
		currentFrame++;
		if (currentFrame > 3)
		{
			currentFrame = 0;
		}
		frameRecDown.x = (float)currentFrame * (float)charecterRight.width / 4+17;
	}
}