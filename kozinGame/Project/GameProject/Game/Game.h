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
	//画像オブジェクト
	CImage m_img;
	//文字表示オブジェクト
	CFont m_clear_text;
public:
	GameClear();
	~GameClear();
	void Update();
	void Draw();
};

class GameOver : public Base {
	//画像オブジェクト
	CImage m_img;
	//文字表示オブジェクト
	CFont m_over_text;
public:
	GameOver();
	~GameOver();
	void Update();
	void Draw();
};