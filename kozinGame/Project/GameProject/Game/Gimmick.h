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
class Gravity2 :public Base {
public:
	int m_stage;
	bool m_gravity;
public:
	Gravity2(int stage, const CRect& rect);
	~Gravity2();
	void Draw();
};