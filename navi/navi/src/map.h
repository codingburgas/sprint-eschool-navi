#pragma once
#include "pch.h"
#include "../src/charecter.h"
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
private:
	vector<Rectangle> ObjInLeft;
	vector<Rectangle> ObjInRight;
	vector<Rectangle> ObjInTop;
	vector<Rectangle> ObjInBottom;
	Vector2 position;
	Charecter charecter;
	Rectangle playerHitBox;
	Vector2 LeftTopMax;
	Vector2 RightBottomMax;
};