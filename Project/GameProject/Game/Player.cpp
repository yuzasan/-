#include "Player.h"
#include "Map.h"
#include "AreaChange.h"
static TexAnim _anim_down[] = {
	{0,4},
	{1,4},
	{2,4},
};
static TexAnim _anim_left[] = {
	{3,4},
	{4,4},
	{5,4},
};
static TexAnim _anim_right[] = {
	{6,4},
	{7,4},
	{8,4},
};
static TexAnim _anim_up[] = {
	{9,4},
	{10,4},
	{11,4},
};

TexAnimData player_anim_data[] = {
	ANIMDATA(_anim_down),		//eUp
	ANIMDATA(_anim_left),		//eLeft
	ANIMDATA(_anim_right),		//eRight
	ANIMDATA(_anim_up),			//eUp
};
Player::Player() :
	Base(eType_Player) {
	m_img = COPY_RESOURCE("Player",CImage);
	//座標設定
	m_pos_old = m_pos = CVector2D(0,0);
	//ジャンプ回数
	m_jump_count =0;
	//着地フラグ
	m_is_ground = false;

	m_img.SetSize(48, 48);
	//当たり判定用矩形設定
	m_rect = CRect(8,0, 40, 48);


	//方向
	m_dir = eUp;
	//アニメーション種類指定
	m_img.ChangeAnimation(m_dir);


	m_enable_area_change = true;
	m_hit_area_change = false;

}
Player::~Player()
{

}
void Player::Update() {
	m_pos_old = m_pos;


	bool is_move = false;
	//左移動
	if (HOLD(CInput::eLeft)) {
		m_dir = eLeft;
		is_move = true;
	}
	//右移動
	if (HOLD(CInput::eRight)) {
		m_dir = eRight;
		is_move = true;
	}
	//上移動
	if (HOLD(CInput::eUp)) {
		m_dir = eUp;
		is_move = true;
	}
	//下移動
	if (HOLD(CInput::eDown)) {
		m_dir = eDown;
		is_move = true;
	}
	if (is_move) {
		float move_speed = 4.0f;
		//現在の方向へ移動
		//各方向の方向ベクトル
		CVector2D move_dir[] = {
			CVector2D(0,1),		//eDown
			CVector2D(-1,0),	//eLeft
			CVector2D(1,0),		//eRight
			CVector2D(0,-1),	//eUp
		};
		//移動
		m_pos += move_dir[m_dir] * move_speed;
		//アニメーション再生
		m_img.m_animSpeed = 1.0f;
	} else {
		//アニメーション停止
		m_img.m_animSpeed = 0.0f;
	}
	//アニメーション種類指定
	m_img.ChangeAnimation(m_dir);
	//アニメーション更新
	m_img.UpdateAnimation();

	//一度エリアチェンジ範囲から離れないと再度エリアチェンジしない
	//連続エリアチェンジ防止
	if (!m_enable_area_change && !m_hit_area_change)
			m_enable_area_change = true;
	m_hit_area_change = false;
}

void Player::Draw() {
	
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}
void Player::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_AreaChange:
		if (Base::CollisionRect(this, b)) {
			//エリアチェンジに触れている
			m_hit_area_change = true;
			//エリアチェンジ可能なら
			if (m_enable_area_change) {
				if (AreaChange* a = dynamic_cast<AreaChange*>(b)) {
					//マップとエリアチェンジオブジェクトを削除
					KillByType(eType_Field);
					KillByType(eType_AreaChange);
					//次のマップを生成
					Base::Add(new Map(a->m_nextArea, a->m_nextplayerpos));
					//エリアチェンジ一時不許可
					m_enable_area_change = false;
				}
			}
		}
		
		break;
	case eType_Field:
		//マップとの判定
		if (Map* m = dynamic_cast<Map*>(b)) {
			CVector2D pos;
			//マップチップの判定（横）
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y),m_rect,&pos);
			//壁ならば
			if (t != NULL_TIP) {
				//壁際まで戻る
				m_pos.x = pos.x;
			}
			//マップチップの判定（縦）
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect, &pos);
			//壁ならば
			if (t != NULL_TIP) {
				//壁際まで戻る
				m_pos.y = pos.y;				
			}
		}
		break;
	}

}

