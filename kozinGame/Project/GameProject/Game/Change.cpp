#include "Change.h"
#include "Player.h"
#include "Field.h"
#include "Slash.h"
#include "Enemy.h"
#include "Effect.h"
#include "../Base/Base.h"
#include "AnimData.h"
#include "Map.h"
#include "AreaChange.h"
#include "Gimmick.h"
#include "Gamedata.h"
#include "UI.h"
#include "Item.h"

void Change::StateIdle() {
	//�ړ���
	const float move_speed = 4;
	//�ړ��t���O
	bool move_flag = false;
	//���ړ�
	if (HOLD(CInput::eLeft)) {
		//�ړ��ʂ�ݒ�
		m_pos.x += -move_speed;
		//���]�t���O
		m_flip = true;
		move_flag = true;
	}
	//�E�ړ�
	if (HOLD(CInput::eRight)) {
		//�ړ��ʂ�ݒ�
		m_pos.x += move_speed;
		//���]�t���O
		m_flip = false;
		move_flag = true;
	}
	//�U��
	if (PUSH(CInput::eButton1)) {
		//�U����Ԃֈڍs
		m_state = eState_Attack;
		m_attack_no++;
	}
	//�ϐg
	if (GameData::ItemC >= 1 && PUSH(CInput::eButton3)) {
		GameData::ItemC = GameData::ItemC - 1;
		//�ϐg��Ԃֈڍs
		m_state = eState_Change;
	}
	/*
	if (move_flag)
		//�����A�j���[�V����
		m_img.ChangeAnimation(eAnimWalk);
	else
		//�ҋ@�A�j���[�V����
		m_img.ChangeAnimation(eAnimIdle);
	*/
}

void Change::StateAttack() {
	/*
	//�U���A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eAnimAttack01, false);
	//3�Ԗڂ̃p�^�[���Ȃ�
	if (m_img.GetIndex() == 1) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Player_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Player_Attack, m_attack_no));
		}
	}
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
		m_state = eState_Idle;
	}
	*/
	m_state = eState_Idle;
}

void Change::StateDamage() {
	/*
	//�_���[�W�A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eAnimDamage, false);
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
		m_state = eState_Idle;
	}
	*/
	m_state = eState_Idle;
}

void Change::StateDown() {
	/*
	//�_�E���A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eAnimDown, false);
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		Base::Add(new Effect("Effect_Smoke", m_pos + CVector2D(0, 0), m_flip));
		//�ʏ��Ԃֈڍs
		m_kill = true;
	}
	*/
	m_kill = true;
}

void Change::StateChange() {
	Base::Add(new Player(m_pos, false));
	SetKill();
}

Change::Change(const CVector2D& p, bool flip) : Base(eType_Change) {
	//�摜����
	m_img = COPY_RESOURCE("Change", CImage);
	//�Đ��A�j���[�V�����ݒ�
	//m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos_old = m_pos = p;
	m_img.SetSize(64, 32);
	//���S�ʒu�ݒ�
	m_img.SetCenter(32, 32);
	//�����蔻��p��`�ݒ�
	m_rect = CRect(-30, -32, 30, 0);
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
	//�J�E���g
	m_cnt = 0;

	m_enable_area_change = true;
	m_hit_area_change = false;

	m_enable_Warp = true;
	m_hit_Warp = false;

	//���n�t���O��
	m_is_ground2 = true;

	//m_item = true;

	m_zoom = true;
}

void Change::Update() {
	m_pos_old = m_pos;
	switch (m_state) {
		//�ʏ���
	case eState_Idle:
		StateIdle();
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
	case eState_Change:
		StateChange();
		break;
	}
	//�����Ă����痎������Ԃֈڍs
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//�d�͂ɂ�闎��
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	//�A�j���[�V�����X�V
	//m_img.UpdateAnimation();

	//��x�G���A�`�F���W�͈͂��痣��Ȃ��ƍēx�G���A�`�F���W���Ȃ�
	//�A���G���A�`�F���W�h�~
	if (!m_enable_area_change && !m_hit_area_change)
		m_enable_area_change = true;
	m_hit_area_change = false;

	//��x���[�v�͈͂��痣��Ȃ��ƍēx���[�v���Ȃ�
	//�A�����[�v�h�~
	if (!m_enable_Warp && !m_hit_Warp)
		m_enable_Warp = true;
	m_hit_Warp = false;

	//�X�N���[���ݒ�
	if (!m_zoom) {
		m_scroll.x = m_pos.x - 1920 / 2;
		m_scroll.y = m_pos.y - 960;
	}
	else {
		m_scroll.x = m_pos.x - 1920 / 2;
		m_scroll.y = m_pos.y - 680;//��m_scroll.y = m_pos.y - 680
	}
}

