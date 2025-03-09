#include "../src/map.h"

Map::Map()
{
	Background = LoadTexture("Graphics/tester.png");
	LeftHitBox = { 0.f, 0.f, 50.f, (float)GetScreenHeight() };
	RightHitBox = { GetScreenWidth() - 50.f, 0.f, 50.f, (float)GetScreenHeight() };
	BottomHitBox = { 0.f, GetScreenHeight() - 50.f,(float)GetScreenWidth(), 50.f };
	TopHitBox = { 0.f, 0.f, (float)GetScreenWidth(), 50.f };
	position = { 0, 0 };
	playerHitBox = { (float)GetScreenWidth() / 2 - 30, (float)GetScreenHeight() / 2 - 30, (float)charecter.frameRecRight.width * 1.5f, charecter.frameRecRight.height * 1.5f };
	colliding = { 1, 1, 1, 1 };
}

void Map::Draw()
{
	ClearBackground(RAYWHITE);
	DrawRectangleRec(LeftHitBox, WHITE);
	DrawRectangleRec(RightHitBox, WHITE);
	DrawRectangleRec(TopHitBox, WHITE);
	DrawRectangleRec(BottomHitBox, WHITE);
	DrawRectangleRec(playerHitBox, WHITE);
	DrawTexture(Background, position.x, position.y, WHITE);

} 

void Map::Update()
{
	if (CheckCollisionRecs(LeftHitBox, playerHitBox) && IsKeyDown(KEY_LEFT))
	{
		position.x += charecter.speed; colliding[1] = false;
	}
	else if (IsKeyDown(KEY_LEFT))
	{
		playerHitBox.x -= charecter.speed; colliding[1] = true;
	}

	if (CheckCollisionRecs(RightHitBox, playerHitBox) && IsKeyDown(KEY_RIGHT))
	{
		position.x -= charecter.speed; colliding[0] = false;
	}
	else if (IsKeyDown(KEY_RIGHT))
	{
		playerHitBox.x += charecter.speed; colliding[0] = true;
	}

	if (CheckCollisionRecs(TopHitBox, playerHitBox) && IsKeyDown(KEY_UP))
	{
		position.y += charecter.speed; colliding[2] = false;
	}
	else if (IsKeyDown(KEY_UP))
	{
		playerHitBox.y -= charecter.speed; colliding[2] = true;
	}

	if (CheckCollisionRecs(BottomHitBox, playerHitBox) && IsKeyDown(KEY_DOWN))
	{
		position.y -= charecter.speed; colliding[3] = false;
	}
	else if (IsKeyDown(KEY_DOWN))
	{
		playerHitBox.y += charecter.speed; colliding[3] = true;
	}
}