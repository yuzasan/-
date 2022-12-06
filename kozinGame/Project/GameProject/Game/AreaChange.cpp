#include "AreaChange.h"

AreaChange::AreaChange(int stage, const CRect& rect, const CVector2D& nextplayerpos)
	:Base(eType_AreaChange)
{
	m_stage = stage;
	m_pos = CVector2D(rect.m_left, rect.m_top);
	m_rect = CRect(0, 0, rect.m_right, rect.m_bottom);
	m_nextplayerpos = nextplayerpos;

}

AreaChange::~AreaChange() {
}

void AreaChange::Draw()
{
	//�f�o�b�O�\��
	DrawRect();
}