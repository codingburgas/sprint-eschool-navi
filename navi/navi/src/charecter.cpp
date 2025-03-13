#include "Charecter.h" 
Character::Character()
{
	CharacterRight = LoadTexture("Graphics/WalkRight.png");
	CharacterLeft = LoadTexture("Graphics/WalkLeft.png");
	CharacterUp = LoadTexture("Graphics/WalkUp.png");
	CharacterDown = LoadTexture("Graphics/WalkDown.png");
	defaultFrame = LoadTexture("Graphics/Default.png");
	position = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
	speed = 7;
	frameSpeed = 10;
	currentFrame = 0;
	frameCounter = 0;
	frames = 4;
	frameRecRight = { 0.0f, 0.0f, (float)CharacterRight.width / frames, (float)CharacterRight.height };
	frameRecLeft = { 0.0f, 0.0f, (float)CharacterLeft.width / frames, (float)CharacterLeft.height };
	frameRecUp = { 0.0f, 0.0f, (float)CharacterUp.width / frames, (float)CharacterUp.height };
	frameRecDown = { 0.0f, 0.0f, (float)CharacterDown.width / frames, (float)CharacterDown.height };
}
void Character::Draw()
{
	ClearBackground(RAYWHITE);

	if (IsKeyDown(KEY_RIGHT))
	DrawTextureRec(CharacterRight, frameRecRight, position, WHITE);
	else if (IsKeyDown(KEY_LEFT))
	DrawTextureRec(CharacterLeft, frameRecLeft, position, WHITE);
	else if (IsKeyDown(KEY_UP))
	DrawTextureRec(CharacterUp, frameRecUp, position, WHITE);
	else if (IsKeyDown(KEY_DOWN))
	DrawTextureRec(CharacterDown, frameRecDown, position, WHITE);
	else DrawTexture(defaultFrame, position.x ,position.y ,WHITE);
}
void Character::Update()
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
void Character::frame_update_right()
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
		frameRecRight.x = (float)currentFrame * (float)CharacterRight.width / 4+17;
	}
}
void Character::frame_update_left()
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
		frameRecLeft.x = (float)currentFrame * (float)CharacterRight.width / 4+17;
	}
}
void Character::frame_update_up()
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
		frameRecUp.x = (float)currentFrame * (float)CharacterRight.width / 4+17;
	}
}
void Character::frame_update_down()
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
		frameRecDown.x = (float)currentFrame * (float)CharacterRight.width / 4+17;
	}
}