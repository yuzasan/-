#pragma once
#include "../Base/Base.h"

class Effect : public Base {
private:
	//�摜�I�u�W�F�N�g
	CImage m_img;
	//���]�t���O
	bool m_flip;
public:
	Effect(const char* name, const CVector2D& pos, bool flip);
	void Update();
	void Draw();
};