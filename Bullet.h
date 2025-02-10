#pragma once
#include "Struct.h"     //Struct.hを挿入
class Bullet            //クラスBulletを宣言
{
public:                 //bulletのメンバ変数宣言
	Transform bullet_;
	int bulletSpeed_;
	int isShot_;

public:
	Bullet();           //bulletのメンバ関数宣言
	void Update();
	void Draw();
};