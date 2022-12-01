#include "Player.h"
#include "Change.h"
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

void Player::StateIdle() {
	//�ړ���
	const float move_speed = 6;
	//�W�����v��
	const float jump_pow = 12;
	//�ړ��t���O
	bool move_flag = false;

	bool move_flag2 = false;
	//���ړ�
	if (HOLD(CInput::eLeft)) {
		//�ړ��ʂ�ݒ�
		m_pos.x += -move_speed;
		//���]�t���O
		m_flip = true;
		move_flag = true;
	}
	//���ړ�
	if (HOLD(CInput::eLeft) && HOLD(CInput::eButton5)) {//�X�y�[�X�L�[
		//�ړ��ʂ�ݒ�
		m_pos.x += -move_speed;
		//���]�t���O
		m_flip = true;
		move_flag = false;
		move_flag2 = true;
	}
	//�E�ړ�
	if (HOLD(CInput::eRight)) {
		//�ړ��ʂ�ݒ�
		m_pos.x += move_speed;
		//���]�t���O
		m_flip = false;
		move_flag = true;
	}
	//�E�ړ�
	if (HOLD(CInput::eRight) && HOLD(CInput::eButton5)) {
		//�ړ��ʂ�ݒ�
		m_pos.x += move_speed;
		//���]�t���O
		m_flip = false;
		move_flag = false;
		move_flag2 = true;
	}
	//�U��
	if (PUSH(CInput::eButton1)) {
		//�U����Ԃֈڍs
		m_state = eState_Attack;
		m_attack_no++;
	}
	//�ϐg
	if (PUSH(CInput::eButton3)) {//if (GameData::life <= 2||PUSH(CInput::eButton3))
		//�ϐg��Ԃֈڍs
		m_state = eState_Change;
	}
	/*
	//�U��2
	if (PUSH(CInput::eButton3)) {
		//�U�����2�ֈڍs
		m_state = eState_Attack2;
		m_attack_no++;
	}
	//�U��3
	if (PUSH(CInput::eButton4)) {
		//�U�����3�ֈڍs
		m_state = eState_Attack3;
		m_attack_no++;
	}
	*/

	if (!m_is_ground2) {
		//�W�����v
		if (m_is_ground && PUSH(CInput::eButton2)) {
			m_vec.y = jump_pow * 0.8;
			m_is_ground2 = false;
		}
	} else {
		//�W�����v
		if (m_is_ground && PUSH(CInput::eButton2)) {
			m_vec.y = -jump_pow;
			m_is_ground = false;
			m_cnt++;
		}
	}

	//�W�����v���Ȃ�
	if (!m_is_ground&&m_is_ground2) {
		//�W�����v�񐔐���
		if (m_cnt<3) {
			//��i�W�����v
			if (!m_is_ground && PUSH(CInput::eButton2)) {
				m_vec.y = -jump_pow;
				m_is_ground = false;
				m_cnt++;
				if (m_vec.y < 0) {
					//�㏸�A�j���[�V����
					m_img.ChangeAnimation(eAnimJumpUp, false);
				}
				else {
					//���~�A�j���[�V����
					m_img.ChangeAnimation(eAnimJumpDown, false);
				}
			}
		}
		if (m_vec.y < 0)
			//�㏸�A�j���[�V����
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//���~�A�j���[�V����
			m_img.ChangeAnimation(eAnimJumpDown, false);
	}
	else {
		m_cnt = 0;
		if (move_flag2) {
			//����A�j���[�V����
			m_img.ChangeAnimation(eAnimRun);
		}
		else if(move_flag) {
			//�����A�j���[�V����
			m_img.ChangeAnimation(eAnimWalk);
		}
		else {
			m_img.ChangeAnimation(eAnimIdle);
		}
	}

	/*
	//��
	//�W�����v
	if (m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}

	//�W�����v���Ȃ�
	if (!m_is_ground) {
		if (m_vec.y < 0)
			//�㏸�A�j���[�V����
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//���~�A�j���[�V����
			m_img.ChangeAnimation(eAnimJumpDown, false);
	}
	else {
		//�ړ����Ȃ�
		if (move_flag) {
			//����A�j���[�V����
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			//�ҋ@�A�j���[�V����
			m_img.ChangeAnimation(eAnimIdle);
		}
	}
	*/

}

void Player::StateAttack(){
	//�U���A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eAnimAttack01, false);
	//3�Ԗڂ̃p�^�[���Ȃ�
	if (m_img.GetIndex() == 1) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Player_Attack, m_attack_no));
		}else {
			Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Player_Attack, m_attack_no));
		}
	}
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
		m_state = eState_Idle;
	}
}

void Player::StateDamage(){
	//�_���[�W�A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eAnimDamage, false);
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
		m_state = eState_Idle;
	}
}

