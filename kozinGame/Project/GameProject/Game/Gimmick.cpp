#include "Gimmick.h"

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
