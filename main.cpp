#include <Novice.h>
#include "enemy.h"
#include "enemyA.h"
#include "enemyB.h"
#include <Player.h>
const char kWindowTitle[] = "GC1C_10_トミグチカオル_タイトル";

enum Scene {          //シーンの宣言
	START,
	PLAY,
	CLEAR
};
int currentScene = 0; //Sceneを0で設定

int time = 60;

int Enemy::isAliveA;  //isAlive
int Enemy::isAliveB;  //

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	Player* player = new Player();
	player->SetTransform(10, 10, 10);
	player->SetSpeed(10);

	Bullet* bullet = new Bullet();


	enemyA* enemya = new enemyA();
	enemyB* enemyb = new enemyB();

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Enemy::isAliveA = true;
	Enemy::isAliveB = true;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (currentScene) {
		case START:
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				currentScene = PLAY;
				player->SetTransform(10, 10, 10);
				player->SetSpeed(10);
				bullet->bullet_.x = -10;
				bullet->bullet_.y = -10;

				Enemy::isAliveA = true;
				Enemy::isAliveB = true;
			}

			break;
		case PLAY:

			if (Enemy::isAliveA == 1) {

				float distX = (float)enemya->GetPosX() - (float)player->bullet_->bullet_.x;
				float distY = (float)enemya->GetPosY() - (float)player->bullet_->bullet_.y;
				float distXY = (distX * distX) + (distY * distY);
				float radiusXY = ((float)enemya->GetRadius() + (float)player->bullet_->bullet_.radius);
				if (distXY <= radiusXY * radiusXY) {
					Enemy::isAliveA = 0;
					bullet->isShot_ = false;
				}

				float distA = (float)enemya->GetPosX() - (float)player->GetTransform().x;
				float distB = (float)enemya->GetPosY() - (float)player->GetTransform().y;
				float distAB = (distA * distA) + (distB * distB);
				float radiusAB = ((float)enemya->GetRadius() + (float)player->GetTransform().radius);
				if (distAB <= radiusAB * radiusAB) {
					Enemy::isAliveA = 0;
				}
				enemya->Update();

			}
			if (Enemy::isAliveB == 1) {

				float distX = (float)enemyb->GetPosX() - (float)player->bullet_->bullet_.x;
				float distY = (float)enemyb->GetPosY() - (float)player->bullet_->bullet_.y;
				float dist = (distX * distX) + (distY * distY);
				float radius = ((float)enemyb->GetRadius() + (float)player->bullet_->bullet_.radius);
				if (dist <= radius * radius) {
					Enemy::isAliveB = 0;
					bullet->isShot_ = false;
				}

				float distA = (float)enemyb->GetPosX() - (float)player->GetTransform().x;
				float distB = (float)enemyb->GetPosY() - (float)player->GetTransform().y;
				float distAB = (distA * distA) + (distB * distB);
				float radiusAB = ((float)enemyb->GetRadius() + (float)player->GetTransform().radius);
				if (distAB <= radiusAB * radiusAB) {
					Enemy::isAliveB = 0;
				}
				enemyb->Update();

			}



			/*if (keys[DIK_R]) {
				Enemy::isAliveA = true;
				Enemy::isAliveB = true;
			}*/
			if (Enemy::isAliveA == false && Enemy::isAliveB == false) {
				time--;

			}
			if (time <= 0) {
				currentScene = CLEAR;
				time = 60;
			}
			player->Update(keys);
			break;
		case CLEAR:
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				currentScene = START;
			}
			break;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (currentScene) {
		case START:
			Novice::ScreenPrintf(10, 10, "START");
			break;
		case PLAY:
			enemya->Draw();
			enemyb->Draw();
			player->Draw();
			break;

		case CLEAR:
			Novice::ScreenPrintf(10, 10, "CLEAR");
			break;
		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}