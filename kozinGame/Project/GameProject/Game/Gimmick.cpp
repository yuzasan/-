#include "Gimmick.h"
#include "Gamedata.h"


Warp::Warp(int stage, const CRect& rect, const CVector2D& nextplayerpos) :Base(eType_Warp) {
	m_stage = stage;
	m_pos = CVector2D(rect.m_left, rect.m_top);
	m_rect = CRect(0, 0, rect.m_right, rect.m_bottom);
	m_nextplayerpos = nextplayerpos;
}

Warp::~Warp(){

}

void Warp::Draw(){
	DrawRect();
}

Gravity2::Gravity2(int stage, const CRect& rect) :Base(eType_Gravity2) {
	m_stage = stage;
	m_pos = CVector2D(rect.m_left, rect.m_top);
	m_rect = CRect(0, 0, rect.m_right, rect.m_bottom);
}

Gravity2::~Gravity2(){

}

void Gravity2::Draw(){
	DrawRect();
}

Gravity3::Gravity3(int stage, const CRect& rect) :Base(eType_Gravity2) {
	m_stage = stage;
	m_pos = CVector2D(rect.m_left, rect.m_top);
	m_rect = CRect(0, 0, rect.m_right, rect.m_bottom);
	i = i;
}

Gravity3::~Gravity3() {

}

void Gravity3::Update() {
	i++;
	if (i % 120 == 0) {
		GameData::k = 1;
	}
	else if (i > 240) {
		i = 0;
		GameData::k = 0;
		KillByType(eType_Gravity2);
	}
	if (i == 120) {
		//重力エリアの生成
		Base::Add(new Gravity3(GameData::stage = 1,
			CRect(32 * 66, 1024, 32 * 12, 32 * 10)));//32*2で1マップチップ
			//CRect(32 * 66, 32 * 32, 512, 512)));
	}
}

void Gravity3::Draw() {
	DrawRect();
}
