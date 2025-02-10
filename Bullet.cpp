#include "Novice.h"
#include "Bullet.h"
Bullet::Bullet() {          //bullet変数の初期化
	bullet_.x = 10;
	bullet_.y = 10;
	bullet_.radius = 10;
	isShot_ = false;
	bulletSpeed_ = 10;
}


void Bullet::Update() {      //bullet関数の初期化

	if (isShot_ == 1) {      //isShotが1の時にY軸に-10移動する
		bullet_.y -= 10;
	}
	if (bullet_.y <= 0) {    //Y軸が0未満になったらisShotを0にする
		isShot_ = false;
	}


}
void Bullet::Draw() {
	if (isShot_ == 1) {      //isShot_が1の時だけ描画
		Novice::DrawEllipse(bullet_.x, bullet_.y, bullet_.radius, bullet_.radius, 0.0f, RED, kFillModeSolid);
	}

}