

#include<iostream>
using namespace std;
#include<fstream>
# include "iGraphics.h"
//#include "level3.h"


#define screenWidth 1200
#define screenHeight 600
#define jumpLimit 200
#define BIRDNUMBER 1
#define bgSpeed 10
#define eagleNUM 1

//int no = 1;
int mposx, mposy;
int i, j;
bool musicOn = true;
int x = 0;
int y = 0;

int r = 255;
int g = 255;
int b = 255;

double dx = 10;
double dy = 10;

//void change();
//void enemyMove();
void enemyMove1();
void coinMove1();
void plusMove();
void steel();
void heroAttack();
void change();
void cactusmove();
//void N_Attack();
//void I_Attac();
void bgcgange();
void render();
//void enemyMovement();
void plusMovement();
void eagleMovement();
void enemyMovement1();
void coinMovement1();
void bossMovement1();
void coinShow();

char BC[4][20] = { "BC\\12.bmp", "BC\\8.bmp", "BC\\14.bmp", "BC\\11.bmp" };

char BG[4][20] = { "BC\\8.bmp", "BC\\11.bmp", "BC\\12.bmp", "BC\\13.bmp" };

int BCIndex = 0;


//ASSASSIN RUNNING FORWARD
char RUN[9][20] = { "RUNRUN\\11.bmp", "RUNRUN\\2.bmp", "RUNRUN\\3.bmp", "RUNRUN\\4.bmp", "RUNRUN\\5.bmp", "RUNRUN\\6.bmp", "RUNRUN\\7.bmp", "RUNRUN\\8.bmp", "RUNRUN\\9.bmp" };// , "RUNRUN\\4.bmp", "RUNURUN\\8.bmp", "RUNURUN\\9.bmp" };
int assRUN = 0;
bool runforcheck = false;

//ASSASSIN RUNNING BACKWARD
char RUNREV[9][20] = { "RUNRUN\\10.bmp", "RUNRUN\\111.bmp", "RUNRUN\\12.bmp", "RUNRUN\\13.bmp", "RUNRUN\\14.bmp", "RUNRUN\\15.bmp", "RUNRUN\\16.bmp", "RUNRUN\\17.bmp", "RUNRUN\\18.bmp" };
int assRunRev = 0;
bool runrevcheck = false;

//ASSASSIN STAND
char STAND[5][20] = { "STND\\stand1.bmp", "STND\\stand2.bmp", "STND\\stand3.bmp", "STND\\stand4.bmp", "STND\\stand5.bmp" };
char STAND_LEFT[5][20] = { "STND\\stand6.bmp", "STND\\stand7.bmp", "STND\\stand8.bmp", "STND\\stand9.bmp", "STND\\stand10.bmp" };
int left_index = 0;
int assSTAND = 0;
int standCounter = 0;
bool standPosition = true;
bool standPositionleft = false;

//FIRE ATTACK
char FIRE[6][20] = { "FIRE ATTACK\\1.bmp", "FIRE ATTACK\\2.bmp", "FIRE ATTACK\\3.bmp", "FIRE ATTACK\\4.bmp", "FIRE ATTACK\\5.bmp", "FIRE ATTACK\\6.bmp" };
int attackreal = 0;
int attackcount = 0;
bool attackFIRE = false;

//JUMP
char AJ[2][20] = { "JUMP\\1.bmp", "JUMP\\2.bmp" };
char AJREV[2][20] = { "JUMP\\5.bmp", "JUMP\\6.bmp" };
int AssCoJump = 0;
bool jump = false;
bool jumpUp = false;
bool jumpDown = false;



//NORMAL ATTACK
char realattack[4][20] = { "Hero Attack\\7.bmp", "Hero Attack\\8.bmp", "Hero Attack\\3.bmp", "Hero Attack\\5.bmp" }; //, "Hero Attack\\5.bmp", "Hero Attack\\6.bmp", "Hero Attack\\7.bmp", "Hero Attack\\8.bmp", };
int n_attack = 0;
bool normal_attack = false;
int n = 0; //normal attack count

//ICE ATTACK
char iceattack[5][20] = { "ICE ATTACK\\1.bmp", "ICE ATTACK\\2.bmp", "ICE ATTACK\\9.bmp", "ICE ATTACK\\4.bmp", "ICE ATTACK\\5.bmp" };
int ice_attack = 0;
bool ICE_ATTACK = false;


//int Fire = 0;


//Assassin's index
float assCoX = 80;
float assCoY = 99;


int face = 0;   //which side facing
int hit = 0; //number hits I am getting


//game
bool gameover = false;
bool game = false;
bool gameOn = false;

char eagle[1][20] = { "eagle\\eagle 4.bmp" };

/*bool showEnemy = true;
int enemyX = 0;
int enemyY = 0;
int enemyIndex = 0;
char birdOne[18][40] = { "skeleton reverse\\2.bmp", "skeleton reverse\\3.bmp", "skeleton reverse\\4.bmp", "skeleton reverse\\5.bmp", "skeleton reverse\\6.bmp", "skeleton reverse\\7.bmp", "skeleton reverse\\8.bmp", "skeleton reverse\\9.bmp", "skeleton reverse\\3.bmp", "skeleton reverse\\20.bmp", "skeleton reverse\\21.bmp", "skeleton reverse\\21.bmp", "skeleton reverse\\22.bmp", "skeleton reverse\\22.bmp", "skeleton reverse\\22.bmp", "skeleton reverse\\22.bmp", "skeleton reverse\\22.bmp", "skeleton reverse\\23.bmp" };*/


//ENEMY
char soldier[24][40] = { "solder walking\\1.bmp", "solder walking\\2.bmp", "solder walking\\3.bmp", "solder walking\\4.bmp", "solder walking\\5.bmp", "solder walking\\6.bmp", "solder walking\\7.bmp", "solder walking\\8.bmp", "solder walking\\9.bmp", "solder walking\\10.bmp", "SoldierA\\15.bmp", "SoldierA\\16.bmp", "SoldierA\\17.bmp", "SoldierA\\18.bmp", "SoldierA\\19.bmp", "SoldierA\\20.bmp", "SoldierA\\20.bmp", "SoldierA\\21.bmp", "soldier dying\\1.bmp", "soldier dying\\2.bmp", "soldier dying\\3.bmp", "soldier dying\\4.bmp", "soldier dying\\5.bmp", "soldier dying\\6.bmp" };
bool showEnemy1 = true;
int enemyX1 = 0;
int enemyY1 = 0;
int enemyIndex1 = 0;
int enemycount = 0;


//ENEMY 2
char soldier2[18][40] = { "skeleton reverse\\1.bmp", "skeleton reverse\\2.bmp", "skeleton reverse\\3.bmp", "skeleton reverse\\4.bmp", "skeleton reverse\\5.bmp", "skeleton reverse\\6.bmp", "skeleton reverse\\7.bmp", "skeleton reverse\\8.bmp", "skeleton reverse\\9.bmp", "skeleton reverse\\1.bmp", "skeleton reverse\\1.bmp", "skeleton reverse\\20.bmp", "skeleton reverse\\21.bmp", "skeleton reverse\\22.bmp", "skeleton reverse\\23.bmp", "skeleton reverse\\24.bmp", "skeleton reverse\\1.bmp", "skeleton reverse\\1.bmp" };
bool showEnemy2 = false;
int enemyX3;
int enemyY3 = 80;
int enemyIndex3 = 0;
int enemycount2;



//ENEMY 3
char soldier3[22][40] = { "tiger\\6.bmp", "tiger\\6.bmp", "tiger\\5.bmp", "tiger\\5.bmp", "tiger\\4.bmp", "tiger\\4.bmp", "tiger\\3.bmp", "tiger\\3.bmp", "tiger\\2.bmp", "tiger\\2.bmp", "tiger\\1.bmp", "tiger\\1.bmp", "tiger\\7.bmp", "tiger\\8.bmp", "tiger\\9.bmp", "tiger\\9.bmp", "tiger\\10.bmp", "tiger\\10.bmp", "tiger\\11.bmp", "tiger\\11.bmp", "tiger\\12.bmp", "tiger\\12.bmp" };

bool showEnemy3 = false;
int enemyX5 = 0;
int enemyY5 = 90;
int enemyIndex5 = 0;
int enemycount3;

// ENEMY 4
char soldier4[16][30] = { "UGABUGAWALK\\1.bmp", "UGABUGAWALK\\2.bmp", "UGABUGAWALK\\3.bmp", "UGABUGAWALK\\4.bmp", "UGABUGAWALK\\5.bmp", "UGABUGAWALK\\6.bmp", "UGABUGAWALK\\7.bmp", "UGABUGAWALK\\8.bmp", "UGABUGAATTACK\\1.bmp", "UGABUGAATTACK\\2.bmp", "UGABUGAATTACK\\3.bmp", "UGABUGAATTACK\\4.bmp", "UGABUGAATTACK\\4.bmp", "UGABUGAATTACK\\4.bmp", "UGABUGAATTACK\\5.bmp", "UGABUGAATTACK\\6.bmp" };
bool showEnemy4 = false;
int enemyX7 = 0;
int enemyY7 = 70;
int enemyIndex7 = 0;
int enemycount4;



struct EAGLE{
	int eagleX = screenWidth;
	int eagleY;
	int eagleIndex;
	bool eagleShow = true;

};

EAGLE eagle_[eagleNUM];



int e_attack = 0;
bool enemyAttack = true;
char enemy_attack[4][20] = { "SA\\1.bmp", "SA\\2.bmp", "SA\\3.bmp", "SA\\4.bmp" };

//INTEGERS CORRESPONDING ITS BOOLEANS
int show_enemy1;
int show_enemy2;
int show_enemy3;
int show_enemy4;
int show_boss1;
int show_boss2;
int show_boss3;
int show_boss4;
int show_coin1;
int show_coin2;
int show_cactus;
int show_plus;
int show_treasure1;

int level = 0;
bool level1 = false;
bool level2 = false;
bool level3 = false;
bool level4 = false;



//RENDERING
int position[200];


char image[200][40] = { "new1\\1.bmp", "new1\\2.bmp", "new1\\3.bmp", "new1\\4.bmp", "new1\\5.bmp", "new1\\6.bmp", "new1\\7.bmp", "new1\\8.bmp", "new1\\9.bmp", "new1\\10.bmp",
"new1\\11.bmp", "new1\\12.bmp", "new1\\13.bmp", "new1\\14.bmp", "new1\\15.bmp", "new1\\16.bmp", "new1\\17.bmp", "new1\\18.bmp", "new1\\19.bmp", "new1\\20.bmp",
"new1\\21.bmp", "new1\\22.bmp", "new1\\23.bmp", "new1\\24.bmp", "new1\\25.bmp", "new1\\26.bmp", "new1\\27.bmp", "new1\\28.bmp", "new1\\29.bmp", "new1\\30.bmp",
"new1\\31.bmp", "new1\\32.bmp", "new1\\33.bmp", "new1\\34.bmp", "new1\\35.bmp", "new1\\36.bmp", "new1\\37.bmp", "new1\\38.bmp", "new1\\39.bmp", "new1\\40.bmp",
"new1\\41.bmp", "new1\\42.bmp", "new1\\43.bmp", "new1\\44.bmp", "new1\\45.bmp", "new1\\46.bmp", "new1\\47.bmp", "new1\\48.bmp", "new1\\49.bmp", "new1\\50.bmp",
"new1\\51.bmp", "new1\\52.bmp", "new1\\53.bmp", "new1\\54.bmp", "new1\\55.bmp", "new1\\56.bmp", "new1\\57.bmp", "new1\\58.bmp", "new1\\59.bmp", "new1\\60.bmp",
"new1\\61.bmp", "new1\\62.bmp", "new1\\63.bmp", "new1\\64.bmp", "new1\\65.bmp", "new1\\66.bmp", "new1\\67.bmp", "new1\\68.bmp", "new1\\69.bmp", "new1\\70.bmp",
"new1\\71.bmp", "new1\\72.bmp", "new1\\73.bmp", "new1\\74.bmp", "new1\\75.bmp", "new1\\76.bmp", "new1\\77.bmp", "new1\\78.bmp", "new1\\79.bmp", "new1\\80.bmp",
"new1\\81.bmp", "new1\\82.bmp", "new1\\83.bmp", "new1\\84.bmp", "new1\\85.bmp", "new1\\86.bmp", "new1\\87.bmp", "new1\\88.bmp", "new1\\89.bmp", "new1\\90.bmp",
"new1\\91.bmp", "new1\\92.bmp", "new1\\93.bmp", "new1\\94.bmp", "new1\\95.bmp", "new1\\96.bmp", "new1\\97.bmp", "new1\\98.bmp", "new1\\99.bmp", "new1\\100.bmp",
"new1\\101.bmp", "new1\\102.bmp", "new1\\103.bmp", "new1\\104.bmp", "new1\\105.bmp", "new1\\106.bmp", "new1\\107.bmp", "new1\\108.bmp", "new1\\109.bmp", "new1\\110.bmp",
"new1\\111.bmp", "new1\\112.bmp", "new1\\113.bmp", "new1\\114.bmp", "new1\\115.bmp", "new1\\116.bmp", "new1\\117.bmp", "new1\\118.bmp", "new1\\119.bmp", "new1\\120.bmp",
"new1\\121.bmp", "new1\\122.bmp", "new1\\123.bmp", "new1\\124.bmp", "new1\\125.bmp", "new1\\126.bmp", "new1\\127.bmp", "new1\\128.bmp", "new1\\129.bmp", "new1\\130.bmp",
"new1\\131.bmp", "new1\\132.bmp", "new1\\133.bmp", "new1\\134.bmp", "new1\\135.bmp", "new1\\136.bmp", "new1\\137.bmp", "new1\\138.bmp", "new1\\139.bmp", "new1\\140.bmp",
"new1\\141.bmp", "new1\\142.bmp", "new1\\143.bmp", "new1\\144.bmp", "new1\\145.bmp", "new1\\146.bmp", "new1\\147.bmp", "new1\\148.bmp", "new1\\149.bmp", "new1\\150.bmp",
"new1\\151.bmp", "new1\\152.bmp", "new1\\153.bmp", "new1\\154.bmp", "new1\\155.bmp", "new1\\156.bmp", "new1\\157.bmp", "new1\\158.bmp", "new1\\159.bmp", "new1\\160.bmp",
"new1\\161.bmp", "new1\\162.bmp", "new1\\163.bmp", "new1\\164.bmp", "new1\\165.bmp", "new1\\166.bmp", "new1\\167.bmp", "new1\\168.bmp", "new1\\169.bmp", "new1\\170.bmp",
"new1\\171.bmp", "new1\\172.bmp", "new1\\173.bmp", "new1\\174.bmp", "new1\\175.bmp", "new1\\176.bmp", "new1\\177.bmp", "new1\\178.bmp", "new1\\179.bmp", "new1\\180.bmp",
"new1\\181.bmp", "new1\\182.bmp", "new1\\183.bmp", "new1\\184.bmp", "new1\\185.bmp", "new1\\186.bmp", "new1\\187.bmp", "new1\\188.bmp", "new1\\189.bmp", "new1\\190.bmp",
"new1\\191.bmp", "new1\\192.bmp", "new1\\193.bmp", "new1\\194.bmp", "new1\\195.bmp", "new1\\196.bmp", "new1\\197.bmp", "new1\\198.bmp", "new1\\199.bmp", "new1\\200.bmp" };


char image2[200][40] = { "new2\\14_1200x700_01_01_result.bmp", "new2\\14_1200x700_01_02_result.bmp", "new2\\14_1200x700_01_03_result.bmp", "new2\\14_1200x700_01_04_result.bmp", "new2\\14_1200x700_01_05_result.bmp", "new2\\14_1200x700_01_06_result.bmp", "new2\\14_1200x700_01_07_result.bmp", "new2\\14_1200x700_01_08_result.bmp", "new2\\14_1200x700_01_09_result.bmp", "new2\\14_1200x700_01_10_result.bmp",
"new2\\14_1200x700_01_11_result.bmp", "new2\\14_1200x700_01_12_result.bmp", "new2\\14_1200x700_01_13_result.bmp", "new2\\14_1200x700_01_14_result.bmp", "new2\\14_1200x700_01_15_result.bmp", "new2\\14_1200x700_01_16_result.bmp", "new2\\14_1200x700_01_17_result.bmp", "new2\\14_1200x700_01_18_result.bmp", "new2\\14_1200x700_01_19_result.bmp", "new2\\14_1200x700_01_20_result.bmp",
"new2\\14_1200x700_01_21_result.bmp", "new2\\14_1200x700_01_22_result.bmp", "new2\\14_1200x700_01_23_result.bmp", "new2\\14_1200x700_01_24_result.bmp", "new2\\14_1200x700_01_25_result.bmp", "new2\\14_1200x700_01_26_result.bmp", "new2\\14_1200x700_01_27_result.bmp", "new2\\14_1200x700_01_28_result.bmp", "new2\\14_1200x700_01_29_result.bmp", "new2\\14_1200x700_01_30_result.bmp",
"new2\\14_1200x700_01_31_result.bmp", "new2\\14_1200x700_01_32_result.bmp", "new2\\14_1200x700_01_33_result.bmp", "new2\\14_1200x700_01_34_result.bmp", "new2\\14_1200x700_01_35_result.bmp", "new2\\14_1200x700_01_36_result.bmp", "new2\\14_1200x700_01_37_result.bmp", "new2\\14_1200x700_01_38_result.bmp", "new2\\14_1200x700_01_39_result.bmp", "new2\\14_1200x700_01_40_result.bmp",
"new2\\14_1200x700_01_41_result.bmp", "new2\\14_1200x700_01_42_result.bmp", "new2\\14_1200x700_01_43_result.bmp", "new2\\14_1200x700_01_44_result.bmp", "new2\\14_1200x700_01_45_result.bmp", "new2\\14_1200x700_01_46_result.bmp", "new2\\14_1200x700_01_47_result.bmp", "new2\\14_1200x700_01_48_result.bmp", "new2\\14_1200x700_01_49_result.bmp", "new2\\14_1200x700_01_50_result.bmp",
"new2\\2_01_result.bmp", "new2\\2_02_result.bmp", "new2\\2_03_result.bmp", "new2\\2_04_result.bmp", "new2\\2_05_result.bmp", "new2\\2_06_result.bmp", "new2\\2_07_result.bmp", "new2\\2_08_result.bmp", "new2\\2_09_result.bmp", "new2\\2_10_result.bmp",
"new2\\2_11_result.bmp", "new2\\2_12_result.bmp", "new2\\2_13_result.bmp", "new2\\2_14_result.bmp", "new2\\2_15_result.bmp", "new2\\2_16_result.bmp", "new2\\2_17_result.bmp", "new2\\2_18_result.bmp", "new2\\2_19_result.bmp", "new2\\2_20_result.bmp",
"new2\\2_21_result.bmp", "new2\\2_22_result.bmp", "new2\\2_23_result.bmp", "new2\\2_24_result.bmp", "new2\\2_25_result.bmp", "new2\\2_26_result.bmp", "new2\\2_27_result.bmp", "new2\\2_28_result.bmp", "new2\\2_29_result.bmp", "new2\\2_30_result.bmp",
"new2\\2_31_result.bmp", "new2\\2_32_result.bmp", "new2\\2_33_result.bmp", "new2\\2_34_result.bmp", "new2\\2_35_result.bmp", "new2\\2_36_result.bmp", "new2\\2_37_result.bmp", "new2\\2_38_result.bmp", "new2\\2_39_result.bmp", "new2\\2_40_result.bmp",
"new2\\2_41_result.bmp", "new2\\2_42_result.bmp", "new2\\2_43_result.bmp", "new2\\2_44_result.bmp", "new2\\2_45_result.bmp", "new2\\2_46_result.bmp", "new2\\2_47_result.bmp", "new2\\2_48_result.bmp", "new2\\2_49_result.bmp", "new2\\2_50_result.bmp",
"new2\\3_01_result.bmp", "new2\\3_02_result.bmp", "new2\\3_03_result.bmp", "new2\\3_04_result.bmp", "new2\\3_05_result.bmp", "new2\\3_06_result.bmp", "new2\\3_07_result.bmp", "new2\\3_08_result.bmp", "new2\\3_09_result.bmp", "new2\\3_10_result.bmp",
"new2\\3_11_result.bmp", "new2\\3_12_result.bmp", "new2\\3_13_result.bmp", "new2\\3_14_result.bmp", "new2\\3_15_result.bmp", "new2\\3_16_result.bmp", "new2\\3_17_result.bmp", "new2\\3_18_result.bmp", "new2\\3_19_result.bmp", "new2\\3_20_result.bmp",
"new2\\3_21_result.bmp", "new2\\3_22_result.bmp", "new2\\3_23_result.bmp", "new2\\3_24_result.bmp", "new2\\3_25_result.bmp", "new2\\3_26_result.bmp", "new2\\3_27_result.bmp", "new2\\3_28_result.bmp", "new2\\3_29_result.bmp", "new2\\3_30_result.bmp",
"new2\\3_31_result.bmp", "new2\\3_32_result.bmp", "new2\\3_33_result.bmp", "new2\\3_34_result.bmp", "new2\\3_35_result.bmp", "new2\\3_36_result.bmp", "new2\\3_37_result.bmp", "new2\\3_38_result.bmp", "new2\\3_39_result.bmp", "new2\\3_40_result.bmp",
"new2\\3_41_result.bmp", "new2\\3_42_result.bmp", "new2\\3_43_result.bmp", "new2\\3_44_result.bmp", "new2\\3_45_result.bmp", "new2\\3_46_result.bmp", "new2\\3_47_result.bmp", "new2\\3_48_result.bmp", "new2\\3_49_result.bmp", "new2\\3_50_result.bmp",
"new2\\4_01_result.bmp", "new2\\4_02_result.bmp", "new2\\4_03_result.bmp", "new2\\4_04_result.bmp", "new2\\4_05_result.bmp", "new2\\4_06_result.bmp", "new2\\4_07_result.bmp", "new2\\4_08_result.bmp", "new2\\4_09_result.bmp", "new2\\4_10_result.bmp",
"new2\\4_11_result.bmp", "new2\\4_12_result.bmp", "new2\\4_13_result.bmp", "new2\\4_14_result.bmp", "new2\\4_15_result.bmp", "new2\\4_16_result.bmp", "new2\\4_17_result.bmp", "new2\\4_18_result.bmp", "new2\\4_19_result.bmp", "new2\\4_20_result.bmp",
"new2\\4_21_result.bmp", "new2\\4_22_result.bmp", "new2\\4_23_result.bmp", "new2\\4_24_result.bmp", "new2\\4_25_result.bmp", "new2\\4_26_result.bmp", "new2\\4_27_result.bmp", "new2\\4_28_result.bmp", "new2\\4_29_result.bmp", "new2\\4_30_result.bmp",
"new2\\4_31_result.bmp", "new2\\4_32_result.bmp", "new2\\4_33_result.bmp", "new2\\4_34_result.bmp", "new2\\4_35_result.bmp", "new2\\4_36_result.bmp", "new2\\4_37_result.bmp", "new2\\4_38_result.bmp", "new2\\4_39_result.bmp", "new2\\4_40_result.bmp",
"new2\\4_41_result.bmp", "new2\\4_42_result.bmp", "new2\\4_43_result.bmp", "new2\\4_44_result.bmp", "new2\\4_45_result.bmp", "new2\\4_46_result.bmp", "new2\\4_47_result.bmp", "new2\\4_48_result.bmp", "new2\\4_49_result.bmp", "new2\\4_50_result.bmp" };


