#include "GamePlayScene.h"
#include "SceneManager.h"
#include "GamePlayScene/Collision.h"

void GamePlayScene::Initialize()
{
	shootingplayer = new ShootingPlayer();

	//追加例
	//通常                           x    y  sizeX sizeY  target
	/*moblist.push_back(new Shooter(800, 100, 32, 32, shootingplayer));
	//ホーミング
	moblist.push_back(new HomingShooter(800, 200, 32, 32, shootingplayer));
	//レーザー
	moblist.push_back(new LaserShooter(800, 300, 32, 32, shootingplayer));*/

}

void GamePlayScene::Finalize()
{
}

void GamePlayScene::Update(char keys[256], char oldkeys[256])
{
	if (keys[KEY_INPUT_ESCAPE] == true && oldkeys[KEY_INPUT_ESCAPE] == false) {
		SceneManager::GetInstance()->ChangeScene("SELECT");
		return;
	}

	if (isClear) {
		// ゲームクリアシーンへ
		SceneManager::GetInstance()->ChangeScene("CLEAR");
		return;
	}

	if (phase == 0 && turn == 0) {
		moblist.push_back(new Shooter(1000, 75, 32, 32, shootingplayer));
		moblist.push_back(new Shooter(800, 225, 32, 32, shootingplayer));
		moblist.push_back(new Shooter(1000, 375, 32, 32, shootingplayer));
		moblist.push_back(new Shooter(800, 525, 32, 32, shootingplayer));
		moblist.push_back(new Shooter(1000, 675, 32, 32, shootingplayer));
		phase = 1;
	}
	if (turn == 0 && moblist.size() == 0) {
		turn = 1;
		phase = 0;
	}
	if (turn == 1 && phase == 0) {
		moblist.push_back(new HomingShooter(800, 75, 32, 32, shootingplayer));
		moblist.push_back(new HomingShooter(1000, 225, 32, 32, shootingplayer));
		moblist.push_back(new HomingShooter(800, 375, 32, 32, shootingplayer));
		moblist.push_back(new HomingShooter(1000, 525, 32, 32, shootingplayer));
		moblist.push_back(new HomingShooter(800, 675, 32, 32, shootingplayer));
		phase = 1;
	}
	if (turn == 1 && moblist.size() == 0) {
		turn = 2;
		phase = 0;
	}
	if (turn == 2 && phase == 0) {
		moblist.push_back(new LaserShooter(800, 120, 32, 32, shootingplayer));
		moblist.push_back(new LaserShooter(900, 240, 32, 32, shootingplayer));
		moblist.push_back(new LaserShooter(1000, 360, 32, 32, shootingplayer));
		moblist.push_back(new LaserShooter(900, 480, 32, 32, shootingplayer));
		moblist.push_back(new LaserShooter(800, 600, 32, 32, shootingplayer));
		phase = 1;
	}
	if (turn == 2 && moblist.size() == 0) {


	}

	AllUpdate();
}

void GamePlayScene::Draw()
{
	for (auto mobitr = moblist.begin(); mobitr != moblist.end(); ++mobitr) {
		(*mobitr)->Draw();
	}

	shootingplayer->Draw();
}

void GamePlayScene::AllUpdate()
{
	for (auto mobitr = moblist.begin(); mobitr != moblist.end(); ++mobitr) {
		(*mobitr)->Update();
	}
	for (auto mobitr = moblist.begin(); mobitr != moblist.end();) {
		if ((*mobitr)->GetHp() <= 0) {
			mobitr = moblist.erase(mobitr);
		}
		else {
			++mobitr;
		}
	}
	Collision();
	shootingplayer->Update();
	if (shootingplayer->GetHp() <= 0) {
		delete(shootingplayer);
	}
}

void GamePlayScene::Collision()
{
	std::list<PlayerBullet*> bullets = shootingplayer->GetPlayerBullet();
	for (auto bulletsitr = bullets.begin(); bulletsitr != bullets.end(); ++bulletsitr) {
		for (auto enemyitr = moblist.begin(); enemyitr != moblist.end(); ++enemyitr) {
			if (Collision::SquareToSquare((*bulletsitr)->GetBulletX() - (*bulletsitr)->GetSizeX(),
				(*bulletsitr)->GetBulletY() - (*bulletsitr)->GetSizeY(),
				(*bulletsitr)->GetBulletX() + (*bulletsitr)->GetSizeX(),
				(*bulletsitr)->GetBulletY() + (*bulletsitr)->GetSizeY(),
				(*enemyitr)->GetULeftX(), (*enemyitr)->GetULeftY(),
				(*enemyitr)->GetDRightX(), (*enemyitr)->GetDRightY())) {
				(*bulletsitr)->onCollision();
				(*enemyitr)->GetShot();
			}
		}
	}
}


