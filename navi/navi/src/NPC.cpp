#include "NPC.h" 

NPC::NPC()
{
	NPC_texture = LoadTexture("Graphics/NPC.png");
	textBox = LoadTexture("Graphics/textBox.png");
	frameSpeed = 10;
	currentFrame = 0;
	frameCounter = 0;
	frames = 7;
	frameRec = { 0.0f, 0.0f, (float)NPC_texture.width / frames, (float)NPC_texture.height };
	NPC_position = {500,150};
	NPC_origin = { 0,0 };
	NPC_destination = { 500, 150,frameRec.width, frameRec.height };
}
void NPC::Draw()
{
	ClearBackground(RAYWHITE);
	DrawTexturePro(NPC_texture, frameRec,  NPC_destination,NPC_origin,0, WHITE);
}
void NPC::Update()
{
	if (IsKeyDown(KEY_RIGHT) && character.iscolliding[0]) NPC_position.x += character.speed;
	if (IsKeyDown(KEY_LEFT) && character.iscolliding[1]) NPC_position.x -= character.speed;
	if (IsKeyDown(KEY_UP) && character.iscolliding[2])	NPC_position.y -= character.speed;
	if (IsKeyDown(KEY_DOWN) && character.iscolliding[3]) NPC_position.y += character.speed;
	if (character.update)
	{
		NPC_destination.width = 192*2;
		NPC_destination.height = 225*2;
	}
}
void NPC::frame_update()
{
	frameCounter++;
	if (frameCounter > (60 / frameSpeed))
	{
		frameCounter = 0;
		currentFrame++;
		if (currentFrame > 6)
		{
			currentFrame = 0;
		}
		frameRec.x = (float)currentFrame * (float)NPC_texture.width /7;
	}
}