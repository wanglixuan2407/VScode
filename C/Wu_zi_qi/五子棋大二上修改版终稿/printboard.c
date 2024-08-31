#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "module.h"

void print_board(int board[ARRAY_SIZE][ARRAY_SIZE]) 
{
	int i = 0, j = 0;//横纵坐标
	for (i = 0; i < ARRAY_SIZE; i++) {
		for (j = 0; j < ARRAY_SIZE; j++) {
			if (board[i][j] == 1) {
				printf("b ");
			}
			else if (board[i][j] == 2) {
				printf("w ");
			}
			else if (i != ARRAY_SIZE - 1 && j != ARRAY_SIZE - 1) {
				board[i][j] = 0;
				if ((i == 0) && (j == 0)) { //左上
					printf("+ ");
				}
				else if ((i == 0) && (j != 0) && (j != ARRAY_SIZE - 2)) { //上边
					printf("+ ");
				}
				else if ((i == 0) && (j == ARRAY_SIZE - 2)) { //右上
					printf("+");
				}
				else if ((i == ARRAY_SIZE - 2) && (j == 0)) { //左下
					printf("+ ");
				}
				else if ((i == ARRAY_SIZE - 2) && (j != 0) && (j != ARRAY_SIZE - 2)) { //下边
					printf("+ ");
				}
				else if ((i == ARRAY_SIZE - 2) && (j == ARRAY_SIZE - 2)) { //右下
					printf("+");
				}
				else if ((j == 0) && (i != 0) && (i != ARRAY_SIZE - 2)) { //左边
					printf("+ ");
				}
				else if ((j == ARRAY_SIZE - 2) && (i != 0) && (i != ARRAY_SIZE - 2)) { //右边
					printf("+");
				}
				else { //中间
					printf("+ ");
				}
			}
			else if (i == ARRAY_SIZE - 1 && j != ARRAY_SIZE - 1) { //纵坐标
				printf("%c ", j +'a');
			}
			else if (i != ARRAY_SIZE - 1 && j == ARRAY_SIZE - 1) { //横坐标
				printf("%c", i +'a');
			}
			else; printf(" ");
		}
		if (i != ARRAY_SIZE - 2)printf("\n\n");  //防止落子后出现棋盘错位情况，加一些换行符和空格进行调整
		else printf("\n");
	}
}