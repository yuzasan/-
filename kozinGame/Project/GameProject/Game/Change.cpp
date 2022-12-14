#include "Change.h"
#include "Player.h"
#include "Field.h"
#include "Slash.h"
#include "Enemy.h"
#include "Effect.h"
#include "../Base/Base.h"
#include "AnimData.h"
#include "Map.h"
#include "AreaChange.h"
#include "Gimmick.h"
#include "Gamedata.h"
#include "UI.h"
#include "Item.h"

void Change::StateIdle() {
	//移動量
	const float move_speed = 4;
	//移動フラグ
	bool move_flag = false;
	//左移動
	if (HOLD(CInput::eLeft)) {
		//移動量を設定
		m_pos.x += -move_speed;
		//反転フラグ
		m_flip = true;
		move_flag = true;
	}
	//右移動
	if (HOLD(CInput::eRight)) {
		//移動量を設定
		m_pos.x += move_speed;
		//反転フラグ
		m_flip = false;
		move_flag = true;
	}
	//攻撃
	if (PUSH(CInput::eButton1)) {
		//攻撃状態へ移行
		m_state = eState_Attack;
		m_attack_no++;
	}
	//変身
	if (GameData::ItemC >= 1 && PUSH(CInput::eButton3)) {
		GameData::ItemC = GameData::ItemC - 1;
		//変身状態へ移行
		m_state = eState_Change;
	}
	/*
	if (move_flag)
		//歩くアニメーション
		m_img.ChangeAnimation(eAnimWalk);
	else
		//待機アニメーション
		m_img.ChangeAnimation(eAnimIdle);
	*/
}

void Change::StateAttack() {
	/*
	//攻撃アニメーションへ変更
	m_img.ChangeAnimation(eAnimAttack01, false);
	//3番目のパターンなら
	if (m_img.GetIndex() == 1) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Player_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Player_Attack, m_attack_no));
		}
	}
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
	}
	*/
	m_state = eState_Idle;
}

void Change::StateDamage() {
	/*
	//ダメージアニメーションへ変更
	m_img.ChangeAnimation(eAnimDamage, false);
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
	}
	*/
	m_state = eState_Idle;
}

void Change::StateDown() {
	/*
	//ダウンアニメーションへ変更
	m_img.ChangeAnimation(eAnimDown, false);
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		Base::Add(new Effect("Effect_Smoke", m_pos + CVector2D(0, 0), m_flip));
		//通常状態へ移行
		m_kill = true;
	}
	*/
	m_kill = true;
}

void Change::StateChange() {
	Base::Add(new Player(m_pos, false));
	SetKill();
}

Change::Change(const CVector2D& p, bool flip) : Base(eType_Change) {
	//画像複製
	m_img = COPY_RESOURCE("Change", CImage);
	//再生アニメーション設定
	//m_img.ChangeAnimation(0);
	//座標設定
	m_pos_old = m_pos = p;
	m_img.SetSize(52, 32);
	//中心位置設定
	m_img.SetCenter(26, 32);
	//当たり判定用矩形設定
	m_rect = CRect(-26, -32, 26, 0);
	//反転フラグ
	m_flip = flip;
	//通常状態へ
	m_state = eState_Idle;
	//着地フラグ
	m_is_ground = true;
	//攻撃番号
	m_attack_no = rand();
	//ダメージ番号
	m_damage_no = -1;
	//ヒットポイント
	m_hp = 100;
	//カウント
	m_cnt = 0;

	m_enable_area_change = true;
	m_hit_area_change = false;

	m_enable_Warp = true;
	m_hit_Warp = false;

	//着地フラグ上
	m_is_ground_up = true;

	//着地フラグ右
	m_is_ground_right = true;

	//着地フラグ左
	m_is_ground_left = true;

	//m_item = true;

	m_zoom = true;
}

void Change::Update() {
	m_pos_old = m_pos;
	switch (m_state) {
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
		//攻撃状態
	case eState_Attack:
		StateAttack();
		break;
		//ダメージ状態
	case eState_Damage:
		StateDamage();
		break;
		//ダウン状態
	case eState_Down:
		StateDown();
		break;
	case eState_Change:
		StateChange();
		break;
	}
	//落ちていたら落下中状態へ移行
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//重力による落下
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	//アニメーション更新
	//m_img.UpdateAnimation();

	//一度エリアチェンジ範囲から離れないと再度エリアチェンジしない
	//連続エリアチェンジ防止
	if (!m_enable_area_change && !m_hit_area_change)
		m_enable_area_change = true;
	m_hit_area_change = false;

	//一度ワープ範囲から離れないと再度ワープしない
	//連続ワープ防止
	if (!m_enable_Warp && !m_hit_Warp)
		m_enable_Warp = true;
	m_hit_Warp = false;

	//スクロール設定
	if (!m_zoom) {
		m_scroll.x = m_pos.x - 1920 / 2;
		m_scroll.y = m_pos.y - 960;
	}
	else {
		m_scroll.x = m_pos.x - 1920 / 2;
		m_scroll.y = m_pos.y - 680;//元m_scroll.y = m_pos.y - 680
	}
	if (m_scroll.x < 0)m_scroll.x = 0;
	if (m_scroll.x > MAP_TIP_SIZE * 40 - 1920)m_scroll.x = MAP_TIP_SIZE * 40 - 1920;
	if (m_scroll.y < 0)m_scroll.y = 0;
	if (m_scroll.y > MAP_TIP_SIZE * 22 - 1080)m_scroll.y = MAP_TIP_SIZE * 22 - 1080;
}

