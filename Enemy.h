#pragma once
class Enemy                         //クラスEnemyを宣言
{
protected:                             //enemyのメンバ変数宣言
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;


public:
	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	void SetPosision(int x, int y);
	int GetSpeedX() { return speedX_; };
	int GetSpeedY() { return speedY_; };
	void SetSpeed(int speedX, int speedY);
	int GetRadius() { return radius_; };
	void SetRadius(int radius);

	static int isAliveA;
	static int isAliveB;

public:                             //enemyのメンバ関数宣言
	virtual void Update();
	virtual void Draw();
};
