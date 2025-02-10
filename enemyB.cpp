#include "enemyB.h"
#include <Novice.h>
enemyB::enemyB()      //enemyB変数の初期化
{
	posX_ = 320;
	posY_ = 200;
	speedX_ = 10;
	speedY_ = 0;
	radius_ = 20;
}
void enemyB::Update() //enemyB関数の初期化
{
	posX_ += speedX_;
	if (posX_ >= 1280 - radius_) {
		speedX_ = -10;
	}
	if (posX_ <= 0 + radius_) {
		speedX_ = 10;
	}
}

void  enemyB::Draw() {
	if (isAliveB == 1) {//isShotが1のときだけ描画
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
}
