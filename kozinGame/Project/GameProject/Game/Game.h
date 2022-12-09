#pragma once
#include "../Base/Base.h"

class Game : public Base {
public:
	int c = 0;
	Game();
	~Game();
	void Update();
};

class GameClear : public Base {
	//�摜�I�u�W�F�N�g
	CImage m_img;
	//�����\���I�u�W�F�N�g
	CFont m_clear_text;
public:
	GameClear();
	~GameClear();
	void Update();
	void Draw();
};

class GameOver : public Base {
	//�摜�I�u�W�F�N�g
	CImage m_img;
	//�����\���I�u�W�F�N�g
	CFont m_over_text;
public:
	GameOver();
	~GameOver();
	void Update();
	void Draw();
};