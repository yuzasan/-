#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include "Goal.h"
#include "../Title/Title.h"
#include "Map.h"

Game::Game() : Base(eType_Scene) {
	//Base::Add(new Field());
	Base::Add(new Map());
	Base::Add(new Player(CVector2D(1000, 540), false));
	Base::Add(new Enemy(CVector2D(1300, 540), true));
	Base::Add(new Enemy(CVector2D(1500, 540), true));
	Base::Add(new Enemy(CVector2D(1700, 540), true));
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
