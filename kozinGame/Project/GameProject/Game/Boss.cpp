#include "Boss.h"
#include "../Base/Base.h"
#include "Field.h"
#include "Player.h"
#include "Slash.h"
#include "Effect.h"
#include "Goal.h"
#include "AnimData.h"
#include "Map.h"
#include "Item.h"
#include "Siya.h"
#include "GameData.h"

void Boss::StateIdle() {
	//�ړ���
	const float move_speed = 6;
	//�ړ��t���O
	bool move_flag = false;

	if (GameData::S == 0) {
		//printf("c:%d\n", c);
		if (c > 36000) {
			c = 0;
		}
		k = rand() % 60 + 120;
		if (c % 4 == 0 || c % 4 == 1) {
			if (w <= k) {
				//�ړ��ʂ�ݒ�
				m_pos.x += -move_speed;
				//���]�t���O
				m_flip = true;
				move_flag = true;
				if (s == 1) {
					Base::Add(new Siya(m_pos + CVector2D(-256, -128), m_flip));
				}
				else if (s > 2) {
					KillByType(eType_Siya);
					s = 0;
				}
			}
		}
		else {
			if (w <= k) {
				//�ړ��ʂ�ݒ�
				m_pos.x += move_speed;
				//���]�t���O
				m_flip = false;
				move_flag = true;
				if (s == 1) {
					Base::Add(new Siya(m_pos + CVector2D(0, -128), m_flip));
				}
				else if (s > 2) {
					KillByType(eType_Siya);
					s = 0;
				}
			}
		}
	}
	else {
		//�v���C���[��T��
		Base* player = Base::FindObject(eType_Player);
		if (player) {
			//���ړ�
			if (player->m_pos.x < m_pos.x - 64) {
				//�ړ��ʂ�ݒ�
				m_pos.x += -move_speed;
				//���]�t���O
				m_flip = true;
				move_flag = true;
				if (s == 1) {
					Base::Add(new Siya(m_pos + CVector2D(-256, -128), m_flip));
				}
				else if (s > 2) {
					KillByType(eType_Siya);
					s = 0;
				}
			}
			else
				//�E�ړ�
				if (player->m_pos.x > m_pos.x + 64) {
					//�ړ��ʂ�ݒ�
					m_pos.x += move_speed;
					//���]�t���O
					m_flip = false;
					move_flag = true;
					if (s == 1) {
						Base::Add(new Siya(m_pos + CVector2D(0, -128), m_flip));
					}
					else if (s > 2) {
						KillByType(eType_Siya);
						s = 0;
					}
				}
				else {
					//�U����Ԃֈڍs
					m_state = eState_Attack;
					m_attack_no++;
				}
		}
		Base* change = Base::FindObject(eType_Change);
		if (change) {
			//���ړ�
			if (change->m_pos.x < m_pos.x - 64) {
				//�ړ��ʂ�ݒ�
				m_pos.x += -move_speed;
				//���]�t���O
				m_flip = true;
				move_flag = true;
				if (s == 1) {
					Base::Add(new Siya(m_pos + CVector2D(0, -128), m_flip));
				}
				else if (s > 2) {
					KillByType(eType_Siya);
					s = 0;
				}
			}
			else
				//�E�ړ�
				if (change->m_pos.x > m_pos.x + 64) {
					//�ړ��ʂ�ݒ�
					m_pos.x += move_speed;
					//���]�t���O
					m_flip = false;
					move_flag = true;
					if (s == 1) {
						Base::Add(new Siya(m_pos + CVector2D(0, -128), m_flip));
					}
					else if (s > 2) {
						KillByType(eType_Siya);
						s = 0;
					}
				}
				else {
					//�U����Ԃֈڍs
					m_state = eState_Attack;
					m_attack_no++;
				}
		}
	}

	//�ړ����Ȃ�
	if (move_flag) {
		//����A�j���[�V����
		m_img.ChangeAnimation(eAnimRun);
	}

	//�J�E���g0�őҋ@��Ԃ�
	if (--m_cnt <= 0) {
		//�ҋ@����1�b�`2�b
		m_cnt = rand() % 60 + 120;
		m_state = eState_Wait;
	}

	if (GameData::S == 1) {
		//k2 = rand() % 600 + 900;
		if (GameData::t > GameData::random) {
			GameData::S = 0;
		}
	}
}

