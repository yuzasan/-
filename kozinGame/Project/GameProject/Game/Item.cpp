#include "Item.h"
#include "Gamedata.h"

ItemC::ItemC(const CVector2D& pos) :Base(eType_Item) {
	m_img = COPY_RESOURCE("ItemC", CImage);
	m_pos = pos;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
	m_rect = CRect(-16, -16, 16, 16);
}
void ItemC::Kill() {
	if (GameData::ItemC < 5) {
		GameData::ItemC = GameData::ItemC + 1;
	}
	m_kill = true;
}

void ItemC::Update() {
	switch (s) {
	case 1:
		Kill();
		break;
	default:
		break;
	}
}

void ItemC::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}

void ItemC::Collision(Base* b) {
	switch (b->m_type) {
		//アイテム判定
	case eType_Player:
		if (Base::CollisionRect(this, b)) {
			s = 1;
		}
		break;
	case eType_Change:
		if (Base::CollisionRect(this, b)) {
			s = 1;
		}
	}
}

ItemK::ItemK(const CVector2D& pos) :Base(eType_Item) {
	m_img = COPY_RESOURCE("ItemK", CImage);
	m_pos = pos;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
	m_rect = CRect(-16, -16, 16, 16);
}
void ItemK::Kill() {
	if (GameData::ItemK < 10) {
		GameData::ItemK = GameData::ItemK + 1;
	}
	m_kill = true;
}

void ItemK::Update() {
	switch (s) {
	case 1:
		Kill();
		break;
	default:
		break;
	}
}

void ItemK::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}

void ItemK::Collision(Base* b) {
	switch (b->m_type) {
		//アイテム判定
	case eType_Player:
		if (Base::CollisionRect(this, b)) {
			s = 1;
		}
		break;
	case eType_Change:
		if (Base::CollisionRect(this, b)) {
			s = 1;
		}
		break;
	}
}