#pragma once
#include "enemy.h"                  //enemy.hを挿入
class enemyA :public Enemy          //enemyクラスの定義
{
public:                             //メンバ関数
	enemyA();                       //コントラクタ(宣言)
	void Update()override;          //Updateの上書き
	void Draw()override;            //Drawの上書き
};
