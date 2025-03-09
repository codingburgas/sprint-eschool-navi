#pragma once
#include "pch.h"
class Charecter
{
public:
	Charecter();
	void Draw();
	void Update();
	void frame_update_right();
	void frame_update_left();
	void frame_update_up();
	void frame_update_down();
	int frames;
	int currentFrame;
	int frameCounter;
	int speed;
	int frameSpeed;
	Vector2 position;
	Rectangle frameRecRight;
	Rectangle frameRecLeft;
	Rectangle frameRecUp;
	Rectangle frameRecDown;
	vector<bool> iscolliding;
private:
	Texture2D charecterRight;
	Texture2D charecterLeft;
	Texture2D charecterUp;
	Texture2D charecterDown;
	Texture2D defaultFrame;
};
