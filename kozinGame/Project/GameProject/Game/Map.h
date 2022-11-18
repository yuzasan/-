#pragma once
#include "../Base/Base.h"
//#include "Gamedata.h"
//�}�b�v�̉��̃`�b�v��
#define MAP_WIDTH	4000
//�}�b�v�̏c�̃`�b�v��
#define MAP_HEIGHT	2200
//�}�b�v�`�b�v�̑傫��
#define MAP_TIP_SIZE	64

class Map :public Base {
private:
	CImage m_img;
	float m_ground_x;
	float m_ground_y;
	int m_map_data[MAP_HEIGHT][MAP_WIDTH];
public:
	Map(int stage, const CVector2D& nextplayerpos);
	void Draw();
	void Update();
	//�w����W�̃`�b�v�ԍ����擾
	int GetTip(const CVector2D& pos);
	//�w���A�w��s�̃}�b�v�`�b�v���擾
	int GetTip(int col, int raw);
	//�}�b�v�Ƃ̓����蔻��
	int CollisionMap(const CVector2D& pos);
	int CollisionMap(const CVector2D& pos, const CRect& rect);
	float GetGroundX() {
		return m_ground_x;
	}
	float GetGroundY() {
		return m_ground_y;
	}
	int i = 0;
};