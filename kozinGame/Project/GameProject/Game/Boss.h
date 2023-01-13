#pragma once
#include "../Base/Base.h"

class Boss : public Base {
private:
	//状態
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
		eState_Wait,
	};
	//状態変数
	int m_state;
	int m_cnt;

	CImage m_img;
	//反転フラグ
	bool m_flip;
	//着地フラグ
	bool m_is_ground;
	//攻撃番号
	int m_attack_no;
	//ダメージ番号
	int m_damage_no;
	//ヒットポイント
	int m_hp;

	//各状態での挙動
	void StateIdle();
	void StateWait();
	void StateAttack();
	void StateDamage();
	void StateDown();

public:
	int s = 0;
	int r = 0;
	int w = 0;
	int k = 0;
	int k2 = 0;
	int c = 0;
	// コンストラクタ
	Boss(const CVector2D& pos, bool flip);
	// 更新
	void Update();
	// 描画
	void Draw();
	void Collision(Base* b);
};