char image3[200][40] = { "jungle\\jungle_1_01_result.bmp", "jungle\\jungle_1_02_result.bmp", "jungle\\jungle_1_03_result.bmp", "jungle\\jungle_1_04_result.bmp", "jungle\\jungle_1_05_result.bmp", "jungle\\jungle_1_06_result.bmp", "jungle\\jungle_1_07_result.bmp",
"jungle\\jungle_1_08_result.bmp", "jungle\\jungle_1_09_result.bmp", "jungle\\jungle_1_10_result.bmp", "jungle\\jungle_1_11_result.bmp", "jungle\\jungle_1_12_result.bmp", "jungle\\jungle_1_13_result.bmp", "jungle\\jungle_1_14_result.bmp", "jungle\\jungle_1_15_result.bmp", "jungle\\jungle_1_16_result.bmp", "jungle\\jungle_1_17_result.bmp",
"jungle\\jungle_1_18_result.bmp", "jungle\\jungle_1_19_result.bmp", "jungle\\jungle_1_20_result.bmp", "jungle\\jungle_1_21_result.bmp", "jungle\\jungle_1_22_result.bmp", "jungle\\jungle_1_23_result.bmp", "jungle\\jungle_1_24_result.bmp", "jungle\\jungle_1_25_result.bmp", "jungle\\jungle_1_26_result.bmp", "jungle\\jungle_1_27_result.bmp", "jungle\\jungle_1_28_result.bmp", "jungle\\jungle_1_29_result.bmp", "jungle\\jungle_1_30_result.bmp", "jungle\\jungle_1_31_result.bmp",
"jungle\\jungle_1_32_result.bmp", "jungle\\jungle_1_33_result.bmp", "jungle\\jungle_1_34_result.bmp", "jungle\\jungle_1_35_result.bmp", "jungle\\jungle_1_36_result.bmp", "jungle\\jungle_1_37_result.bmp", "jungle\\jungle_1_38_result.bmp", "jungle\\jungle_1_39_result.bmp", "jungle\\jungle_1_40_result.bmp", "jungle\\jungle_1_41_result.bmp", "jungle\\jungle_1_42_result.bmp", "jungle\\jungle_1_43_result.bmp", "jungle\\jungle_1_44_result.bmp", "jungle\\jungle_1_45_result.bmp",
"jungle\\jungle_1_46_result.bmp", "jungle\\jungle_1_47_result.bmp", "jungle\\jungle_1_48_result.bmp", "jungle\\jungle_1_49_result.bmp", "jungle\\jungle_1_50_result.bmp", "jungle\\jungle_2_01_result.bmp", "jungle\\jungle_2_02_result.bmp", "jungle\\jungle_2_03_result.bmp", "jungle\\jungle_2_04_result.bmp", "jungle\\jungle_2_05_result.bmp", "jungle\\jungle_2_06_result.bmp", "jungle\\jungle_2_07_result.bmp",
"jungle\\jungle_2_08_result.bmp", "jungle\\jungle_2_09_result.bmp", "jungle\\jungle_2_10_result.bmp", "jungle\\jungle_2_11_result.bmp", "jungle\\jungle_2_12_result.bmp", "jungle\\jungle_2_13_result.bmp", "jungle\\jungle_2_14_result.bmp", "jungle\\jungle_2_15_result.bmp", "jungle\\jungle_2_16_result.bmp", "jungle\\jungle_2_17_result.bmp",
"jungle\\jungle_2_18_result.bmp", "jungle\\jungle_2_19_result.bmp", "jungle\\jungle_2_20_result.bmp", "jungle\\jungle_2_21_result.bmp", "jungle\\jungle_2_22_result.bmp", "jungle\\jungle_2_23_result.bmp", "jungle\\jungle_2_24_result.bmp", "jungle\\jungle_2_25_result.bmp", "jungle\\jungle_2_26_result.bmp", "jungle\\jungle_2_27_result.bmp", "jungle\\jungle_2_28_result.bmp", "jungle\\jungle_2_29_result.bmp", "jungle\\jungle_2_30_result.bmp", "jungle\\jungle_2_31_result.bmp",
"jungle\\jungle_2_32_result.bmp", "jungle\\jungle_2_33_result.bmp", "jungle\\jungle_2_34_result.bmp", "jungle\\jungle_2_35_result.bmp", "jungle\\jungle_2_36_result.bmp", "jungle\\jungle_2_37_result.bmp", "jungle\\jungle_2_38_result.bmp", "jungle\\jungle_2_39_result.bmp", "jungle\\jungle_2_40_result.bmp", "jungle\\jungle_2_41_result.bmp", "jungle\\jungle_2_42_result.bmp", "jungle\\jungle_2_43_result.bmp", "jungle\\jungle_2_44_result.bmp", "jungle\\jungle_2_45_result.bmp",
"jungle\\jungle_2_46_result.bmp", "jungle\\jungle_2_47_result.bmp", "jungle\\jungle_2_48_result.bmp", "jungle\\jungle_2_49_result.bmp", "jungle\\jungle_2_50_result.bmp", "jungle\\jungle_3_01_result.bmp", "jungle\\jungle_3_02_result.bmp", "jungle\\jungle_3_03_result.bmp", "jungle\\jungle_3_04_result.bmp", "jungle\\jungle_3_05_result.bmp", "jungle\\jungle_3_06_result.bmp", "jungle\\jungle_3_07_result.bmp",
"jungle\\jungle_3_08_result.bmp", "jungle\\jungle_3_09_result.bmp", "jungle\\jungle_3_10_result.bmp", "jungle\\jungle_3_11_result.bmp", "jungle\\jungle_3_12_result.bmp", "jungle\\jungle_3_13_result.bmp", "jungle\\jungle_3_14_result.bmp", "jungle\\jungle_3_15_result.bmp", "jungle\\jungle_3_16_result.bmp", "jungle\\jungle_3_17_result.bmp",
"jungle\\jungle_3_18_result.bmp", "jungle\\jungle_3_19_result.bmp", "jungle\\jungle_3_20_result.bmp", "jungle\\jungle_3_21_result.bmp", "jungle\\jungle_3_22_result.bmp", "jungle\\jungle_3_23_result.bmp", "jungle\\jungle_3_24_result.bmp", "jungle\\jungle_3_25_result.bmp", "jungle\\jungle_3_26_result.bmp", "jungle\\jungle_3_27_result.bmp", "jungle\\jungle_3_28_result.bmp", "jungle\\jungle_3_29_result.bmp", "jungle\\jungle_3_30_result.bmp", "jungle\\jungle_3_31_result.bmp",
"jungle\\jungle_3_32_result.bmp", "jungle\\jungle_3_33_result.bmp", "jungle\\jungle_3_34_result.bmp", "jungle\\jungle_3_35_result.bmp", "jungle\\jungle_3_36_result.bmp", "jungle\\jungle_3_37_result.bmp", "jungle\\jungle_3_38_result.bmp", "jungle\\jungle_3_39_result.bmp", "jungle\\jungle_3_40_result.bmp", "jungle\\jungle_3_41_result.bmp", "jungle\\jungle_3_42_result.bmp", "jungle\\jungle_3_43_result.bmp", "jungle\\jungle_3_44_result.bmp", "jungle\\jungle_3_45_result.bmp",
"jungle\\jungle_3_46_result.bmp", "jungle\\jungle_3_47_result.bmp", "jungle\\jungle_3_48_result.bmp", "jungle\\jungle_3_49_result.bmp", "jungle\\jungle_3_50_result.bmp", "jungle\\jungle_4_01_result.bmp", "jungle\\jungle_4_02_result.bmp", "jungle\\jungle_4_03_result.bmp", "jungle\\jungle_4_04_result.bmp", "jungle\\jungle_4_05_result.bmp", "jungle\\jungle_4_06_result.bmp", "jungle\\jungle_4_07_result.bmp",
"jungle\\jungle_4_08_result.bmp", "jungle\\jungle_4_09_result.bmp", "jungle\\jungle_4_10_result.bmp", "jungle\\jungle_4_11_result.bmp", "jungle\\jungle_4_12_result.bmp", "jungle\\jungle_4_13_result.bmp", "jungle\\jungle_4_14_result.bmp", "jungle\\jungle_4_15_result.bmp", "jungle\\jungle_4_16_result.bmp", "jungle\\jungle_4_17_result.bmp",
"jungle\\jungle_4_18_result.bmp", "jungle\\jungle_4_19_result.bmp", "jungle\\jungle_4_20_result.bmp", "jungle\\jungle_4_21_result.bmp", "jungle\\jungle_4_22_result.bmp", "jungle\\jungle_4_23_result.bmp", "jungle\\jungle_4_24_result.bmp", "jungle\\jungle_4_25_result.bmp", "jungle\\jungle_4_26_result.bmp", "jungle\\jungle_4_27_result.bmp", "jungle\\jungle_4_28_result.bmp", "jungle\\jungle_4_29_result.bmp", "jungle\\jungle_4_30_result.bmp", "jungle\\jungle_4_31_result.bmp",
"jungle\\jungle_4_32_result.bmp", "jungle\\jungle_4_33_result.bmp", "jungle\\jungle_4_34_result.bmp", "jungle\\jungle_4_35_result.bmp", "jungle\\jungle_4_36_result.bmp", "jungle\\jungle_4_37_result.bmp", "jungle\\jungle_4_38_result.bmp", "jungle\\jungle_4_39_result.bmp", "jungle\\jungle_4_40_result.bmp", "jungle\\jungle_4_41_result.bmp", "jungle\\jungle_4_42_result.bmp", "jungle\\jungle_4_43_result.bmp", "jungle\\jungle_4_44_result.bmp", "jungle\\jungle_4_45_result.bmp",
"jungle\\jungle_4_46_result.bmp", "jungle\\jungle_4_47_result.bmp", "jungle\\jungle_4_48_result.bmp", "jungle\\jungle_4_49_result.bmp", "jungle\\jungle_4_50_result.bmp" };


// cave bg
char image4[200][40] = { "cave\\1_01_result.bmp", "cave\\1_02_result.bmp", "cave\\1_03_result.bmp", "cave\\1_04_result.bmp",
"cave\\1_05_result.bmp", "cave\\1_06_result.bmp", "cave\\1_07_result.bmp", "cave\\1_08_result.bmp", "cave\\1_09_result.bmp",
"cave\\1_10_result.bmp", "cave\\1_11_result.bmp", "cave\\1_12_result.bmp", "cave\\1_13_result.bmp", "cave\\1_14_result.bmp",
"cave\\1_15_result.bmp", "cave\\1_16_result.bmp", "cave\\1_17_result.bmp", "cave\\1_18_result.bmp", "cave\\1_19_result.bmp",
"cave\\1_20_result.bmp", "cave\\1_21_result.bmp", "cave\\1_22_result.bmp", "cave\\1_23_result.bmp", "cave\\1_24_result.bmp",
"cave\\1_25_result.bmp", "cave\\1_26_result.bmp", "cave\\1_27_result.bmp", "cave\\1_28_result.bmp", "cave\\1_29_result.bmp",
"cave\\1_30_result.bmp", "cave\\1_31_result.bmp", "cave\\1_32_result.bmp", "cave\\1_33_result.bmp", "cave\\1_34_result.bmp",
"cave\\1_35_result.bmp", "cave\\1_36_result.bmp", "cave\\1_37_result.bmp", "cave\\1_38_result.bmp", "cave\\1_39_result.bmp",
"cave\\1_40_result.bmp", "cave\\1_41_result.bmp", "cave\\1_42_result.bmp", "cave\\1_43_result.bmp", "cave\\1_44_result.bmp",
"cave\\1_45_result.bmp", "cave\\1_46_result.bmp", "cave\\1_47_result.bmp", "cave\\1_48_result.bmp", "cave\\1_49_result.bmp",
"cave\\1_50_result.bmp", "cave\\2_01_result.bmp", "cave\\2_02_result.bmp", "cave\\2_03_result.bmp", "cave\\2_04_result.bmp",
"cave\\2_05_result.bmp", "cave\\2_06_result.bmp", "cave\\2_07_result.bmp", "cave\\2_08_result.bmp", "cave\\2_09_result.bmp",
"cave\\2_10_result.bmp", "cave\\2_11_result.bmp", "cave\\2_12_result.bmp", "cave\\2_13_result.bmp", "cave\\2_14_result.bmp",
"cave\\2_15_result.bmp", "cave\\2_16_result.bmp", "cave\\2_17_result.bmp", "cave\\2_18_result.bmp", "cave\\2_19_result.bmp",
"cave\\2_20_result.bmp", "cave\\2_21_result.bmp", "cave\\2_22_result.bmp", "cave\\2_23_result.bmp", "cave\\2_24_result.bmp",
"cave\\2_25_result.bmp", "cave\\2_26_result.bmp", "cave\\2_27_result.bmp", "cave\\2_28_result.bmp", "cave\\2_29_result.bmp",
"cave\\2_30_result.bmp", "cave\\2_31_result.bmp", "cave\\2_32_result.bmp", "cave\\2_33_result.bmp", "cave\\2_34_result.bmp",
"cave\\2_35_result.bmp", "cave\\2_36_result.bmp", "cave\\2_37_result.bmp", "cave\\2_38_result.bmp", "cave\\2_39_result.bmp",
"cave\\2_40_result.bmp", "cave\\2_41_result.bmp", "cave\\2_42_result.bmp", "cave\\2_43_result.bmp", "cave\\2_44_result.bmp",
"cave\\2_45_result.bmp", "cave\\2_46_result.bmp", "cave\\2_47_result.bmp", "cave\\2_48_result.bmp", "cave\\2_49_result.bmp",
"cave\\2_50_result.bmp", "cave\\3_01_result.bmp", "cave\\3_02_result.bmp", "cave\\3_03_result.bmp", "cave\\3_04_result.bmp",
"cave\\3_05_result.bmp", "cave\\3_06_result.bmp", "cave\\3_07_result.bmp", "cave\\3_08_result.bmp", "cave\\3_09_result.bmp",
"cave\\3_10_result.bmp", "cave\\3_11_result.bmp", "cave\\3_12_result.bmp", "cave\\3_13_result.bmp", "cave\\3_14_result.bmp",
"cave\\3_15_result.bmp", "cave\\3_16_result.bmp", "cave\\3_17_result.bmp", "cave\\3_18_result.bmp", "cave\\3_19_result.bmp",
"cave\\3_20_result.bmp", "cave\\3_21_result.bmp", "cave\\3_22_result.bmp", "cave\\3_23_result.bmp", "cave\\3_24_result.bmp",
"cave\\3_25_result.bmp", "cave\\3_26_result.bmp", "cave\\3_27_result.bmp", "cave\\3_28_result.bmp", "cave\\3_29_result.bmp",
"cave\\3_30_result.bmp", "cave\\3_31_result.bmp", "cave\\3_32_result.bmp", "cave\\3_33_result.bmp", "cave\\3_34_result.bmp",
"cave\\3_35_result.bmp", "cave\\3_36_result.bmp", "cave\\3_37_result.bmp", "cave\\3_38_result.bmp", "cave\\3_39_result.bmp",
"cave\\3_40_result.bmp", "cave\\3_41_result.bmp", "cave\\3_42_result.bmp", "cave\\3_43_result.bmp", "cave\\3_44_result.bmp",
"cave\\3_45_result.bmp", "cave\\3_46_result.bmp", "cave\\3_47_result.bmp", "cave\\3_48_result.bmp", "cave\\3_49_result.bmp",
"cave\\3_50_result.bmp", "cave\\4_01_result.bmp", "cave\\4_02_result.bmp", "cave\\4_03_result.bmp", "cave\\4_04_result.bmp",
"cave\\4_05_result.bmp", "cave\\4_06_result.bmp", "cave\\4_07_result.bmp", "cave\\4_08_result.bmp", "cave\\4_09_result.bmp",
"cave\\4_10_result.bmp", "cave\\4_11_result.bmp", "cave\\4_12_result.bmp", "cave\\4_13_result.bmp", "cave\\4_14_result.bmp",
"cave\\4_15_result.bmp", "cave\\4_16_result.bmp", "cave\\4_17_result.bmp", "cave\\4_18_result.bmp", "cave\\4_19_result.bmp",
"cave\\4_20_result.bmp", "cave\\4_21_result.bmp", "cave\\4_22_result.bmp", "cave\\4_23_result.bmp", "cave\\4_24_result.bmp",
"cave\\4_25_result.bmp", "cave\\4_26_result.bmp", "cave\\4_27_result.bmp", "cave\\4_28_result.bmp", "cave\\4_29_result.bmp",
"cave\\4_30_result.bmp", "cave\\4_31_result.bmp", "cave\\4_32_result.bmp", "cave\\4_33_result.bmp", "cave\\4_34_result.bmp",
"cave\\4_35_result.bmp", "cave\\4_36_result.bmp", "cave\\4_37_result.bmp", "cave\\4_38_result.bmp", "cave\\4_39_result.bmp",
"cave\\4_40_result.bmp", "cave\\4_41_result.bmp", "cave\\4_42_result.bmp", "cave\\4_43_result.bmp", "cave\\4_44_result.bmp",
"cave\\4_45_result.bmp", "cave\\4_46_result.bmp", "cave\\4_47_result.bmp", "cave\\4_48_result.bmp", "cave\\4_49_result.bmp", "cave\\4_50_result.bmp" };