void Boss::StateWait() {
	//�ҋ@�A�j���[�V����
	m_img.ChangeAnimation(eAnimIdle);
	//�J�E���g0�Œʏ��Ԃ�
	if (--m_cnt <= 0) {
		//�ҋ@����1�b�`2�b
		m_cnt = rand() % 60 + 120;
		w = 0;
		c += 1;
		m_state = eState_Idle;
	}
}

void Boss::StateAttack() {
	//�U���A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eAnimAttack01, false);
	//3�Ԗڂ̃p�^�[���Ȃ�
	if (m_img.GetIndex() == 3) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
		}

	}
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
		m_state = eState_Idle;
	}
}

void Boss::StateDamage() {
	//�_���[�W�A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eAnimDamage, false);
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
		m_state = eState_Idle;
	}

}

void Boss::StateDown() {
	//�_�E���A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eAnimDown, false);
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		Base::Add(new Effect("Effect_Smoke", m_pos + CVector2D(0, 0), m_flip));
		//�ʏ��Ԃֈڍs
		m_kill = true;
		GameData::S = 0;
	}
}

Boss::Boss(const CVector2D& pos, bool flip) :Base(eType_Boss) {
	//�摜����
	m_img = COPY_RESOURCE("Boss", CImage);
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos = pos;
	//���W�ݒ�
	m_pos_old = m_pos = pos;
	//���S�ʒu�ݒ�
	m_img.SetCenter(128, 224);
	//�����蔻��p��`�ݒ�
	m_rect = CRect(-32, -128, 32, 0);
	//���]�t���O
	m_flip = flip;
	//�ʏ��Ԃ�
	m_state = eState_Idle;
	//���n�t���O
	m_is_ground = true;
	//�U���ԍ�
	m_attack_no = rand();
	//�_���[�W�ԍ�
	m_damage_no = -1;
	//�q�b�g�|�C���g
	m_hp = 100;
}

void Boss::Update() {
	m_pos_old = m_pos;
	switch (m_state) {
		//�ʏ���
	case eState_Idle:
		StateIdle();
		break;
		//�҂����
	case eState_Wait:
		StateWait();
		break;
		//�U�����
	case eState_Attack:
		StateAttack();
		break;
		//�_���[�W���
	case eState_Damage:
		StateDamage();
		break;
		//�_�E�����
	case eState_Down:
		StateDown();
		break;
	}

	//�����Ă����痎������Ԃֈڍs
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//�d�͂ɂ�闎��
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	s++;
	w++;

	GameData::t++;
	//printf("k2:%d t:%d\n",k2, GameData::t);

	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();
}

void Boss::Draw() {
	//�ʒu�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	//�����蔻���`�̕\��
	//DrawRect();
	//DrawRectB();
}

void Boss::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Field:
		/*
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y));
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y));
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				m_vec.y = 0;
				m_is_ground = true;
			}
		}
		break;
		*/
		if (Map* m = dynamic_cast<Map*>(b)) {
			for (int i = 0; i < 4; i++) {
				int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y), m_rect, i);
				if (GameData::S == 1) {
					if (t != 0) {
						m_pos.x = m_pos_old.x;
					}
				}
				else {
					if (t == 1) {
						if (m_flip == 0) {
							m_flip = false;
							c += 1;
						}
						if (m_flip == 1) {
							m_flip = true;
							c += 1;
						}
						//m_pos.x = 640;
						//m_pos.y = 1340;
					}
					if (t == 2 || t == 3 || t == 4) {
						m_pos.x = m_pos_old.x;
					}
				}
				t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect, i);
				if (t != 0) {
					m_pos.y = m_pos_old.y;
					m_vec.y = 0;
					m_is_ground = true;
				}
				/*
				if (t == 1 || t == 2 || t == 4) {
					m_pos.y = m_pos_old.y;
					m_vec.y = 0;
					m_is_ground = true;
				}
				*/
			}
		}
		break;
		//�U���I�u�W�F�N�g�Ƃ̔���
	case eType_Player_Attack:
		//Slash�^�փL���X�g�A�^�ϊ��ł�����
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				//�����U���̘A���_���[�W�h�~
				m_damage_no = s->GetAttackNo();
				m_hp -= 50;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
				Base::Add(new Effect("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
			}
		}
		break;
	}
}