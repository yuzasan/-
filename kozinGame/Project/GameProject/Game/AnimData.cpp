#include "AnimData.h"


static TexAnim playerIdle[] = {
	{ 0,4 },
	{ 1,4 },
	{ 2,4 },
	{ 3,4 },
	{ 4,4 },
	{ 5,4 },
};
static TexAnim playerWalk[] = {
	{ 6,6 },
	{ 7,6 },
	{ 8,6 },
	{ 9,6 },
	{ 10,6 },
	{ 11,6 },
};
static TexAnim playerRun[] = {
	{ 12,4 },
	{ 13,2 },
	{ 14,3 },
	{ 15,4 },
	{ 16,2 },
	{ 17,3 },
};
static TexAnim playerJumpUp[] = {
	{ 18,4 },
	{ 19,4 },
	{ 20,4 },
};
static TexAnim playerJumpDown[] = {
	{ 21,4 },
	{ 22,4 },
	{ 23,4 },
};
static TexAnim playerAttack01[] = {
	{ 24,12 },
	{ 25,6 },
	{ 26,6 },
};
static TexAnim playerAttack01End[] = {
	{ 27,8 },
	{ 28,8 },
	{ 29,8 },
};
static TexAnim playerAttack02[] = {
	{ 0,0 },
};
static TexAnim playerAttack02End[] = {
	{ 0,0 },
};
static TexAnim playerAttack03[] = {
	{ 0,0 },
};
static TexAnim playerAttack03End[] = {
	{ 0,0 },
};
static TexAnim playerDamage[] = {
	{ 36,10 },
	{ 37,10 },
	{ 38,10 },
};
static TexAnim playerDamageEnd[] = {
	{ 39,10 },
	{ 40,10 },
	{ 41,10 },
};
static TexAnim playerDeath[] = {
	{ 0,0 },
};
static TexAnim playerDown[] = {
	{ 30,10 },
	{ 31,10 },
	{ 32,10 },
	{ 33,10 },
	{ 34,10 },
	{ 35,10 },
};
static TexAnim playerDownGround[] = {
	{ 0,0 },
};
static TexAnim playerWakeup[] = {
	{ 0,0 },
};
static TexAnim playerGuard[] = {
	{ 0,0 },
};
static TexAnim playerGuardEnd[] = {
	{ 0,0 },
};
static TexAnim playerCrash[] = {
	{ 0,0 },
};
static TexAnim playerCrash01End[] = {
	{ 0,0 },
};
static TexAnim playerExtAttack01[] = {
	{ 0,0 },
};
static TexAnim playerExtAttack01End[] = {
	{ 0,0 },
};
static TexAnim playerExtAttack02[] = {
	{ 0,0 },
};
static TexAnim playerExtAttack02End[] = {
	{ 0,0 },
};
static TexAnim playerStep[] = {
	{ 0,0 },
};
TexAnimData player_anim_data[] = {
	ANIMDATA(playerIdle),
	ANIMDATA(playerWalk),
	ANIMDATA(playerRun),
	ANIMDATA(playerJumpUp),
	ANIMDATA(playerJumpDown),
	ANIMDATA(playerAttack01),
	ANIMDATA(playerAttack01End),
	ANIMDATA(playerAttack02),
	ANIMDATA(playerAttack02End),
	ANIMDATA(playerAttack03),
	ANIMDATA(playerAttack03End),
	ANIMDATA(playerDamage),
	ANIMDATA(playerDamageEnd),
	ANIMDATA(playerDeath),
	ANIMDATA(playerDown),
	ANIMDATA(playerDownGround),
	ANIMDATA(playerWakeup),
	ANIMDATA(playerGuard),
	ANIMDATA(playerGuardEnd),
	ANIMDATA(playerCrash),
	ANIMDATA(playerCrash01End),
	ANIMDATA(playerExtAttack01),
	ANIMDATA(playerExtAttack01End),
	ANIMDATA(playerExtAttack02),
	ANIMDATA(playerExtAttack02End),
	ANIMDATA(playerStep),
};

