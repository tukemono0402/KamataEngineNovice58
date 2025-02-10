#pragma once
#include "Struct.h"
#include "Bullet.h"
class Player
{
public:
	Transform GetTransform();

	int GetSpeed() { return playerSpeed_; };
	void SetSpeed(int speed);
	void SetTransform(int x, int y, int radius);
	Bullet* bullet_;

private:

	Transform player_;
	int playerSpeed_;
public:
	Player();
	~Player();
	void Update(char* keys);
	void Draw();
};