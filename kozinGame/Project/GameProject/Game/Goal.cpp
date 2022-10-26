#include "Goal.h"
#include "../Base/Base.h"

Goal::Goal(const CVector2D& pos) : Base(eType_Goal) {
	//�摜�̕���
	m_img = COPY_RESOURCE("Goal", CImage);
	//���W�ݒ�
	m_pos = pos;
	//�\���T�C�Y�ݒ�
	m_img.SetSize(64, 128);
	//���S�ʒu�ݒ�
	m_img.SetCenter(32, 128);
	//m_rect�̐ݒ�Ȃ�
	m_rect = CRect(-32, -128, 32, 0);
}

void Goal::Draw(){
	//�摜�̕`��
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	//�����蔻���`�̕\��
	DrawRect();

}
