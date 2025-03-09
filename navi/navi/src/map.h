#pragma once
#include "pch.h"
#include "../src/charecter.h"
class Map {
public:
	Map();
	void Draw();
	void Update();
	vector<bool> colliding;
	Rectangle LeftHitBox;
	Rectangle RightHitBox;
	Rectangle TopHitBox;
	Rectangle BottomHitBox;
private:
	Texture2D Background;
	vector<Rectangle> ObjInLeft;
	vector<Rectangle> ObjInRight;
	vector<Rectangle> ObjInTop;
	vector<Rectangle> ObjInBottom;
	Vector2 position;
	Charecter charecter;
	Rectangle playerHitBox;
};