int slice = 200;
int width = 1400 / 200.1;
bool RENDER = true;
//RENDERING FINISH

char bcr[1][20]{ "BC\\city.bmp" };

char menu[8][40] = { "New folder\\continue.bmp", "New folder\\newgame.bmp", "New folder\\story.bmp", "New folder\\sound.bmp", "New folder\\help.bmp", "New folder\\credits.bmp", "New folder\\exit.bmp", "New folder\\sound off.bmp" };
int gamestate, jerin = 0, help = 0;
int rx = 0;

//assassin health
char health[7][20] = { "health bar\\2.bmp", "health bar\\3.bmp", "health bar\\4.bmp", "health bar\\5.bmp", "health bar\\6.bmp", "health bar\\1.bmp", "health bar\\7.bmp" };
int hx = 50;
int hy = 610;
int hindex;


//COIN
char coin[8][20] = { "coin\\1.bmp", "coin\\2.bmp", "coin\\3.bmp", "coin\\4.bmp", "coin\\5.bmp", "coin\\6.bmp", "coin\\7.bmp", "coin\\8.bmp" };
int coinindex;
int cx = 500;
int cy = 120;
int cx2 = 510;
int cy2 = 260;
int cx4 = 510;
int cy4 = 120;
bool showCoin = true;
bool showCoin2 = true;
bool showCoin3 = true;
int tc;
int tc2;
int tp;
int asd;
int dang = 0;
int dang2 = 0;
char ASD[52][30] = { "numbers\\51.bmp", "numbers\\1.bmp", "numbers\\2.bmp", "numbers\\3.bmp", "numbers\\4.bmp", "numbers\\5.bmp", "numbers\\6.bmp", "numbers\\7.bmp", "numbers\\8.bmp", "numbers\\9.bmp", "numbers\\10.bmp", "numbers\\11.bmp", "numbers\\12.bmp", "numbers\\13.bmp", "numbers\\14.bmp", "numbers\\15.bmp",
"numbers\\16.bmp", "numbers\\17.bmp", "numbers\\18.bmp", "numbers\\19.bmp", "numbers\\20.bmp", "numbers\\21.bmp", "numbers\\22.bmp", "numbers\\23.bmp", "numbers\\24.bmp", "numbers\\25.bmp", "numbers\\26.bmp", "numbers\\27.bmp", "numbers\\28.bmp", "numbers\\29.bmp", "numbers\\30.bmp", "numbers\\31.bmp",
"numbers\\32.bmp", "numbers\\33.bmp", "numbers\\34.bmp", "numbers\\35.bmp", "numbers\\36.bmp", "numbers\\37.bmp", "numbers\\38.bmp", "numbers\\39.bmp", "numbers\\40.bmp", "numbers\\41.bmp", "numbers\\42.bmp", "numbers\\43.bmp", "numbers\\44.bmp", "numbers\\45.bmp", "numbers\\46.bmp", "numbers\\47.bmp", "numbers\\48.bmp", "numbers\\49.bmp", "numbers\\45.bmp", "numbers\\50.bmp" };

//BOSS1
int bossX1;
int bossY1;
int bossIndex1 = 0;
bool showBoss1 = false;
char boss1[16][30] = { "UGABUGAWALK\\1.bmp", "UGABUGAWALK\\2.bmp", "UGABUGAWALK\\3.bmp", "UGABUGAWALK\\4.bmp", "UGABUGAWALK\\5.bmp", "UGABUGAWALK\\6.bmp", "UGABUGAWALK\\7.bmp", "UGABUGAWALK\\8.bmp", "UGABUGAATTACK\\1.bmp", "UGABUGAATTACK\\2.bmp", "UGABUGAATTACK\\3.bmp", "UGABUGAATTACK\\4.bmp", "UGABUGAATTACK\\4.bmp", "UGABUGAATTACK\\4.bmp", "UGABUGAATTACK\\5.bmp", "UGABUGAATTACK\\6.bmp" };


//BOSS2
char boss2[16][30] = { "S2W\\1.bmp", "S2W\\2.bmp", "S2W\\3.bmp", "S2W\\4.bmp", "S2W\\5.bmp", "S2W\\6.bmp", "S2W\\7.bmp", "S2W\\8.bmp", "S2A\\1.bmp", "S2A\\2.bmp", "S2A\\3.bmp", "S2A\\4.bmp", "S2A\\4.bmp", "S2A\\5.bmp", "S2A\\6.bmp", "S2A\\7.bmp", };
int bossX3;
int bossY3 = -23;
bool showBoss2 = false;
int bosscount2;
int bossIndex3 = 0;
int bhx1 = 880;
int bhy1 = 640;
int bhIndex;
int hit2;
char B1H[8][30] = { "health bar 3\\10.bmp", "health bar 3\\11.bmp", "health bar 3\\12.bmp", "health bar 3\\13.bmp", "health bar 3\\14.bmp", "health bar 3\\15.bmp", "health bar 3\\16.bmp", "health bar 3\\17.bmp" };

//BOSS3
char boss3[23][40] = { "lion\\1.bmp", "lion\\1.bmp", "lion\\2.bmp", "lion\\2.bmp", "lion\\3.bmp", "lion\\3.bmp", "lion\\4.bmp", "lion\\4.bmp", "lion\\5.bmp", "lion\\5.bmp", "lion\\6.bmp", "lion\\6.bmp", "lion\\7.bmp", "lion\\7.bmp", "lion\\8.bmp", "lion\\9.bmp", "lion\\9.bmp", "lion\\9.bmp", "lion\\10.bmp", "lion\\10.bmp", "lion\\10.bmp", "lion\\11.bmp", "lion\\11.bmp" };
int bossX5;
int bossY5 = 8;
bool showBoss3 = false;
int bosscount3;
int bossIndex5 = 0;
int hit3;
char B3H[12][30] = { "health bar 3\\10.bmp", "health bar 3\\10.bmp", "health bar 3\\12.bmp", "health bar 3\\12.bmp", "health bar 3\\13.bmp", "health bar 3\\14.bmp", "health bar 3\\15.bmp", "health bar 3\\16.bmp", "health bar 3\\16.bmp", "health bar 3\\17.bmp", "health bar 3\\18.bmp", "health bar 3\\19.bmp" };



//BOSS4 >>>>> MEDUSA!!
char boss4[21][40] = { "medusa\\st1.bmp", "medusa\\st2.bmp", "medusa\\st3.bmp", "medusa\\st4.bmp", "medusa\\st5.bmp", "medusa\\st6.bmp", "medusa\\st7.bmp", "medusa\\st8.bmp", "medusa\\st9.bmp", "medusa\\s1.bmp", "medusa\\s2.bmp", "medusa\\s3.bmp", "medusa\\s4.bmp", "medusa\\s5.bmp", "medusa\\s6.bmp", "medusa\\s7.bmp", "medusa\\s8.bmp", "medusa\\s9.bmp", "medusa\\s10.bmp", "medusa\\s11.bmp", "medusa\\s12.bmp" };
int bossX7;
int bossY7;
bool showBoss4 = false;
int bosscount4;
int bossIndex7 = 0;
int hit4;
char B4H[12][30] = { "health bar 3\\10.bmp", "health bar 3\\10.bmp", "health bar 3\\12.bmp", "health bar 3\\12.bmp", "health bar 3\\13.bmp", "health bar 3\\14.bmp", "health bar 3\\15.bmp", "health bar 3\\16.bmp", "health bar 3\\16.bmp", "health bar 3\\17.bmp", "health bar 3\\18.bmp", "health bar 3\\19.bmp" };




//CACTUS
int cactusX;
int cactusY;
bool showCactus = false;

//JUNGLE THORNS
int thornX;
int thornY;
bool showThorn = false;


//SNAKES!
int snakeX;
int snakeY;
bool showSnake;
char snake[10][40] = { "snake\\S_01-removebg-preview.png", "snake\\S_02-removebg-preview.png", "snake\\S_03-removebg-preview.png", "snake\\S_04-removebg-preview.png", "snake\\S_05-removebg-preview.png", "snake\\s1_01-removebg-preview.png", "snake\\s1_02-removebg-preview.png", "snake\\s1_03-removebg-preview.png", "snake\\s1_04-removebg-preview.png", "snake\\s1_05-removebg-preview.png" };
int snakeIndex = 0;


//TREASURE
char treasure[7][39] = { "treasure box\\1.bmp", "treasure box\\2.bmp", "treasure box\\3.bmp", "treasure box\\4.bmp", "treasure box\\5.bmp", "treasure box\\6.bmp", "treasure box\\7.bmp" };
int treasureindex;
int treasurex = 1000;
int treasurey = 120;
int treasurecheck = 0;
bool showTreasure = 0;


//CROSS HEALTH
int plusx;
int plusy;
bool showPlus = true;
int cross;


//LEVEL 1 BOSS HEALTH
char bosshealthone[4][50] = { "health bar 3\\10.bmp", "health bar 3\\14.bmp", "health bar 3\\16.bmp", "health bar 3\\19.bmp" };
int bosshealth1index;
int hitlevelone;


//PAUSE
int hit1;
int enemyX2;
int enemyY2;
bool pause = false;
int assCoX2;
int assCoY2;
int assRUN2;
int assRunRev2;
int assCoJump2;
int p;
int assCoX3;
int assCoY3;
int assCoX4;
int assCoY4;
int assSTAND2;
int cx1;
int cy1;
int cx3;
int cy3;
int coinindex1;
int bossX2;
int bossY2;
int bossindex2;
int enemyIndex2;
int enemyX4;
int enemyY4;
int bossX4;
int bossY4;
int enemyIndex4;
int bossIndex4;
int cactusX2;
int cactusY2;

//for level 3
int enemyX6;
int enemyY6;
int bossX6;
int bossY6;
int enemyIndex6;
int bossIndex6;
int thornX2;
int thornY2;
//for level 4
int enemyX8;
int enemyY8;
int bossX8;
int bossY8;
int enemyIndex8;
int bossIndex8;
int snakeX2;
int snakeY2;
int snakeIndex2;

int P = 1;
int ACJ = 20;




bool jerin1 = false, jerin2 = false, jerin3 = false, jerin4 = false, jerin5 = false, jerin6 = false, jerin7 = false, jerin4o = false;
bool soundon = true;
bool pause1 = false, pause2 = false, pause3 = false;
char blust[12][40] = { "bomb\\Untitled-removebg-preview.png", "bomb\\Untitled-removebg-preview.png", "bomb\\Untitled-removebg-preview.png", "bomb\\Untitled-removebg-preview.png", "bomb\\Untitled-removebg-preview.png", "bomb\\Untitled-removebg-preview.png", "bomb\\3_01-removebg-preview.png", "bomb\\3_02-removebg-preview.png", "bomb\\3_04-removebg-preview.png", "bomb\\3_06-removebg-preview.png", "bomb\\3_08-removebg-preview.png", "bomb\\3_09-removebg-preview.png" };

//puzzle
bool puzzlelevel1 = false, puzzlelevel2 = false, puzzlelevel3 = false, puzzlelevel4 = false;
int puzzlex1 = 100, puzzley1 = 400;
int puzzlex = 99, puzzley = 399;
bool puzzle1 = true, puzzle2 = true, puzzle3 = true, puzzle4 = true;
bool puzzlem = false;
bool puzzle12 = false, puzzle22 = false, puzzle32 = false, puzzle42 = false;

bool save = false;
bool pausebar = true;
bool saveyes = false;
bool saveno = false;
int ei = 0;
int bx = 350, by = 550,b1x=350,b1y=550;
int bdy = 89, ex = 1200, ey = 550,e1x=1200,e1y=550, edx = 100;
bool bomb = false;
bool eaglec = false;

// FILE
int xx;
int gamesave = 0;



void readfile(){

	ifstream fp2;
	fp2.open("gamesave.txt", ios::in);

	for (int q = 0; q < 77; q++)
	{

		fp2 >> xx;
		if (q == 0)
		{
			j = xx;
		}
		if (q == 1)
		{
			i = xx;
		}
		if (q == 2)
		{
			RENDER = xx;
			RENDER = 1;
		}
		if (q == 3)
		{
			level1 = xx;
		}
		if (q == 4)
		{
			level2 = xx;
		}
		if (q == 5)
		{
			showEnemy1 = xx;
			//showEnemy1 = true;
		}
		if (q == 6)
		{
			showEnemy2 = xx;
		}
		if (q == 7)
		{
			showBoss1 = xx;
		}
		if (q == 8)
		{
			showBoss2 = xx;
		}
		if (q == 9)
		{
			showCoin = xx;
			//showCoin = 1;
		}
		if (q == 10)
		{
			showCoin2 = xx;
			//showCoin2 = 1;
		}
		if (q == 11)
		{
			showPlus = xx;
			//showPlus = 1;
		}
		if (q == 12)
		{
			showCactus = xx;
			//showCactus = 1;
		}
		if (q == 13)
		{
			assCoX = xx;
		}
		if (q == 14)
		{
			assCoY = xx;
		}
		if (q == 15)
		{
			cx = xx;
			//cx = true;
		}
		if (q == 16)
		{
			cy = xx;
		}
		if (q == 17)
		{
			cx2 = xx;
			//cx2 = true;
		}
		if (q == 18)
		{
			cy2 = xx;
		}
		if (q == 19)
		{
			plusx = xx;
		}
		if (q == 20)
		{
			plusy = xx;
		}
		if (q == 21)
		{
			cactusX = xx;
		}
		if (q == 22)
		{
			cactusY = xx;
		}
		if (q == 23)
		{
			AssCoJump = xx;
		}
		if (q == 24)
		{
			enemyX1 = xx;
		}
		if (q == 25)
		{
			enemyY1 = xx;
		}
		if (q == 26)
		{
			enemyX3 = xx;
		}
		if (q == 27)
		{
			enemyY3 = xx;
		}
		if (q == 28)
		{
			bossX1 = xx;
		}
		if (q == 29)
		{
			bossY1 = xx;
		}
		if (q == 30)
		{
			bossX3 = xx;
		}
		if (q == 31)
		{
			bossY3 = xx;
		}
		if (q == 32)
		{
			assRunRev = xx;
		}
		if (q == 33)
		{
			assRUN = xx;
		}
		if (q == 34)
		{
			standCounter = xx;
			//standCounter = 0;
		}
		if (q == 35)
		{
			n_attack = xx;
		}
		if (q == 36)
		{
			coinindex = xx;
		}
		if (q == 37)
		{
			enemyIndex1 = xx;
		}
		if (q == 38)
		{
			enemyIndex3 = xx;
		}
		if (q == 39)
		{
			bossIndex1 = xx;
		}
		if (q == 40)
		{
			bossIndex3 = xx;
		}
		if (q == 41)
		{
			hit1 = xx;
		}
		if (q == 42)
		{
			hit2 = xx;
		}
		if (q == 43)
		{
			asd = xx;
		}
		if (q == 44)
		{
			hindex = xx;
		}
		if (q == 45)
		{
			standPosition = xx;
			//standPosition = true;
		}
		if (q == 46)
		{
			runforcheck = xx;
			//runforcheck = false;
		}
		if (q == 47)
		{
			runrevcheck = xx;
			//runrevcheck = false;
		}
		if (q == 48)
		{
			face = xx;
		}
		if (q == 49)
		{
			standPositionleft = xx;
		}
		if (q == 50)
		{
			left_index = xx;
		}
		if (q == 51)
		{
			P = xx;
			P = 1;
		}
		if (q == 52)
		{
			gamesave = xx;
		}
		if (q == 53)
		{
			enemyX5 = xx;
		}
		if (q == 54)
		{
			enemyY5 = xx;
		}
		if (q == 55)
		{
			enemyX7 = xx;
		}
		if (q == 56)
		{
			enemyY7 = xx;
		}
		if (q == 57)
		{
			bossX5 = xx;
		}
		if (q == 58)
		{
			bossY5 = xx;
		}
		if (q == 59)
		{
			bossX7 = xx;
		}
		if (q == 60)
		{
			bossY7 = xx;
		}
		if (q == 61)
		{
			showEnemy3 = xx;
		}
		if (q == 62)
		{
			showEnemy4 = xx;
		}
		if (q == 63)
		{
			showBoss3 = xx;
		}
		if (q == 64)
		{
			showBoss4 = xx;
		}
		if (q == 65)
		{
			showSnake = xx;
		}
		if (q == 66)
		{
			showThorn = xx;
		}
		if (q == 67)
		{
			snakeX = xx;
		}
		if (q == 68)
		{
			snakeY = xx;
		}
		if (q == 69)
		{
			thornX = xx;
		}
		if (q == 70)
		{
			thornY = xx;
		}
		if (q == 71)
		{
			level3 = xx;
		}
		if (q == 72)
		{
			level4 = xx;
		}
		if (q == 73)
		{
			puzzlelevel1 = xx;
		}
		if (q == 74)
		{
			puzzlelevel2 = xx;
		}
		if (q == 75)
		{
			puzzlelevel3 = xx;
		}
		if (q == 76)
		{
			puzzlelevel4 = xx;
		}
	}
	fp2.close();
}


bool gamestart = true;

