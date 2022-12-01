#pragma once
#include<GLLibrary.h>
//重力加速度
#define GRAVITY (9.8f/20)


enum {
	eType_Gravity2,//表示の順番が大事
	eType_Field,
	eType_Warp,
	eType_Player,
	eType_Change,
	eType_Enemy,
	eType_Item,
	eType_Bullet,
	eType_Goal,
	eType_Player_Attack,
	eType_Enemy_Attack,
	eType_Effect,
	eType_UI,
	eType_Scene,
	eType_AreaChange,
};

class Base {
public:
	//オブジェクトの種類
	int m_type;
	//座標
	CVector2D m_pos;
	//移動前の座標
	CVector2D m_pos_old;
	//半径
	float m_rad;
	//矩形
	CRect m_rect;
	//移動ベクトル
	CVector2D m_vec;
	//スクロール値
	static CVector2D m_scroll;
	//削除フラグ
	bool m_kill;
	//オブジェクトの追加
	static std::list<Base*> m_list;
	//特定のオブジェクトを探索
	Base* Base::FindObject(int type);
	//特定のオブジェクトを探索する(複数)
	static std::list<Base*>FindObjects(int type);
public:
	//削除処理
	void SetKill() { m_kill = true; }
	// 座標の設定
	void ResetPos(const CVector2D& pos) {
		m_pos = m_pos_old = pos;
	}
	//コンストラクタにtypeオブジェクトの種類を入れる
	Base(int type);
	//(仮想関数化)デストラクタ
	virtual ~Base();
	//(仮想関数化)更新処理
	virtual void Update();
	//(仮想関数化)描画処理
	virtual void Draw();
	//(仮想関数化)オブジェクトの当たり判定の検証処理
	virtual void Collision(Base* b);

	//Allはstaticを付ける
	//(静的メンバ関数)スクロール
	static CVector2D GetScreenPos(const CVector2D& pos);
	// 削除フラグON
	static void CheckKillAll();
	//(静的メンバ関数)全て更新処理
	static void UpdateAll();
	//(静的メンバ関数)全て描画処理
	static void DrawAll();
	//(静的メンバ関数)全てオブジェクトの当たり判定の検証処理
	static void CollisionAll();
	//(静的メンバ関数)追加処理
	static void Add(Base* b);
	//全オブジェクトの削除
	static void KillAll();

	// 指定した種類のオブジェクトを削除
	static void KillByType(int type);

	//円同士の衝突
	static bool CollisionCircle(Base* b1, Base* b2);
	//矩形同士の判定
	static bool CollisionRect(Base* b1, Base* b2);
	//矩形の表示
	void DrawRect();
};