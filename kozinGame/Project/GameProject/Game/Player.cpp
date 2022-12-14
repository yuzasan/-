#include "Player.h"
#include "Change.h"
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
#include "Siya.h"

void Player::StateIdle() {
	//移動量
	const float move_speed = 6;
	//ジャンプ力
	const float jump_pow = 12;
	//移動フラグ
	bool move_flag = false;

	bool move_flag2 = false;
	//左移動
	if (HOLD(CInput::eLeft)) {
		//移動量を設定
		m_pos.x += -move_speed;
		//反転フラグ
		m_flip = true;
		move_flag = true;
	}
	//左移動
	if (HOLD(CInput::eLeft) && HOLD(CInput::eButton5)) {//スペースキー
		//移動量を設定
		m_pos.x += -move_speed;
		//反転フラグ
		m_flip = true;
		move_flag = false;
		move_flag2 = true;
	}
	//右移動
	if (HOLD(CInput::eRight)) {
		//移動量を設定
		m_pos.x += move_speed;
		//反転フラグ
		m_flip = false;
		move_flag = true;
	}
	//右移動
	if (HOLD(CInput::eRight) && HOLD(CInput::eButton5)) {
		//移動量を設定
		m_pos.x += move_speed;
		//反転フラグ
		m_flip = false;
		move_flag = false;
		move_flag2 = true;
	}
	//攻撃
	if (GameData::ItemK >= 1 && PUSH(CInput::eButton1)) {
		GameData::ItemK = GameData::ItemK - 1;
		//攻撃状態へ移行
		m_state = eState_Attack;
		m_attack_no++;
	}
	//変身
	if (PUSH(CInput::eButton3)) {//if (GameData::life <= 2||PUSH(CInput::eButton3))
		//変身状態へ移行
		m_state = eState_Change;
	}
	/*
	//攻撃2
	if (PUSH(CInput::eButton3)) {
		//攻撃状態2へ移行
		m_state = eState_Attack2;
		m_attack_no++;
	}
	//攻撃3
	if (PUSH(CInput::eButton4)) {
		//攻撃状態3へ移行
		m_state = eState_Attack3;
		m_attack_no++;
	}
	*/

	if (!m_is_ground_up) {
		//ジャンプ
		if (m_is_ground && PUSH(CInput::eButton2)) {
			m_vec.y = jump_pow * 0.8;
			m_is_ground_up = false;
		}
	}
	else {
		//ジャンプ
		if (m_is_ground && PUSH(CInput::eButton2)) {
			m_vec.y = -jump_pow;
			m_is_ground = false;
			m_cnt++;
		}
	}

	//ジャンプ中なら
	if (!m_is_ground && m_is_ground_up) {
		//ジャンプ回数制限
		if (m_cnt < 3) {
			//二段ジャンプ
			if (!m_is_ground && PUSH(CInput::eButton2)) {
				m_vec.y = -jump_pow;
				m_is_ground = false;
				m_cnt++;
				if (m_vec.y < 0) {
					//上昇アニメーション
					m_img.ChangeAnimation(eAnimJumpUp, false);
				}
				else {
					//下降アニメーション
					m_img.ChangeAnimation(eAnimJumpDown, false);
				}
			}
		}
		if (m_vec.y < 0)
			//上昇アニメーション
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//下降アニメーション
			m_img.ChangeAnimation(eAnimJumpDown, false);
	}
	else {
		m_cnt = 0;
		if (move_flag2) {
			//走るアニメーション
			m_img.ChangeAnimation(eAnimRun);
		}
		else if (move_flag) {
			//歩くアニメーション
			m_img.ChangeAnimation(eAnimWalk);
		}
		else {
			m_img.ChangeAnimation(eAnimIdle);
		}
	}

	/*
	//元
	//ジャンプ
	if (m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}

	//ジャンプ中なら
	if (!m_is_ground) {
		if (m_vec.y < 0)
			//上昇アニメーション
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//下降アニメーション
			m_img.ChangeAnimation(eAnimJumpDown, false);
	}
	else {
		//移動中なら
		if (move_flag) {
			//走るアニメーション
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			//待機アニメーション
			m_img.ChangeAnimation(eAnimIdle);
		}
	}
	*/

}

void Player::StateAttack() {
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
}

void Player::StateDamage() {
	//ダメージアニメーションへ変更
	m_img.ChangeAnimation(eAnimDamage, false);
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
	}
}

void Player::StateDown() {
	//ダウンアニメーションへ変更
	m_img.ChangeAnimation(eAnimDown, false);
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		Base::Add(new Effect("Effect_Smoke", m_pos + CVector2D(0, 0), m_flip));
		//通常状態へ移行
		m_kill = true;
	}
}

void Player::StateChange() {
	Base::Add(new Change(m_pos, false));
	SetKill();
}

