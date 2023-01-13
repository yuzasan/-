#include "Base.h"
//static�����o�ϐ��̒�`
std::list<Base*> Base::m_list;
//�X�N���[���l�̒�`
CVector2D Base::m_scroll(0, 0);

Base* Base::FindObject(int type) {
	//�擪�̗v�f
	auto it = m_list.begin();
	//�����̗v�f
	auto last = m_list.end();
	//it�������łȂ����
	while (it != last) {
		if ((*it)->m_type == type) {
			//�������I�u�W�F�N�g�̕ԋp
			return (*it);
		}
		it++;
	}

	return nullptr;
}

std::list<Base*> Base::FindObjects(int type) {
	std::list<Base*> ret;
	for (auto& b : m_list) {
		if (b->m_type == type)
			ret.push_back(b);
	}
	return ret;
}

//�R���X�g���N�^�̃����o�ϐ��� : �ϐ���() �ŏ������łł���
Base::Base(int type) : m_type(type), m_kill(false), m_pos(0, 0), m_vec(0, 0), m_rad(0) {

}

Base::~Base() {

}

void Base::Update() {

}

void Base::Draw() {

}

void Base::Collision(Base* b) {

}

CVector2D Base::GetScreenPos(const CVector2D& pos) {
	//���W-�X�N���[���l=��ʏ�ł̈ʒu
	return pos - m_scroll;
}

void Base::CheckKillAll() {
	auto it = m_list.begin();
	auto last = m_list.end();
	while (it != last) {
		if ((*it)->m_kill) {
			delete(*it);
			it = m_list.erase(it);
		}
		else {
			//����
			it++;
		}
	}
}

void Base::UpdateAll() {
	//�S�ẴI�u�W�F�N�g�̍X�V����
	//b��Base��b
	for (auto& b : m_list) {
		b->Update();
	}
}

void Base::DrawAll() {
	//�S�ẴI�u�W�F�N�g�̕`�揈��
	//b��Base��b
	for (auto& b : m_list) {
		b->Draw();
	}
}

void Base::Add(Base* b) {
	//Type���ɂ��\�[�g
	auto itr = m_list.begin();
	while (itr != m_list.end()) {
		if ((*itr)->m_type > b->m_type) {
			m_list.insert(itr, b);
			return;
		}
		itr++;
	}

	//�I�u�W�F�N�gb�𖖔��ɒǉ�
	//b��Base��b
	m_list.push_back(b);
}

void Base::KillAll() {
	std::list<Base*>ret;
	for (auto& b : m_list) {
		b->SetKill();
	}
}

void Base::KillByType(int type)
{
	//�w��̎�ނ�S�č폜
	std::list<Base*> ret;
	for (auto& b : m_list) {
		if (b->m_type == type)
			b->SetKill();
	}
}

void Base::CollisionAll() {
	//�����蔻��̌���
	auto it1 = m_list.begin();
	auto last = m_list.end();
	while (it1 != last) {
		auto it2 = it1;
		it2++;
		while (it2 != last) {
			(*it1)->Collision(*it2);
			(*it2)->Collision(*it1);
			it2++;
		}
		it1++;
	}
}

bool Base::CollisionCircle(Base* b1, Base* b2) {
	CVector2D v = b1->m_pos - b2->m_pos;
	float l = v.Length();
	if (l < b1->m_rad + b2->m_rad) {
		return true;
	}
	return false;
}

bool Base::CollisionRect(Base* b1, Base* b2) {
	//b1�̋�`
	CRect rect1 = CRect(
		b1->m_pos.x + b1->m_rect.m_left,
		b1->m_pos.y + b1->m_rect.m_top,
		b1->m_pos.x + b1->m_rect.m_right,
		b1->m_pos.y + b1->m_rect.m_bottom);
	//b2�̒Z�`
	CRect rect2 = CRect(
		b2->m_pos.x + b2->m_rect.m_left,
		b2->m_pos.y + b2->m_rect.m_top,
		b2->m_pos.x + b2->m_rect.m_right,
		b2->m_pos.y + b2->m_rect.m_bottom);

	//��`���m�̔���
	if (rect1.m_left <= rect2.m_right &&
		rect1.m_right >= rect2.m_left &&
		rect1.m_top <= rect2.m_bottom &&
		rect1.m_bottom >= rect2.m_top)
		return true;

	return false;
}

void Base::DrawRect() {
	//�f�o�b�N�p ��`�\��
	CRect rect = CRect(
		m_pos.x + m_rect.m_left,
		m_pos.y + m_rect.m_top,
		m_pos.x + m_rect.m_right,
		m_pos.y + m_rect.m_bottom);
	Utility::DrawQuad(
		CVector2D(rect.m_left, rect.m_top) - m_scroll,
		CVector2D(rect.m_width, rect.m_height),
		CVector4D(1, 0, 0, 0.5f));
}

void Base::DrawRectB() {
	//�f�o�b�N�p ��`�\��
	CRect rect = CRect(
		m_pos.x + m_rect.m_left,
		m_pos.y + m_rect.m_top,
		m_pos.x + m_rect.m_right,
		m_pos.y + m_rect.m_bottom);
	Utility::DrawQuad(
		CVector2D(rect.m_left, rect.m_top) - m_scroll,
		CVector2D(rect.m_width, rect.m_height),
		CVector4D(0, 0, 1, 0.5f));
}
