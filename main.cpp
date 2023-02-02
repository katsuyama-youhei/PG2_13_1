#include"Enemy.h"
#include"Player.h"
#include <Novice.h>

const char kWindowTitle[] = "LC1A_06_カツヤマヨウヘイ_タイトル";

const int Enemy::enemyCount = 2;
int Enemy::isAlive = true;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	int e2bX[Enemy::enemyCount];
	int e2bY[Enemy::enemyCount];
	int e2bR[Enemy::enemyCount];

	Enemy *enemy[Enemy::enemyCount];
	for (int i = 0; i < Enemy::enemyCount; i++) {
		enemy[i] = new Enemy;
		e2bX[i] = 0;
		e2bY[i] = 0;
		e2bR[i] = 0;
		enemy[i]->SetPositionY(enemy[i]->GetPositionY(), i);
		enemy[i]->SetPositionX(enemy[i]->GetPositionX(), i);
	}
	Player* player = new Player;
	

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

		for (int i = 0; i < Enemy::enemyCount; i++) {
			enemy[i]->Update();
			e2bX[i]=enemy[i]->GetPositionX()-player->GetPositionX();
			e2bY[i]= enemy[i]->GetPositionY() - player->GetPositionY();
			e2bR[i]= enemy[i]->GetRadius() + player->GetRadius();
			if (e2bR[i] * e2bR[i] > e2bX[i] * e2bX[i] + e2bY[i] * e2bY[i]) {
				Enemy::isAlive = false;
			}
		}
		player->Update(keys);

		if (keys[DIK_R]) {
			Enemy::isAlive = true;
		}
		

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		for (int i = 0; i < Enemy::enemyCount; i++) {
			enemy[i]->Draw();
		}
		player->Draw();

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
