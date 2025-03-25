#pragma once
#include "pch.h"
#include "Charecter.h"
class NPC
{
public:
	NPC();
	void Draw();
	void frame_update();
	void Update();
	int frameSpeed;
	int currentFrame;
	int frameCounter;
	int frames;
	Rectangle frameRec;
	Rectangle NPC_HitBox;
	Rectangle NPC_destination;
	Texture2D NPC_texture;
	Texture2D textBox;
	Vector2 NPC_position;
	Vector2 NPC_origin;
private:
	Character character;
};
