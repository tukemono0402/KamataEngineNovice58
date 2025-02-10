#pragma once
#include "enemy.h"                  //enemy.hを挿入
class enemyB :public Enemy          //enemyクラスの定義
{
public:                             //メンバ関数
	enemyB();                       //コントラクタの宣言
	void Update()override;          //Updateの上書き
	void Draw()override;            //Drawの上書き
};
