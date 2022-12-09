#pragma once
#include "../Base/Base.h"

class Change : public Base {
private:
	//���
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
		eState_Change,
	};
	//��ԕϐ�
	int m_state;
	int m_cnt;

	CImage m_img;
	//���]�t���O
	bool m_flip;
	//���n�t���O
	bool m_is_ground;

	//���n�t���O��
	bool m_is_ground2;

	//�A�C�e���t���O
	//bool m_item;

	//�G���A�`�F���W�t���O
	bool m_enable_area_change;
	//�G���A�`�F���W�I�u�W�F�N�g�ɐG��Ă���t���O
	bool m_hit_area_change;

	//�G���A���[�v�t���O
	bool m_enable_Warp;
	//�G���A���[�v�I�u�W�F�N�g�ɐG��Ă���t���O
	bool m_hit_Warp;

	//�U���ԍ�
	int m_attack_no;
	//�_���[�W�ԍ�
	int m_damage_no;
	//�q�b�g�|�C���g
	int m_hp;

	//�e��Ԃł̋���
	void StateIdle();
	void StateAttack();
	void StateDamage();
	void StateDown();
	void StateChange();

public:
	Change(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};