static TexAnim enemyIdle[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	{ 3,2 },
	{ 4,2 },
	{ 5,2 },
	{ 6,2 },
	{ 7,2 },
	{ 8,2 },
	{ 9,2 },
	{ 10,2 },
	{ 11,2 },
	{ 12,2 },
	{ 13,2 },
	{ 14,2 },
};
static TexAnim enemyWalk[] = {
	{ 0,0 },
};
static TexAnim enemyRun[] = {
	{ 16,2 },
	{ 17,2 },
	{ 18,2 },
	{ 19,2 },
	{ 20,2 },
	{ 21,2 },
	{ 22,2 },
	{ 23,2 },
	{ 24,2 },
	{ 25,2 },
	{ 26,2 },
	{ 27,2 },
	{ 28,2 },
	{ 29,2 },
	{ 30,2 },
};
static TexAnim enemyJumpUp[] = {
	{ 0,0 },
};
static TexAnim enemyJumpDown[] = {
	{ 0,0 },
};

static TexAnim enemyAttack01[] = {
	{ 40,4 },
	{ 41,4 },
	{ 42,4 },
	{ 43,8 },
	{ 44,2 },
	{ 45,3 },
	{ 46,3 },
	{ 47,3 },
};
static TexAnim enemyAttack01End[] = {
	{ 48,2 },
	{ 49,2 },
	{ 50,2 },
	{ 51,2 },
	{ 52,2 },
};
static TexAnim enemyAttack02[] = {
	{ 0,0 },
};
static TexAnim enemyAttack02End[] = {
	{ 0,0 },
};
static TexAnim enemyAttack03[] = {
	{ 0,0 },
};
static TexAnim enemyAttack03End[] = {
	{ 0,0 },
};
static TexAnim enemyDamage[] = {
	{ 88,2 },
	{ 89,2 },
	{ 90,2 },
	{ 91,2 },
};
static TexAnim enemyDamageEnd[] = {
	{ 92,2 },
	{ 93,2 },
	{ 94,2 },
	{ 95,2 },
};
static TexAnim enemyDeath[] = {
	{ 96,4 },
	{ 97,4 },
	{ 98,8 },
	{ 99,4 },
	{ 100,4 },
	{ 101,4 },
	{ 102,4 },
	{ 103,4 },
};

static TexAnim enemyDown[] = {
	{ 104,4 },
	{ 105,4 },
	{ 106,4 },
	{ 107,4 },
	{ 108,4 },
};
static TexAnim enemyDownGround[] = {
	{ 109,4 },
	{ 110,4 },
	{ 111,4 },
};
static TexAnim enemyWakeup[] = {
	{ 112,4 },
	{ 113,4 },
	{ 114,4 },
	{ 115,4 },
	{ 116,4 },
	{ 117,4 },
	{ 118,4 },
};
static TexAnim enemyGuard[] = {
	{ 0,4 },
};
static TexAnim enemyGuardEnd[] = {
	{ 0,4 },
};
static TexAnim enemyCrash[] = {
	{ 128,4 },
	{ 129,4 },
	{ 130,4 },
	{ 131,60 },
};
static TexAnim enemyCrash01End[] = {
	{ 131,4 },
	{ 130,4 },
	{ 129,4 },
	{ 128,4 },
};
static TexAnim enemyExt01Attack[] = {
	{ 0,4 },
};
static TexAnim enemyExtAttack01End[] = {
	{ 0,4 },
};
TexAnimData enemy_anim_data[] = {
	ANIMDATA(enemyIdle),
	ANIMDATA(enemyWalk),
	ANIMDATA(enemyRun),
	ANIMDATA(enemyJumpUp),
	ANIMDATA(enemyJumpDown),
	ANIMDATA(enemyAttack01),
	ANIMDATA(enemyAttack01End),
	ANIMDATA(enemyAttack02),
	ANIMDATA(enemyAttack02End),
	ANIMDATA(enemyAttack03),
	ANIMDATA(enemyAttack03End),
	ANIMDATA(enemyDamage),
	ANIMDATA(enemyDamageEnd),
	ANIMDATA(enemyDeath),
	ANIMDATA(enemyDown),
	ANIMDATA(enemyDownGround),
	ANIMDATA(enemyWakeup),
	ANIMDATA(enemyGuard),
	ANIMDATA(enemyGuardEnd),
	ANIMDATA(enemyCrash),
	ANIMDATA(enemyCrash01End),
	ANIMDATA(enemyExt01Attack),
	ANIMDATA(enemyExtAttack01End),
};

