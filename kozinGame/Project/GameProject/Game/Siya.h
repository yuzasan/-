#pragma once
#include "../Base/Base.h"

class Siya : public Base {
private:
	//画像オブジェクト
	//CImage m_img;
	//反転フラグ
	bool m_flip;
public:
	int t = 0;
	Siya(const CVector2D& pos, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};