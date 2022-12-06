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
	Base::Add(new Map(1,CVector2D(100,100)));
	//�v���C���[�̐���
	Base::Add(new Player(CVector2D(32 * 65, 1340), false));
	//Base::Add(new Player(CVector2D(100, 32 * 8), false));
}

Game::~Game(){
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	GameData::a = 0;
	GameData::life = 4;
	GameData::ItemC = 3;
	GameData::ItemK = 10;
	//�^�C�g���V�[����
	Base::Add(new Title());
}

void Game::Update(){
	//�S�[����������΃Q�[���V�[���I��
	if (GameData::a==1) {
		SetKill();
	}


	//�G���^�[�L�[(�{�^��10)�ŃQ�[���V�[���I��
	if (PUSH(CInput::eButton10)) {
		SetKill();
	}

	//�̗�(Heart)���Ȃ��Ȃ�{�^��1�ŃQ�[���V�[���I��
	if (GameData::life == 0 && PUSH(CInput::eButton1)) {
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
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	//�^�C�g���V�[����
	Base::Add(new Title());
}

void Game::Update(){
	//�S�[����������΃Q�[���V�[���I��
	if (!Base::FindObject(eType_Goal)) {
		SetKill();
	}

	//�v���C���[���S�@�{�^��1�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}
}
*/