static TexAnim bossIdle[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	{ 3,2 },
	{ 4,2 },
	{ 5,2 },
	{ 6,2 },
	{ 7,2 },
	{ 8,2 },
	{ 9,2 },
	{ 10,2 },
	{ 11,2 },
	{ 12,2 },
	{ 13,2 },
	{ 14,2 },
};
static TexAnim bossWalk[] = {
	{ 0,0 },
};
static TexAnim bossRun[] = {
	{ 16,2 },
	{ 17,2 },
	{ 18,2 },
	{ 19,2 },
	{ 20,2 },
	{ 21,2 },
	{ 22,2 },
	{ 23,2 },
	{ 24,2 },
	{ 25,2 },
	{ 26,2 },
	{ 27,2 },
	{ 28,2 },
	{ 29,2 },
	{ 30,2 },
};
static TexAnim bossJumpUp[] = {
	{ 0,0 },
};
static TexAnim bossJumpDown[] = {
	{ 0,0 },
};

static TexAnim bossAttack01[] = {
	{ 40,4 },
	{ 41,4 },
	{ 42,4 },
	{ 43,8 },
	{ 44,2 },
	{ 45,3 },
	{ 46,3 },
	{ 47,3 },
};
static TexAnim bossAttack01End[] = {
	{ 48,2 },
	{ 49,2 },
	{ 50,2 },
	{ 51,2 },
	{ 52,2 },
};
static TexAnim bossAttack02[] = {
	{ 0,0 },
};
static TexAnim bossAttack02End[] = {
	{ 0,0 },
};
static TexAnim bossAttack03[] = {
	{ 0,0 },
};
static TexAnim bossAttack03End[] = {
	{ 0,0 },
};
static TexAnim bossDamage[] = {
	{ 88,2 },
	{ 89,2 },
	{ 90,2 },
	{ 91,2 },
};
static TexAnim bossDamageEnd[] = {
	{ 92,2 },
	{ 93,2 },
	{ 94,2 },
	{ 95,2 },
};
static TexAnim bossDeath[] = {
	{ 96,4 },
	{ 97,4 },
	{ 98,8 },
	{ 99,4 },
	{ 100,4 },
	{ 101,4 },
	{ 102,4 },
	{ 103,4 },
};

static TexAnim bossDown[] = {
	{ 104,4 },
	{ 105,4 },
	{ 106,4 },
	{ 107,4 },
	{ 108,4 },
};
static TexAnim bossDownGround[] = {
	{ 109,4 },
	{ 110,4 },
	{ 111,4 },
};
static TexAnim bossWakeup[] = {
	{ 112,4 },
	{ 113,4 },
	{ 114,4 },
	{ 115,4 },
	{ 116,4 },
	{ 117,4 },
	{ 118,4 },
};
static TexAnim bossGuard[] = {
	{ 0,4 },
};
static TexAnim bossGuardEnd[] = {
	{ 0,4 },
};
static TexAnim bossCrash[] = {
	{ 128,4 },
	{ 129,4 },
	{ 130,4 },
	{ 131,60 },
};
static TexAnim bossCrash01End[] = {
	{ 131,4 },
	{ 130,4 },
	{ 129,4 },
	{ 128,4 },
};
static TexAnim bossExt01Attack[] = {
	{ 0,4 },
};
static TexAnim bossExtAttack01End[] = {
	{ 0,4 },
};
TexAnimData boss_anim_data[] = {
	ANIMDATA(bossIdle),
	ANIMDATA(bossWalk),
	ANIMDATA(bossRun),
	ANIMDATA(bossJumpUp),
	ANIMDATA(bossJumpDown),
	ANIMDATA(bossAttack01),
	ANIMDATA(bossAttack01End),
	ANIMDATA(bossAttack02),
	ANIMDATA(bossAttack02End),
	ANIMDATA(bossAttack03),
	ANIMDATA(bossAttack03End),
	ANIMDATA(bossDamage),
	ANIMDATA(bossDamageEnd),
	ANIMDATA(bossDeath),
	ANIMDATA(bossDown),
	ANIMDATA(bossDownGround),
	ANIMDATA(bossWakeup),
	ANIMDATA(bossGuard),
	ANIMDATA(bossGuardEnd),
	ANIMDATA(bossCrash),
	ANIMDATA(bossCrash01End),
	ANIMDATA(bossExt01Attack),
	ANIMDATA(bossExtAttack01End),
};


