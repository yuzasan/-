#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include "Goal.h"
#include "../Title/Title.h"
#include "Map.h"

Game::Game() : Base(eType_Scene) {
	Base::Add(new Map(1,CVector2D(100,100)));
	//プレイヤーの生成
	Base::Add(new Player(CVector2D(100, 32 * 8), false));
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

	//エンターキー(ボタン10)でゲームシーン終了
	if (PUSH(CInput::eButton10)) {
		SetKill();
	}

	
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
