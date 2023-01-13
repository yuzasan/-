#pragma once
#include "../Base/Base.h"

class Boss : public Base {
private:
	//���
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
		eState_Wait,
	};
	//��ԕϐ�
	int m_state;
	int m_cnt;

	CImage m_img;
	//���]�t���O
	bool m_flip;
	//���n�t���O
	bool m_is_ground;
	//�U���ԍ�
	int m_attack_no;
	//�_���[�W�ԍ�
	int m_damage_no;
	//�q�b�g�|�C���g
	int m_hp;

	//�e��Ԃł̋���
	void StateIdle();
	void StateWait();
	void StateAttack();
	void StateDamage();
	void StateDown();

public:
	int s = 0;
	int r = 0;
	int w = 0;
	int k = 0;
	int k2 = 0;
	int c = 0;
	// �R���X�g���N�^
	Boss(const CVector2D& pos, bool flip);
	// �X�V
	void Update();
	// �`��
	void Draw();
	void Collision(Base* b);
};