void iDraw()
{
	iClear();

	if (gamestart)
	{
		int st = iLoadImage("New folder\\start.jpg");
		iShowImage(0, 0, 1200, 700, st);
		iSetColor(r, g, b);
		iText(500, 70, "Press S Key", GLUT_BITMAP_TIMES_ROMAN_24);
	}


	if (game  &&  gamestate == 0)
	{
		//PlaySound("menu.wav", NULL, SND_LOOP | SND_ASYNC);

		int m = iLoadImage("New folder\\menu2.bmp");
		iShowImage(0, 0, 1200, 700, m);
		int m1 = iLoadImage("New folder\\mainmenu.bmp");
		iShowImage(100, 600, 200, 60, m1);
		int m2 = iLoadImage(menu[0]);
		iShowImage(100, 540, 200, 60, m2);
		int m3 = iLoadImage(menu[1]);
		iShowImage(100, 480, 200, 60, m3);
		int m4 = iLoadImage(menu[2]);
		iShowImage(100, 420, 200, 60, m4);
		if (soundon)
		{
			int m5 = iLoadImage(menu[3]);
			iShowImage(100, 360, 200, 60, m5);
		}
		if (soundon == false)
		{
			int sf = iLoadImage(menu[7]);
			iShowImage(100, 360, 200, 60, sf);
		}

		int m6 = iLoadImage(menu[4]);
		iShowImage(100, 300, 200, 60, m6);
		int m7 = iLoadImage(menu[5]);
		iShowImage(100, 240, 200, 60, m7);
		int m8 = iLoadImage(menu[6]);
		iShowImage(100, 180, 200, 60, m8);
		if (jerin1 == true)
		{
			int j1 = iLoadImage("New folder\\red-menu_01.jpg");
			iShowImage(100, 540, 200, 60, j1);
		}
		if (jerin2 == true)
		{
			int j2 = iLoadImage("New folder\\red-menu_02.jpg");
			iShowImage(100, 480, 200, 60, j2);
		}
		if (jerin3 == true)
		{
			int j3 = iLoadImage("New folder\\red-menu_03.jpg");
			iShowImage(100, 420, 200, 60, j3);
		}
		if (jerin4 == true)
		{
			int j4 = iLoadImage("New folder\\red-menu_04.jpg");
			iShowImage(100, 360, 200, 60, j4);
		}
		if (jerin4o == true)
		{
			int j4o = iLoadImage("New folder\\red sound off.bmp");
			iShowImage(100, 360, 200, 60, j4o);
		}
		if (jerin5 == true)
		{
			int j5 = iLoadImage("New folder\\red-menu_05.jpg");
			iShowImage(100, 300, 200, 60, j5);
		}
		if (jerin6 == true)
		{
			int j6 = iLoadImage("New folder\\red-menu_06.jpg");
			iShowImage(100, 240, 200, 60, j6);
		}
		if (jerin7 == true)
		{
			int j7 = iLoadImage("New folder\\red-menu_07.jpg");
			iShowImage(100, 180, 200, 60, j7);
		}


	}
	else if (game  &&  gamestate>0)
	{
		if (gamestate == 1)
		{


			//gameOn = true;

		}
		if (gamestate == 3)
		{
			int c1 = iLoadImage("menu\\st.jpg");
			iShowImage(0, 0, 1200, 700, c1);
			iShowBMP2(40, 50, "menu\\back1.bmp", 0);
		}
		if (gamestate == 5 && help == 1)
		{
			int c1 = iLoadImage("menu\\h2.jpg");
			iShowImage(0, 0, 1200, 700, c1);
			iShowBMP2(40, 50, "menu\\back1.bmp", 0);
			iShowBMP2(50, 350, "menu\\next2.bmp", 0);
		}
		if (gamestate == 5 && help == 0)
		{
			int c1 = iLoadImage("menu\\h1.jpg");
			iShowImage(0, 0, 1200, 700, c1);
			iShowBMP2(40, 50, "menu\\back1.bmp", 0);
			iShowBMP2(1050, 350, "menu\\next1.bmp", 0);
		}
		if (gamestate == 6)
		{
			int c1 = iLoadImage("menu\\cr.jpg");
			iShowImage(0, 0, 1200, 700, c1);
			iShowBMP2(40, 50, "menu\\back1.bmp", 0);
		}
		if (gamestate == 5)
		{
			//int c1 = iLoadImage("h1.jpg");
			//iShowImage(0, 0, 1600, 800, c1);
			//iShowBMP2(50, 100, "back1.bmp", 0);
		}

	}





	int i, j = 0;



	//iShowBMP2(assCoX, assCoY, RUN[assRUN], 0);


	if (gameOn == true && level1 == true)
	{
		//RENDERING
		for (i = 0; i < 200; i++)
		{
			{
				iShowBMP(position[i], 0, image[i]);
			}
		}

		//SCORE
		if (asd >= 0 && asd < 1000)
		{
			
			iShowBMP2(535, 570, ASD[asd], 0);
		}

		//PLUS
		if (!showTreasure){
			if (showPlus)
			{
				iShowBMP2(plusx - 20, plusy, "plus.bmp", 0);
			}
		}

		//PAUSE
		if (!pause){


			if (jump)
			{


				if (jumpUp)
				{

					if (runforcheck)
					{
						iShowBMP2(assCoX, assCoY + AssCoJump, AJ[0], 0);
					}
					else if (runrevcheck)
					{
						iShowBMP2(assCoX, assCoY + AssCoJump, AJREV[0], 0);
					}

				}
				else if (!jumpUp)
				{

					if (runforcheck)
					{
						iShowBMP2(assCoX, assCoY + AssCoJump, AJ[1], 0);
					}
					else if (runrevcheck)
					{
						iShowBMP2(assCoX, assCoY + AssCoJump, AJREV[1], 0);
					}
				}
			}
			else if (!jump)
			{
				if (!standPosition)
				{
					if (runrevcheck)
					{
						iShowBMP2(assCoX, assCoY + 7, RUNREV[assRunRev], 0);
					}
					else if (runforcheck)
					{
						iShowBMP2(assCoX, assCoY, RUN[assRUN], 0);
					}

					standCounter++;
					if (standCounter >= 12)
					{
						standCounter = 0;
						assRUN = 0;
						standPosition = true;
					}
				}
				else if (attackFIRE)
				{

					iShowBMP2(assCoX + 20, assCoY, FIRE[attackreal], 0);
					assSTAND = 0;
					//attackcount++;

				}
				else if (normal_attack)
				{
					iShowBMP2(assCoX, assCoY, realattack[n_attack], 0);
				}
				else if (ICE_ATTACK)
				{
					iShowBMP2(assCoX, assCoY - 15, iceattack[ice_attack], 0);
				}
				else if (standPosition)
				{
					if (face == 0)
					{
						iShowBMP2(assCoX, assCoY, STAND[assSTAND], 0);
					}
					else if (face == 1)
					{
						iShowBMP2(assCoX, assCoY, STAND_LEFT[left_index], 0);
					}
				}
			}
			if (showCoin || show_coin1 == 1)
			{
				iShowBMP2(cx - 100, cy + 40, coin[coinindex], 0);
			}
			if (showCoin2 || show_coin2 == 1)
			{
				iShowBMP2(cx2 - 10, cy2 + 40, coin[coinindex], 0);
			}
			if (showEnemy1 || show_enemy1 == 1)
			{
				iShowBMP2(enemyX1 - 100, enemyY1 + 36, soldier[enemyIndex1], 0);
			}
			else if ((showEnemy1 == false || show_enemy1 == 0) && (showBoss1 == true || show_boss1 == 1))
			{
				iShowBMP2(bossX1 - 100, bossY1 + 112, boss1[bossIndex1], 0);
			}
			else if ((showBoss1 == false || show_boss1 == 0) && (showTreasure == true || show_treasure1 == 1))
			{
				iShowBMP2(treasurex, treasurey, treasure[treasureindex], 0);
				//iShowBMP2(1015, 200, "puzzle1.bmp", 0);
				iShowBMP2(1000, 600, "menu\\next1.bmp", 0);
				iShowBMP2(940, 600, "menu\\next2.bmp", 0);
			}

		}


		else if (pause)
		{
			if (runforcheck && !jump && !standPosition){
				iShowBMP2(assCoX2, assCoY2, RUN[assRUN2], 0);
			}
			else if (runrevcheck && !jump && !standPosition){
				iShowBMP2(assCoX2, assCoY2 + 7, RUNREV[assRunRev2], 0);
			}
			else if (standPosition)
			{
				iShowBMP2(assCoX4, assCoY4, STAND[assSTAND2], 0);
			}
			//else if (jump)
			//{
			if (jump){
				if (jumpUp)
					iShowBMP2(assCoX3, assCoY3 + AssCoJump, AJ[0], 0);
				else
					iShowBMP2(assCoX3, assCoY3 + AssCoJump, AJ[1], 0);

			}

			//}
			if (showEnemy1 || show_enemy1 == 1)
			{
				iShowBMP2(enemyX2 - 100, enemyY2 + 36, soldier[enemyIndex2], 0);
			}
			else if ((showEnemy1 == false || show_enemy1 == 0) && (showBoss1 == true || show_boss1 == 1))
			{
				iShowBMP2(bossX2 - 100, bossY2 + 112, boss1[bossindex2], 0);
			}
			if (showCoin || show_coin1 == 1)
			{
				iShowBMP2(cx1 - 100, cy1 + 40, coin[coinindex1], 0);
			}
			if (showCoin2 || show_coin2 == 1)
			{
				iShowBMP2(cx3 - 10, cy3 + 40, coin[coinindex], 0);
			}
			RENDER = false;
			if (pausebar)
			{
				int p = iLoadImage("pause\\pause__1_-removebg-preview.png");
				iShowImage(300, 90, 700, 600, p);
				//iShowBMP2(420, 200, "Untitled1.bmp",0);
				int p1 = iLoadImage("pause\\pause-(12)_01.jpg");
				iShowImage(470, 340, 300, 100, p1);
				int p2 = iLoadImage("pause\\pause_02.jpg");
				iShowImage(440, 240, 300, 100, p2);

				if (soundon == false)
					iShowBMP2(745, 260, "pause\\off.bmp", 0);

				if (soundon)
					iShowBMP2(745, 260, "pause\\Untitledo.bmp", 0);

				int p3 = iLoadImage("pause\\pause_03.jpg");
				iShowImage(470, 140, 300, 100, p3);
				if (pause1)
				{
					int pp1 = iLoadImage("pause\\pause-(11)_01.jpg");
					iShowImage(470, 340, 300, 100, pp1);
				}
				if (pause2)
				{
					int pp2 = iLoadImage("pause\\pause-(10)_02.jpg");
					iShowImage(440, 240, 300, 100, pp2);
				}
				if (pause3)
				{
					int pp3 = iLoadImage("pause\\pause-(10)_03.jpg");
					iShowImage(470, 140, 300, 100, pp3);
				}

			}

			if (save)
			{
				int tr = iLoadImage("pause\\Do_you_want_to_save_the_game-removebg-preview.png");
				iShowImage(400, 200, 400, 300, tr);
				int tr1 = iLoadImage("pause\\Do-you-want-to-save-the-game-_2__01-removebg-preview.png");
				iShowImage(465, 300, 130, 60, tr1);
				int tr2 = iLoadImage("pause\\Do-you-want-to-save-the-game-_2__02-removebg-preview.png");
				iShowImage(615, 300, 130, 60, tr2);
				if (saveyes == true)
				{
					int say = iLoadImage("pause\\Do-you-want-to-save-the-game-_3__01-removebg-preview.png");
					iShowImage(465, 300, 130, 60, say);
				}
				if (saveno == true)
				{
					int san = iLoadImage("pause\\Do-you-want-to-save-the-game-_3__02-removebg-preview.png");
					iShowImage(615, 300, 130, 60, san);
				}
			}

		}


		for (int j = 0; j < eagleNUM; j++)
		{
			if (eagle_[j].eagleShow)
			{
				iShowBMP2(eagle_[j].eagleX, eagle_[j].eagleY + 500, eagle[eagle_[j].eagleIndex], 0);
			}
		}

		//Assassin health
		iShowBMP2(hx, hy, health[hindex], 0);

		//BOSSHEALTH
		if (showBoss1){
			//iShowBMP2(bhx1, bhy1, B1H[hit1], 0);
			iShowBMP2(bhx1, bhy1, bosshealthone[hit1], 0);


		}
		/*int bo = iLoadImage("bomb\\images-removebg-preview.png");
		iShowImage(750, 620, 100, 100, bo);
		if (eaglec == true)
		iShowBMP2(ex, ey, "eagle\\eagle 2.bmp", 0);

		if (bomb == true)
		{
		iShowBMP(bx, by, blust[ei]);
		//int bl = iLoadImage(blust[ei]);
		//iShowImage(bx, by, 200, 200, bl);
		}
		*/



		//GAMEOVER
		if (gameover)
		{
			game = false;
			hindex = 0;
			iShowBMP(0, 0, "BC\\gameOver.bmp");
			iShowBMP2(70, 600, "New folder\\option.bmp", 0);
		}


	}

	//puzzle after level 1
	else if (puzzlelevel1 && level1 == false)
	{
		int pl1 = iLoadImage("puzzle\\images.jpg");
		iShowImage(0, 0, 1200, 700, pl1);

		if (puzzle1)
		{
			int p11 = iLoadImage("puzzle\\330387022_2348029662046569_8555532466156205350_n.jpg");
			iShowImage(500, 70, 500, 500, p11);
			int p12 = iLoadImage("puzzle\\IMG_5109_01-removebg-preview.png");
			iShowImage(puzzlex, puzzley, 250, 200, p12);
		}
		if (puzzlem  &&  puzzle1 == false)

		{
			int p13 = iLoadImage("puzzle\\330387022_2348029662046569_8555532466156205350_n.jpg");
			iShowImage(500, 70, 500, 500, p13);
			int p14 = iLoadImage("puzzle\\IMG_5109_01-removebg-preview.png");
			iShowImage(puzzlex1, puzzley1, 250, 200, p14);
		}

		if (puzzle12 == true && puzzlem == false)
		{
			int p15 = iLoadImage("puzzle\\329948236_1163658354340471_3818849513456494359_n.jpg");
			iShowImage(500, 70, 500, 500, p15);
			iShowBMP2(1050, 600, "menu\\next1.bmp", 0);
			iShowBMP2(100, 600, "menu\\next2.bmp", 0);
		}
	}


	//  LEVEL 2 START
	else if (gameOn == true && level2 == true)
	{
		//RENDER = true;
		//showTreasure = false;
		showCoin = true;
		showCoin2 = true;
		//showEnemy2 = true;
		//showBoss1 = false;
		enemycount = 0;

		for (i = 0; i < 200; i++)
			iShowBMP(position[i], 0, image2[i]);

		if (asd >= 0 && asd < 1000)
			iShowBMP2(535, 570, ASD[asd], 0);

		if (!showTreasure)
		{
			if (showPlus)
				iShowBMP2(plusx - 20, plusy, "plus.bmp", 0);
		}

		if (!pause)
		{
			if (jump)
			{
				if (jumpUp)
				{
					//attackNIGGA = false;
					if (runforcheck)       //run forward
						iShowBMP2(assCoX, assCoY + AssCoJump, AJ[0], 0);

					else if (runrevcheck)    //run backward
						iShowBMP2(assCoX, assCoY + AssCoJump, AJREV[0], 0);
				}
				else if (!jumpUp)
				{
					if (runforcheck)
						iShowBMP2(assCoX, assCoY + AssCoJump, AJ[1], 0);

					else if (runrevcheck)
						iShowBMP2(assCoX, assCoY + AssCoJump, AJREV[1], 0);
				}
			}
			else if (!jump)
			{
				if (!standPosition)
				{
					if (runrevcheck)
						iShowBMP2(assCoX, assCoY + 7, RUNREV[assRunRev], 0);

					else if (runforcheck)
						iShowBMP2(assCoX, assCoY, RUN[assRUN], 0);

					standCounter++;
					if (standCounter >= 12)
					{
						standCounter = 0;
						assRUN = 0;
						standPosition = true;
					}
				}
				else if (attackFIRE)
				{
					iShowBMP2(assCoX + 20, assCoY, FIRE[attackreal], 0);
					assSTAND = 0;
					//attackcount++;
				}
				else if (normal_attack)
					iShowBMP2(assCoX, assCoY, realattack[n_attack], 0);

				else if (ICE_ATTACK)
					iShowBMP2(assCoX, assCoY - 15, iceattack[ice_attack], 0);

				else if (standPosition)
					iShowBMP2(assCoX, assCoY, STAND[assSTAND], 0);
			}

			if (showCactus){
				iShowBMP2(cactusX, cactusY, "cactus.bmp", 0);
			}

			if (showCoin && !showTreasure)
			{
				iShowBMP2(cx - 100, cy + 40, coin[coinindex], 0);
			}
			if (showCoin2 && !showTreasure)
			{
				iShowBMP2(cx2 - 30, cy2 + 40, coin[coinindex], 0);
			}

			if (showEnemy2)
				iShowBMP2(enemyX3 - 100, enemyY3 + 36, soldier2[enemyIndex3], 0);

			else if (showEnemy2 == false && showBoss2 == true)
			{
				iShowBMP2(bossX3 - 100, bossY3 + 112, boss2[bossIndex3], 0);
			}
			else if (showBoss2 == false && showTreasure == true)
			{
				iShowBMP2(treasurex, treasurey, treasure[treasureindex], 0);
				//iShowBMP2(1015, 200, "puzzle1.bmp", 0);
				iShowBMP2(1000, 600, "menu\\next1.bmp", 0);
				iShowBMP2(940, 600, "menu\\next2.bmp", 0);
			}
		}

		else if (pause)
		{


			if (runforcheck && !jump && !standPosition){
				iShowBMP2(assCoX2, assCoY2, RUN[assRUN2], 0);
			}
			else if (runrevcheck && !jump && !standPosition){
				iShowBMP2(assCoX2, assCoY2 + 7, RUNREV[assRunRev2], 0);
			}
			else if (standPosition)
			{
				iShowBMP2(assCoX4, assCoY4, STAND[assSTAND2], 0);
			}
			if (jump){
				if (jumpUp)
					iShowBMP2(assCoX3, assCoY3 + AssCoJump, AJ[0], 0);
				else
					iShowBMP2(assCoX3, assCoY3 + AssCoJump, AJ[1], 0);

			}


			if (showEnemy2)
				iShowBMP2(enemyX4 - 100, enemyY4 + 36, soldier2[enemyIndex4], 0);

			else if (showEnemy2 == false && showBoss2 == true)
				iShowBMP2(bossX4 - 100, bossY4 + 112, boss2[bossIndex4], 0);

			if (showCoin)
				iShowBMP2(cx1 - 100, cy1 + 40, coin[coinindex1], 0);

			if (showCoin2)
				iShowBMP2(cx3 - 30, cy3 + 40, coin[coinindex], 0);

			if (showCactus)
			{
				iShowBMP2(cactusX2, cactusY2, "cactus.bmp", 0);
			}

			RENDER = false;
			if (pausebar)
			{
				int p = iLoadImage("pause\\pause__1_-removebg-preview.png");
				iShowImage(300, 90, 700, 600, p);
				//iShowBMP2(420, 200, "Untitled1.bmp",0);
				int p1 = iLoadImage("pause\\pause-(12)_01.jpg");
				iShowImage(470, 340, 300, 100, p1);
				int p2 = iLoadImage("pause\\pause_02.jpg");
				iShowImage(440, 240, 300, 100, p2);

				if (soundon == false)
					iShowBMP2(745, 260, "pause\\off.bmp", 0);

				if (soundon)
					iShowBMP2(745, 260, "pause\\Untitledo.bmp", 0);

				int p3 = iLoadImage("pause\\pause_03.jpg");
				iShowImage(470, 140, 300, 100, p3);
				if (pause1)
				{
					int pp1 = iLoadImage("pause\\pause-(11)_01.jpg");
					iShowImage(470, 340, 300, 100, pp1);
				}
				if (pause2)
				{
					int pp2 = iLoadImage("pause\\pause-(10)_02.jpg");
					iShowImage(440, 240, 300, 100, pp2);
				}
				if (pause3)
				{
					int pp3 = iLoadImage("pause\\pause-(10)_03.jpg");
					iShowImage(470, 140, 300, 100, pp3);
				}

			}

			if (save)
			{
				int tr = iLoadImage("pause\\Do_you_want_to_save_the_game-removebg-preview.png");
				iShowImage(400, 200, 400, 300, tr);
				int tr1 = iLoadImage("pause\\Do-you-want-to-save-the-game-_2__01-removebg-preview.png");
				iShowImage(465, 300, 130, 60, tr1);
				int tr2 = iLoadImage("pause\\Do-you-want-to-save-the-game-_2__02-removebg-preview.png");
				iShowImage(615, 300, 130, 60, tr2);
				if (saveyes == true)
				{
					int say = iLoadImage("pause\\Do-you-want-to-save-the-game-_3__01-removebg-preview.png");
					iShowImage(465, 300, 130, 60, say);
				}
				if (saveno == true)
				{
					int san = iLoadImage("pause\\Do-you-want-to-save-the-game-_3__02-removebg-preview.png");
					iShowImage(615, 300, 130, 60, san);
				}
			}

		}



		for (int j = 0; j < eagleNUM; j++)
		{
			if (eagle_[j].eagleShow)
				iShowBMP2(eagle_[j].eagleX, eagle_[j].eagleY + 500, eagle[eagle_[j].eagleIndex], 0);
		}

		//Assassin health
		iShowBMP2(hx, hy, health[hindex], 0);

		//BOSSHEALTH
		if (showBoss2)
			iShowBMP2(bhx1, bhy1, B1H[hit2], 0);


		if (showBoss2 == true)
		{
			int bo = iLoadImage("bomb\\images-removebg-preview.png");
			iShowImage(750, 620, 100, 100, bo);
		}

		if (eaglec == true)
			iShowBMP2(ex, ey, "eagle\\eagle 2.bmp", 0);

		if (bomb == true)
		{
			int bl = iLoadImage(blust[ei]);
			iShowImage(bx, by, 200, 200, bl);
		}
		if (gameover)
		{
			game = false;
			hindex = 0;
			iShowBMP(0, 0, "BC\\gameOver.bmp");
			iShowBMP2(70, 600, "New folder\\option.bmp", 0);
		}


	}
	else if (puzzlelevel2 && level2 == false)
	{
		int i2 = iLoadImage("puzzle\\images.jpg");
		iShowImage(0, 0, 1200, 700, i2);

		if (puzzle2)
		{
			int p21 = iLoadImage("puzzle\\329948236_1163658354340471_3818849513456494359_n.jpg");
			iShowImage(500, 70, 500, 500, p21);
			int p22 = iLoadImage("puzzle\\IMG_5109_02-removebg-preview.png");
			iShowImage(puzzlex, puzzley, 250, 200, p22);

		}

		if (puzzlem && puzzle2 == false)
		{
			int p23 = iLoadImage("puzzle\\329948236_1163658354340471_3818849513456494359_n.jpg");
			iShowImage(500, 70, 500, 500, p23);
			int p24 = iLoadImage("puzzle\\IMG_5109_02-removebg-preview.png");
			iShowImage(puzzlex1, puzzley1, 250, 200, p24);
		}
		if (puzzle22 == true)
		{
			int p25 = iLoadImage("puzzle\\330314770_1281664912417483_2147475942210750013_n.jpg");
			iShowImage(500, 70, 500, 500, p25);
			iShowBMP2(1050, 600, "menu\\next1.bmp", 0);
			iShowBMP2(100, 600, "menu\\next2.bmp", 0);
		}

	}

	else if (gameOn == true && level3 == true)
	{
		//RENDER = true;
		//showTreasure = false;
		showCoin = true;
		showCoin2 = true;
		//showEnemy2 = true;
		//showBoss1 = false;
		enemycount = 0;


		//render
		for (i = 0; i < 200; i++)
			iShowBMP(position[i], 0, image3[i]);

		//score
		if (asd >= 0 && asd < 1000)
			iShowBMP2(535, 570, ASD[asd], 0);

		//plus
		if (!showTreasure)
		{
			if (showPlus)
				iShowBMP2(plusx - 20, plusy, "plus.bmp", 0);
		}



		if (!pause)
		{
			if (jump)
			{
				if (jumpUp)
				{
					//attackNIGGA = false;
					if (runforcheck)       //run forward
						iShowBMP2(assCoX, assCoY + AssCoJump, AJ[0], 0);

					else if (runrevcheck)    //run backward
						iShowBMP2(assCoX, assCoY + AssCoJump, AJREV[0], 0);
				}
				else if (!jumpUp)
				{
					if (runforcheck)
						iShowBMP2(assCoX, assCoY + AssCoJump, AJ[1], 0);

					else if (runrevcheck)
						iShowBMP2(assCoX, assCoY + AssCoJump, AJREV[1], 0);
				}
			}
			else if (!jump)
			{
				if (!standPosition)
				{
					if (runrevcheck)
						iShowBMP2(assCoX, assCoY + 7, RUNREV[assRunRev], 0);

					else if (runforcheck)
						iShowBMP2(assCoX, assCoY, RUN[assRUN], 0);

					standCounter++;
					if (standCounter >= 12)
					{
						standCounter = 0;
						assRUN = 0;
						standPosition = true;
					}
				}
				else if (attackFIRE)
				{
					iShowBMP2(assCoX + 20, assCoY, FIRE[attackreal], 0);
					assSTAND = 0;
					attackcount++;
				}
				else if (normal_attack)
					iShowBMP2(assCoX, assCoY, realattack[n_attack], 0);

				else if (ICE_ATTACK)
					iShowBMP2(assCoX, assCoY - 15, iceattack[ice_attack], 0);

				else if (standPosition)
					iShowBMP2(assCoX, assCoY, STAND[assSTAND], 0);
			}


			//here we'll place the thorns
			if (showThorn){
				iShowBMP2(thornX, thornY, "thorn.bmp", 0);
			}


			//coin1
			if (showCoin && !showTreasure)
			{
				iShowBMP2(cx - 100, cy + 40, coin[coinindex], 0);
			}

			//coin2
			if (showCoin2 && !showTreasure)
			{
				iShowBMP2(cx2 - 30, cy2 + 40, coin[coinindex], 0);
			}


			//tiger and lion
			if (showEnemy3)
				iShowBMP2(enemyX5 - 100, enemyY5 + 36, soldier3[enemyIndex5], 0);

			else if (showEnemy3 == false && showBoss3 == true)
			{
				iShowBMP2(bossX5 - 100, bossY5 + 112, boss3[bossIndex5], 0);
			}
			else if (showBoss3 == false && showTreasure == true)
			{
				iShowBMP2(treasurex, treasurey, treasure[treasureindex], 0);
				//iShowBMP2(1015, 200, "puzzle1.bmp", 0);
				iShowBMP2(1000, 600, "menu\\next1.bmp", 0);
				iShowBMP2(940, 600, "menu\\next2.bmp", 0);
			}
		}



		else if (pause)
		{


			if (runforcheck && !jump && !standPosition){
				iShowBMP2(assCoX2, assCoY2, RUN[assRUN2], 0);
			}
			else if (runrevcheck && !jump && !standPosition){
				iShowBMP2(assCoX2, assCoY2 + 7, RUNREV[assRunRev2], 0);
			}
			else if (standPosition)
			{
				iShowBMP2(assCoX4, assCoY4, STAND[assSTAND2], 0);
			}
			else if (jump)
				iShowBMP2(assCoX3, assCoY3 + assCoJump2, AJ[0], 0);

			if (showEnemy3)
				iShowBMP2(enemyX6 - 100, enemyY6 + 36, soldier3[enemyIndex6], 0);

			else if (showEnemy3 == false && showBoss3 == true)
				iShowBMP2(bossX6 - 100, bossY6 + 112, boss3[bossIndex6], 0);

			//coin1
			if (showCoin)
				iShowBMP2(cx1 - 100, cy1 + 40, coin[coinindex1], 0);

			//coin2
			if (showCoin2)
				iShowBMP2(cx3 - 30, cy3 + 40, coin[coinindex], 0);

			//thorns!!
			if (showThorn)
			{
				iShowBMP2(thornX2, thornY2, "thorn.bmp", 0);
			}


			RENDER = false;
			if (pausebar)
			{
				int p = iLoadImage("pause\\pause__1_-removebg-preview.png");
				iShowImage(300, 90, 700, 600, p);
				//iShowBMP2(420, 200, "Untitled1.bmp",0);
				int p1 = iLoadImage("pause\\pause-(12)_01.jpg");
				iShowImage(470, 340, 300, 100, p1);
				int p2 = iLoadImage("pause\\pause_02.jpg");
				iShowImage(440, 240, 300, 100, p2);

				if (soundon == false)
					iShowBMP2(745, 260, "pause\\off.bmp", 0);

				if (soundon)
					iShowBMP2(745, 260, "pause\\Untitledo.bmp", 0);

				int p3 = iLoadImage("pause\\pause_03.jpg");
				iShowImage(470, 140, 300, 100, p3);
				if (pause1)
				{
					int pp1 = iLoadImage("pause\\pause-(11)_01.jpg");
					iShowImage(470, 340, 300, 100, pp1);
				}
				if (pause2)
				{
					int pp2 = iLoadImage("pause\\pause-(10)_02.jpg");
					iShowImage(440, 240, 300, 100, pp2);
				}
				if (pause3)
				{
					int pp3 = iLoadImage("pause\\pause-(10)_03.jpg");
					iShowImage(470, 140, 300, 100, pp3);
				}

			}

			if (save)
			{
				int tr = iLoadImage("pause\\Do_you_want_to_save_the_game-removebg-preview.png");
				iShowImage(400, 200, 400, 300, tr);
				int tr1 = iLoadImage("pause\\Do-you-want-to-save-the-game-_2__01-removebg-preview.png");
				iShowImage(465, 300, 130, 60, tr1);
				int tr2 = iLoadImage("pause\\Do-you-want-to-save-the-game-_2__02-removebg-preview.png");
				iShowImage(615, 300, 130, 60, tr2);
				if (saveyes == true)
				{
					int say = iLoadImage("pause\\Do-you-want-to-save-the-game-_3__01-removebg-preview.png");
					iShowImage(465, 300, 130, 60, say);
				}
				if (saveno == true)
				{
					int san = iLoadImage("pause\\Do-you-want-to-save-the-game-_3__02-removebg-preview.png");
					iShowImage(615, 300, 130, 60, san);
				}
			}
		}


		//eagle
		for (int j = 0; j < eagleNUM; j++)
		{
			if (eagle_[j].eagleShow)
				iShowBMP2(eagle_[j].eagleX, eagle_[j].eagleY + 500, eagle[eagle_[j].eagleIndex], 0);
		}


		//Assassin health
		iShowBMP2(hx, hy, health[hindex], 0);

		//BOSSHEALTH 3
		if (showBoss3)
			iShowBMP2(bhx1, bhy1, B3H[hit3], 0);
		if (showBoss4 == true)
		{
			int bo = iLoadImage("bomb\\images-removebg-preview.png");
			iShowImage(750, 620, 100, 100, bo);
		}

		if (eaglec == true)
			iShowBMP2(e1x, e1y, "eagle\\eagle 2.bmp", 0);

		if (bomb == true)
		{
			int bl1 = iLoadImage(blust[ei]);
			iShowImage(b1x, b1y, 200, 200, bl1);
		}



		if (gameover)
		{
			game = false;
			hindex = 0;
			iShowBMP(0, 0, "BC\\gameOver.bmp");
			iShowBMP2(70, 600, "New folder\\option.bmp", 0);
		}


	}
	else if (puzzlelevel3 && level3 == false)
	{
		int i = iLoadImage("puzzle\\images.jpg");
		iShowImage(0, 0, 1200, 700, i);
		if (puzzle3)
		{
			int p31 = iLoadImage("puzzle\\330314770_1281664912417483_2147475942210750013_n.jpg");
			iShowImage(500, 70, 500, 500, p31);
			int p32 = iLoadImage("puzzle\\IMG_5107-removebg-preview.png");
			iShowImage(puzzlex, puzzley, 320, 270, p32);
		}

		if (puzzlem && puzzle3 == false)
		{
			int p33 = iLoadImage("puzzle\\330314770_1281664912417483_2147475942210750013_n.jpg");
			iShowImage(500, 70, 500, 500, p33);
			int p34 = iLoadImage("puzzle\\IMG_5107-removebg-preview.png");
			iShowImage(puzzlex1, puzzley1, 320, 270, p34);

		}

		if (puzzle32)
		{
			int p23 = iLoadImage("puzzle\\330284975_3472154486339171_2135037695627635892_n.jpg");
			iShowImage(500, 70, 500, 500, p23);
			iShowBMP2(1050, 600, "menu\\next1.bmp", 0);
			iShowBMP2(100, 600, "menu\\next2.bmp", 0);
		}

	}

	//level 4
	else if (gameOn == true && level4 == true)
	{

		//RENDER = true;
		//showTreasure = false;
		showCoin = true;
		showCoin2 = true;
		//showEnemy2 = true;
		//showBoss1 = false;
		enemycount = 0;


		//render
		for (i = 0; i < 200; i++)
			iShowBMP(position[i], 0, image4[i]);

		//score
		if (asd >= 0 && asd < 1000)
			iShowBMP2(535, 570, ASD[asd], 0);

		//plus
		if (!showTreasure)
		{
			if (showPlus)
				iShowBMP2(plusx - 20, plusy, "plus.bmp", 0);
		}



		if (!pause)
		{
			if (jump)
			{
				if (jumpUp)
				{
					//attackNIGGA = false;
					if (runforcheck)       //run forward
						iShowBMP2(assCoX, assCoY + AssCoJump, AJ[0], 0);

					else if (runrevcheck)    //run backward
						iShowBMP2(assCoX, assCoY + AssCoJump, AJREV[0], 0);
				}
				else if (!jumpUp)
				{
					if (runforcheck)
						iShowBMP2(assCoX, assCoY + AssCoJump, AJ[1], 0);

					else if (runrevcheck)
						iShowBMP2(assCoX, assCoY + AssCoJump, AJREV[1], 0);
				}
			}
			else if (!jump)
			{
				if (!standPosition)
				{
					if (runrevcheck)
						iShowBMP2(assCoX, assCoY + 7, RUNREV[assRunRev], 0);

					else if (runforcheck)
						iShowBMP2(assCoX, assCoY, RUN[assRUN], 0);

					standCounter++;
					if (standCounter >= 12)
					{
						standCounter = 0;
						assRUN = 0;
						standPosition = true;
					}
				}
				else if (attackFIRE)
				{
					iShowBMP2(assCoX + 20, assCoY, FIRE[attackreal], 0);
					assSTAND = 0;
					attackcount++;
				}
				else if (normal_attack)
					iShowBMP2(assCoX, assCoY, realattack[n_attack], 0);

				else if (ICE_ATTACK)
					iShowBMP2(assCoX, assCoY - 15, iceattack[ice_attack], 0);

				else if (standPosition)
					iShowBMP2(assCoX, assCoY, STAND[assSTAND], 0);
			}


			//here we'll place the snakes!!!
			if (showSnake){
				int sn = iLoadImage(snake[snakeIndex]);
				iShowImage(snakeX, snakeY, 120, 58, sn);
				//iShowBMP2(snakeX, snakeY, snake[snakeIndex], 0);
			}


			//coin1
			if (showCoin && !showTreasure)
			{
				iShowBMP2(cx - 100, cy + 40, coin[coinindex], 0);
			}

			//coin2
			if (showCoin2 && !showTreasure)
			{
				iShowBMP2(cx2 - 30, cy2 + 40, coin[coinindex], 0);
			}


			//ugabuga and medusa
			if (showEnemy4)
				iShowBMP2(enemyX7 - 100, enemyY7 + 36, soldier4[enemyIndex7], 0);

			else if (showEnemy4 == false && showBoss4 == true)
			{
				iShowBMP2(bossX7 - 100, bossY7 + 112, boss4[bossIndex7], 0);
			}
			else if (showBoss4 == false && showTreasure == true)
			{
				iShowBMP2(treasurex, treasurey, treasure[treasureindex], 0);
				//iShowBMP2(1015, 200, "puzzle1.bmp", 0);
				iShowBMP2(1000, 600, "menu\\next1.bmp", 0);
				iShowBMP2(940, 600, "menu\\next2.bmp", 0);
			}
		}



		else if (pause)
		{


			if (runforcheck && !jump && !standPosition){
				iShowBMP2(assCoX2, assCoY2, RUN[assRUN2], 0);
			}
			else if (runrevcheck && !jump && !standPosition){
				iShowBMP2(assCoX2, assCoY2 + 7, RUNREV[assRunRev2], 0);
			}
			else if (standPosition)
			{
				iShowBMP2(assCoX4, assCoY4, STAND[assSTAND2], 0);
			}
			else if (jump)
				iShowBMP2(assCoX3, assCoY3 + assCoJump2, AJ[0], 0);

			if (showEnemy4)
				iShowBMP2(enemyX8 - 100, enemyY8 + 36, soldier4[enemyIndex8], 0);

			else if (showEnemy4 == false && showBoss4 == true)
				iShowBMP2(bossX8 - 100, bossY8 + 112, boss4[bossIndex8], 0);

			//coin1
			if (showCoin)
				iShowBMP2(cx1 - 100, cy1 + 40, coin[coinindex1], 0);

			//coin2
			if (showCoin2)
				iShowBMP2(cx3 - 30, cy3 + 40, coin[coinindex], 0);

			//snakes!!
			if (showSnake){
				iShowBMP2(snakeX2, snakeY2, snake[snakeIndex2], 0);
			}

			RENDER = false;
			if (pausebar)
			{
				int p = iLoadImage("pause\\pause__1_-removebg-preview.png");
				iShowImage(300, 90, 700, 600, p);
				//iShowBMP2(420, 200, "Untitled1.bmp",0);
				int p1 = iLoadImage("pause\\pause-(12)_01.jpg");
				iShowImage(470, 340, 300, 100, p1);
				int p2 = iLoadImage("pause\\pause_02.jpg");
				iShowImage(440, 240, 300, 100, p2);

				if (soundon == false)
					iShowBMP2(745, 260, "pause\\off.bmp", 0);

				if (soundon)
					iShowBMP2(745, 260, "pause\\Untitledo.bmp", 0);

				int p3 = iLoadImage("pause\\pause_03.jpg");
				iShowImage(470, 140, 300, 100, p3);
				if (pause1)
				{
					int pp1 = iLoadImage("pause\\pause-(11)_01.jpg");
					iShowImage(470, 340, 300, 100, pp1);
				}
				if (pause2)
				{
					int pp2 = iLoadImage("pause\\pause-(10)_02.jpg");
					iShowImage(440, 240, 300, 100, pp2);
				}
				if (pause3)
				{
					int pp3 = iLoadImage("pause\\pause-(10)_03.jpg");
					iShowImage(470, 140, 300, 100, pp3);
				}

			}

			if (save)
			{
				int tr = iLoadImage("pause\\Do_you_want_to_save_the_game-removebg-preview.png");
				iShowImage(400, 200, 400, 300, tr);
				int tr1 = iLoadImage("pause\\Do-you-want-to-save-the-game-_2__01-removebg-preview.png");
				iShowImage(465, 300, 130, 60, tr1);
				int tr2 = iLoadImage("pause\\Do-you-want-to-save-the-game-_2__02-removebg-preview.png");
				iShowImage(615, 300, 130, 60, tr2);
				if (saveyes == true)
				{
					int say = iLoadImage("pause\\Do-you-want-to-save-the-game-_3__01-removebg-preview.png");
					iShowImage(465, 300, 130, 60, say);
				}
				if (saveno == true)
				{
					int san = iLoadImage("pause\\Do-you-want-to-save-the-game-_3__02-removebg-preview.png");
					iShowImage(615, 300, 130, 60, san);
				}
			}
		}


		//eagle
		for (int j = 0; j < eagleNUM; j++)
		{
			if (eagle_[j].eagleShow)
				iShowBMP2(eagle_[j].eagleX, eagle_[j].eagleY + 500, eagle[eagle_[j].eagleIndex], 0);
		}


		//Assassin health
		iShowBMP2(hx, hy, health[hindex], 0);

		//BOSSHEALTH 4
		if (showBoss4)
			iShowBMP2(bhx1, bhy1, B4H[hit4], 0);

		


		if (gameover)
		{
			game = false;
			hindex = 0;
			iShowBMP(0, 0, "BC\\gameOver.bmp");
			iShowBMP2(70, 600, "New folder\\option.bmp", 0);
		}



	}

	else if (puzzlelevel4 && level4 == false)
	{
		int i = iLoadImage("puzzle\\images.jpg");
		iShowImage(0, 0, 1200, 700, i);
		if (puzzle4)
		{
			int p41 = iLoadImage("puzzle\\330284975_3472154486339171_2135037695627635892_n.jpg");
			iShowImage(500, 70, 500, 500, p41);
			int p42 = iLoadImage("puzzle\\IMG_5108-removebg-preview.png");
			iShowImage(puzzlex, puzzley, 320, 270, p42);
		}

		if (puzzlem && puzzle4 == false)
		{
			int p43 = iLoadImage("puzzle\\330284975_3472154486339171_2135037695627635892_n.jpg");
			iShowImage(500, 70, 500, 500, p43);
			int p44 = iLoadImage("puzzle\\IMG_5108-removebg-preview.png");
			iShowImage(puzzlex1, puzzley1, 320, 270, p44);

		}

		if (puzzle42)
		{
			int p43 = iLoadImage("puzzle\\329246938_551261173437096_1501005587369751379_n.jpg");
			iShowImage(500, 70, 500, 500, p43);

			iShowBMP2(100, 600, "menu\\next2.bmp", 0);
		}
	}

}



