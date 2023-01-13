#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include "Goal.h"
#include "../Title/Title.h"
#include "Map.h"
#include "Gamedata.h"
#include "UI.h"

Game::Game() : Base(eType_Scene) {
	Base::Add(new Map(0, CVector2D(100, 100)));
	//プレイヤーの生成
	Base::Add(new Player(CVector2D(MAP_TIP_SIZE * 20, 1340), false));
	//Base::Add(new Player(CVector2D(100, 32 * 8), false));
}

Game::~Game() {
	switch (c) {
	case 1:
		//全てのオブジェクトを破棄
		Base::KillAll();
		GameData::a = 0;
		GameData::life = 4;
		GameData::ItemC = 3;
		GameData::ItemK = 6;
		GameData::time = 240;//GameData::time = 60;
		GameData::S = 0;
		c = 0;
		Base::Add(new GameClear());
		break;
	case 2:
		//全てのオブジェクトを破棄
		Base::KillAll();
		GameData::a = 0;
		GameData::life = 4;
		GameData::ItemC = 3;
		GameData::ItemK = 6;
		GameData::time = 60;
		GameData::S = 0;
		c = 0;
		Base::Add(new GameOver());
		break;
	default:
		//全てのオブジェクトを破棄
		Base::KillAll();
		GameData::a = 0;
		GameData::life = 4;
		GameData::ItemC = 3;
		GameData::ItemK = 6;
		GameData::time = 60;
		GameData::S = 0;
		c = 0;
		//タイトルシーンへ
		Base::Add(new Title());
		break;
	}
}

void Game::Update() {
	if (a > 36000) {
		a = 0;
	}
	a++;
	//ゴールが無ければゲームシーン終了
	if (GameData::a == 1) {
		SetKill();
		c = 1;
	}

	//エンターキー(ボタン10)でゲームシーン終了
	if (PUSH(CInput::eButton10)) {
		//SetKill();
	}

	//マウス右clickでゲームシーン終了
	if (PUSH(CInput::eMouseR)) {
		SetKill();
	}

	//体力(Heart)がなくなりボタン1でゲームシーン終了
	if (GameData::life == 0 && !Base::FindObject(eType_Player) || GameData::life == 0 && !Base::FindObject(eType_Change)) {
		SetKill();
		c = 2;
	}

	if (GameData::time <= 0) {
		SetKill();
		c = 2;
	}

	if (GameData::S == 1) {
		b++;
		if (b == 1) {
			GameData::random = rand() % 600 + 900;
		}
	}
	else {
		b = 0;
	}
	printf("random:%d t:%d\n", GameData::random, GameData::t);
}


/*
#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include "Goal.h"
#include "../Title/Title.h"
#include "Map.h"

Game::Game() : Base(eType_Scene) {
	//Base::Add(new Field());
	Base::Add(new Map(1,CVector2D(100,100)));
	Base::Add(new Player(CVector2D(100, 100), false));
	//Base::Add(new Player(CVector2D(1000, 540), false));
	Base::Add(new Enemy(CVector2D(1300, 540), true));
	//Base::Add(new Enemy(CVector2D(1500, 540), true));
	//Base::Add(new Enemy(CVector2D(1700, 540), true));
	Base::Add(new Goal(CVector2D(2048, 540)));
}

Game::~Game(){
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーンへ
	Base::Add(new Title());
}

void Game::Update(){
	//ゴールが無ければゲームシーン終了
	if (!Base::FindObject(eType_Goal)) {
		SetKill();
	}

	//プレイヤー死亡　ボタン1でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}
}
*/

GameClear::GameClear() : Base(eType_Scene), m_clear_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("Title", CImage);//後で変更する
}

GameClear::~GameClear() {
	//全てのオブジェクトを破棄
	Base::KillAll();
	//ゲームシーンへ
	Base::Add(new Title());
}

void GameClear::Update() {
	//ボタン1でタイトル破棄
	if (PUSH(CInput::eButton1)) {
		SetKill();
	}
}

void GameClear::Draw() {
	m_img.Draw();
	//文字表示
	m_clear_text.Draw(64, 255, 255, 255, 255, "ゲームクリア");
	m_clear_text.Draw(64, 355, 255, 255, 255, "THANK YOU FOR PLAYING");
	m_clear_text.Draw(64, 512, 255, 255, 255, "Push Z");
}

GameOver::GameOver() : Base(eType_Scene), m_over_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("Title", CImage);//後で変更する
}

GameOver::~GameOver() {
	//全てのオブジェクトを破棄
	Base::KillAll();
	//ゲームシーンへ
	Base::Add(new Title());
}

void GameOver::Update() {
	//ボタン1でタイトル破棄
	if (PUSH(CInput::eButton1)) {
		SetKill();
	}
}

void GameOver::Draw() {
	m_img.Draw();
	//文字表示
	m_over_text.Draw(64, 255, 255, 255, 255, "ゲームオーバー");
	m_over_text.Draw(64, 355, 255, 255, 255, "行動は慎重に");
	m_over_text.Draw(64, 512, 255, 255, 255, "Push Z");
}