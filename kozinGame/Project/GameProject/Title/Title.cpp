#include "Title.h"
#include "../Game/Game.h"
#include "../Base/Base.h"
#include "../Game/Gamedata.h"

Title::Title() : Base(eType_Scene), m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("Title", CImage);
}

Title::~Title() {
	//全てのオブジェクトを破棄
	Base::KillAll();
	//ゲームシーンへ
	Base::Add(new Game());
}

void Title::Update() {
	//ボタン1でタイトル破棄
	if (PUSH(CInput::eButton1)) {
		SetKill();
	}
}

void Title::Draw() {
	m_img.Draw();
	//文字表示
	m_title_text.Draw(64, 255, 255, 255, 255, "Title(仮)");
	m_title_text.Draw(64, 512, 255, 255, 255, "Push Z");
}
