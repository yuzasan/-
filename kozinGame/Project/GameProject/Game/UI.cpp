#include "UI.h"
#include "Gamedata.h"

UI::UI():Base(eType_UI) {
	m_img.Load("Image/Heart.png");
	m_img2 = COPY_RESOURCE("ItemC", CImage);
	m_img3 = COPY_RESOURCE("ItemK", CImage);
	m_rect = CRect(-16, -16, 16, 16);
}

void UI::Draw(){
	int life = GameData::life;
	for (int i = 0; i < life; i++) {
		m_img.SetSize(32, 32);
		m_img.SetPos(100+32*i, 100);
		m_img.Draw();
		m_img2.SetSize(32, 32);
		m_img2.SetCenter(16, 16);
		m_img2.SetPos(300, 100);
		m_img2.Draw();
		m_img3.SetSize(32, 32);
		m_img3.SetCenter(16, 16);
		m_img3.SetPos(400, 100);
		m_img3.Draw();
	}
}
