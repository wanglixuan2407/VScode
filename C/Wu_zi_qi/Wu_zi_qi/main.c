#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "module.h"

//warning:DONOT use system(cls) in this program!
int n = 1;//步数n
int max = 0;//最高得分
int c = 0;//纵坐标全局变量，落子函数要用到
int d = 0;//横坐标全局变量，落子函数要用到
int N = 0;//复盘函数用到，记录本局最终步数
int p = 0;//复盘时希望回退/前进的步数
int N1 = 0;//临时记录复盘到哪一步
int BoardMap[ROW + 1][COLUMN + 1];
int ScoreMap[ROW][COLUMN];
char buf;

struct step step[300];

FILE* f;

int main()
{
	f = fopen("wuziqi.txt", "w");
	printf("         Welcome          \n");
	printf("(ROW)(LINE):0-14\n");
	print_board(BoardMap);
	choose_and_play();
	return 0;
}