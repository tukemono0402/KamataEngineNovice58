#include "Novice.h"
#include "Player.h"

Transform Player::GetTransform()
{
	Transform a;
	a = player_;

	return a;
}



void Player::SetSpeed(int speed)
{
	playerSpeed_ = speed;
}

void Player::SetTransform(int x, int y, int radius)
{
	player_.x = x;
	player_.y = y;
	player_.radius = radius;
}

Player::Player() {
	player_.x = 10;
	player_.y = 10;
	player_.radius = 10;
	playerSpeed_ = 10;
	bullet_ = new Bullet;
}
Player::~Player() {
	delete bullet_;
}
void Player::Update(char* keys) {
	if (keys[DIK_W]) {//Dを押したら右に移動
		player_.y -= playerSpeed_;
	}

	if (keys[DIK_S]) {//Aを押したら左に移動
		player_.y += playerSpeed_;
	}

	if (keys[DIK_D]) {       //Wを押したら上に移動
		player_.x += playerSpeed_;
	}

	if (keys[DIK_A]) {       //Sを押したら下に移動
		player_.x -= playerSpeed_;
	}

	bullet_->Update();
	if (keys[DIK_SPACE]) {

		bullet_->isShot_ = true;
		bullet_->bullet_.x = player_.x;
		bullet_->bullet_.y = player_.y;


	}
}
void Player::Draw() {

	bullet_->Draw();

	Novice::DrawEllipse(player_.x, player_.y, player_.radius, player_.radius, 0.0f, WHITE, kFillModeSolid);
}