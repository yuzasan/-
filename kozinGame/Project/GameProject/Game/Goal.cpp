#include "Goal.h"
#include "../Base/Base.h"

Goal::Goal(const CVector2D& pos) : Base(eType_Goal) {
	//画像の複製
	m_img = COPY_RESOURCE("Goal", CImage);
	//座標設定
	m_pos = pos;
	//表示サイズ設定
	m_img.SetSize(64, 128);
	//中心位置設定
	m_img.SetCenter(32, 128);
	//m_rectの設定など
	m_rect = CRect(-32, -128, 32, 0);
}

void Goal::Draw(){
	//画像の描画
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	//当たり判定矩形の表示
	DrawRect();

}