void render()
{
	int i, j = 0;
	if (RENDER)
	{
		//iSetTimer(80, render);
		for (i = 0; i < 200; i++)
		{
			if (!standPosition && !runrevcheck && assCoX > 300)
			{
				position[i] -= width;
				if (position[i] < 0)
				{

					{
						position[i] = (slice*width) - width;
					}

				}
			}

		}
	}
}


void positionfunction()
{
	int i, k = 0;
	for (i = 0, j = 0; i < 200; i++)
	{
		position[i] = j;
		j += width;

	}
}


void iMouseMove(int mx, int my)
{
	puzzlex1 = mx - 60;
	puzzley1 = my - 60;

	/*x = mx - 150;
	y = my - 20;*/
	//place your codes here
}



/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//x = mx - 150;
		//y = my - 20;

		if (mx >= 750 && mx <= 850 && my >= 620 && my <= 720 && (showBoss2 || showBoss3))
		{
			eaglec = true;
		}

		if (game && gameOn == false)
		{
			if (mx >= 100 && mx <= 300 && my >= 540 && my <= 600 && gamesave == 1)		//CONTINUE
			{
				if (gamestate == 0)
				{
					gamestate = 1;
					gameOn = true;
					readfile();

					//game = false;
				}




				//jerin = 1;
				//gameOn = true;
				//game = false;
			}
			else if (mx >= 100 && mx <= 300 && my >= 480 && my <= 540)		//NEW GAME 
			{
				//jerin = 2;
				gamestate = 2;
				gameOn = true;
				game = false;
				pausebar = true;
				level1 = true;
				asd = 0;
				assCoX = 80;
				assCoY = 99;
				hindex = 0;
				showEnemy2 = false;
				showEnemy3 = false;
				showEnemy4 = false;
				showEnemy1 = true;
				enemyX1 = 0;
				enemyY1 = 80;
				P = 1;
				RENDER = true;
				standPosition = true;

			}
			else if (mx >= 100 && mx <= 300 && my >= 420 && my <= 480)
				gamestate = 3;
			else if (mx >= 100 && mx <= 300 && my >= 360 && my <= 420 && soundon)
				soundon = false;
			else if (mx >= 100 && mx <= 300 && my >= 360 && my <= 420 && soundon == false)
				soundon = true;
			else if (mx >= 100 && mx <= 300 && my >= 300 && my <= 360)
				gamestate = 5;
			else if (mx >= 100 && mx <= 300 && my >= 240 && my <= 300)
				gamestate = 6;
			else if (mx >= 100 && mx <= 300 && my >= 180 && my <= 240)
			{
				gamestate = 7;
				exit(0);
			}
			if (mx >= 40 && mx <= 140 && my >= 50 && my <= 110)
				gamestate = 0;
			if (mx >= 1050 && mx <= 1100 && my >= 350 && my <= 403)
				help = 1;
			if (mx >= 50 && mx <= 100 && my >= 350 && my <= 403)
				help = 0;
		}
		if (mx >= 1000 && mx <= 1050 && my >= 600 && my <= 653 && showBoss1 == false && level1)
		{
			puzzlelevel1 = true;
			level1 = false;
		}
		if (mx >= 940 && mx <= 990 && my >= 600 && my <= 653 && level1 && showBoss1 == false)
		{
			gamestate = 0;
			game = true;
			gameOn = false;
		}
		if (mx >= 100 && mx <= 350 && my >= 400 && my <= 600 && puzzlelevel1 && puzzlem == false)
		{
			puzzlem = true;
			puzzle1 = false;
		}

		if (mx >= 625 && mx <= 720 && my >= 200 && my <= 300 && puzzlelevel1 && puzzlex1 >= 500 && puzzlex1 <= 1000 && puzzley1 >= 70 && puzzley1 <= 570)
		{
			puzzle12 = true;
			puzzlem = false;
		}
		if (mx >= 1050 && mx <= 1100 && my >= 600 && my <= 653 && puzzlelevel1 && puzzlem == false)
		{
			puzzlelevel1 = false;
			//puzzle1 = true;
			puzzle12 = false;
			level2 = true;
			assCoX = 80;
			enemycount = 0;
			showEnemy2 = true;
			RENDER = true;
			showCactus = true;
			hindex = 0;
			hit1 = 0;
			cx = 500;
			cx2 = 510;
			tc = 0;
			tc2 = 0;
			plusx = -1;
			//cactusX = -1;
			showTreasure = false;
			asd = 0;

		}
		if (mx >= 100 && mx <= 150 && my >= 600 && my <= 653 && puzzlelevel1 && puzzlem == false)
		{
			gamestate = 0;
			game = true;
			gameOn = false;
		}

		if (mx >= 1000 && mx <= 1050 && my >= 600 && my <= 653 && level2 && showBoss2 == false)
		{
			puzzlelevel2 = true;
			level2 = false;

		}
		if (mx >= 940 && mx <= 990 && my >= 600 && my <= 653 && level2 && showBoss2 == false)
		{
			gamestate = 0;
			game = true;
			gameOn = false;
		}
		if (mx >= 100 && mx <= 350 && my >= 400 && my <= 600 && puzzlelevel2 && puzzlem == false)
		{
			puzzlem = true;
			puzzle2 = false;
		}

		if (mx >= 750 && mx <= 875 && my >= 200 && my <= 300 && puzzlelevel2 && puzzlex1 >= 500 && puzzlex1 <= 1000 && puzzley1 >= 70 && puzzley1 <= 570)
		{
			puzzle22 = true;
			puzzlem = false;

		}
		if (mx >= 1050 && mx <= 1100 && my >= 600 && my <= 653 && puzzlelevel2 && puzzlem == false)
		{
			puzzlelevel2 = false;
			level2 = false;
			level3 = true;
			assCoX = 80;
			enemycount2 = 0;
			showEnemy3 = true;
			RENDER = true;
			showCactus = false;
			showThorn = true;
			hindex = 0;
			//hit or hit1 or hit2??
			hit2 = 0;
			hit = 0;
			cx = 500;
			cx2 = 510;
			tc = 0;
			tc2 = 0;
			plusx = -1;
			//cactusX = -1;
			showTreasure = false;
			asd = 0;


		}
		if (mx >= 100 && mx <= 150 && my >= 600 && my <= 653 && puzzlelevel2 && puzzlem == false)
		{
			gamestate = 0;
			game = true;
			gameOn = false;
		}


		if (mx >= 1000 && mx <= 1050 && my >= 600 && my <= 653 && level3 && showBoss3 == false)
		{
			puzzlelevel3 = true;
			level3 = false;

		}

		if (mx >= 940 && mx <= 990 && my >= 600 && my <= 653 && level3 && showBoss3 == false)
		{
			gamestate = 0;
			game = true;
			gameOn = false;
		}

		if (mx >= 100 && mx <= 350 && my >= 400 && my <= 600 && puzzlelevel3 && puzzlem == false)
		{
			puzzlem = true;
			puzzle3 = false;
		}

		if (mx >= 625 && mx <= 720 && my >= 70 && my <= 190 && puzzlelevel3 && puzzlex1 >= 500 && puzzlex1 <= 1000 && puzzley1 >= 70 && puzzley1 <= 570)
		{
			puzzle32 = true;
			puzzlem = false;

		}
		if (mx >= 1050 && mx <= 1100 && my >= 600 && my <= 653 && puzzlelevel3 && puzzlem == false)
		{
			puzzlelevel3 = false;

			level3 = false;
			level4 = true;
			assCoX = 80;
			enemycount3 = 0;
			showEnemy4 = true;
			RENDER = true;
			showThorn = false;
			showSnake = true;
			hindex = 0;
			//hit or hit1 or hit2??
			hit3 = 0;
			hit = 0;
			cx = 500;
			cx2 = 510;
			tc = 0;
			tc2 = 0;
			plusx = -1;
			//cactusX = -1;
			showTreasure = false;
			asd = 0;
		}


		if (mx >= 100 && mx <= 150 && my >= 600 && my <= 653 && puzzlelevel3 && puzzlem == false)
		{
			gamestate = 0;
			game = true;
			gameOn = false;
		}
		if (mx >= 1000 && mx <= 1050 && my >= 600 && my <= 653 && showBoss4 == false && level4)
		{
			puzzlelevel4 = true;
			level4 = false;
		}
		if (mx >= 940 && mx <= 990 && my >= 600 && my <= 653 && level4 && showBoss4 == false)
		{
			gamestate = 0;
			game = true;
			gameOn = false;
		}
		if (mx >= 100 && mx <= 350 && my >= 400 && my <= 600 && puzzlelevel4 && puzzlem == false)
		{
			puzzlem = true;
			puzzle4 = false;
		}

		if (mx >= 750 && mx <= 875 && my >= 100 && my <= 180 && puzzlelevel4 && puzzlex1 >= 500 && puzzlex1 <= 1000 && puzzley1 >= 70 && puzzley1 <= 570)
		{
			puzzle42 = true;
			puzzlem = false;
		}

		if (gameover && mx >= 70 && mx <= 140 && my >= 600 && my <= 648)
		{
			gameOn = false;
			game = true;
			gamestate = 0;
		}

		if (pause)
		{
			if (mx >= 470 && mx <= 770 && my >= 140 && my <= 240)
			{
				pausebar = false;
				save = true;
			}
			else if (mx >= 440 && mx <= 815 && my >= 240 && my <= 340 && soundon)
				soundon = false;
			else if (mx >= 440 && mx <= 815 && my >= 240 && my <= 340 && soundon == false)
				soundon = true;
		}

		if (mx >= 465 && mx <= 595 && my >= 300 && my <= 360 && save)
		{
			gamestate = 0;
			game = true;
			gameOn = false;
			save = false;
			pause = false;

			gamesave = 1;

			ofstream fp;
			fp.open("gamesave.txt");


			fp << j << endl << i << endl << RENDER << endl << level1 << endl << level2 << endl << showEnemy1 << endl
				<< showEnemy2 << endl << showBoss1 << endl << showBoss2 << endl << showCoin << endl << showCoin2 << endl
				<< showPlus << endl << showCactus << endl << assCoX << endl << assCoY << endl << cx << endl << cy << endl
				<< cx2 << endl << cy2 << endl << plusx << endl << plusy << endl << cactusX << endl << cactusY << endl <<
				AssCoJump << endl << enemyX1 << endl << enemyY1 << endl << enemyX3 << endl << enemyY3 << endl << bossX1 <<
				endl << bossY1 << endl << bossX3 << endl << bossY3 << endl << assRunRev << endl << assRUN << endl << standCounter
				<< endl << n_attack << endl << coinindex << endl << enemyIndex1 << endl << enemyIndex3 << endl << bossIndex1
				<< endl << bossIndex3 << endl << hit1 << endl << hit2 << endl << asd << endl << hindex << endl << standPosition
				<< endl << runforcheck << endl << runrevcheck << endl << face << endl << standPositionleft << endl << left_index
				<< endl << P << endl << gamesave << endl << enemyX5 << endl << enemyY5 << endl << enemyX7 << endl << enemyY7
				<< endl << bossX5 << endl << bossY5 << endl << bossX7 << endl << bossY7 << endl << showEnemy3 << endl << showEnemy4
				<< endl << showBoss3 << endl << showBoss4 << endl << showSnake << endl << showThorn << endl << snakeX << endl <<
				snakeY << endl << thornX << endl << thornY << endl << level3 << endl << level4 << endl << puzzlelevel1 << endl
				<< puzzlelevel2 << endl << puzzlelevel3 << endl << puzzlelevel4 << endl;



			fp.close();



		}
		else if (mx >= 615 && mx <= 745 && my >= 300 && my <= 360 && save)
		{
			gamestate = 0;
			game = true;
			gameOn = false;
			pause = false;
			save = false;

			ofstream fp3;
			fp3.open("gamesave.txt");

			fp3 << 0 << endl << 0 << endl << 0 << endl << 0 << endl << 0 << endl << 1 << endl << 0 << endl <<
				0 << endl << 0 << endl << 1 << endl << 1 << endl << 1 << endl << 0 << endl << 80 << endl <<
				99 << endl << 500 << endl << 120 << endl << 510 << endl << 260 << endl << 0 << endl << 0 <<
				endl << 0 << endl << 0 << endl << 0 << endl << 0 << endl << 0 << endl << 0 << endl << 0 <<
				endl << 0 << endl << 0 << endl << 0 << endl << 0 << endl << 0 << endl << 0 << endl << 0 <<
				endl << 0 << endl << 0 << endl << 0 << endl << 0 << endl << 0 << endl << 0 << endl << 0 <<
				endl << 0 << endl << 0 << endl << 0 << endl << 0 << endl << 0 << endl << 0 << endl << 0 <<
				endl << 0 << endl << 0 << endl << 1 << endl;

			fp3.close();
		}


	}
	/*if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	r = 255;
	g = 0;
	b = 0;
	//place your codes here
	}*/


}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx, int my)
{
	//place your code here
	if (game)
	{
		if (mx >= 100 && mx <= 300 && my >= 540 && my <= 600)
			jerin1 = true;
		else jerin1 = false;
		if (mx >= 100 && mx <= 300 && my >= 480 && my <= 540)
			jerin2 = true;
		else jerin2 = false;
		if (mx >= 100 && mx <= 300 && my >= 420 && my <= 480)
			jerin3 = true;
		else jerin3 = false;
		if (mx >= 100 && mx <= 300 && my >= 360 && my <= 420 && soundon)
			jerin4 = true;
		else jerin4 = false;
		if (mx >= 100 && mx <= 300 && my >= 360 && my <= 420 && soundon == false)
			jerin4o = true;
		else jerin4o = false;
		if (mx >= 100 && mx <= 300 && my >= 300 && my <= 360)
			jerin5 = true;
		else jerin5 = false;
		if (mx >= 100 && mx <= 300 && my >= 240 && my <= 300)
			jerin6 = true;
		else jerin6 = false;
		if (mx >= 100 && mx <= 300 && my >= 180 && my <= 240)
			jerin7 = true;
		else jerin7 = false;
	}
	if (gameOn  &&  pause)
	{
		if (mx >= 470 && mx <= 770 && my >= 340 && my <= 440)
			pause1 = true;
		else pause1 = false;
		if (mx >= 470 && mx <= 770 && my >= 240 && my <= 340)
			pause2 = true;
		else pause2 = false;
		if (mx >= 470 && mx <= 770 && my >= 140 && my <= 240)
			pause3 = true;
		else pause3 = false;
	}
	if (mx >= 465 && mx <= 595 && my >= 300 && my <= 360 && save)
		saveyes = true;
	else saveyes = false;
	if (mx >= 615 && mx <= 745 && my >= 300 && my <= 360 && save)
		saveno = true;
	else saveno = false;
	/*mposx = mx;
	mposy = my;
	if (mx == 2){}        //Something to do with mx
	else if (my == 2){}   //Something to do with my
	*/
}