void Change::Draw() {
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//当たり判定矩形の表示
	DrawRect();

}

void Change::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Zoom:
		if (Base::CollisionRect(this, b)) {
			//ズームエリアに触れていたら
			m_zoom = true;
			if (m_zoom) {
				m_zoom = false;
			}
		}
		break;
		/*
			//アイテム判定
		case eType_Item:
			if (Base::CollisionRect(this, b)) {
				//アイテムに触れていたら
				if (m_item) {
					GameData::Item = GameData::Item + 1;
					KillByType(eType_Item);
					m_item = false;
				}
			}
			break;
		*/
		//重力判定
	case eType_Gravity_Up:
		if (Base::CollisionRect(this, b)) {
			//重力エリアに触れていたら
			if (m_is_ground_up)
				m_is_ground_up = false;
			//重力による落下
			m_vec.y -= GRAVITY * 1.5f;
			m_pos += m_vec;
		}
		break;
	case eType_Gravity_Right:
		if (Base::CollisionRect(this, b)) {
			//重力エリアに触れていたら
			if (m_is_ground_right)
				m_is_ground_right = false;
			//重力による落下
			if (m_pos.x + m_rect.m_left < b->m_pos.x + b->m_rect.m_right - 7) {
				m_vec.x += GRAVITY * 25;
			}
			else {
				m_pos.x = m_pos_old.x;
			}
			m_pos += m_vec;
		}
		m_vec.x = 0;
		m_is_ground_right = true;
		break;
	case eType_Gravity_Left:
		if (Base::CollisionRect(this, b)) {
			//重力エリアに触れていたら
			if (m_is_ground_left)
				m_is_ground_left = false;
			//重力による落下
			if (m_pos.x + m_rect.m_right > b->m_pos.x + b->m_rect.m_left + 7) {
				m_vec.x -= GRAVITY * 25;
			}
			else {
				m_pos.x = m_pos_old.x;
			}
			m_pos += m_vec;
		}
		m_vec.x = 0;
		m_is_ground_left = true;
		break;
		//エリアチェンジ判定
	case eType_AreaChange:
		if (Base::CollisionRect(this, b) && PUSH(CInput::eButton5)) {//スペースキー
			//エリアチェンジに触れている
			m_hit_area_change = true;
			//エリアチェンジ可能なら
			if (m_enable_area_change) {
				if (AreaChange* a = dynamic_cast<AreaChange*>(b)) {
					//マップとエリアチェンジオブジェクトを削除
					KillByType(eType_Field);
					KillByType(eType_AreaChange);
					KillByType(eType_Warp);
					KillByType(eType_Enemy);
					KillByType(eType_Goal);
					KillByType(eType_Gravity_Up);
					KillByType(eType_Gravity_Right);
					KillByType(eType_Gravity_Left);
					KillByType(eType_UI);
					KillByType(eType_Item);
					KillByType(eType_Zoom);
					KillByType(eType_Smog);
					//次のマップを生成
					Base::Add(new Map(a->m_stage, a->m_nextplayerpos));
					//エリアチェンジ一時不許可
					m_enable_area_change = false;
					m_zoom = true;
				}
			}
		}
		break;
		//ワープ判定
	case eType_Warp:
		if (Base::CollisionRect(this, b)) {
			//ワープに触れている
			m_hit_Warp = true;
			//ワープ可能なら
			if (m_enable_Warp) {
				if (Warp* a = dynamic_cast<Warp*>(b)) {
					ResetPos(a->m_nextplayerpos);
					//エリアチェンジ一時不許可
					m_enable_area_change = false;
				}
			}
		}
		break;
		//ゴール判定
	case eType_Goal:
		if (Base::CollisionRect(this, b)) {
			b->SetKill();
			GameData::a = 1;
		}
		break;
		//攻撃オブジェクトとの判定
	case eType_Enemy_Attack:
		//Slash型へキャスト、型変換できたら
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				//同じ攻撃の連続ダメージ防止
				m_damage_no = s->GetAttackNo();
				//m_hp -= 50;
				GameData::life = GameData::life - 1;
				KillByType(eType_UI);
				if (GameData::life <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
				Base::Add(new Effect("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
			}
		}
		break;
	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {
			for (int i = 0; i < 4; i++) {
				int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y), m_rect, i);
				if (t == 1 || t == 2 || t == 3) {
					m_pos.x = m_pos_old.x;
				}
				t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect, i);
				if (t == 1 || t == 2 || t == 4) {
					m_pos.y = m_pos_old.y;
					m_vec.y = 0;
					m_is_ground = true;
					m_is_ground_up = true;
				}
			}
		}
		break;
	}
}