Player::Player(const CVector2D& p, bool flip) : Base(eType_Player) {
	//画像複製
	m_img = COPY_RESOURCE("Player", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos_old = m_pos = p;
	m_img.SetSize(60, 52);//m_img.SetSize(64, 64);
	//m_img.SetSize(128, 128);
	//中心位置設定
	m_img.SetCenter(30, 52);//m_img.SetCenter(32, 64);
	//m_img.SetCenter(64, 128);
	//実サイズ
	//m_img.SetCenter(16, 32);
	//当たり判定用矩形設定
	//拡大
	m_rect = CRect(-26, -60, 26, 0);//m_rect = CRect(-29, -60, 29, 0);

	//m_rect = CRect(-32, -64, 32, 0);//大事
	//m_rect = CRect(-64, -128, 64, 0);
	//実サイズ
	//m_rect = CRect(-16, -32, 16, 0);
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

	m_enable_Smog = true;
	m_hit_Smog = false;

	//着地フラグ上
	m_is_ground_up = true;

	//着地フラグ右
	m_is_ground_right = true;

	//着地フラグ左
	m_is_ground_left = true;

	//m_item = true;

	//m_siya = true;

	m_zoom = true;
}

void Player::Update() {
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

	//待機アニメーション
	//m_img.ChangeAnimation(eAnimIdle);

	//アニメーション更新
	m_img.UpdateAnimation();

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

	//一度スモッグ範囲から離れないと再度スモッグ生成しない
	//連続スモッグ生成防止
	if (!m_enable_Smog && !m_hit_Smog)
		m_enable_Smog = true;
	m_hit_Smog = false;

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

void Player::Draw() {
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//当たり判定矩形の表示
	DrawRect();

}

void Player::Collision(Base* b) {
	switch (b->m_type) {
		/*
		case eType_Siya:
			if (Siya* s = dynamic_cast<Siya*>(b)) {
				if (Base::CollisionRect(this, s)) {
					m_siya = true;
					//視野に触れていたら
					if (m_siya) {
						GameData::S = 1;
						m_siya = false;
					}
					GameData::S = 0;
				}
			}
			break;
		*/
	case eType_SmogAll:
		if (Base::CollisionRect(this, b)) {
			//スモッグオブジェクトに触れている
			m_hit_Smog = true;
			//スモッグ生成可能なら
			if (m_enable_Smog) {
				KillByType(eType_Smog);
				//スモッグの生成
				//1段目左
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 20, MAP_TIP_SIZE * 5)));
				//1段目左中
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 25, MAP_TIP_SIZE * 5)));
				//1段目右中
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 30, MAP_TIP_SIZE * 5)));
				//1段目右
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 35, MAP_TIP_SIZE * 5)));

				//2段目左
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 20, MAP_TIP_SIZE * 8)));
				//2段目左中
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 25, MAP_TIP_SIZE * 8)));
				//2段目右中
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 30, MAP_TIP_SIZE * 8)));
				//2段目右
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 35, MAP_TIP_SIZE * 8)));

				//3段目左左
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 5, MAP_TIP_SIZE * 11)));
				//3段目左中
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 10, MAP_TIP_SIZE * 11)));
				//3段目中左
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 15, MAP_TIP_SIZE * 11)));
				//3段目中
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 20, MAP_TIP_SIZE * 11)));
				//3段目中右
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 25, MAP_TIP_SIZE * 11)));
				//3段目右中
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 30, MAP_TIP_SIZE * 11)));
				//3段目右右
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 35, MAP_TIP_SIZE * 11)));

				//4段目左左
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 5, MAP_TIP_SIZE * 14)));
				//4段目左中
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 10, MAP_TIP_SIZE * 14)));
				//4段目中左
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 15, MAP_TIP_SIZE * 14)));
				//4段目中
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 20, MAP_TIP_SIZE * 14)));
				//4段目中右
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 25, MAP_TIP_SIZE * 14)));
				//4段目右中
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 30, MAP_TIP_SIZE * 14)));
				//4段目右右
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 35, MAP_TIP_SIZE * 14)));

				//5段目左左
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 5, MAP_TIP_SIZE * 17)));
				//5段目左中
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 10, MAP_TIP_SIZE * 17)));
				//5段目中左
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 15, MAP_TIP_SIZE * 17)));
				//5段目中
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 20, MAP_TIP_SIZE * 17)));
				//5段目中右
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 25, MAP_TIP_SIZE * 17)));
				//5段目右中
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 30, MAP_TIP_SIZE * 17)));
				//5段目右右
				Base::Add(new Smog(CVector2D(MAP_TIP_SIZE * 35, MAP_TIP_SIZE * 17)));
				//エリアチェンジ一時不許可
				m_enable_Smog = false;
			}
		}
		break;
	case eType_Zoom:
		if (Base::CollisionRect(this, b)) {
			m_zoom = true;
			//ズームエリアに触れていたら
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
					//KillByType(eType_Item);
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
			m_vec.y -= GRAVITY * 2;
			m_pos += m_vec;
		}
		break;
	case eType_Gravity_Right:
		if (Base::CollisionRect(this, b)) {
			//重力エリアに触れていたら
			if (m_is_ground_right)
				m_is_ground_right = false;
			//重力による落下
			if (m_pos.x + m_rect.m_left < b->m_pos.x + b->m_rect.m_right - 4) {
				m_vec.x += GRAVITY * 25;
			}
			else {
				m_pos.x = m_pos_old.x;
			}
			m_pos += m_vec;
			//プレイヤーm_pos.x+m_rect.m_right - エリア	b->m_pos.x+b->m_rect.m_left
			//エリア	b->m_pos.x+b->m_rect.m_left
			//m_pos.x+m_rect.m_right - b->m_pos.x+b->m_rect.m_left
			if (PUSH(CInput::eButton2)) {
				m_vec.y = 0;
			}
		}
		m_is_ground_right = true;
		m_vec.x = 0;
		break;
	case eType_Gravity_Left:
		if (Base::CollisionRect(this, b)) {
			//重力エリアに触れていたら
			if (m_is_ground_left)
				m_is_ground_left = false;
			//重力による落下
			if (m_pos.x + m_rect.m_right > b->m_pos.x + b->m_rect.m_left + 4) {
				m_vec.x -= GRAVITY * 25;
			}
			else {
				m_pos.x = m_pos_old.x;
			}
			m_pos += m_vec;
			if (PUSH(CInput::eButton2)) {
				m_vec.y = 0;
			}
		}
		m_is_ground_left = true;
		m_vec.x = 0;
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
					KillByType(eType_SmogAll);
					KillByType(eType_Siya);
					KillByType(eType_Boss);
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
		/*
		//Field型へキャスト、型変換できたら
		if (Field* f = dynamic_cast<Field*>(b)) {
			//地面より下にいったら
			if (m_pos.y > f->GetGroundY()) {
				//地面の高さに戻す
				m_pos.y = f->GetGroundY();
				//落下速度リセット
				m_vec.y = 0;
				//接地フラグON
				m_is_ground = true;
			}
		}
		break;
		*/
		if (Map* m = dynamic_cast<Map*>(b)) {
			for (int i = 0; i < 4; i++) {
				int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y), m_rect, i);
				if (t != 0) {
					m_pos.x = m_pos_old.x;
				}
				t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect, i);
				if (t != 0) {
					m_pos.y = m_pos_old.y;
					m_vec.y = 0;
					m_is_ground = true;
					m_is_ground_up = true;
				}
			}
			/*
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y), m_rect);
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect);
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				m_vec.y = 0;
				m_is_ground = true;
				m_is_ground2 = true;
			}*/
		}
		break;
	}
}
/*
元
#include "Player.h"
#include "Field.h"
#include "AnimData.h"

void Player::StateIdle(){
	//移動量
	const float move_speed = 6;
	//ジャンプ力
	const float jump_pow = 12;
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
	}
	//ジャンプ
	if (m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}
	//ジャンプ中なら
	if (!m_is_ground) {
		if (m_vec.y < 0)
			//上昇アニメーション
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//下降アニメーション
			m_img.ChangeAnimation(eAnimJumpDown, false);
	}
	else {
		//移動中なら
		if (move_flag) {
			//走るアニメーション
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			//待機アニメーション
			m_img.ChangeAnimation(eAnimIdle);
		}
	}
}

void Player::StateAttack(){
	//攻撃アニメーションへ変更
	m_img.ChangeAnimation(eAnimAttack01, false);
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
	}
}

void Player::StateDamage(){
	//ダメージアニメーションへ変更
	m_img.ChangeAnimation(eAnimDamage, false);
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
	}

}

void Player::StateDown(){
	//ダウンアニメーションへ変更
	m_img.ChangeAnimation(eAnimDown, false);
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_kill = true;
	}
}

Player::Player(const CVector2D& p, bool flip) : Base(eType_Player) {
	//画像複製
	m_img = COPY_RESOURCE("Player", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos = p;
	//中心位置設定
	m_img.SetCenter(128, 224);
	//反転フラグ
	m_flip = flip;
	//通常状態へ
	m_state = eState_Idle;
	//着地フラグ
	m_is_ground = true;
}

void Player::Update(){
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
	}
	//落ちていたら落下中状態へ移行
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//重力による落下
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	//待機アニメーション
	//m_img.ChangeAnimation(eAnimIdle);

	//アニメーション更新
	m_img.UpdateAnimation();
}

void Player::Draw(){
	//位置設定
	m_img.SetPos(m_pos);
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
}

void Player::Collision(Base* b){
	switch (b->m_type) {
	case eType_Field:
		//Field型へキャスト、型変換できたら
		if (Field* f = dynamic_cast<Field*>(b)) {
			//地面より下にいったら
			if (m_pos.y > f->GetGroundY()) {
				//地面の高さに戻す
				m_pos.y = f->GetGroundY();
				//落下速度リセット
				m_vec.y = 0;
				//接地フラグON
				m_is_ground = true;
			}
		}
		break;
	}
}

*/