void iKeyboard(unsigned char key)
{
	if (key == 's')
	{
		gamestart = false;
		game = true;
	}
	if (key == 'w')
	{
		y += 10;   //do something with 'q'
	}
	else if (key == 'a')
	{
		x -= 10;
	}
	else if (key == 's')
	{
		y -= 10;
	}
	else if (key == 'd')
	{
		x += 10;
	}
	else if (key == 'r')
	{
		r = 255;
		g = 0;
		b = 0;
	}
	else if (key == 'g')
	{
		r = 0;
		g = 255;
		b = 0;
	}
	else if (key == 'b')
	{
		r = 0;
		g = 0;
		b = 255;
	}

	if (key == ' ')
	{

		if (!jump)
		{
			jump = true;
			jumpUp = true;
			standPosition = false;
			if (soundon)
				PlaySound("Sound\\jumps-65494 (mp3cut.net).wav", NULL, SND_ASYNC);
			//PlaySound("music\\r.wav", NULL, SND_LOOP | SND_ASYNC);
		}

	}
	else if (key == 't')
	{
		//attackNIGGA = true;

		//runrevcheck = false;
		if (!gameover){
			if (!level1){
				if (!attackFIRE)
				{
					//attackNIGGA
					attackFIRE = true;
					if (soundon)
						PlaySound("Sound\\mixkit-sword-slash-swoosh-1476 (mp3cut.net).wav", NULL, SND_ASYNC);
					//jumpUp = false;
				}
			}
		}

	}
	else if (key == 'n')
	{


		n++;


		if (!gameover){
			if (!normal_attack)
			{

				normal_attack = true;
				if (soundon)
					PlaySound("Sound\\mixkit-sword-slash-swoosh-1476 (mp3cut.net).wav", NULL, SND_ASYNC);
			}
		}
	}
	else if (key == 'i')
	{
		if (!gameover){
			if (!level1){
				if (!ICE_ATTACK)
				{

					runrevcheck = false;
					runforcheck = false;

					ICE_ATTACK = true;
					if (soundon)
						PlaySound("Sound\\mixkit-sword-slash-swoosh-1476 (mp3cut.net).wav", NULL, SND_ASYNC);
				}
			}
		}
	}
	//place your codes for other keys here


}


/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	//jump = true;
	if (key == GLUT_KEY_UP)
	{
		y += 10;
		if (musicOn)
		{
			musicOn = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			//musicOn = true;
			//PlaySound("music\\arpeggiator-end-credits-wav-14644", NULL, SND_LOOP | SND_ASYNC);
		}
	}
	else if ((key == GLUT_KEY_DOWN))
	{
		//BCIndex = 1;
		iShowBMP2(assCoX, assCoY, realattack[attackreal], 0);
	}
	if ((key == GLUT_KEY_LEFT))
	{
		if (!pause){
			face = 1;
			//runrevcheck = true;
			assCoX -= 10;
			assCoX -= 10;



			if ((assCoX > cx && assCoX < cx + 20) && (assCoY < 175) && (assCoY + AssCoJump < 175))
			{
				showCoin = false;
				asd++;

			}

			assRunRev++; //assRUN--;


			if (assRunRev >= 8)   //if (assRUN < 0)
				assRunRev = 0;    //assRUN = 8;

			if (assCoX <= 0)
			{
				assCoX += 10;
				assCoX += 10;
			}


			runforcheck = false;
			runrevcheck = true;
			standPosition = false;

		}
	}
	if ((key == GLUT_KEY_RIGHT))
	{
		if (!pause){
			face = 0;
			assCoX += 10;
			assCoX += 10;
			/*if (runforcheck){
			PlaySound("running-1-6846 (mp3cut.net).wav", NULL, SND_ASYNC);
			}*/
			if (assCoX >= 300)
			{
				cx -= 10;
				cx2 -= 10;
				enemyX1 -= 10;
				bossX1 -= 10;
				plusx -= 10;
				enemyX3 -= 10;
				enemyX5 -= 12;
				enemyX7 -= 12;
				bossX3 -= 10;
				bossX5 -= 12;
				if (showBoss2 || showEnemy2){
					cactusX -= 9;
				}
				if (showBoss3 || showEnemy3)
				{
					thornX -= 9;
				}

				snakeX -= 10;

			}

			tc++;
			if (tc >= 150)
			{
				showCoin = true;

				cx = 1000;
				tc = 0;
			}

			tc2++;
			if (tc2 >= 200)
			{
				showCoin2 = true;
				cx2 = 1000;
				tc2 = 0;
			}

			tp++;
			//if (tp >= 100)
			//{
			//showPlus = true;
			//plusx = 1000;
			//tp = 0;
			//}

			if (!showTreasure){
				if (level1){
					if (assCoX > 350)
					{
						assCoX -= 21;
					}
				}
				else if (level2)
				{
					if (assCoX > 350)
					{
						assCoX -= 21;
					}
				}
				else if (level3)
				{
					if (assCoX > 350)
					{
						assCoX -= 21;
					}

				}
				else if (level4)
				{
					if (assCoX > 350)
					{
						assCoX -= 21;
						if (showBoss4)
						{
							assCoX += 5;
						}
					}


				}
			}


			//cx -= 10;
			//shapeX += 25;
			/*if (!shape_run_extend_dx)
			{
			shape_run_extend_dx = true;
			}*/

			//shapedX += 10;


			assRUN++;
			if (assRUN >= 8)
				assRUN = 0;
			if (assCoX >= (width * 200) - 80)
			{
				assCoX -= 10.5;
				assCoX -= 10.5;
			}

			runrevcheck = false;
			runforcheck = true;

			standPosition = false;
		}
	}
	if ((key == GLUT_KEY_HOME))
	{
		r = 255;
		g = 0;
		b = 0;
	}
	if ((key == GLUT_KEY_F1))
	{
		//p++;
		if (pause == false)
		{
			pause = true;
			P = 0;
			if (jump)
			{
				assCoX3 = assCoX;
				assCoY3 = assCoY;
			}

			assCoX2 = assCoX;
			assCoY2 = assCoY;
			assRUN2 = assRUN;
			assRunRev2 = assRunRev;
			//assCoJump2 = AssCoJump;
			if (showEnemy1){
				enemyX2 = enemyX1;
				enemyY2 = enemyY1;
				enemyIndex2 = enemyIndex1;
			}
			else if (showBoss1)
			{
				bossX2 = bossX1;
				bossY2 = bossY1;
				bossindex2 = bossIndex1;
			}
			if (showEnemy2)
			{
				enemyX4 = enemyX3;
				enemyY4 = enemyY3;
				enemyIndex4 = enemyIndex3;
			}
			else if (showBoss2)
			{
				bossX4 = bossX3;
				bossY4 = bossY3;
				bossIndex4 = bossIndex3;
			}
			if (showEnemy3)
			{
				enemyX6 = enemyX5;
				enemyY6 = enemyY5;
				enemyIndex6 = enemyIndex5;
			}
			else if (showBoss3)
			{
				bossX6 = bossX5;
				bossY6 = bossY5;
				bossIndex6 = bossIndex5;
			}
			if (showEnemy4)
			{
				enemyX8 = enemyX7;
				enemyY8 = enemyY7;
				enemyIndex8 = enemyIndex7;
			}
			else if (showBoss4)
			{
				bossX8 = bossX7;
				bossY8 = bossY7;
				bossIndex8 = bossIndex7;
			}

			if (showCoin){
				cx1 = cx;
				cy1 = cy;
				coinindex1 = coinindex;
			}
			if (showCoin2)
			{
				cx3 = cx2;
				cy3 = cy2;
				coinindex1 = coinindex;
			}
			if (showCactus)
			{
				cactusX2 = cactusX;
				cactusY2 = cactusY;
			}
			if (showThorn)
			{
				thornX2 = thornX;
				thornY2 = thornY;
			}
			if (showSnake)
			{
				snakeX2 = snakeX;
				snakeY2 = snakeY;
				snakeIndex2 = snakeIndex;
			}

			showCoin = true;
			if (standPosition)
			{
				assSTAND2 = assSTAND;
				assCoX4 = assCoX;
				assCoY4 = assCoY;
			}
		}
		else if (pause)
		{
			pause = false;
			RENDER = true;
			P = 1;
			//p = 0;
		}
	}

	//place your codes for other keys here
}

