#include "Boss.h"
#include "../Base/Base.h"
#include "Field.h"
#include "Player.h"
#include "Slash.h"
#include "Effect.h"
#include "Goal.h"
#include "AnimData.h"
#include "Map.h"
#include "Item.h"
#include "Siya.h"
#include "GameData.h"

void Boss::StateIdle() {
	//移動量
	const float move_speed = 6;
	//移動フラグ
	bool move_flag = false;

	if (GameData::S == 0) {
		//printf("c:%d\n", c);
		if (c > 36000) {
			c = 0;
		}
		k = rand() % 60 + 120;
		if (c % 4 == 0 || c % 4 == 1) {
			if (w <= k) {
				//移動量を設定
				m_pos.x += -move_speed;
				//反転フラグ
				m_flip = true;
				move_flag = true;
				if (s == 1) {
					Base::Add(new Siya(m_pos + CVector2D(-256, -128), m_flip));
				}
				else if (s > 2) {
					KillByType(eType_Siya);
					s = 0;
				}
			}
		}
		else {
			if (w <= k) {
				//移動量を設定
				m_pos.x += move_speed;
				//反転フラグ
				m_flip = false;
				move_flag = true;
				if (s == 1) {
					Base::Add(new Siya(m_pos + CVector2D(0, -128), m_flip));
				}
				else if (s > 2) {
					KillByType(eType_Siya);
					s = 0;
				}
			}
		}
	}
	else {
		//プレイヤーを探索
		Base* player = Base::FindObject(eType_Player);
		if (player) {
			//左移動
			if (player->m_pos.x < m_pos.x - 64) {
				//移動量を設定
				m_pos.x += -move_speed;
				//反転フラグ
				m_flip = true;
				move_flag = true;
				if (s == 1) {
					Base::Add(new Siya(m_pos + CVector2D(-256, -128), m_flip));
				}
				else if (s > 2) {
					KillByType(eType_Siya);
					s = 0;
				}
			}
			else
				//右移動
				if (player->m_pos.x > m_pos.x + 64) {
					//移動量を設定
					m_pos.x += move_speed;
					//反転フラグ
					m_flip = false;
					move_flag = true;
					if (s == 1) {
						Base::Add(new Siya(m_pos + CVector2D(0, -128), m_flip));
					}
					else if (s > 2) {
						KillByType(eType_Siya);
						s = 0;
					}
				}
				else {
					//攻撃状態へ移行
					m_state = eState_Attack;
					m_attack_no++;
				}
		}
		Base* change = Base::FindObject(eType_Change);
		if (change) {
			//左移動
			if (change->m_pos.x < m_pos.x - 64) {
				//移動量を設定
				m_pos.x += -move_speed;
				//反転フラグ
				m_flip = true;
				move_flag = true;
				if (s == 1) {
					Base::Add(new Siya(m_pos + CVector2D(0, -128), m_flip));
				}
				else if (s > 2) {
					KillByType(eType_Siya);
					s = 0;
				}
			}
			else
				//右移動
				if (change->m_pos.x > m_pos.x + 64) {
					//移動量を設定
					m_pos.x += move_speed;
					//反転フラグ
					m_flip = false;
					move_flag = true;
					if (s == 1) {
						Base::Add(new Siya(m_pos + CVector2D(0, -128), m_flip));
					}
					else if (s > 2) {
						KillByType(eType_Siya);
						s = 0;
					}
				}
				else {
					//攻撃状態へ移行
					m_state = eState_Attack;
					m_attack_no++;
				}
		}
	}

	//移動中なら
	if (move_flag) {
		//走るアニメーション
		m_img.ChangeAnimation(eAnimRun);
	}

	//カウント0で待機状態へ
	if (--m_cnt <= 0) {
		//待機時間1秒～2秒
		m_cnt = rand() % 60 + 120;
		m_state = eState_Wait;
	}

	if (GameData::S == 1) {
		//k2 = rand() % 600 + 900;
		if (GameData::t > GameData::random) {
			GameData::S = 0;
		}
	}
}

void Boss::StateWait() {
	//待機アニメーション
	m_img.ChangeAnimation(eAnimIdle);
	//カウント0で通常状態へ
	if (--m_cnt <= 0) {
		//待機時間1秒～2秒
		m_cnt = rand() % 60 + 120;
		w = 0;
		c += 1;
		m_state = eState_Idle;
	}
}

void Boss::StateAttack() {
	//攻撃アニメーションへ変更
	m_img.ChangeAnimation(eAnimAttack01, false);
	//3番目のパターンなら
	if (m_img.GetIndex() == 3) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
		}

	}
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
	}
}

void Boss::StateDamage() {
	//ダメージアニメーションへ変更
	m_img.ChangeAnimation(eAnimDamage, false);
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
	}

}

void Boss::StateDown() {
	//ダウンアニメーションへ変更
	m_img.ChangeAnimation(eAnimDown, false);
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		Base::Add(new Effect("Effect_Smoke", m_pos + CVector2D(0, 0), m_flip));
		//通常状態へ移行
		m_kill = true;
		GameData::S = 0;
	}
}

Boss::Boss(const CVector2D& pos, bool flip) :Base(eType_Boss) {
	//画像複製
	m_img = COPY_RESOURCE("Boss", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos = pos;
	//座標設定
	m_pos_old = m_pos = pos;
	//中心位置設定
	m_img.SetCenter(128, 224);
	//当たり判定用矩形設定
	m_rect = CRect(-32, -128, 32, 0);
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
}

void Boss::Update() {
	m_pos_old = m_pos;
	switch (m_state) {
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
		//待ち状態
	case eState_Wait:
		StateWait();
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

	s++;
	w++;

	GameData::t++;
	//printf("k2:%d t:%d\n",k2, GameData::t);

	//アニメーション更新
	m_img.UpdateAnimation();
}

void Boss::Draw() {
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//当たり判定矩形の表示
	//DrawRect();
	//DrawRectB();
}

void Boss::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Field:
		/*
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y));
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y));
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				m_vec.y = 0;
				m_is_ground = true;
			}
		}
		break;
		*/
		if (Map* m = dynamic_cast<Map*>(b)) {
			for (int i = 0; i < 4; i++) {
				int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y), m_rect, i);
				if (GameData::S == 1) {
					if (t != 0) {
						m_pos.x = m_pos_old.x;
					}
				}
				else {
					if (t == 1) {
						if (m_flip == 0) {
							m_flip = false;
							c += 1;
						}
						if (m_flip == 1) {
							m_flip = true;
							c += 1;
						}
						//m_pos.x = 640;
						//m_pos.y = 1340;
					}
					if (t == 2 || t == 3 || t == 4) {
						m_pos.x = m_pos_old.x;
					}
				}
				t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect, i);
				if (t != 0) {
					m_pos.y = m_pos_old.y;
					m_vec.y = 0;
					m_is_ground = true;
				}
				/*
				if (t == 1 || t == 2 || t == 4) {
					m_pos.y = m_pos_old.y;
					m_vec.y = 0;
					m_is_ground = true;
				}
				*/
			}
		}
		break;
		//攻撃オブジェクトとの判定
	case eType_Player_Attack:
		//Slash型へキャスト、型変換できたら
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				//同じ攻撃の連続ダメージ防止
				m_damage_no = s->GetAttackNo();
				m_hp -= 50;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
				Base::Add(new Effect("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
			}
		}
		break;
	}
}