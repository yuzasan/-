#pragma once
#include "../Base/Base.h"

class ItemC :public Base {
public:
	CImage m_img;
public:
	int s;
	ItemC(const CVector2D& pos);
	void Kill();
	void Update();
	void Draw();
	void Collision(Base* b);
};

class ItemK :public Base {
public:
	CImage m_img;
public:
	int s;
	ItemK(const CVector2D& pos);
	void Kill();
	void Update();
	void Draw();
	void Collision(Base* b);
};