void Player::StateDown() {
	//�_�E���A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eAnimDown, false);
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		Base::Add(new Effect("Effect_Smoke", m_pos + CVector2D(0, 0), m_flip));
		//�ʏ��Ԃֈڍs
		m_kill = true;
	}
}

void Player::StateChange() {
	Base::Add(new Change(m_pos,false));
	SetKill();
}

Player::Player(const CVector2D& p, bool flip) : Base(eType_Player) {
	//�摜����
	m_img = COPY_RESOURCE("Player", CImage);
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos_old = m_pos = p;
	m_img.SetSize(64, 64);
	//m_img.SetSize(128, 128);
	//���S�ʒu�ݒ�
	m_img.SetCenter(32, 64);
	//m_img.SetCenter(64, 128);
	//���T�C�Y
	//m_img.SetCenter(16, 32);
	//�����蔻��p��`�ݒ�
	//�g��
	m_rect = CRect(-29, -60, 29, 0);
	//m_rect = CRect(-32, -64, 32, 0);//�厖
	//m_rect = CRect(-64, -128, 64, 0);
	//���T�C�Y
	//m_rect = CRect(-16, -32, 16, 0);
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

	m_item = true;
}

void Player::Update() {
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

	//�ҋ@�A�j���[�V����
	//m_img.ChangeAnimation(eAnimIdle);

	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();

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
	m_scroll.x = m_pos.x - 1280 / 2;
	m_scroll.y = m_pos.y - 600;
}

void Player::Draw() {
	//�ʒu�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	//�����蔻���`�̕\��
	DrawRect();

}

void Player::Collision(Base* b) {
	switch (b->m_type) {
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
		if (Base::CollisionRect(this, b)&& PUSH(CInput::eButton5)) {//�X�y�[�X�L�[
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
					KillByType(eType_UI);
					KillByType(eType_Item);
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
		/*
		//Field�^�փL���X�g�A�^�ϊ��ł�����
		if (Field* f = dynamic_cast<Field*>(b)) {
			//�n�ʂ�艺�ɂ�������
			if (m_pos.y > f->GetGroundY()) {
				//�n�ʂ̍����ɖ߂�
				m_pos.y = f->GetGroundY();
				//�������x���Z�b�g
				m_vec.y = 0;
				//�ڒn�t���OON
				m_is_ground = true;
			}
		}
		break;
		*/
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y), m_rect);
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect);
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				m_vec.y = 0;
				m_is_ground = true;
				m_is_ground2 = true;
			}
		}
		break;
	}
}
/*
��
#include "Player.h"
#include "Field.h"
#include "AnimData.h"

void Player::StateIdle(){
	//�ړ���
	const float move_speed = 6;
	//�W�����v��
	const float jump_pow = 12;
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
	}
	//�W�����v
	if (m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}
	//�W�����v���Ȃ�
	if (!m_is_ground) {
		if (m_vec.y < 0)
			//�㏸�A�j���[�V����
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//���~�A�j���[�V����
			m_img.ChangeAnimation(eAnimJumpDown, false);
	}
	else {
		//�ړ����Ȃ�
		if (move_flag) {
			//����A�j���[�V����
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			//�ҋ@�A�j���[�V����
			m_img.ChangeAnimation(eAnimIdle);
		}
	}
}

void Player::StateAttack(){
	//�U���A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eAnimAttack01, false);
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
		m_state = eState_Idle;
	}
}

void Player::StateDamage(){
	//�_���[�W�A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eAnimDamage, false);
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
		m_state = eState_Idle;
	}

}

void Player::StateDown(){
	//�_�E���A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eAnimDown, false);
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
		m_kill = true;
	}
}

Player::Player(const CVector2D& p, bool flip) : Base(eType_Player) {
	//�摜����
	m_img = COPY_RESOURCE("Player", CImage);
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos = p;
	//���S�ʒu�ݒ�
	m_img.SetCenter(128, 224);
	//���]�t���O
	m_flip = flip;
	//�ʏ��Ԃ�
	m_state = eState_Idle;
	//���n�t���O
	m_is_ground = true;
}

void Player::Update(){
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
	}
	//�����Ă����痎������Ԃֈڍs
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//�d�͂ɂ�闎��
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	//�ҋ@�A�j���[�V����
	//m_img.ChangeAnimation(eAnimIdle);

	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();
}

void Player::Draw(){
	//�ʒu�ݒ�
	m_img.SetPos(m_pos);
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
}

void Player::Collision(Base* b){
	switch (b->m_type) {
	case eType_Field:
		//Field�^�փL���X�g�A�^�ϊ��ł�����
		if (Field* f = dynamic_cast<Field*>(b)) {
			//�n�ʂ�艺�ɂ�������
			if (m_pos.y > f->GetGroundY()) {
				//�n�ʂ̍����ɖ߂�
				m_pos.y = f->GetGroundY();
				//�������x���Z�b�g
				m_vec.y = 0;
				//�ڒn�t���OON
				m_is_ground = true;
			}
		}
		break;
	}
}

*/