static TexAnim _effect_blood[] = {
	{ 0,1 },
	{ 1,1 },
	{ 2,1 },
	{ 3,1 },
};
TexAnimData effect_blood_anim_data[] = {
	ANIMDATA(_effect_blood),
};
static TexAnim _effect_smoke[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	{ 3,2 },
	{ 4,2 },
};
TexAnimData effect_smoke_anim_data[] = {
	ANIMDATA(_effect_smoke),
};

static TexAnim _effect_bomb[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	{ 3,2 },
	{ 4,2 },
};
TexAnimData effect_bomb_anim_data[] = {
	ANIMDATA(_effect_smoke),
};
static TexAnim _effect_slash[] = {
	{ 0,4 },
	{ 1,4 },
	{ 2,4 },
	{ 3,4 },
	{ 4,4 },
};
TexAnimData effect_slash_anim_data[] = {
	ANIMDATA(_effect_slash),
};


/*
* #include "AnimData.h"


static TexAnim playerIdle[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	{ 3,2 },
	{ 4,2 },
	{ 5,2 },
	{ 6,2 },
	{ 7,2 },
	{ 8,2 },
	{ 9,2 },
	{ 10,2 },
	{ 11,2 },
	{ 12,2 },
	{ 13,2 },
	{ 14,2 },
};
static TexAnim playerRun[] = {
	{ 16,2 },
	{ 17,2 },
	{ 18,2 },
	{ 19,2 },
	{ 20,2 },
	{ 21,2 },
	{ 22,2 },
	{ 23,2 },
	{ 24,2 },
	{ 25,2 },
	{ 26,2 },
	{ 27,2 },
	{ 28,2 },
	{ 29,2 },
	{ 30,2 },
};
static TexAnim playerJumpUp[] = {
	{ 32,4 },
	{ 33,4 },
	{ 34,4 },

};
static TexAnim playerJumpDown[] = {
	{ 36,4 },
	{ 37,4 },
	{ 38,4 },

};
static TexAnim playerAttack01[] = {
	{ 40,3 },
	{ 41,3 },
	{ 42,3 },
	{ 43,2 },
	{ 44,2 },
	{ 45,3 },
	{ 46,4 },
};
static TexAnim playerAttack01End[] = {
	{ 48,4 },
	{ 49,4 },
	{ 50,4 },
	{ 51,4 },
	{ 52,4 },
};
static TexAnim playerAttack02[] = {
	{ 56,6 },
	{ 57,6 },
	{ 58,4 },
	{ 59,2 },
	{ 60,2 },
	{ 61,2 },
	{ 62,4 },
};
static TexAnim playerAttack02End[] = {
	{ 64,4 },
	{ 65,4 },
	{ 66,4 },
	{ 67,4 },
	{ 68,4 },
};
static TexAnim playerAttack03[] = {
	{ 72,6 },
	{ 73,6 },
	{ 74,4 },
	{ 75,4 },
	{ 76,3 },
	{ 77,2 },
	{ 78,2 },
	{ 79,4 },
};
static TexAnim playerAttack03End[] = {
	{ 80,4 },
	{ 81,4 },
	{ 82,4 },
	{ 83,4 },
};

static TexAnim playerDamage[] = {
	{ 88,2 },
	{ 89,2 },
	{ 90,2 },
	{ 91,2 },
};
static TexAnim playerDamageEnd[] = {
	{ 92,2 },
	{ 93,2 },
	{ 94,2 },
	{ 95,2 },
};
static TexAnim playerDeath[] = {
	{ 96,4 },
	{ 97,4 },
	{ 98,8 },
	{ 99,4 },
	{ 100,4 },
	{ 101,4 },
	{ 102,4 },
	{ 103,4 },
};

static TexAnim playerDown[] = {
	{ 104,4 },
	{ 105,4 },
	{ 106,4 },
	{ 107,4 },
	{ 108,4 },
};
static TexAnim playerDownGround[] = {
	{ 109,4 },
	{ 110,4 },
	{ 111,4 },
};
static TexAnim playerWakeup[] = {
	{ 112,4 },
	{ 113,4 },
	{ 114,4 },
	{ 115,4 },
	{ 116,4 },
	{ 117,4 },
	{ 118,4 },
};
static TexAnim playerGuard[] = {
	//	{ 120,4 },
	//	{ 121,4 },
	{ 122,4 },
};
static TexAnim playerGuardEnd[] = {
	{ 122,4 },
	{ 121,4 },
	{ 120,4 },
};
static TexAnim playerCrash[] = {
	{ 128,4 },
	{ 129,4 },
	{ 130,4 },
	{ 131,90 },
};
static TexAnim playerCrash01End[] = {
	{ 131,4 },
	{ 130,4 },
	{ 129,4 },
	{ 128,4 },
};
static TexAnim playerExtAttack01[] = {
	{ 144,4 },
	{ 145,4 },
	{ 146,12 },
	{ 147,2 },
	{ 148,2 },
	{ 149,2 },
	{ 150,16 },
};
static TexAnim playerExtAttack01End[] = {
	{ 151,4 },
	{ 152,4 },
};
static TexAnim playerExtAttack02[] = {
	{ 160,2 },
	{ 161,2 },
	{ 162,2 },
	{ 163,2 },
	{ 164,2 },
	{ 165,2 },
	{ 166,2 },
	{ 167,2 },
	{ 168,2 },
};
static TexAnim playerExtAttack02End[] = {
	{ 169,16 },
	{ 170,4 },
	{ 171,4 },
};
static TexAnim playerStep[] = {
	{ 120,4 },
	{ 121,4 },
	{ 122,4 },
};
TexAnimData player_anim_data[] = {
	ANIMDATA(playerIdle),
	ANIMDATA(playerRun),
	ANIMDATA(playerJumpUp),
	ANIMDATA(playerJumpDown),
	ANIMDATA(playerAttack01),
	ANIMDATA(playerAttack01End),
	ANIMDATA(playerAttack02),
	ANIMDATA(playerAttack02End),
	ANIMDATA(playerAttack03),
	ANIMDATA(playerAttack03End),
	ANIMDATA(playerDamage),
	ANIMDATA(playerDamageEnd),
	ANIMDATA(playerDeath),
	ANIMDATA(playerDown),
	ANIMDATA(playerDownGround),
	ANIMDATA(playerWakeup),
	ANIMDATA(playerGuard),
	ANIMDATA(playerGuardEnd),
	ANIMDATA(playerCrash),
	ANIMDATA(playerCrash01End),
	ANIMDATA(playerExtAttack01),
	ANIMDATA(playerExtAttack01End),
	ANIMDATA(playerExtAttack02),
	ANIMDATA(playerExtAttack02End),
	ANIMDATA(playerStep),
};

static TexAnim enemyIdle[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	{ 3,2 },
	{ 4,2 },
	{ 5,2 },
	{ 6,2 },
	{ 7,2 },
	{ 8,2 },
	{ 9,2 },
	{ 10,2 },
	{ 11,2 },
	{ 12,2 },
	{ 13,2 },
	{ 14,2 },
};
static TexAnim enemyRun[] = {
	{ 16,2 },
	{ 17,2 },
	{ 18,2 },
	{ 19,2 },
	{ 20,2 },
	{ 21,2 },
	{ 22,2 },
	{ 23,2 },
	{ 24,2 },
	{ 25,2 },
	{ 26,2 },
	{ 27,2 },
	{ 28,2 },
	{ 29,2 },
	{ 30,2 },
};
static TexAnim enemyJumpUp[] = {
	{ 0,0 },
};
static TexAnim enemyJumpDown[] = {
	{ 0,0 },
};

static TexAnim enemyAttack01[] = {
	{ 40,4 },
	{ 41,4 },
	{ 42,4 },
	{ 43,8 },
	{ 44,2 },
	{ 45,3 },
	{ 46,3 },
	{ 47,3 },
};
static TexAnim enemyAttack01End[] = {
	{ 48,2 },
	{ 49,2 },
	{ 50,2 },
	{ 51,2 },
	{ 52,2 },
};
static TexAnim enemyAttack02[] = {
	{ 0,0 },
};
static TexAnim enemyAttack02End[] = {
	{ 0,0 },
};
static TexAnim enemyAttack03[] = {
	{ 0,0 },
};
static TexAnim enemyAttack03End[] = {
	{ 0,0 },
};
static TexAnim enemyDamage[] = {
	{ 88,2 },
	{ 89,2 },
	{ 90,2 },
	{ 91,2 },
};
static TexAnim enemyDamageEnd[] = {
	{ 92,2 },
	{ 93,2 },
	{ 94,2 },
	{ 95,2 },
};
static TexAnim enemyDeath[] = {
	{ 96,4 },
	{ 97,4 },
	{ 98,8 },
	{ 99,4 },
	{ 100,4 },
	{ 101,4 },
	{ 102,4 },
	{ 103,4 },
};

static TexAnim enemyDown[] = {
	{ 104,4 },
	{ 105,4 },
	{ 106,4 },
	{ 107,4 },
	{ 108,4 },
};
static TexAnim enemyDownGround[] = {
	{ 109,4 },
	{ 110,4 },
	{ 111,4 },
};
static TexAnim enemyWakeup[] = {
	{ 112,4 },
	{ 113,4 },
	{ 114,4 },
	{ 115,4 },
	{ 116,4 },
	{ 117,4 },
	{ 118,4 },
};
static TexAnim enemyGuard[] = {
	{ 0,4 },
};
static TexAnim enemyGuardEnd[] = {
	{ 0,4 },
};
static TexAnim enemyCrash[] = {
	{ 128,4 },
	{ 129,4 },
	{ 130,4 },
	{ 131,60 },
};
static TexAnim enemyCrash01End[] = {
	{ 131,4 },
	{ 130,4 },
	{ 129,4 },
	{ 128,4 },
};
static TexAnim enemyExt01Attack[] = {
	{ 0,4 },
};
static TexAnim enemyExtAttack01End[] = {
	{ 0,4 },
};
TexAnimData enemy_anim_data[] = {
	ANIMDATA(enemyIdle),
	ANIMDATA(enemyRun),
	ANIMDATA(enemyJumpUp),
	ANIMDATA(enemyJumpDown),
	ANIMDATA(enemyAttack01),
	ANIMDATA(enemyAttack01End),
	ANIMDATA(enemyAttack02),
	ANIMDATA(enemyAttack02End),
	ANIMDATA(enemyAttack03),
	ANIMDATA(enemyAttack03End),
	ANIMDATA(enemyDamage),
	ANIMDATA(enemyDamageEnd),
	ANIMDATA(enemyDeath),
	ANIMDATA(enemyDown),
	ANIMDATA(enemyDownGround),
	ANIMDATA(enemyWakeup),
	ANIMDATA(enemyGuard),
	ANIMDATA(enemyGuardEnd),
	ANIMDATA(enemyCrash),
	ANIMDATA(enemyCrash01End),
	ANIMDATA(enemyExt01Attack),
	ANIMDATA(enemyExtAttack01End),
};




static TexAnim _effect_blood[] = {
	{ 0,1 },
	{ 1,1 },
	{ 2,1 },
	{ 3,1 },
};
TexAnimData effect_blood_anim_data[] = {
	ANIMDATA(_effect_blood),
};
static TexAnim _effect_smoke[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	{ 3,2 },
	{ 4,2 },
};
TexAnimData effect_smoke_anim_data[] = {
	ANIMDATA(_effect_smoke),
};

static TexAnim _effect_bomb[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	{ 3,2 },
	{ 4,2 },
};
TexAnimData effect_bomb_anim_data[] = {
	ANIMDATA(_effect_smoke),
};
static TexAnim _effect_slash[] = {
	{ 0,4 },
	{ 1,4 },
	{ 2,4 },
	{ 3,4 },
	{ 4,4 },
};
TexAnimData effect_slash_anim_data[] = {
	ANIMDATA(_effect_slash),
};
*/