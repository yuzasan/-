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

Gravity_Up::Gravity_Up(int stage, const CRect& rect) :Base(eType_Gravity_Up) {
	m_stage = stage;
	m_pos = CVector2D(rect.m_left, rect.m_top);
	m_rect = CRect(0, 0, rect.m_right, rect.m_bottom);
}

Gravity_Up::~Gravity_Up(){

}

void Gravity_Up::Draw(){
	DrawRect();
}

Gravity_Right::Gravity_Right(int stage, const CRect& rect) :Base(eType_Gravity_Right) {
	m_stage = stage;
	m_pos = CVector2D(rect.m_left, rect.m_top);
	m_rect = CRect(0, 0, rect.m_right, rect.m_bottom);
	//i = i;
}

Gravity_Right::~Gravity_Right() {

}

void Gravity_Right::Update() {
	/*
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
	*/
}

void Gravity_Right::Draw() {
	DrawRect();
}

Gravity_Left::Gravity_Left(int stage, const CRect& rect) :Base(eType_Gravity_Left) {
	m_stage = stage;
	m_pos = CVector2D(rect.m_left, rect.m_top);
	m_rect = CRect(0, 0, rect.m_right, rect.m_bottom);
}

Gravity_Left::~Gravity_Left() {

}

void Gravity_Left::Draw() {
	DrawRect();
}

Zoom::Zoom(int stage, const CRect& rect) :Base(eType_Zoom) {
	m_stage = stage;
	m_pos = CVector2D(rect.m_left, rect.m_top);
	m_rect = CRect(0, 0, rect.m_right, rect.m_bottom);
}

Zoom::~Zoom(){

}

void Zoom::UpDate(){

}

void Zoom::Draw(){
	//DrawRect();
}

/*
void Zoom::Collision(Base* b){
	switch (b->m_type) {
		//アイテム判定
	case eType_Player:
		GameData::Z = 1;
		break;
	case eType_Change:
		GameData::Z = 1;
		break;
	}
}
*/
