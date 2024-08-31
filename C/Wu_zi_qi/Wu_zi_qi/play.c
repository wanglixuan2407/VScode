#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "module.h"

void black_turn(int n)
{
	int r = 0, l = 0;
	printf("Black,please enter coordinates.");
	scanf_s("%d%d", &r, &l);
	if ((BoardMap[r][l] == 1) || (BoardMap[r][l] == 2) || (r >= ROW) || (l >= COLUMN)) {
		black_turn(n);
	}
	else {
		BoardMap[r][l] = 1;
		score_white();//获取机器打分
		step[n].x = r;
		step[n].y = l;
		//system("cls");//清屏
		print_board(BoardMap);
		fprintf(f, "step[%d]=%d,%d\n", n, r, l);
		printf("step[%d]=%d,%d\n", n, r, l);
	}
}

void white_turn(int n) {
	int r = 0, l = 0;
	printf("White,please enter coordinates.");
	scanf_s("%d%d", &r, &l);
	if ((BoardMap[r][l] == 1) || (BoardMap[r][l] == 2) || (r >= ROW) || (l >= COLUMN)) {
		white_turn(n);
	}
	else {
		BoardMap[r][l] = 2;
		score_black();//获取机器打分
		step[n].x = r;
		step[n].y = l;
		//system("cls");//清屏
		print_board(BoardMap);
		fprintf(f, "step[%d]=%d,%d\n", n, r, l);
		printf("step[%d]=%d,%d\n", n, r, l);
	}
}

void blackbot()
{
	if (n == 1) {
		c = 7;d = 7;
		BoardMap[c][d] = 1;
		step[n].x = c;
		step[n].y = d;
		print_board(BoardMap);
		fprintf(f, "step[%d]=%d,%d\n", n, c, d);
		printf("step[%d]=%d,%d\n", n, c, d);
	}
	else {
		score_black();
		//system("cls");
		BoardMap[c][d] = 1;
		step[n].x = c;
		step[n].y = d;
		print_board(BoardMap);
		fprintf(f, "step[%d]=%d,%d\n", n, c, d);
		printf("step[%d]=%d,%d\n", n, c, d);
		max = 0;//max清零 不影响下一轮打分
	}
}


void whitebot()
{
	score_white();
	//system("cls");
	BoardMap[c][d] = 2;
	step[n].x = c;
	step[n].y = d;
	print_board(BoardMap);
	fprintf(f, "step[%d]=%d,%d\n", n, c, d);
	printf("step[%d]=%d,%d\n", n, c, d);
	max = 0;//max清零 不影响下一轮打分
}