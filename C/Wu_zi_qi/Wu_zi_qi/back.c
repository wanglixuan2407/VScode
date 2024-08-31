#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "module.h"

void black_back() {
	int h = 0;
	for (h = 0; h < BACK; h++) {
		int m;
		printf("Black:%d back?yes:1,no:2\n", h + 1);
		scanf_s("%d", &m);
		if (m == 1) {
			n--;
			BoardMap[step[n].x][step[n].y] = 0;
			fprintf(f, "step[%d] was removed\n", n);
			if (n <= 0) {
				n = 1;
				break;
			}
			n--;
			BoardMap[step[n].x][step[n].y] = 0;
			fprintf(f, "step[%d] was removed\n", n);
			if (n <= 0) {
				n = 1;
				break;
			}
			print_board(BoardMap);
			printf("step[%d]\n", n);
		}
		else if (m == 2) {
			break;
		}
	}
}

void white_back() {
	int h = 0;
	for (h = 0; h < BACK; h++) {
		int m;
		printf("White:%d back?yes:1,no:2\n\n", h + 1);
		scanf_s("%d", &m);
		if (m == 1) {
			if (n <= 2) {   
				n = 2;
				break;
			}
			n--;
			BoardMap[step[n].x][step[n].y] = 0;
			fprintf(f, "step[%d] was removed\n", n);
			if (n < 2) {
				n = 2;
				break;
			}
			n--;
			BoardMap[step[n].x][step[n].y] = 0;
			fprintf(f, "step[%d] was removed\n", n);
			if (n < 2) {
				n = 2;
				break;
			}
			print_board(BoardMap);
			printf("step[%d]\n", n);
		}
		else if (m == 2) {
			break;
		}
	}
}