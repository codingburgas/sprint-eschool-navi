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
	toBeStoped = { 0, 0, 0, 0 };
	LeftTopMax = { -(Background.width - (float)GetScreenWidth()) / 2 - 190 , -540 };
	RightBottomMax ={ 1440, 1340 };
}

void Map::Draw()
{
	ClearBackground(RAYWHITE);
	DrawRectangleRec(LeftHitBox, WHITE);
	DrawRectangleRec(RightHitBox, WHITE);
	DrawRectangleRec(TopHitBox, WHITE);
	DrawRectangleRec(BottomHitBox, WHITE);
	
	DrawTexture(Background, position.x-GetScreenWidth()/2, position.y-GetScreenHeight()/2, WHITE);
	DrawRectangleRec(playerHitBox, RED);

} 

void Map::Update()
{
	if(!colliding[1])
	LeftTopMax.x > 0 ? colliding[1] = false : colliding[1] = true;
	if(!colliding[2])
	LeftTopMax.y > 0 ? colliding[2] = false : colliding[2] = true;
	if(!colliding[0])
	RightBottomMax.x <= GetScreenWidth() ? colliding[0] = false : colliding[0] = true;
	if(!colliding[3])
	RightBottomMax.y <= GetScreenHeight() ? colliding[3] = false : colliding[3] = true;
	if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_UP)) colliding[1] = true;
	if (CheckCollisionRecs(LeftHitBox, playerHitBox) && IsKeyDown(KEY_LEFT) && colliding[1])
	{
		colliding[1] = false;
		if (LeftTopMax.x < 0) { LeftTopMax.x += 10; position.x += 10; }
		RightBottomMax.x += 10;
	}
	else if (IsKeyDown(KEY_LEFT) && colliding[1])
	{
		playerHitBox.x -= 10; colliding[1] = true;
	}
	
	if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_UP)) colliding[0] = true;
	if (CheckCollisionRecs(RightHitBox, playerHitBox) && IsKeyDown(KEY_RIGHT) && colliding[0])
	{
		colliding[0] = false;
		if (RightBottomMax.x > GetScreenWidth()) { RightBottomMax.x -= 10; position.x -= 10;}
		LeftTopMax.x -= 10;
	}
	else if (IsKeyDown(KEY_RIGHT) && colliding[0])
	{
		playerHitBox.x += 10; colliding[0] = true;
	}

	if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_LEFT)) colliding[2] = true;
	if (CheckCollisionRecs(TopHitBox, playerHitBox) && IsKeyDown(KEY_UP) && colliding[2])
	{
		colliding[2] = false;
		if (LeftTopMax.y < 0) { LeftTopMax.y += 10; position.y += 10; }
		RightBottomMax.y += 10;
	}
	else if (IsKeyDown(KEY_UP) && colliding[2])
	{
		playerHitBox.y -= 10; colliding[2] = true;
	}

	if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_UP)) colliding[3] = true;
	if (CheckCollisionRecs(BottomHitBox, playerHitBox) && IsKeyDown(KEY_DOWN) && colliding[3])
	{
		colliding[3] = false;
		if (RightBottomMax.y > GetScreenHeight()) { RightBottomMax.y -= 10; position.y -= 10; }
		LeftTopMax.y -= 10;
	}
	else if (IsKeyDown(KEY_DOWN) && colliding[3])
	{
		playerHitBox.y += 10; colliding[3] = true;
	}
	cout << LeftTopMax.x;
}