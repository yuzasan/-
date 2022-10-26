#pragma once
#include "../Base/Base.h"

class Player : public Base {
private:
	//���
	enum {
		eState_Idle,
		eState_Attack,
		eState_Attack2,
		eState_Attack3,
		eState_Damage,
		eState_Down,
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
	void StateAttack();
	void StateAttack2();
	void StateAttack3();
	void StateDamage();
	void StateDown();

public:
	Player(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};
/*
��
#pragma once
#include "../Base/Base.h"

class Player : public Base {
private:
	//���
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
	};
	//��ԕϐ�
	int m_state;

	CImage m_img;
	//���]�t���O
	bool m_flip;
	//���n�t���O
	bool m_is_ground;

	//�e��Ԃł̋���
	void StateIdle();
	void StateAttack();
	void StateDamage();
	void StateDown();

public:
	Player(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};
*/