#include "Siya.h"
#include "Player.h"
#include "Gamedata.h"
#include "../Base/Base.h"

Siya::Siya(const CVector2D& pos, bool flip) : Base(eType_Siya) {
	//画像情報
	//m_img = COPY_RESOURCE("Effect_Slash", CImage);
	//反転フラグ設定
	m_flip = flip;
	//座標設定
	m_pos = pos;
	//当たり判定用矩形
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
		//当たり判定矩形の表示
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
