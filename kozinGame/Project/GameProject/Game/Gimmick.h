#pragma once
#include "../Base/Base.h"
class Warp :public Base {
public:
	int m_stage;
	CVector2D m_nextplayerpos;
public:
	Warp(int stage, const CRect& rect, const CVector2D& nextplayerpos);
	~Warp();
	void Draw();
};

class Gravity_Up :public Base {
public:
	int m_stage;
	bool m_gravity;
public:
	Gravity_Up(int stage, const CRect& rect);
	~Gravity_Up();
	void Draw();
};

class Gravity_Right :public Base {
public:
	int m_stage;
	bool m_gravity;
public:
	int i;
	Gravity_Right(int stage, const CRect& rect);
	~Gravity_Right();
	void Update();
	void Draw();
};

class Gravity_Left :public Base {
public:
	int m_stage;
	bool m_gravity;
public:
	Gravity_Left(int stage, const CRect& rect);
	~Gravity_Left();
	void Draw();
};

class Zoom :public Base {
public:
	int m_stage;
	bool m_zoom;
public:
	Zoom(int stage, const CRect& rect);
	~Zoom();
	void UpDate();
	void Draw();
	//void Collision(Base* b);
};

class Smog :public Base {
public:
	CImage m_img;
public:
	int s;
	Smog(const CVector2D& pos);
	void Kill();
	void Update();
	void Draw();
	void Collision(Base* b);
};

class SmogAll :public Base {
public:
	int m_stage;
	bool m_smog;
public:
	SmogAll(int stage, const CRect& rect);
	~SmogAll();
	void Draw();
};