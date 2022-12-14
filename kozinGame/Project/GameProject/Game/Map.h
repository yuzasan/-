#pragma once
#include "../Base/Base.h"
//#include "Gamedata.h"
//マップの横のチップ数
#define MAP_WIDTH	80
//マップの縦のチップ数
#define MAP_HEIGHT	40
//マップチップの大きさ
#define MAP_TIP_SIZE	64

class Map :public Base {
private:
	CImage m_img;
	//文字表示オブジェクト
	CFont m_title_text;
	CFont m_key_text;
	float m_ground_x;
	float m_ground_y;
	int m_map_data[MAP_HEIGHT][MAP_WIDTH];
public:
	Map(int stage, const CVector2D& nextplayerpos);
	void Draw();
	void Update();
	//指定座標のチップ番号を取得
	int GetTip(const CVector2D& pos);
	//指定列、指定行のマップチップを取得
	int GetTip(int col, int raw);
	//マップとの当たり判定
	int CollisionMap(const CVector2D& pos);
	int CollisionMap(const CVector2D& pos, const CRect& rect, int idx);
	//int CollisionMap(const CVector2D& pos, const CRect& rect);
	float GetGroundX() {
		return m_ground_x;
	}
	float GetGroundY() {
		return m_ground_y;
	}
	int i = 0;
};