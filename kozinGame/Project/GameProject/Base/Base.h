#pragma once
#include<GLLibrary.h>
//�d�͉����x
#define GRAVITY (9.8f/20)


enum {
	eType_Gravity2,//�\���̏��Ԃ��厖
	eType_Field,
	eType_Warp,
	eType_Player,
	eType_Change,
	eType_Enemy,
	eType_Item,
	eType_Bullet,
	eType_Goal,
	eType_Player_Attack,
	eType_Enemy_Attack,
	eType_Effect,
	eType_UI,
	eType_Scene,
	eType_AreaChange,
};

class Base {
public:
	//�I�u�W�F�N�g�̎��
	int m_type;
	//���W
	CVector2D m_pos;
	//�ړ��O�̍��W
	CVector2D m_pos_old;
	//���a
	float m_rad;
	//��`
	CRect m_rect;
	//�ړ��x�N�g��
	CVector2D m_vec;
	//�X�N���[���l
	static CVector2D m_scroll;
	//�폜�t���O
	bool m_kill;
	//�I�u�W�F�N�g�̒ǉ�
	static std::list<Base*> m_list;
	//����̃I�u�W�F�N�g��T��
	Base* Base::FindObject(int type);
	//����̃I�u�W�F�N�g��T������(����)
	static std::list<Base*>FindObjects(int type);
public:
	//�폜����
	void SetKill() { m_kill = true; }
	// ���W�̐ݒ�
	void ResetPos(const CVector2D& pos) {
		m_pos = m_pos_old = pos;
	}
	//�R���X�g���N�^��type�I�u�W�F�N�g�̎�ނ�����
	Base(int type);
	//(���z�֐���)�f�X�g���N�^
	virtual ~Base();
	//(���z�֐���)�X�V����
	virtual void Update();
	//(���z�֐���)�`�揈��
	virtual void Draw();
	//(���z�֐���)�I�u�W�F�N�g�̓����蔻��̌��؏���
	virtual void Collision(Base* b);

	//All��static��t����
	//(�ÓI�����o�֐�)�X�N���[��
	static CVector2D GetScreenPos(const CVector2D& pos);
	// �폜�t���OON
	static void CheckKillAll();
	//(�ÓI�����o�֐�)�S�čX�V����
	static void UpdateAll();
	//(�ÓI�����o�֐�)�S�ĕ`�揈��
	static void DrawAll();
	//(�ÓI�����o�֐�)�S�ăI�u�W�F�N�g�̓����蔻��̌��؏���
	static void CollisionAll();
	//(�ÓI�����o�֐�)�ǉ�����
	static void Add(Base* b);
	//�S�I�u�W�F�N�g�̍폜
	static void KillAll();

	// �w�肵����ނ̃I�u�W�F�N�g���폜
	static void KillByType(int type);

	//�~���m�̏Փ�
	static bool CollisionCircle(Base* b1, Base* b2);
	//��`���m�̔���
	static bool CollisionRect(Base* b1, Base* b2);
	//��`�̕\��
	void DrawRect();
};