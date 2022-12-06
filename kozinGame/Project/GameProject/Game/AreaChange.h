#pragma once
#include "../Base/Base.h"
class AreaChange :public Base {
public:
	int m_stage;
	CVector2D m_nextplayerpos;
public:
	AreaChange(int stage, const CRect& rect, const CVector2D& nextplayerpos);
	~AreaChange();
	void Draw();
};