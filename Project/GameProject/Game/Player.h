#pragma once
#include "../Base/Base.h"
class Player : public Base {
private:
	//ジャンプフラグ
	int	m_jump_count;
	//着地フラグ
	bool m_is_ground;

	CImage m_img;

	int m_hp;
	int m_max_hp;

	//エリアチェンジフラグ
	bool m_enable_area_change;
	//エリアチェンジオブジェクトに触れているフラグ
	bool m_hit_area_change;


public:
	Player();
	~Player();
	void Update();
	void Draw();
	void Collision(Base* b);
};

extern TexAnimData player_anim_data[];
