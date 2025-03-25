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
	destination = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 , frameRecRight.width, frameRecRight.height };
	origin = { 0,0 };
	health = 5;
	hp = { LoadTexture("Graphics/health bar1.png"), LoadTexture("Graphics/health bar2.png"), LoadTexture("Graphics/health bar3.png"), LoadTexture("Graphics/health bar4.png"), LoadTexture("Graphics/health bar5.png")};
	gameOver = LoadTexture("Graphics/GameOver.png");
}
void Character::Draw()
{
	ClearBackground(RAYWHITE);

	if (IsKeyDown(KEY_RIGHT))
	DrawTexturePro(CharacterRight, frameRecRight, destination, origin, 0, WHITE);
	else if (IsKeyDown(KEY_LEFT))
	DrawTexturePro(CharacterLeft, frameRecLeft, destination, origin, 0, WHITE);
	else if (IsKeyDown(KEY_UP))
	DrawTexturePro(CharacterUp, frameRecUp, destination, origin, 0, WHITE);
	else if (IsKeyDown(KEY_DOWN))
	DrawTexturePro(CharacterDown, frameRecDown, destination, origin, 0, WHITE);
	else DrawTexture(defaultFrame, destination.x, destination.y, WHITE);
}
void Character::Update()
{
	if (IsKeyDown(KEY_RIGHT) && iscolliding[0]) destination.x += speed;
	if (IsKeyDown(KEY_LEFT) && iscolliding[1]) destination.x -= speed;
	if (IsKeyDown(KEY_UP) && iscolliding[2])	destination.y -= speed;
	if (IsKeyDown(KEY_DOWN) && iscolliding[3]) destination.y += speed;
	if(IsKeyDown(KEY_RIGHT))frame_update_right();
	else frameRecRight.x=0;
	if (IsKeyDown(KEY_LEFT))frame_update_left();
	else frameRecLeft.x = 0;
	if (IsKeyDown(KEY_UP))frame_update_up();
	else frameRecUp.x = 0;
	if (IsKeyDown(KEY_DOWN))frame_update_down();
	else frameRecDown.x = 0;

	if (update)
	{
		destination.width = 192;
		destination.height = 225;
		defaultFrame.width = 192;
		defaultFrame.height = 225;
	}

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

void Character::draw_health_bar()
{
	switch (health)
	{
	case 1:
		DrawTextureEx(hp[0], { 10, 20 }, 0, 0.2, WHITE);
		break;
	case 2:
		DrawTextureEx(hp[1], { 10, 20 }, 0, 0.2, WHITE);
		break;
	case 3:
		DrawTextureEx(hp[2], { 10, 20}, 0, 0.2, WHITE);
		break;
	case 4:
		DrawTextureEx(hp[3], { 10, 20}, 0, 0.2, WHITE);
		break;
	case 5:
		DrawTextureEx(hp[4], { 10, 20}, 0, 0.2, WHITE);
		break;
	case 0:
		DrawTextureEx(gameOver, { 10, 20 }, 0, 0.2, WHITE);
		break;
	}
}