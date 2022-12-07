#pragma once
#include "../Base/Base.h"

class UI :public Base {
public:
	CImage m_img;
	CImage m_img2;
	CImage m_img3;
	int cnt;
public:
	UI();
	void Update();
	void Draw();
};
