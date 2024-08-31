#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "module.h"

void check()
{
	if (n == ROW * COLUMN + 1) {
		printf("DRAW!\n");
		fclose(f);/*关闭文件*/
		replay();
	}
	for (int r = 0; r < ROW; r++) {
		for (int l = 0; l < COLUMN; l++) { //每个点都被扫描一次
			switch (test_winner(r, l)) {
			case 1 /* black */: printf("Black won!\n");
				fprintf(f, "Black won!");
				fclose(f);//关闭文件
				replay();
				break;
			
			case 2 /* white */: printf("White won!\n");
				fprintf(f, "White won!");
				fclose(f);//关闭文件
				replay();
				break;
			default: break;
			}
		}
	}
}

int test_winner(int r, int l)
{
	if ((BoardMap[r][l] != 0) && (test_row(r, l) || test_column(r, l) || test_diagonal_45(r, l) || test_diagonal_135(r, l))) {
		return BoardMap[r][l];//只有先确保a[r][l]有子(a[i][j]非0),才有接下来的test
	}
	else {
		return FALSE;
	}
}

int test_row(int r, int l)
{
	if (r >= NUM - 1) {
		for (int i = 1; i < NUM; i++) {
			if (BoardMap[r - i][l] != BoardMap[r][l]) {
				return FALSE;
			}
		}
	}
	else if (r < NUM) {
		return FALSE;
	}
	return TRUE;
}

int test_column(int r, int l)
{
	if (l >= NUM - 1) {
		for (int i = 1; i < NUM; i++) {
			if ((BoardMap[r][l - i] != BoardMap[r][l])) {
				return FALSE;
			}
		}
	}
	else if (l < NUM) {
		return FALSE;
	}
	return TRUE;
}

int test_diagonal_45(int r, int l)
{
	if ((l >= NUM - 1) && (r >= NUM - 1)) {
		for (int i = 1; i < NUM; i++) {
			if ((BoardMap[r - i][l - i] != BoardMap[r][l])) {
				return FALSE;
			}
		}
	}
	else if ((l < NUM) || (r < NUM)) {
		return FALSE;
	}
	return TRUE;
}

int test_diagonal_135(int r, int l) {
	if ((l >= NUM - 1) && (r <= ROW - NUM)) {
		for (int i = 1; i < NUM; i++) {
			if ((BoardMap[r + i][l - i] != BoardMap[r][l])) {
				return FALSE;
			}
		}
	}
	else if ((l < NUM) || (r > ROW - NUM)) {
		return FALSE;
	}
	return TRUE;
}