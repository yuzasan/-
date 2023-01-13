#include "Map.h"
#include "Player.h"
#include "Change.h"
#include "Enemy.h"
#include "Boss.h"
#include "Goal.h"
#include "AreaChange.h"
#include "Gamedata.h"
#include "Gimmick.h"
#include "UI.h"
#include "Item.h"
#include "Boss.h"
static int stage0data[MAP_HEIGHT][MAP_WIDTH] = {
	//1,2,3,4,5,6,7,8,910111213141516171819202122232425262728293031323334353637383940
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//1
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//2
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//3
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//4
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//5
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//6
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//7
	{ 1,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1},//8
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//9
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//10
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},//11
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//12
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//13
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//14
	{ 1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1},//15
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//16
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//17
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},//18
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//19
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//20
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//21=1340
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//22
	//1,2,3,4,5,6,7,8,910111213141516171819202122232425262728293031323334353637383940
};

static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
	//1,2,3,4,5,6,7,8,910111213141516171819202122232425262728293031323334353637383940
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//1
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//2
	{ 1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//3
	{ 1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//4
	{ 1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//5
	{ 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//6
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//7
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1},//8
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//9
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//10
	{ 1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//11
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1},//12
	{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//13
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//14
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//15
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,3,1,1,1,1,1,1,1},//16
	{ 1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,1},//17
	{ 1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,3,0,0,0,0,0,0,1},//18
	{ 1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1},//19
	{ 1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,3,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//20
	{ 1,0,0,0,0,0,0,0,0,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//21
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//22
};

static int stage2data[MAP_HEIGHT][MAP_WIDTH] = {
	//1,2,3,4,5,6,7,8,910111213141516171819202122232425262728293031323334353637383940
   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//1
   { 1,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//2
   { 1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//3
   { 1,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//4
   { 1,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//5
   { 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//6
   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//7
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1},//8
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//9
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//10
   { 1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//11
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1},//12
   { 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//13
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//14
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//15
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1},//16
   { 1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//17
   { 1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1},//18
   { 1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1},//19
   { 1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//20
   { 1,0,0,1,0,0,0,0,0,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//21
   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//22
};

static int stage3data[MAP_HEIGHT][MAP_WIDTH] = {
	//1,2,3,4,5,6,7,8,910111213141516171819202122232425262728293031323334353637383940
   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//1
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//2
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//3
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//4
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//5
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//6
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//7
   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//8
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//9
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//10
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//11
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//12
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//13
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//14
   { 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//15
   { 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//16
   { 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//17
   { 1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//18
   { 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//19
   { 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//20
   { 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//21=1340
   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//22
};

static int stage4data[MAP_HEIGHT][MAP_WIDTH] = {
	//1,2,3,4,5,6,7,8,910111213141516171819202122232425262728293031323334353637383940
   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//1
   { 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//2
   { 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//3
   { 1,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,3,3,1,1,1,3,3,1,1,1,3,3,1,1,1,3,3,1,1,0,1},//4
   { 1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1},//5
   { 1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1},//6
   { 1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,1,1,1,1,3,1,1,1,1,1,1,1,3,1,3,1,1,1,1,0,1},//7
   { 1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1},//8
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,4,0,0,0,0,4,0,0,0,0,1,0,0,0,0,0,0,1},//9
   { 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,0,1},//10
   { 1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1},//11
   { 1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,4,0,0,0,0,4,0,0,0,0,1,0,0,0,0,4,0,0,0,0,0,0,1},//12
   { 1,0,1,1,1,1,0,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,0,1},//13
   { 1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,4,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1},//14
   { 1,0,1,0,0,0,0,4,0,0,0,0,4,0,0,0,0,1,3,1,1,0,1,0,0,0,0,4,0,0,0,0,4,0,0,0,0,0,0,1},//15
   { 1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,3,1,3,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,0,1},//16
   { 1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},//17
   { 1,0,0,0,0,0,0,4,0,0,0,0,4,0,0,0,0,1,0,1,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//18
   { 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,0,0,1,1,1,1,1,0,1},//19
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//20
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//21=1340
   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//22
};

Map::Map(int stage, const CVector2D& nextplayerpos) : Base(eType_Field), m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 32), m_key_text("C:\\Windows\\Fonts\\msgothic.ttc", 128) {
	m_ground_x = 500;
	m_ground_y = 500;
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (m_map_data[i][j] < 2)continue;
			int x;
			int y;
			x = j * MAP_TIP_SIZE;
			y = i * MAP_TIP_SIZE;
			int& t = m_map_data[i][j];
		}
	}
	//画像複製
	m_img = COPY_RESOURCE("MapTip2", CImage);
	i = i;
	switch (stage) {
	case 0:
		memcpy(m_map_data, stage0data, sizeof(stage0data));
		//敵の生成
		//Base::Add(new Enemy(CVector2D(32 * 4, 1340 - 32), true));
		//Base::Add(new Enemy(CVector2D(32 * 30, 32 * 16), true));

		//エリアチェンジの生成
		Base::Add(new AreaChange(GameData::stage = 1,
			CRect(MAP_TIP_SIZE * 8, MAP_TIP_SIZE * 19, 64, 128),
			CVector2D(100, 200)));

		Base::Add(new AreaChange(GameData::stage = 2,
			CRect(MAP_TIP_SIZE * 15, MAP_TIP_SIZE * 19, 64, 128),
			CVector2D(32 * 3, 1340)));//左下

		Base::Add(new AreaChange(GameData::stage = 3,
			CRect(MAP_TIP_SIZE * 24, MAP_TIP_SIZE * 19, 64, 128),
			CVector2D(32 * 3, 1340)));

		Base::Add(new AreaChange(GameData::stage = 4,
			CRect(MAP_TIP_SIZE * 31, MAP_TIP_SIZE * 19, 64, 128),
			CVector2D(32 * 3, MAP_TIP_SIZE * 2)));

		/*
		//ワープの生成
		Base::Add(new Warp(GameData::stage = 1,
			CRect(32 * 26, 32 * 8, 64, 128),
			CVector2D(32 * 43, 32 * 19)));
		//ワープの生成
		Base::Add(new Warp(GameData::stage = 1,
			CRect(32 * 50, 32 * 10, 64, 128),
			CVector2D(32 * 39, 32 * 19)));
		*/

		//重力エリアの生成
		//上
		Base::Add(new Gravity_Up(GameData::stage = 0,
			CRect(MAP_TIP_SIZE * 1, MAP_TIP_SIZE * 7, MAP_TIP_SIZE * 3, MAP_TIP_SIZE * 14)));//32*2で1マップチップ
		//上
		Base::Add(new Gravity_Up(GameData::stage = 0,
			CRect(MAP_TIP_SIZE * 36, MAP_TIP_SIZE * 7, MAP_TIP_SIZE * 3, MAP_TIP_SIZE * 14)));
		/*
		//左
		Base::Add(new Gravity_Left(GameData::stage = 0,
			CRect(MAP_TIP_SIZE * 17, MAP_TIP_SIZE * 19, MAP_TIP_SIZE * 2, MAP_TIP_SIZE * 2)));
		//右
		Base::Add(new Gravity_Right(GameData::stage = 0,
			CRect(MAP_TIP_SIZE * 21, MAP_TIP_SIZE * 19, MAP_TIP_SIZE * 2, MAP_TIP_SIZE * 2)));
		*/

		break;
	case 1:
		memcpy(m_map_data, stage1data, sizeof(stage1data));
		//敵の生成
		Base::Add(new Enemy(CVector2D(32 * 4, 1340 - 32), true));
		Base::Add(new Enemy(CVector2D(32 * 30, 32 * 16), true));

		//ゴールの生成
		//Base::Add(new Goal(CVector2D(32 * 30, 32 * 4)));

		//エリアチェンジの生成
		Base::Add(new AreaChange(GameData::stage = 0,
			CRect(32 * 20, 32 * 8, 64, 128),
			CVector2D(MAP_TIP_SIZE * 20, 1340)));

		Base::Add(new AreaChange(GameData::stage = 2,
			CRect(32 * 20, 32 * 16, 64, 128),
			CVector2D(100, 200)));

		Base::Add(new AreaChange(GameData::stage = 3,
			CRect(32 * 55, 1344 - 128, 64, 128),
			CVector2D(32 * 3, 1340)));

		//ワープの生成
		Base::Add(new Warp(GameData::stage = 1,
			CRect(32 * 26, 32 * 8, 64, 128),
			CVector2D(32 * 43, 32 * 19)));
		//ワープの生成
		Base::Add(new Warp(GameData::stage = 1,
			CRect(32 * 50, 32 * 10, 64, 128),
			CVector2D(32 * 39, 32 * 15)));

		//アイテム
		Base::Add(new ItemC(CVector2D(32 * 63, 1340 - 32)));
		//Base::Add(new ItemC(CVector2D(32 * 61, 1340)));
		Base::Add(new ItemK(CVector2D(32 * 59, 1340 - 32)));

		//重力エリアの生成
		Base::Add(new Gravity_Up(GameData::stage = 1,
			CRect(32 * 66, 1024, 32 * 12, 32 * 10)));//32*2で1マップチップ
			//CRect(32 * 66, 32 * 32, 512, 512)));

		break;
	case 2:
		memcpy(m_map_data, stage2data, sizeof(stage2data));
		//敵の生成
		Base::Add(new Enemy(CVector2D(32 * 30, 32 * 16), true));
		Base::Add(new Enemy(CVector2D(MAP_TIP_SIZE * 5, MAP_TIP_SIZE * 20), true));

		//ゴールの生成
		Base::Add(new Goal(CVector2D(32 * 50, 32 * 8)));

		//エリアチェンジの生成
		Base::Add(new AreaChange(GameData::stage = 0,
			CRect(32 * 20, 32 * 8, 64, 128),
			CVector2D(MAP_TIP_SIZE * 20, 1340)));

		//アイテム
		Base::Add(new ItemC(CVector2D(32 * 63, 1340)));

		break;
	case 3:
		memcpy(m_map_data, stage3data, sizeof(stage3data));

		//ボスの生成
		Base::Add(new Boss(CVector2D(MAP_TIP_SIZE * 10, 1340), true));

		//ボスの生成
		Base::Add(new Boss(CVector2D(MAP_TIP_SIZE * 15, 1340), true));


		//ワープの生成
		Base::Add(new Warp(GameData::stage = 3,
			CRect(MAP_TIP_SIZE * 19, MAP_TIP_SIZE * 19, 64, 128),		//左1階
			CVector2D(MAP_TIP_SIZE / 2 * 3, 1340 - MAP_TIP_SIZE * 7)));	//左2階
			//CVector2D(MAP_TIP_SIZE / 2 * 3, 1340)));

		Base::Add(new Warp(GameData::stage = 3,
			CRect(MAP_TIP_SIZE * 19, MAP_TIP_SIZE * 12, 64, 128),		//左2階
			CVector2D(MAP_TIP_SIZE / 2 * 3, 1340 - MAP_TIP_SIZE * 14)));//左3階

		Base::Add(new Warp(GameData::stage = 3,
			CRect(MAP_TIP_SIZE * 19, MAP_TIP_SIZE * 5, 64, 128),		//左3階
			CVector2D(MAP_TIP_SIZE / 2 * 3 + MAP_TIP_SIZE * 20, 1340 - MAP_TIP_SIZE * 14)));//右3階

		Base::Add(new Warp(GameData::stage = 3,
			CRect(MAP_TIP_SIZE * 38, MAP_TIP_SIZE * 5, 64, 128),		//右3階
			CVector2D(MAP_TIP_SIZE / 2 * 3 + MAP_TIP_SIZE * 20, 1340 - MAP_TIP_SIZE * 7)));//右2階

		Base::Add(new Warp(GameData::stage = 3,
			CRect(MAP_TIP_SIZE * 38, MAP_TIP_SIZE * 12, 64, 128),		//右2階
			CVector2D(MAP_TIP_SIZE / 2 * 3 + MAP_TIP_SIZE * 20, 1340)));//右1階

		//エリアチェンジの生成
		Base::Add(new AreaChange(GameData::stage = 0,
			CRect(MAP_TIP_SIZE * 38, MAP_TIP_SIZE * 19, 64, 128),
			CVector2D(MAP_TIP_SIZE * 20, 1340)));

		break;
	case 4:
		memcpy(m_map_data, stage4data, sizeof(stage4data));
		//重力エリアの生成

		//上
		Base::Add(new Gravity_Up(GameData::stage = 4,
			CRect(MAP_TIP_SIZE * 2, MAP_TIP_SIZE * 3, MAP_TIP_SIZE * 1, MAP_TIP_SIZE * 2)));
		//上
		Base::Add(new Gravity_Up(GameData::stage = 4,
			CRect(MAP_TIP_SIZE * 1, MAP_TIP_SIZE * 5, MAP_TIP_SIZE * 1, MAP_TIP_SIZE * 16)));
		//左
		Base::Add(new Gravity_Left(GameData::stage = 4,
			CRect(MAP_TIP_SIZE * 0, MAP_TIP_SIZE * 19, MAP_TIP_SIZE * 39, MAP_TIP_SIZE * 2)));
		//左
		Base::Add(new Gravity_Left(GameData::stage = 4,
			CRect(MAP_TIP_SIZE * 2, MAP_TIP_SIZE * 8, MAP_TIP_SIZE * 16, MAP_TIP_SIZE * 1)));
		//右
		Base::Add(new Gravity_Right(GameData::stage = 4,
			CRect(MAP_TIP_SIZE * 0, MAP_TIP_SIZE * 4, MAP_TIP_SIZE * 3, MAP_TIP_SIZE * 2)));

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


		//スモッグの生成
		Base::Add(new SmogAll(GameData::stage = 4,
			CRect(MAP_TIP_SIZE * 2, MAP_TIP_SIZE * 1, MAP_TIP_SIZE * 1, MAP_TIP_SIZE * 2)));

		//ズームの生成
		Base::Add(new Zoom(GameData::stage = 4,
			CRect(MAP_TIP_SIZE * 1, MAP_TIP_SIZE * 1, MAP_TIP_SIZE * 39, MAP_TIP_SIZE * 20)));

		//エリアチェンジの生成
		Base::Add(new AreaChange(GameData::stage = 0,
			//CRect(MAP_TIP_SIZE * 38, MAP_TIP_SIZE * 19, 64, 128),
			CRect(MAP_TIP_SIZE * 22, MAP_TIP_SIZE * 16, 64, 128),
			CVector2D(MAP_TIP_SIZE * 20, 1340)));

		Base::Add(new AreaChange(GameData::stage = 0,
			//CRect(MAP_TIP_SIZE * 38, MAP_TIP_SIZE * 19, 64, 128),
			CRect(MAP_TIP_SIZE * 17, MAP_TIP_SIZE * 16, 64, 128),
			CVector2D(MAP_TIP_SIZE * 20, 1340)));

		break;
	}

	//プレイヤーの位置決定
	if (Base* p = Base::FindObject(eType_Player)) {
		p->ResetPos(nextplayerpos);
	}

	//プレイヤーの位置決定
	if (Base* p = Base::FindObject(eType_Change)) {
		p->ResetPos(nextplayerpos);
	}
}

void Map::Draw() {
	//横
	int x1 = m_scroll.x / MAP_TIP_SIZE;
	if (x1 < 0) x1 = 0;
	int	x2 = x1 + 31;
	if (x2 > MAP_WIDTH - 1) x2 = MAP_WIDTH - 1;
	//縦
	int y1 = m_scroll.y / MAP_TIP_SIZE;
	if (y1 < 0) y1 = 0;
	int	y2 = y1 + 17;
	if (y2 > MAP_HEIGHT - 1) y2 = MAP_HEIGHT - 1;


	//マップチップによる表示の繰り返し
	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) {
			//表示しない制御
			if (m_map_data[i][j] == 0)continue;
			int t = m_map_data[i][j];
			//画像切り抜き
			m_img.SetRect(32 * t, 0, 32 * t + 32, 32);
			//表示サイズ設定
			m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);
			//表示位置設定
			m_img.SetPos(MAP_TIP_SIZE * j - m_scroll.x, MAP_TIP_SIZE * i - m_scroll.y);
			//描画
			m_img.Draw();
		}
	}
	if (Base::FindObject(eType_Player) || Base::FindObject(eType_Change)) {
		if (GameData::ItemC == 5) {
			m_title_text.Draw(350, 100, 255, 255, 255, "×MAX");
		}
		else {
			m_title_text.Draw(350, 100, 255, 255, 255, "×%d", GameData::ItemC);
		}

		if (GameData::ItemK == 10) {
			m_title_text.Draw(500, 100, 255, 255, 255, "×MAX");
		}
		else {
			m_title_text.Draw(500, 100, 255, 255, 255, "×%d", GameData::ItemK);
		}
	}
	m_title_text.Draw(700, 100, 255, 255, 255, "残り時間:%03d秒", GameData::time);

	//説明用
	if (HOLD(CInput::eRight) && HOLD(CInput::eButton2) && HOLD(CInput::eButton5)) {
		m_key_text.Draw(200, 400, 255, 255, 255, "→キー&&Xキー&&spaceキー");
	}
	else if (HOLD(CInput::eLeft) && HOLD(CInput::eButton2) && HOLD(CInput::eButton5)) {
		m_key_text.Draw(200, 400, 255, 255, 255, "←キー&&Xキー&&spaceキー");
	}
	else if (HOLD(CInput::eRight) && HOLD(CInput::eButton5)) {
		m_key_text.Draw(400, 400, 255, 255, 255, "→キー&&spaceキー");
	}
	else if (HOLD(CInput::eLeft) && HOLD(CInput::eButton5)) {
		m_key_text.Draw(400, 400, 255, 255, 255, "←キー&&spaceキー");
	}
	else if (HOLD(CInput::eRight) && HOLD(CInput::eButton2)) {
		m_key_text.Draw(400, 400, 255, 255, 255, "→キー&&Xキー");
	}
	else if (HOLD(CInput::eLeft) && HOLD(CInput::eButton2)) {
		m_key_text.Draw(400, 400, 255, 255, 255, "←キー&&Xキー");
	}
	else if (HOLD(CInput::eRight)) {
		m_key_text.Draw(800, 400, 255, 255, 255, "→キー");
	}
	else if (HOLD(CInput::eLeft)) {
		m_key_text.Draw(800, 400, 255, 255, 255, "←キー");
	}
	else if (HOLD(CInput::eButton1)) {
		m_key_text.Draw(800, 400, 255, 255, 255, "Zキー");
	}
	else if (HOLD(CInput::eButton2)) {
		m_key_text.Draw(800, 400, 255, 255, 255, "Xキー");
	}
	else if (HOLD(CInput::eButton3)) {
		m_key_text.Draw(800, 400, 255, 255, 255, "Cキー");
	}
	else if (HOLD(CInput::eButton5)) {
		m_key_text.Draw(800, 400, 255, 255, 255, "spaceキー");
	}
	else if (HOLD(CInput::eButton10)) {
		m_key_text.Draw(800, 400, 255, 255, 255, "enterキー");
	}

}

void Map::Update() {
	m_scroll.x = m_pos.x - 1280 / 2;
	m_scroll.y = m_pos.y - 440 / 2;
	/*
	i++;
	if (i % 120 == 0) {
		GameData::k = 1;
	}
	else if (i > 240) {
		i = 0;
		GameData::k = 0;
		KillByType(eType_Gravity2);
	}
	if (i == 120) {
		//重力エリアの生成
		Base::Add(new Gravity2(GameData::stage = 1,
			CRect(32 * 66, 1024, 32 * 12, 32 * 10)));//32*2で1マップチップ
			//CRect(32 * 66, 32 * 32, 512, 512)));
	}
	*/

	if (!Base::FindObject(eType_UI)) {
		Base::Add(new UI());
	}
};

int Map::GetTip(const CVector2D& pos) {
	//列を計算
	int col = pos.x / MAP_TIP_SIZE;
	//列の制限(0〜MAP_WIDTH-1)
	if (col < 0)col = 0;
	if (col > MAP_WIDTH - 1)col = MAP_WIDTH - 1;
	//行を計算
	int raw = pos.y / MAP_TIP_SIZE;
	//行の制限(0〜MAP_HEIGHT-1)
	if (raw < 0)raw = 0;
	if (raw > MAP_HEIGHT - 1)raw = MAP_HEIGHT - 1;
	//チップデータを返却
	return GetTip(col, raw);
}

int Map::GetTip(int col, int raw) {

	return m_map_data[raw][col];
}

int Map::CollisionMap(const CVector2D& pos) {
	//一点のみ検証
	int t = GetTip(pos);
	if (t != 0)return t;
	return 0;
}

int Map::CollisionMap(const CVector2D& pos, const CRect& rect, int idx) {
	switch (idx) {
	case 0:
		//左上
		return GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_top));
		break;
	case 1:
		//右上
		return GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_top));
		break;
	case 2:
		//左下
		return GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_bottom));
		break;
	case 3:
		//右下
		return GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_bottom));
		break;

	}
	return 0;
}
/*
int Map::CollisionMap(const CVector2D& pos, const CRect& rect){
	//左上
	int t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_top));
	if (t != 0)return t;
	//右上
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_top));
	if (t != 0)return t;
	//左下
	t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_bottom));
	if (t != 0)return t;
	//右下
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_bottom));
	if (t != 0)return t;
	return 0;
}
*/

/*
#include "Map.h"
static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,1,1,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
	{ 1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

Map::Map() : Base(eType_Field) {
	//画像複製
	m_img = COPY_RESOURCE("MapTip", CImage);
}

void Map::Draw(){
	//マップチップによる表示の繰り返し
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			//表示しない制御
			if (stage1data[i][j] == 0)continue;
			int t = stage1data[i][j];
			//画像切り抜き
			m_img.SetRect(32 * t, 0, 32 * t + 32, 32);
			//表示サイズ設定
			m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);
			//表示位置設定
			m_img.SetPos(MAP_TIP_SIZE * j - m_scroll.x, MAP_TIP_SIZE * i - m_scroll.y);
			//描画
			m_img.Draw();
		}
	}
}

int Map::GetTip(const CVector2D& pos){
	//列を計算
	int col = pos.x / MAP_TIP_SIZE;
	//列の制限(0〜MAP_WIDTH-1)
	if (col < 0)col = 0;
	if (col > MAP_WIDTH - 1)col = MAP_WIDTH - 1;
	//行を計算
	int raw = pos.y / MAP_TIP_SIZE;
	//行の制限(0〜MAP_HEIGHT-1)
	if (raw < 0)raw = 0;
	if (raw > MAP_HEIGHT - 1)raw = MAP_HEIGHT - 1;
	//チップデータを返却
	return GetTip(col,raw);
}

int Map::GetTip(int col, int raw){

	return stage1data[raw][col];
}

int Map::CollisionMap(const CVector2D& pos){
	//一点のみ検証
	int t = GetTip(pos);
	if (t != 0)return t;
	return 0;
}

int Map::CollisionMap(const CVector2D& pos, const CRect& rect){
	//左上
	int t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_top));
	if (t != 0)return t;
	//右上
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_top));
	if (t != 0)return t;
	//左下
	t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_bottom));
	if (t != 0)return t;
	//右下
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_bottom));
	if (t != 0)return t;
	return 0;
}
*/