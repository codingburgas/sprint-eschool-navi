#pragma once
#include "pch.h"
#include "../src/Charecter.h"
class Map {
public:
	Map();
	void Draw();
	void Update();
	vector<Rectangle> doorsHitBox;
	vector<bool> colliding;
	vector<bool> toBeStoped;
	vector<bool> doors;
	vector<Rectangle> roomObjectHitBoxes;
	Rectangle LeftHitBox;
	Rectangle RightHitBox;
	Rectangle TopHitBox;
	Rectangle BottomHitBox;
	Rectangle DoorHitBox;
	Rectangle FirstDoorHitBox;
	Texture2D Background;
	Texture2D mainDoor_Opened;
	Texture2D mainDoor_Closed;
	Texture2D hallway;
	Texture2D room;
	bool playerInHall;
	bool doorOpened;
	bool playerInRoom;
	bool hallwayDoorOpened;
	Vector2 holder;
	float SetStop;
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