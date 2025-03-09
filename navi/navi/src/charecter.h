#pragma once
#include "pch.h"
class Charecter
{
public:
	Charecter();
	void Draw();
	void PlayerMoving();
	void FrameChecker();
	int frames;
	int frameWidth;
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
