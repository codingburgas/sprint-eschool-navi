#pragma once
#include "pch.h"
class Charecter
{
public:
	Charecter();
	void Draw();
	void Update();
	void frame_update();
	int frames;
	int currentFrame;
	int frameCounter;
	int speed;
	int frameSpeed;
	Vector2 position;
	Rectangle frameRec;
	vector<bool> iscolliding;
private:
	Texture2D charecter;
};
