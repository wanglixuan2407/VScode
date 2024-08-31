#define _CRT_SECURE_NO_WARNINGS

#define ROW 15    //15行
#define COLUMN 15 //15列
#define NUM 5     //连成5子
#define ARRAY_SIZE 16   //多出1行1列用于标注坐标

#define TRUE  1
#define FALSE 0
#define BACK 3 //悔棋上限次数为3
#define Otherspace FrontEmptyNum + BehindEmptyNum  //判断落子后一串棋子左右两边空格数

#define Bounday_judgement checkingrow >= 0 && checkingrow < ROW && checkingcolumn >= 0 && checkingcolumn < COLUMN  //打分函数的边界条件

extern int n ;//步数n
extern int max ;//最高得分
extern int c ;//纵坐标全局变量，落子函数要用到
extern int d ;//横坐标全局变量，落子函数要用到
extern int N ;//复盘函数用到，记录本局最终步数
extern int p ;//复盘时希望回退/前进的步数
extern int N1 ;//临时记录复盘到哪一步

extern char buf;//scanf 缓冲区

void print_board(int board[ARRAY_SIZE][ARRAY_SIZE]);//打印棋盘
void choose_and_play();//选择模式
void play1();//人人对战
void play2();//执黑人机对战
void play3();//执白人机对战
void play4();//机器对战
void black_turn(int n);//黑棋落子（人工）
void blackbot();//黑棋落子（机器）
void white_turn(int n);//白棋落子（人工）
void whitebot();//白棋落子（机器）
void check();//判断胜负
void black_back();//黑方悔棋函数
void white_back();//白方悔棋函数
void score_black();//黑方落点打分
void score_white();//白方落点打分
void replaycourse(int p, int N);

int test_winner(int r, int l);//判断胜负
int test_row(int r, int l);//判断1行是否连成5子
int test_column(int r, int l);//判断1列是否连成5子
int test_diagonal_45(int r, int l);//判断右上--左下斜线是否连成5子
int test_diagonal_135(int r, int l);//判断左上--右下斜线是否连成5子
int state_black(int BlackNum, int FrontEmptyNum, int BehindEmptyNum);// 判断黑方落子后是否形成活二、活三、活四、连五
int state_white(int WhiteNum, int FrontEmptyNum, int BehindEmptyNum);// 判断白方落子后是否形成活二、活三、活四、连五
int state_jumpblack1(int black_front_jumpNum1, int black_behind_jumpNum1, int black_front_emptyNum1, int black_behind_emptyNum1);//判断黑方落子后是否形成跳形 eg 10X1 X为即将落子的点 1为黑子，0为空点
int state_jumpwhite1(int white_front_jumpNum1, int white_behind_jumpNum1, int white_front_emptyNum1, int white_behind_emptyNum1);//判断白方落子后是否形成跳形
int state_jumpblack2(int black_front_jumpNum2, int black_behind_jumpNum2, int black_front_emptyNum2, int black_behind_emptyNum2);//判断黑方落子后是否形成跳形 eg 101X，110X X为即将落子的点 1为黑子 0为空点
int state_jumpwhite2(int white_front_jumpNum2, int white_behind_jumpNum2, int white_front_emptyNum2, int white_behind_emptyNum2);//判断白方落子后是否形成跳形

void replay();

extern int BoardMap[ROW + 1][COLUMN + 1];//棋盘数组
extern int ScoreMap[ROW][COLUMN];//计分数组

extern struct step {
	int x;
	int y;
}step[300]; //结构体，储存坐标x，y，用于悔棋函数

extern FILE* f;