/*void steel()
{
assSTAND++;

if (assSTAND >= 4)
assSTAND = 0;

}*/

void change()
{
	if (jump)
	{
		//attackNIGGA = false;
		if (jumpUp)
		{

			//attackNIGGA = false;
			AssCoJump = AssCoJump + (ACJ*P);
			assCoJump2 = AssCoJump;
			//shapeY += 5;
			if (AssCoJump >= jumpLimit)
			{
				jumpUp = false;

			}
			//attackNIGGA = false;
		}
		else
		{
			//attackNIGGA = false;
			AssCoJump = AssCoJump - (ACJ*P);
			assCoJump2 = AssCoJump;
			//shapeY -= 5;
			if (AssCoJump < 0)
			{
				jump = false;
				AssCoJump = 0;
				assCoJump2 = AssCoJump;
			}
		}
	}
	if (face == 0)
	{
		assSTAND++;

		if (assSTAND >= 4)
			assSTAND = 0;
	}
	else if (face == 1)
	{
		left_index++;
		if (left_index >= 4)
			left_index = 0;
	}



}

void heroAttack()
{
	//jump = true;


	if (attackFIRE)
	{
		attackreal++;
		if (attackreal >= 5)
		{
			attackFIRE = false;
			attackreal = 0;
			//jump = true;
		}

		//standPosition = false;
		runforcheck = true; //false;
		runrevcheck = false; //false;
		//jump = true;
		//attackreal = false;
	}
	else if (normal_attack)
	{
		n_attack++;
		if (n_attack >= 3)
		{
			normal_attack = false;
			n_attack = 0;
		}
		runforcheck = true;
		runrevcheck = false;
	}
	else if (ICE_ATTACK)
	{

		ice_attack++;
		if (ice_attack >= 4)
		{
			ICE_ATTACK = false;
			ice_attack = 0;
		}
		runforcheck = true;
		runrevcheck = false;

	}
	if (showTreasure){
		if (treasurecheck == 0){
			treasureindex++;
			if (treasureindex >= 6)
			{
				treasureindex = 6;
				treasurecheck++;
			}
		}
	}

}

void coinMove1()
{
	if (!pause){
		if (showCoin){
			coinindex++;
			if (coinindex >= 7)
				coinindex = 0;

			if (cx <= 0)
			{
				cx -= 6;
				if (tc >= 80){
					cx = 1200 + rand() % 100;
					//cx2 = screenWidth + rand() % 100;

					tc = 0;
				}
			}
			if ((assCoX > cx - 150 && assCoX < cx + 150) && (assCoY < 175) && (assCoY + AssCoJump < 175))
			{
				cx = false;
				if (!showTreasure){
					if (soundon)
						PlaySound("Sound\\coin-2-47744.wav", NULL, SND_ASYNC);
				}
				dang = 1;

				if (dang == 1 && cx == false)
				{
					if (!showTreasure)
						asd++;
					//dang = 0;
				}
				dang = 0;
			}
		}

		if (showCoin2){
			coinindex++;
			if (coinindex >= 7)
				coinindex = 0;

			if (cx2 <= 0)
			{
				//cx2 -= 6;
				{
					//cx2 = 1500 + rand() % 100;
					if (tc2 >= 80)
					cx2 = 1200 + rand() % 100;

					tc2 = 0;
				}
			}



			if ((assCoX > cx2 - 150 && assCoX < cx2 + 150) && (assCoY + AssCoJump >= 190))// (assCoY < 175) && (assCoY + AssCoJump < 175))
			{
				cx2 = false;
				if (!showTreasure){
					if (soundon)
						PlaySound("Sound\\coin-2-47744.wav", NULL, SND_ASYNC);
				}
				dang = 1;

				if (dang == 1 && cx2 == false)
				{
					if (!showTreasure)
						asd++;
					//dang = 0;
				}
				dang = 0;
			}
		}


		//}
		if (showPlus)
		{
			//plusx -= 6;
			if (plusx < 0)
			{
				plusx += 6;
				if (tp >= 120)
				{
					plusx = 3000 + rand() % 100;
					tp = 0;
				}
			}
			//if ((assCoX+100<=plusx && assCoX+20>plusx) && (assCoY+AssCoJump >= 200)) //&& (assCoY + AssCoJump >= 100))
			if ((assCoX>plusx - 100 && assCoX<plusx + 100) && (assCoY + AssCoJump >= 230)) //&& (assCoY + AssCoJump >= 100))
			{
				plusx = false;
				//PlaySound("coin-2-47744.wav", NULL, SND_ASYNC);
				//cross++;
				if (!showTreasure){
					if (hindex != 0)
					{
						hindex--;
					}
					else if (hindex == 0)
					{
						hindex = 0;
					}
				}
			}
		}
		if (level2){
			if (showCactus){

				//cactusX -= 6;
				if (cactusX < 0)
				{
					cactusX -= 5;
					if (tp >= 120)
					{
						cactusX = 1200 + rand() % 100;
						tp = 0;
					}
				}

				if ((assCoX > cactusX - 12 && assCoX < cactusX + 11) && (assCoY < 130) && (assCoY + AssCoJump < 130))
				{
					hindex++;
					if (hindex >= 6)
					{
						if (soundon)
							PlaySound("Sound\\Player-Death-Scream-Sound-Effect-Third-Variation.wav", NULL, SND_ASYNC);
						gameover = true;
						RENDER = false;
						hindex = 0;
					}
				}
			}
		}

		if (level3){
			if (showThorn){

				//thornX -= 6;
				if (thornX < 0)
				{
					//thornX -= 5;
					//if (tp >= 120)
					//{
					thornX = 1200 + rand() % 100;
					//tp = 0;
					//}
				}

				if ((assCoX > thornX - 12 && assCoX < thornX + 11) && (assCoY < 130) && (assCoY + AssCoJump < 130))
				{
					hindex++;
					if (hindex >= 6)
					{
						gameover = true;
						RENDER = false;
						hindex = 0;
					}
				}
			}
		}

		if (level4){
			if (showSnake){
				snakeX -= 6;
				/*if (snakeX <= 0)
				{
				snakeX += 6;
				if (tc >= 80){
				snakeX = 1400 + rand() % 100;
				tc = 0;
				}
				}*/

				if (snakeX <= 0)
				{
					//snakeX -= 6;
					//if (tp >= 120)
					//{
					snakeX = 1200 + rand() % 100;
					//tp = 0;
					//}
				}

				snakeIndex++;
				if (snakeIndex >= 9)
				{
					snakeIndex = 0;
				}
			}

			if ((assCoX > snakeX - 12 && assCoX < snakeX + 11) && (assCoY < 130) && (assCoY + AssCoJump < 130))
			{
				hindex++;
				if (hindex >= 6)
				{
					gameover = true;
					RENDER = false;
					hindex = 0;
				}
			}


		}


	}
}



//int eX;

