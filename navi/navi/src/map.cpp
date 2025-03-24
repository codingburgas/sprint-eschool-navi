#include "../src/map.h"

Map::Map()
{
	Background = LoadTexture("Graphics/map.png");
	LeftHitBox = { 0.f, 0.f, 50.f, (float)GetScreenHeight() };
	RightHitBox = { GetScreenWidth() - 50.f, 0.f, 50.f, (float)GetScreenHeight() };
	BottomHitBox = { 0.f, GetScreenHeight() - 50.f,(float)GetScreenWidth(), 50.f };
	TopHitBox = { 0.f, 0.f, (float)GetScreenWidth(), 50.f };
	position = { 0, 0 };
	playerHitBox = { (float)GetScreenWidth() / 2 - 30, (float)GetScreenHeight() / 2 - 30, (float)Character.frameRecRight.width * 1.5f, Character.frameRecRight.height * 1.5f };
	colliding = { 1, 1, 1, 1 };
	toBeStoped = { 0, 0, 0, 0 };
	LeftTopMax = { -(Background.width - (float)GetScreenWidth()) / 2 - 190 , -540 };
	RightBottomMax ={ 1440, 1340 };
	mainDoor_Opened = LoadTexture("Graphics/doorOpened.png");
	mainDoor_Closed = LoadTexture("Graphics/doorClosed.png");
	hallway = LoadTexture("Graphics/Hallway.png");
	playerInHall = 0;
	playerInRoom = 0;
	room = LoadTexture("Graphics/Schoolroom.png");
	doors = { 0,0,0,0,0 };
	doorsHitBox = { { 450, (float)GetScreenHeight() / 2, (float)mainDoor_Opened.width / 2, (float)mainDoor_Closed.height / 2 - 55}, { 10, 10, 250, 370 } };

	SetStop = 0;
}

void Map::Draw()
{
	if (playerInRoom)
	{
		ClearBackground(WHITE);
		DrawTextureEx(room, position, 0, 6, WHITE);
	}
	else
	{
		if (playerInHall)
		{
			ClearBackground(WHITE);
			DrawTexture(hallway, position.x, position.y, WHITE);
			DrawRectangleRec(doorsHitBox[1], RED);
			DrawRectangleRec(playerHitBox, RED);

		}
		else
		{
			ClearBackground(RAYWHITE);
			DrawRectangleRec(LeftHitBox, WHITE);
			DrawRectangleRec(RightHitBox, WHITE);
			DrawRectangleRec(TopHitBox, WHITE);
			DrawRectangleRec(BottomHitBox, WHITE);


			DrawRectangleRec(DoorHitBox, RED);
			DrawTexture(Background, position.x - GetScreenWidth() / 2, position.y - GetScreenHeight() / 2, WHITE);
			if (doors[0])
			{
				DrawTexture(mainDoor_Opened, 450, (float)GetScreenHeight() / 2, WHITE);
				DrawText("Press E to enter", 400, (float)GetScreenHeight() - 25, 25, RED);
			}
			else
			{
				DrawTexture(mainDoor_Closed, 450, (float)GetScreenHeight() / 2, WHITE);
			}
		}
			if (doors[1])
			{
				DrawText("Press E to enter", 400, (float)GetScreenHeight() - 25, 25, RED);
			}
	}

} 

void Map::Update()
{
	holder = Character.GetDest();
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
		if (LeftTopMax.x < 0) { LeftTopMax.x += Character.speed; position.x += Character.speed; }
		RightBottomMax.x += Character.speed;
	}
	else if (IsKeyDown(KEY_LEFT) && colliding[1])
	{
		playerHitBox.x -= Character.speed; colliding[1] = true;
	}
	
	if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_UP)) colliding[0] = true;
	if (CheckCollisionRecs(RightHitBox, playerHitBox) && IsKeyDown(KEY_RIGHT) && colliding[0])
	{
		colliding[0] = false;
		if (RightBottomMax.x > GetScreenWidth()) { RightBottomMax.x -= Character.speed; position.x -= Character.speed; }
		LeftTopMax.x -= Character.speed;
	}
	else if (IsKeyDown(KEY_RIGHT) && colliding[0])
	{
		playerHitBox.x += Character.speed; colliding[0] = true;
	}

	if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_LEFT)) colliding[2] = true;
	if (CheckCollisionRecs(TopHitBox, playerHitBox) && IsKeyDown(KEY_UP) && colliding[2])
	{
		colliding[2] = false;
		if (LeftTopMax.y < 0 && SetStop < holder.y) { LeftTopMax.y += Character.speed; position.y += Character.speed; }
		RightBottomMax.y += Character.speed;
	}
	else if (IsKeyDown(KEY_UP) && colliding[2])
	{
		playerHitBox.y -= Character.speed; colliding[2] = true;
	}

	if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_UP)) colliding[3] = true;
	if (CheckCollisionRecs(BottomHitBox, playerHitBox) && IsKeyDown(KEY_DOWN) && colliding[3])
	{
		colliding[3] = false;
		if (RightBottomMax.y > GetScreenHeight()) { RightBottomMax.y -= Character.speed; position.y -= Character.speed; }
		LeftTopMax.y -= Character.speed;
	}
	else if (IsKeyDown(KEY_DOWN) && colliding[3])
	{
		playerHitBox.y += Character.speed; colliding[3] = true;
	}
	for (size_t i = 1; i < doorsHitBox.size(); i++)
	{
		if (CheckCollisionRecs(doorsHitBox[i], playerHitBox) && playerInHall)
		{
			doors[i] = 1;
			if (IsKeyPressed(KEY_E))
			{
				playerInRoom = 1;
				position = { 0, 0 };
			}
		}
		else doors[i] = 0;
	}
		if (CheckCollisionRecs(doorsHitBox[0], playerHitBox))
		{
			doors[0] = 1;

			if (IsKeyPressed(KEY_E))
			{
				playerInHall = 1;
				position = { 0, 0 };
				LeftTopMax = { 400, 0 };
				RightBottomMax = { 4500, (float)GetScreenHeight() };
				position.x = -400;
				SetStop = 200;
			}
		}
		else doors[0] = 0;

		cout << holder.y;

}