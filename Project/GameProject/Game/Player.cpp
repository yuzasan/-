#include "Player.h"
#include "Map.h"
#include "AreaChange.h"
static TexAnim _anim_down[] = {
	{0,4},
	{1,4},
	{2,4},
};
static TexAnim _anim_left[] = {
	{3,4},
	{4,4},
	{5,4},
};
static TexAnim _anim_right[] = {
	{6,4},
	{7,4},
	{8,4},
};
static TexAnim _anim_up[] = {
	{9,4},
	{10,4},
	{11,4},
};

TexAnimData player_anim_data[] = {
	ANIMDATA(_anim_down),		//eUp
	ANIMDATA(_anim_left),		//eLeft
	ANIMDATA(_anim_right),		//eRight
	ANIMDATA(_anim_up),			//eUp
};
Player::Player() :
	Base(eType_Player) {
	m_img = COPY_RESOURCE("Player",CImage);
	//���W�ݒ�
	m_pos_old = m_pos = CVector2D(0,0);
	//�W�����v��
	m_jump_count =0;
	//���n�t���O
	m_is_ground = false;

	m_img.SetSize(48, 48);
	//�����蔻��p��`�ݒ�
	m_rect = CRect(8,0, 40, 48);


	//����
	m_dir = eUp;
	//�A�j���[�V������ގw��
	m_img.ChangeAnimation(m_dir);


	m_enable_area_change = true;
	m_hit_area_change = false;

}
Player::~Player()
{

}
void Player::Update() {
	m_pos_old = m_pos;


	bool is_move = false;
	//���ړ�
	if (HOLD(CInput::eLeft)) {
		m_dir = eLeft;
		is_move = true;
	}
	//�E�ړ�
	if (HOLD(CInput::eRight)) {
		m_dir = eRight;
		is_move = true;
	}
	//��ړ�
	if (HOLD(CInput::eUp)) {
		m_dir = eUp;
		is_move = true;
	}
	//���ړ�
	if (HOLD(CInput::eDown)) {
		m_dir = eDown;
		is_move = true;
	}
	if (is_move) {
		float move_speed = 4.0f;
		//���݂̕����ֈړ�
		//�e�����̕����x�N�g��
		CVector2D move_dir[] = {
			CVector2D(0,1),		//eDown
			CVector2D(-1,0),	//eLeft
			CVector2D(1,0),		//eRight
			CVector2D(0,-1),	//eUp
		};
		//�ړ�
		m_pos += move_dir[m_dir] * move_speed;
		//�A�j���[�V�����Đ�
		m_img.m_animSpeed = 1.0f;
	} else {
		//�A�j���[�V������~
		m_img.m_animSpeed = 0.0f;
	}
	//�A�j���[�V������ގw��
	m_img.ChangeAnimation(m_dir);
	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();

	//��x�G���A�`�F���W�͈͂��痣��Ȃ��ƍēx�G���A�`�F���W���Ȃ�
	//�A���G���A�`�F���W�h�~
	if (!m_enable_area_change && !m_hit_area_change)
			m_enable_area_change = true;
	m_hit_area_change = false;
}

void Player::Draw() {
	
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}
void Player::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_AreaChange:
		if (Base::CollisionRect(this, b)) {
			//�G���A�`�F���W�ɐG��Ă���
			m_hit_area_change = true;
			//�G���A�`�F���W�\�Ȃ�
			if (m_enable_area_change) {
				if (AreaChange* a = dynamic_cast<AreaChange*>(b)) {
					//�}�b�v�ƃG���A�`�F���W�I�u�W�F�N�g���폜
					KillByType(eType_Field);
					KillByType(eType_AreaChange);
					//���̃}�b�v�𐶐�
					Base::Add(new Map(a->m_nextArea, a->m_nextplayerpos));
					//�G���A�`�F���W�ꎞ�s����
					m_enable_area_change = false;
				}
			}
		}
		
		break;
	case eType_Field:
		//�}�b�v�Ƃ̔���
		if (Map* m = dynamic_cast<Map*>(b)) {
			CVector2D pos;
			//�}�b�v�`�b�v�̔���i���j
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y),m_rect,&pos);
			//�ǂȂ��
			if (t != NULL_TIP) {
				//�Ǎۂ܂Ŗ߂�
				m_pos.x = pos.x;
			}
			//�}�b�v�`�b�v�̔���i�c�j
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect, &pos);
			//�ǂȂ��
			if (t != NULL_TIP) {
				//�Ǎۂ܂Ŗ߂�
				m_pos.y = pos.y;				
			}
		}
		break;
	}

}

