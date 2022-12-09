#pragma once
#include "../Base/Base.h"
class Player : public Base {
private:
	//�W�����v�t���O
	int	m_jump_count;
	//���n�t���O
	bool m_is_ground;

	CImage m_img;

	int m_hp;
	int m_max_hp;

	//�G���A�`�F���W�t���O
	bool m_enable_area_change;
	//�G���A�`�F���W�I�u�W�F�N�g�ɐG��Ă���t���O
	bool m_hit_area_change;


public:
	Player();
	~Player();
	void Update();
	void Draw();
	void Collision(Base* b);
};

extern TexAnimData player_anim_data[];
