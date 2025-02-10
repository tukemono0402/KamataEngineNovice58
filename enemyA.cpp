#include "enemyA.h"
#include <Novice.h>
enemyA::enemyA()                    //enemyA変数の初期化
{
	posX_ = 640;
	posY_ = 360;
	speedX_ = 10;
	speedY_ = 0;
	radius_ = 50;
}

void enemyA::Update()               //enemyA関数の初期化
{
	posX_ += speedX_;
	if (posX_ >= 1280 - radius_) {
		speedX_ = -10;
	}
	if (posX_ <= 0 + radius_) {
		speedX_ = 10;
	}
}
void  enemyA::Draw() {

	if (isAliveA == 1) {           //isShotが1のときだけ描画
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}

}