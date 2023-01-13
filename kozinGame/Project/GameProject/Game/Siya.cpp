#include "Siya.h"
#include "Player.h"
#include "Gamedata.h"
#include "../Base/Base.h"

Siya::Siya(const CVector2D& pos, bool flip) : Base(eType_Siya) {
	//�摜���
	//m_img = COPY_RESOURCE("Effect_Slash", CImage);
	//���]�t���O�ݒ�
	m_flip = flip;
	//���W�ݒ�
	m_pos = pos;
	//�����蔻��p��`
	m_rect = CRect(0, 0, 256, 256);
}

void Siya::Update() {
	//printf("S:%d\n",GameData::S);
	if (GameData::t > 36000) {
		GameData::t = 0;
	}
}

void Siya::Draw() {

	if (GameData::S == 1) {
		//�����蔻���`�̕\��
		DrawRect();
	}
	else {
		DrawRectB();
	}

}

void Siya::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Player:
		if (Base::CollisionRect(this, b)) {
			GameData::S = 1;
			GameData::t = 0;
		}
		break;
	case eType_Change:
		if (Base::CollisionRect(this, b)) {
			GameData::S = 1;
			GameData::t = 0;
		}
		break;
	}
}
