#pragma once
#include "../Base/Base.h"

class Siya : public Base {
private:
	//�摜�I�u�W�F�N�g
	//CImage m_img;
	//���]�t���O
	bool m_flip;
public:
	int t = 0;
	Siya(const CVector2D& pos, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};