int bosscount;
void enemyMove1()
{
	if (gameOn){
		if (!pause){
			if (showEnemy1 || show_enemy1 == 1)
			{
				enemyX1 -= 6;
				if (enemyX1 <= 0)
				{
					enemyX1 += 6;
					if (tc >= 80){
						enemyX1 = 1400 + rand() % 100;
						tc = 0;
					}
				}


				enemyIndex1++;
				if (enemyIndex1 == 16)
				{
					hit++;
					hindex++;
					if (hit >= 7 && hindex >= 6)
					{
						if (soundon)
							PlaySound("Sound\\Player-Death-Scream-Sound-Effect-Third-Variation.wav", NULL, SND_ASYNC);
						standPosition = false;
						runrevcheck = false;
						runforcheck = false;
						RENDER = false;
						hit = 0;
						hindex = 0;
						gameover = true;

					}

				}
				if (enemyX1 > assCoX + 150 || enemyX1 < assCoX - 50)
				{
					if (enemyIndex1 >= 10)
					{
						enemyIndex1 = 0;
					}
				}
				else if (enemyX1 < assCoX + 150 || enemyX1>assCoX - 150)
				{
					if (enemyIndex1 >= 17)
					{
						enemyIndex1 = 10;
						if (!gameover){
							if (soundon)
								PlaySound("Sound\\Sword Draw Sound Effect.wav", NULL, SND_ASYNC);
						}
					}
				}


				if ((enemyX1 <= assCoX + 150 && enemyX1 >= assCoX) && enemyX1 >= 0)
				{
					if ((enemyX1 <= assCoX + 250) && (enemyY1 + 100 >= assCoY + AssCoJump))
					{
						//enemyX1 += 6;
						if (enemyX1 <= assCoX + 150)
						{
							enemyX1 += 6;
							if (attackFIRE == true)
							{
								hindex++;
								enemyX1 = false;
								enemycount++;
								if (enemycount > 0)
								{
									showEnemy1 = false;
									show_enemy1 = 0;
									showBoss1 = true;
									show_boss1 = 1;
									enemycount = 0;
								}

							}
							else if (ICE_ATTACK)
							{
								hindex++;
								enemyX1 = false;
								enemycount++;
								if (enemycount > 0)
								{
									showEnemy1 = false;
									show_enemy1 = 0;
									showBoss1 = true;
									show_boss1 = 1;
									enemycount = 0;
								}
							}
							else if (normal_attack)
							{
								if (n >= 2)
								{
									enemyX1 = false;
									enemycount++;
									if (enemycount > 0)
									{
										showEnemy1 = false;
										show_enemy1 = 0;
										showBoss1 = true;
										show_boss1 = 1;
										enemycount = 0;
									}
									n = 0;
								}
							}
						}
					}
				}
			}




			else if (showEnemy2)
			{
				enemyX3 -= 6;
				if (enemyX3 <= 0)
				{
					enemyX3 += 6;
					if (tc >= 80){
						enemyX3 = 1400 + rand() % 100;
						tc = 0;
					}
				}


				enemyIndex3++;
				if (enemyIndex3 == 16)
				{
					hit++;
					hindex++;
					if (hit >= 7 && hindex >= 6)   //assassin health
					{
						if (soundon)
							PlaySound("Sound\\Player-Death-Scream-Sound-Effect-Third-Variation.wav", NULL, SND_ASYNC);
						standPosition = false;
						runrevcheck = false;
						runforcheck = false;
						RENDER = false;
						hit = 0;
						hindex = 0;
						gameover = true;

					}

				}
				if (enemyX3 > assCoX + 150 || enemyX3 < assCoX - 50)
				{
					if (enemyIndex3 >= 10)
					{
						enemyIndex3 = 0;
					}
				}
				else if (enemyX3 <= assCoX + 150 || enemyX3>assCoX - 150)
				{
					if (enemyIndex3 >= 17)
					{
						enemyIndex3 = 10;
						if (!gameover){
							if (soundon)
								PlaySound("Sound\\Sword Draw Sound Effect.wav", NULL, SND_ASYNC);
						}
					}
				}


				if ((enemyX3 <= assCoX + 150 && enemyX3 >= assCoX) && enemyX3 >= 0)
				{
					if ((enemyX3 <= assCoX + 250) && (enemyY3 + 100 >= assCoY + AssCoJump))
					{
						//enemyX1 += 6;
						if (enemyX3 <= assCoX + 150)
						{
							enemyX3 += 6;
							if (attackFIRE == true)
							{
								hindex++;
								enemyX3 = false;
								enemycount2++;
								if (enemycount2 > 0)
								{
									showEnemy2 = false;
									showBoss2 = true;
									enemycount2 = 0;
								}

							}
							else if (ICE_ATTACK)
							{
								//hindex++;
								enemyX3 = false;
								enemycount2++;
								if (enemycount2 > 0)
								{
									showEnemy2 = false;
									showBoss2 = true;
									enemycount2 = 0;
								}
							}
							else if (normal_attack)
							{
								//hindex++;
								if (n >= 2)
								{
									enemyX3 = false;
									enemycount2++;
									if (enemycount2 > 0)
									{
										showEnemy2 = false;
										showBoss2 = true;
										enemycount2 = 0;
									}
									n = 0;
								}
							}
						}
					}
				}
			}

			else if (showEnemy3)
			{
				enemyX5 -= 6;
				if (enemyX5 <= 0)
				{
					enemyX5 += 6;
					if (tc >= 80){
						enemyX5 = 1400 + rand() % 100;
						tc = 0;
					}
				}

				///////why 16????
				enemyIndex5++;
				if (enemyIndex5 == 17)
				{
					hit++;
					hindex++;
					if (hit >= 7 && hindex >= 6)   //assassin health
					{

						PlaySound("Player-Death-Scream-Sound-Effect-Third-Variation.wav", NULL, SND_ASYNC);
						standPosition = false;
						runrevcheck = false;
						runforcheck = false;
						RENDER = false;
						hit = 0;
						hindex = 0;
						gameover = true;

					}

				}
				if (enemyX5 > assCoX + 150 || enemyX5 < assCoX - 50)
				{
					if (enemyIndex5 >= 13)
					{
						enemyIndex5 = 0;
					}
				}
				else if (enemyX5 <= assCoX + 150 || enemyX5>assCoX - 150)
				{
					if (enemyIndex5 >= 21)
					{
						enemyIndex5 = 13;
						if (!gameover){
							PlaySound("Sword Draw Sound Effect.wav", NULL, SND_ASYNC);
						}
					}
				}


				if ((enemyX5 <= assCoX + 150 && enemyX5 >= assCoX) && enemyX5 >= 0)
				{
					if ((enemyX5 <= assCoX + 250) && (enemyY5 + 100 >= assCoY + AssCoJump))
					{
						//enemyX1 += 6;
						if (enemyX5 <= assCoX + 150)
						{
							enemyX5 += 6;
							if (attackFIRE == true)
							{
								//hindex++;
								enemyX5 = false;
								enemycount3++;
								if (enemycount3 >= 0)
								{
									showEnemy3 = false;
									showBoss3 = true;
									enemycount3 = 0;
								}

							}
							else if (ICE_ATTACK)
							{
								//hindex++;
								enemyX5 = false;
								enemycount3++;
								if (enemycount3 >= 0)
								{
									showEnemy3 = false;
									showBoss3 = true;
									enemycount3 = 0;
								}
							}
							else if (normal_attack)
							{
								//hindex++;
								if (n >= 2)
								{
									enemyX5 = false;
									enemycount3++;
									if (enemycount3 >= 0)
									{
										showEnemy3 = false;
										showBoss3 = true;
										enemycount3 = 0;
									}
									n = 0;
								}
							}
						}
					}
				}
			}

			else if (showEnemy4)
			{
				enemyX7 -= 6;
				if (enemyX7 <= 0)
				{
					//enemyX7 += 6;
					//if (tc >= 80){
					enemyX7 = 1600 + rand() % 100;
					//tc = 0;
					//}
				}

				enemyIndex7++;
				if (enemyIndex7 == 19)
				{
					hit++;
					hindex++;
					if (hit >= 7 && hindex >= 6)   //assassin health
					{

						PlaySound("Player-Death-Scream-Sound-Effect-Third-Variation.wav", NULL, SND_ASYNC);
						standPosition = false;
						runrevcheck = false;
						runforcheck = false;
						RENDER = false;
						hit = 0;
						hindex = 0;
						gameover = true;

					}

				}
				if (enemyX7 > assCoX + 150 || enemyX7 < assCoX - 50)
				{
					if (enemyIndex7 >= 14)
					{
						enemyIndex7 = 0;
					}
				}
				else if (enemyX7 <= assCoX + 150 || enemyX7>assCoX - 150)
				{
					if (enemyIndex7 >= 22)
					{
						enemyIndex7 = 15;
						if (!gameover){
							PlaySound("Sword Draw Sound Effect.wav", NULL, SND_ASYNC);
						}
					}
				}


				if ((enemyX7 <= assCoX + 150 && enemyX7 >= assCoX) && enemyX7 >= 0)
				{
					if ((enemyX7 <= assCoX + 250) && (enemyY7 + 100 >= assCoY + AssCoJump))
					{
						//enemyX1 += 6;
						if (enemyX7 <= assCoX + 150)
						{
							enemyX7 += 6;
							if (attackFIRE)
							{
								//hindex++;
								enemyX7 = false;
								enemycount4++;
								if (enemycount4 > 0)
								{
									showEnemy4 = false;
									showBoss4 = true;
									enemycount4 = 0;
								}

							}
							else if (ICE_ATTACK)
							{
								//hindex++;
								enemyX7 = false;
								enemycount4++;
								if (enemycount4 > 0)
								{
									showEnemy4 = false;
									showBoss4 = true;
									enemycount4 = 0;
								}
							}
							else if (normal_attack)
							{
								//hindex++;
								if (n >= 2)
								{
									enemyX7 = false;
									enemycount4++;
									if (enemycount4 > 0)
									{
										showEnemy4 = false;
										showBoss4 = true;
										enemycount4 = 0;
									}
									n = 0;
								}
							}
						}
					}
				}
			}


			else if (showBoss1 || show_boss1 == 1)
			{
				bossX1 -= 6;
				if (bossX1 <= 0)
				{
					bossX1 += 6;
					bossX1 = 1500 + rand() % 100;
				}
				bossIndex1++;
				/*if (enemyIndex1 == 16)
				{
				eX = enemyX;
				eX = eX - 50;
				}*/

				if (bossIndex1 == 12)
				{
					hit += 2;
					hindex += 2;
					if (hit >= 7 && hindex >= 6)
					{
						if (soundon)
							PlaySound("Sound\\Player-Death-Scream-Sound-Effect-Third-Variation.wav", NULL, SND_ASYNC);
						standPosition = false;
						runrevcheck = false;
						runforcheck = false;
						RENDER = false;
						hit = 0;
						hindex = 0;
						gameover = true;


					}

				}
				if (bossX1 > assCoX + 141 || bossX1 < assCoX - 50)
				{
					if (bossIndex1 >= 7)
					{
						bossIndex1 = 0;
					}
				}
				else if (bossX1 < assCoX + 141 || bossX1>assCoX - 150)
				{
					if (bossIndex1 >= 15)
					{
						bossIndex1 = 8;
						if (!gameover){
							if (soundon)
								PlaySound("Sound\\Sword Draw Sound Effect.wav", NULL, SND_ASYNC);
						}
					}
				}


				if ((bossX1 <= assCoX + 140 && bossX1 >= assCoX) && bossX1 >= 0)
				{
					if ((bossX1 <= assCoX + 140) && (bossY1 + 100 >= assCoY + AssCoJump))
					{
						if (bossX1 <= assCoX + 140)
						{
							bossX1 += 6;
							if (attackFIRE == true)
							{
								//bossX1 = false;
								//hit1++;
								bosshealth1index++;
								bosscount++;
								if (bosscount >= 1 && hit1 == 3)
								{
									//showEnemy1 = false;
									//treasurecheck++;
									bossX1 = false;
									showBoss1 = false;
									show_boss1 = 0;
									showTreasure = true;
									show_treasure1 = 1;
									RENDER = false;
									showCoin = false;
									show_coin1 = 0;
									showCoin2 = false;
									show_coin2 = 0;
									bosscount = 0;
									if (soundon)
										PlaySound("Sound\\success-fanfare-trumpets-6185.wav", NULL, SND_ASYNC);

									hit1 = 0;

								}

							}
							else if (ICE_ATTACK)
							{
								//bossX1 = false;
								hit1++;
								bosscount++;
								if (bosscount >= 1 && hit1 == 3)
								{
									//showboss1 = false;
									//treasurecheck++;
									bosscount = 0;
									bossX1 = false;
									showBoss1 = false;
									show_boss1 = 0;
									showTreasure = true;
									show_treasure1 = 1;
									RENDER = false;
									showCoin = false;
									show_coin1 = 0;
									showCoin2 = false;
									show_coin2 = 0;
									hit1 = 0;
									if (soundon)
										PlaySound("Sound\\success-fanfare-trumpets-6185.wav", NULL, SND_ASYNC);
								}
							}
							else if (normal_attack)
							{
								if (n >= 2)
								{
									//bossX1 = false;
									//hit1++;
									hit1++;
									bosscount++;
									if (bosscount >= 1 && hit1 == 3)
									{

										bosscount = 0;
										bossX1 = false;
										showBoss1 = false;
										show_boss1 = 0;
										showTreasure = true;
										show_treasure1 = 1;
										RENDER = false;
										showCoin = false;
										show_coin1 = 0;
										showCoin2 = false;
										show_coin2 = 0;
										hit1 = 0;

										if (soundon)
											PlaySound("Sound\\success-fanfare-trumpets-6185.wav", NULL, SND_ASYNC);
										//showBoss1 = true;
									}
									n = 0;
								}
							}
						}
					}
				}
			}


			else if (showBoss2)
			{
				bossX3 -= 6;
				if (bossX3 <= 0)
				{
					bossX3 += 6;
					bossX3 = 1500 + rand() % 100;
				}
				bossIndex3++;
				/*if (enemyIndex1 == 16)
				{
				eX = enemyX;
				eX = eX - 50;
				}*/

				if (bossIndex3 == 12)
				{
					hit += 2;
					hindex += 2;
					if (hit >= 7 && hindex >= 6)
					{
						if (soundon)
							PlaySound("Sound\\Player-Death-Scream-Sound-Effect-Third-Variation.wav", NULL, SND_ASYNC);
						standPosition = false;
						runrevcheck = false;
						runforcheck = false;
						RENDER = false;
						hit = 0;
						hindex = 0;
						gameover = true;

					}

				}
				if (bossX3 > assCoX + 141 || bossX3 < assCoX - 50)
				{
					if (bossIndex3 >= 7)
					{
						bossIndex3 = 0;
					}
				}
				else if (bossX3 < assCoX + 141 || bossX3>assCoX - 150)
				{
					if (bossIndex3 >= 15)
					{
						bossIndex3 = 8;
						if (!gameover){
							if (soundon)
								PlaySound("Sound\\Sword Draw Sound Effect.wav", NULL, SND_ASYNC);
						}
					}
				}


				if ((bossX3 <= assCoX + 140 && bossX3 >= assCoX) && bossX3 >= 0)
				{
					if ((bossX3 <= assCoX + 140) && (bossY3 + 130 >= assCoY + AssCoJump))
					{
						if (bossX3 <= assCoX + 140)
						{
							bossX3 += 6;
							if (attackFIRE == true)
							{
								//bossX1 = false;
								hit2++;
								bosscount2++;
								if (bosscount2 >= 1 && hit2 == 8)
								{
									//showEnemy1 = false;
									//treasurecheck++;
									bossX3 = false;
									showBoss2 = false;
									showTreasure = true;
									RENDER = false;
									showCoin = false;
									showCoin2 = false;
									bosscount2 = 0;
									if (soundon)
										PlaySound("Sound\\success-fanfare-trumpets-6185.wav", NULL, SND_ASYNC);

									hit2 = 0;
								}

							}
							else if (ICE_ATTACK)
							{
								//bossX1 = false;
								hit2++;
								bosscount2++;
								if (bosscount2 >= 1 && hit2 == 8)
								{
									//showboss1 = false;
									//treasurecheck++;
									bosscount2 = 0;
									bossX3 = false;
									showBoss2 = false;
									showTreasure = true;
									RENDER = false;
									showCoin = false;
									showCoin2 = false;
									hit2 = 0;
									if (soundon)
										PlaySound("Sound\\success-fanfare-trumpets-6185.wav", NULL, SND_ASYNC);
								}
							}
							else if (normal_attack)
							{
								if (n >= 2)
								{
									//bossX1 = false;
									hit2++;
									bosscount++;
									if (bosscount >= 1 && hit2 == 8)
									{
										//treasurecheck++;
										bosscount2 = 0;
										bossX3 = false;
										showBoss2 = false;
										showTreasure = true;
										RENDER = false;
										showCoin = false;
										showCoin2 = false;
										hit2 = 0;
										if (soundon)
											PlaySound("Sound\\success-fanfare-trumpets-6185.wav", NULL, SND_ASYNC);
										//showBoss1 = true;
									}
									n = 0;
								}
							}
						}
					}
				}
			}
			else if (showBoss3)
			{
				bossX5 -= 6;
				if (bossX5 <= 0)
				{
					bossX5 += 6;
					bossX5 = 1500 + rand() % 100;
				}
				bossIndex5++;


				////////////////why 12?
				if (bossIndex5 == 9)
				{
					hit += 2;
					hindex += 2;
					if (hit >= 7 && hindex >= 6)
					{
						PlaySound("Player-Death-Scream-Sound-Effect-Third-Variation.wav", NULL, SND_ASYNC);
						standPosition = false;
						runrevcheck = false;
						runforcheck = false;
						RENDER = false;
						hit = 0;
						hindex = 0;
						gameover = true;

					}

				}
				if (bossX5 > assCoX + 141 || bossX5 < assCoX - 50)
				{
					if (bossIndex5 >= 7)
					{
						bossIndex5 = 0;
					}
				}
				else if (bossX5 < assCoX + 141 || bossX5>assCoX - 150)
				{
					if (bossIndex5 >= 15)
					{
						bossIndex5 = 7;
						if (!gameover){
							PlaySound("Sword Draw Sound Effect.wav", NULL, SND_ASYNC);
						}
					}
				}


				if ((bossX5 <= assCoX + 140 && bossX5 >= assCoX) && bossX5 >= 0)
				{
					if ((bossX5 <= assCoX + 140) && (bossY5 + 130 >= assCoY + AssCoJump))
					{
						if (bossX5 <= assCoX + 140)
						{
							bossX5 += 6;
							if (attackFIRE == true)
							{
								//bossX1 = false;
								hit3++;
								bosscount3++;
								if (bosscount3 >= 1 && hit3 == 12)
								{
									//showEnemy1 = false;
									//treasurecheck++;
									bossX5 = false;
									showBoss3 = false;
									showTreasure = true;
									RENDER = false;
									showCoin = false;
									showCoin2 = false;
									bosscount3 = 0;
									PlaySound("success-fanfare-trumpets-6185.wav", NULL, SND_ASYNC);

									hit3 = 0;
								}

							}
							else if (ICE_ATTACK)
							{
								//bossX1 = false;
								hit3++;
								bosscount3++;
								if (bosscount3 >= 1 && hit3 == 12)
								{
									//showboss1 = false;
									//treasurecheck++;
									bosscount3 = 0;
									bossX5 = false;
									showBoss3 = false;
									showTreasure = true;
									RENDER = false;
									showCoin = false;
									showCoin2 = false;
									hit3 = 0;
									PlaySound("success-fanfare-trumpets-6185.wav", NULL, SND_ASYNC);
								}
							}
							else if (normal_attack)
							{
								if (n >= 2)
								{
									//bossX1 = false;
									hit3++;
									bosscount3++;
									if (bosscount3 >= 1 && hit3 == 12)
									{
										//treasurecheck++;
										bosscount3 = 0;
										bossX5 = false;
										showBoss3 = false;
										showTreasure = true;
										RENDER = false;
										showCoin = false;
										showCoin2 = false;
										hit3 = 0;
										PlaySound("success-fanfare-trumpets-6185.wav", NULL, SND_ASYNC);
										//showBoss1 = true;
									}
									n = 0;
								}
							}
						}
					}
				}
			}

			//medusa won't walk
			else if (showBoss4)
			{
				bossX7 -= 6;
				if (bossX7 <= 0)
				{
					//bossX7 += 6;
					bossX7 = 1500 + rand() % 100;
				}



				////////////////why 12?
				bossIndex7++;
				if (bossIndex7 == 15)
				{
					//hit += 2;
					hindex += 2;
					if (hindex >= 6)
					{
						PlaySound("Player-Death-Scream-Sound-Effect-Third-Variation.wav", NULL, SND_ASYNC);
						standPosition = false;
						runrevcheck = false;
						runforcheck = false;
						RENDER = false;
						hit = 0;
						hindex = 0;
						gameover = true;

					}

				}

				if (bossX7 >= 800)// || bossX7 < assCoX - 50)
				{
					bossIndex7++;

					if (bossIndex7 >= 8)
					{
						bossIndex7 = 0;
					}
				}
				else if (bossX7 < 800)
				{
					bossX7 += 6;
					//if (assCoX > bossX7 - 30 && assCoX < bossX7 + 30)
					//{
					bossIndex7++;

					if (bossIndex7 >= 20)
					{
						bossIndex7 = 9;
					}
					//}
				}

				if (assCoX >= bossX7 - 100 && assCoX <= bossX7 + 100)
				{

					if (bossIndex7 == 15)
					{
						//hit += 2;
						hindex += 1;
						if (hindex >= 6)
						{
							PlaySound("Player-Death-Scream-Sound-Effect-Third-Variation.wav", NULL, SND_ASYNC);
							standPosition = false;
							runrevcheck = false;
							runforcheck = false;
							RENDER = false;
							hit = 0;
							hindex = 0;
							gameover = true;

						}

					}
					if (attackFIRE == true)
					{
						//bossX1 = false;
						hit4++;
						bosscount4++;
						if (bosscount4 >= 1 && hit4 == 12)
						{
							//showEnemy1 = false;
							//treasurecheck++;
							bossX7 = false;
							showBoss4 = false;
							showTreasure = true;
							RENDER = false;
							showCoin = false;
							showCoin2 = false;
							bosscount4 = 0;
							PlaySound("success-fanfare-trumpets-6185.wav", NULL, SND_ASYNC);

							hit4 = 0;
						}

					}
					else if (ICE_ATTACK)
					{
						//bossX1 = false;
						hit4++;
						bosscount4++;
						if (bosscount4 >= 1 && hit4 == 12)
						{
							//showboss1 = false;
							//treasurecheck++;
							bosscount4 = 0;
							bossX7 = false;
							showBoss4 = false;
							showTreasure = true;
							RENDER = false;
							showCoin = false;
							showCoin2 = false;
							hit4 = 0;
							PlaySound("success-fanfare-trumpets-6185.wav", NULL, SND_ASYNC);
						}
					}
					else if (normal_attack)
					{
						if (n >= 2)
						{
							//bossX1 = false;
							hit4++;
							bosscount4++;
							if (bosscount4 >= 1 && hit4 == 12)
							{
								//treasurecheck++;
								bosscount4 = 0;
								bossX7 = false;
								showBoss4 = false;
								showTreasure = true;
								RENDER = false;
								showCoin = false;
								showCoin2 = false;
								hit4 = 0;
								PlaySound("success-fanfare-trumpets-6185.wav", NULL, SND_ASYNC);
								//showBoss1 = true;
							}
							n = 0;
						}
					}
				}



				/*if ((bossX7 <= assCoX + 140 && bossX7 >= assCoX) && bossX7 >= 0)
				{
				if ((bossX7 <= assCoX + 140) && (bossY7 + 130 >= assCoY + AssCoJump))
				{
				if (bossX7 <= assCoX + 140)
				{
				bossX7 += 6;
				if (attackFIRE == true)
				{
				//bossX1 = false;
				hit4++;
				bosscount4++;
				if (bosscount4 >= 1 && hit4 == 12)
				{
				//showEnemy1 = false;
				//treasurecheck++;
				bossX7 = false;
				showBoss4 = false;
				showTreasure = true;
				RENDER = false;
				showCoin = false;
				showCoin2 = false;
				bosscount4 = 0;
				PlaySound("success-fanfare-trumpets-6185.wav", NULL, SND_ASYNC);

				hit4 = 0;
				}

				}
				else if (ICE_ATTACK)
				{
				//bossX1 = false;
				hit4++;
				bosscount4++;
				if (bosscount4 >= 1 && hit4 == 12)
				{
				//showboss1 = false;
				//treasurecheck++;
				bosscount4 = 0;
				bossX7 = false;
				showBoss4 = false;
				showTreasure = true;
				RENDER = false;
				showCoin = false;
				showCoin2 = false;
				hit4 = 0;
				PlaySound("success-fanfare-trumpets-6185.wav", NULL, SND_ASYNC);
				}
				}
				else if (normal_attack)
				{
				if (n >= 2)
				{
				//bossX1 = false;
				hit4++;
				bosscount4++;
				if (bosscount4 >= 1 && hit4 == 12)
				{
				//treasurecheck++;
				bosscount4 = 0;
				bossX7 = false;
				showBoss4 = false;
				showTreasure = true;
				RENDER = false;
				showCoin = false;
				showCoin2 = false;
				hit4 = 0;
				PlaySound("success-fanfare-trumpets-6185.wav", NULL, SND_ASYNC);
				//showBoss1 = true;
				}
				n = 0;
				}
				}
				}
				}
				}*/
			}
		}
	}
}










/*void eagleMove()
{
for (int j = 0; j < eagleNUM; j++)
{
//enemy[i].birdShow = true;
eagle_[j].eagleX -= 10;
if (eagle_[j].eagleX <= 0)
{
eagle_[j].eagleX = screenWidth + rand() % 1000;
}
eagle_[j].eagleIndex++;
if (eagle_[j].eagleIndex >= 1)
{
eagle_[j].eagleIndex = 0;
}
}
}*/

/*void setEnemyVariables()
{
if (showEnemy)
{
enemyX = screenWidth + rand() % 100;
enemyY = 70 + rand() % 10;
enemyIndex = rand() % 100;
showEnemy = true;
}
}*/

void setEnemyVariables()
{
	if (showEnemy1)
	{
		enemyX1 = screenWidth + rand() % 100;
		enemyY1 = 70 + rand() % 10;
		enemyIndex1 = rand() % 100;
		showEnemy1 = true;
	}
	else if (showEnemy2)
	{
		enemyX3 = screenWidth + rand() % 100;
		enemyY3 = 250 + rand() % 10;
		enemyIndex3 = rand() % 100;
		showEnemy2 = true;
	}
	else if (showEnemy3)
	{
		enemyX5 = screenWidth + rand() % 100;
		enemyY5 = 250 + rand() % 10;
		enemyIndex5 = rand() % 100;
		showEnemy3 = true;
	}
	else if (showEnemy4)
	{
		enemyX7 = screenWidth + rand() % 100;
		enemyY7 = 250 + rand() % 10;
		enemyIndex7 = rand() % 100;
		showEnemy4 = true;
	}
}

void setBossVariables()
{
	if (showBoss1)
	{
		bossX1 = screenWidth + rand() % 100;
		bossY1 = 180 + rand() % 10;
		bossIndex1 = rand() % 100;
		showBoss1 = true;
	}
	else if (showBoss2)
	{
		bossX3 = screenWidth + rand() % 100;
		bossY3 = 180 + rand() % 10;
		bossIndex3 = rand() % 100;
		showBoss2 = true;

	}
	else if (showBoss3)
	{
		bossX5 = screenWidth + rand() % 100;
		bossY5 = 180 + rand() % 10;
		bossIndex5 = rand() % 100;
		showBoss3 = true;

	}
	else if (showBoss4)
	{
		bossX7 = screenWidth + rand() % 100;
		bossY7 = 180 + rand() % 10;
		bossIndex7 = rand() % 100;
		showBoss4 = true;

	}
}

void setCoinVariables()
{
	if (showCoin)
	{

		cx = 1200 + rand() % 100 + 50;
		cy = 73 + rand() % 10;
		coinindex = rand() % 100;
		showCoin = true;

	}
	if (showCoin2)
	{
		cx2 = 1200 + rand() % 100 + 50;
		cy2 = 200 + rand() % 10;
		coinindex = rand() % 100;
		showCoin2 = true;
	}
}

void setThornVariables()
{
	//if (showThorn)
	//{

	thornX = screenWidth + rand() % 100 + 100;
	thornY = 120 + rand() % 10;
	showThorn = true;
	//}
}

void setSnakeVariables()
{
	//if (showSnake)
	{
		snakeX = screenWidth + rand() % 100;
		snakeY = 120 + rand() % 10;
		snakeIndex = rand() % 100;
		showSnake = true;
	}

}



void setPlusVariables()
{
	if (showPlus)
	{
		plusx = screenWidth + rand() % 100 + 100;
		plusy = 320 + rand() % 10;
		//coinindex = rand() % 1	00;
		showPlus = true;

	}
}

void setCactusVariables()
{
	cactusX = screenWidth + rand() % 100 + 100;
	cactusY = 120 + rand() % 10;
	showCactus = true;
}

void setEagleVariables()
{
	for (int j = 0; j < 1; j++)
	{
		eagle_[j].eagleX = screenWidth + rand() % 100;
		eagle_[j].eagleY = 70 + rand() % 100;
		eagle_[j].eagleIndex = rand() % 10000;
		eagle_[j].eagleShow = true;
	}
}

void bombchange()
{
	//asd -= 5;
	if (eaglec == true)
	{
		ex -= edx;
		if (ex == 400)
			bomb = true;
	}
	if (bomb == true)
	{
		by -= bdy;
		ei++;
		if (ei > 4)
			bdy = 0;
		if (ei > 11)
			bomb = false;
		if (bossX3 >= 350 && bossX3 <= 500)
			hit2 += 2;

	}

}


void changecolor()
{
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;
}
/*void MUSIC()
{
if (gamestate==0)
PlaySound("music\\menu.wav", NULL, SND_LOOP | SND_ASYNC);
else if (gamestate==2)
PlaySound("music\\r.wav", NULL, SND_LOOP | SND_ASYNC);
}*/


int main()
{
	///srand((unsigned)time(NULL));
	positionfunction();
	iSetTimer(20, render);
	//place your own initialization codes here.
	iSetTimer(50, changecolor);



	//setAll();
	//iSetTimer(25, bgchange);
	setEnemyVariables();
	setBossVariables();
	setCoinVariables();
	setPlusVariables();
	setCactusVariables();
	setThornVariables();
	setSnakeVariables();
	iSetTimer(200, bombchange);
	
	//imgposf();
	//iSetTimer(5100, MUSIC);
	//iSetTimer(50, cactusmove);
	iSetTimer(15, change);
	//iSetTimer(1, enemyMove);
	iSetTimer(60, enemyMove1);
	//iSetTimer(75, bossMove1);
	//iSetTimer(50, plusMove);
	//iSetTimer(5, eagleMove);
	//iSetTimer(40, steel);
	iSetTimer(1, heroAttack);
	iSetTimer(30, coinMove1);
	/*if (!ICE_ATTACK)
	PlaySound("music\\menu.wav", NULL, SND_LOOP | SND_ASYNC);*/
	//iSetTimer(50, E_attack);
	//iSetTimer(100, N_Attack);
	//iSetTimer(70, I_Attack);
	//iSetTimer(10, enemyVanish);
	//iSetTimer(15, assjump);

	//iInitialize(width * 200, 600, "demooo");

	//return 0;
	/*if (musicone)
	{
	PlaySound("music\\menu.wav", NULL, SND_LOOP);
	//PlaySound("music\\1", NULL, SND_LOOP | SND_ASYNC);
	}
	else if (musictwo)
	{
	PlaySound("music\\r.wav", NULL, SND_LOOP);
	}*/
	//if (gamestate==0)
	//PlaySound("music\\menu.wav", NULL, SND_LOOP | SND_ASYNC);

	/*else if (musictwo)
	PlaySound("music\\r.wav", NULL, SND_LOOP);*/

	//else if (gameover)
	//game = false;
	iInitialize(width * 200, 700, "Assassin's Creed-The Missing Pieces");
	iStart();
	return 0;
}