#pragma once
#include "../Base/Base.h"

class Goal : public Base {
private:
	//�摜�I�u�W�F�N�g
	CImage m_img;
public:
	Goal(const CVector2D& pos);
	void Draw();
};