void Change::Draw() {
	//�ʒu�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	//�����蔻���`�̕\��
	DrawRect();

}

void Change::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Zoom:
		if (Base::CollisionRect(this, b)) {
			//�Y�[���G���A�ɐG��Ă�����
			m_zoom = true;
			if (m_zoom)
				m_zoom = false;
		}
		break;
	/*
		//�A�C�e������
	case eType_Item:
		if (Base::CollisionRect(this, b)) {
			//�A�C�e���ɐG��Ă�����
			if (m_item) {
				GameData::Item = GameData::Item + 1;
				KillByType(eType_Item);
				m_item = false;
			}
		}
		break;
	*/
		//�d�͔���
	case eType_Gravity2:
		if (Base::CollisionRect(this, b)) {
			//�d�̓G���A�ɐG��Ă�����
			if (m_is_ground2)
				m_is_ground2 = false;
			//�d�͂ɂ�闎��
			m_vec.y -= GRAVITY * 2;
			m_pos += m_vec;
		}
		break;
		//�G���A�`�F���W����
	case eType_AreaChange:
		if (Base::CollisionRect(this, b) && PUSH(CInput::eButton5)) {//�X�y�[�X�L�[
			//�G���A�`�F���W�ɐG��Ă���
			m_hit_area_change = true;
			//�G���A�`�F���W�\�Ȃ�
			if (m_enable_area_change) {
				if (AreaChange* a = dynamic_cast<AreaChange*>(b)) {
					//�}�b�v�ƃG���A�`�F���W�I�u�W�F�N�g���폜
					KillByType(eType_Field);
					KillByType(eType_AreaChange);
					KillByType(eType_Warp);
					KillByType(eType_Enemy);
					KillByType(eType_Goal);
					KillByType(eType_Gravity2);
					//���̃}�b�v�𐶐�
					Base::Add(new Map(a->m_stage, a->m_nextplayerpos));
					//�G���A�`�F���W�ꎞ�s����
					m_enable_area_change = false;
				}
			}
		}
		break;
		//���[�v����
	case eType_Warp:
		if (Base::CollisionRect(this, b)) {
			//���[�v�ɐG��Ă���
			m_hit_Warp = true;
			//���[�v�\�Ȃ�
			if (m_enable_Warp) {
				if (Warp* a = dynamic_cast<Warp*>(b)) {
					ResetPos(a->m_nextplayerpos);
					//�G���A�`�F���W�ꎞ�s����
					m_enable_area_change = false;
				}
			}
		}
		break;
		//�S�[������
	case eType_Goal:
		if (Base::CollisionRect(this, b)) {
			b->SetKill();
			GameData::a = 1;
		}
		break;
		//�U���I�u�W�F�N�g�Ƃ̔���
	case eType_Enemy_Attack:
		//Slash�^�փL���X�g�A�^�ϊ��ł�����
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				//�����U���̘A���_���[�W�h�~
				m_damage_no = s->GetAttackNo();
				//m_hp -= 50;
				GameData::life = GameData::life - 1;
				KillByType(eType_UI);
				if (GameData::life <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
				Base::Add(new Effect("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
			}
		}
		break;
	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {
			for (int i = 0; i < 4; i++) {
				int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y), m_rect, i);
				if (t == 1 || t == 3) {
					m_pos.x = m_pos_old.x;
				}
				t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect, i);
				if (t == 1 || t == 4||t == 2) {
					m_pos.y = m_pos_old.y;
					m_vec.y = 0;
					m_is_ground = true;
					m_is_ground2 = true;
				}
			}
			/*
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y), m_rect);
			if (t == 1) {
				m_pos.x = m_pos_old.x;
			}
			if (t == 4) {
				m_pos.y = m_pos_old.y;
			}
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect);
			if (t == 3) {
				m_pos.x = m_pos_old.x;
				m_is_ground = true;
				m_is_ground2 = true;
			}
			if (t == 1 || t == 4) {
				m_pos.y = m_pos_old.y;
				m_vec.y = 0;
				m_is_ground = true;
				m_is_ground2 = true;
			}*/
			/*
			else{
				m_pos.y = m_pos_old.y;
				m_vec.y = 0;
				m_is_ground = true;
				m_is_ground2 = true;
			}
			
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				m_vec.y = 0;
				m_is_ground = true;
				m_is_ground2 = true;
			}
			*/
		}
		break;
	}
}