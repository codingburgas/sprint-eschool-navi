#pragma once
#include "pch.h"
#include "../src/Charecter.h"
class Map {
public:
	Map();
	void Draw();
	void Update();
	vector<bool> colliding;
	vector<bool> toBeStoped;
	Rectangle LeftHitBox;
	Rectangle RightHitBox;
	Rectangle TopHitBox;
	Rectangle BottomHitBox;
	Texture2D Background;
	Texture2D mainDoor_Opened;
	Texture2D mainDoor_Closed;
	Rectangle DoorHitBox;
	Texture2D hallway;
	bool playerInHall;
	bool doorOpened;
private:
	vector<Rectangle> ObjInLeft;
	vector<Rectangle> ObjInRight;
	vector<Rectangle> ObjInTop;
	vector<Rectangle> ObjInBottom;
	Vector2 position;
	Character Character;
	Rectangle playerHitBox;
	Vector2 LeftTopMax;
	Vector2 RightBottomMax;
};