#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "module.h"

void replaycourse(int p, int N)
{
    //刚开始复盘时:n = N1 + 1,N1 = N > 0(最终手数)
	scanf_s("%d", &p);
	if (p > 0) {
		if (N1 + p <= N) {
			for (n = 1; n <N1 + p; n++) {
				if (n % 2 == 1)/*black*/BoardMap[step[n].x][step[n].y] = 1;
				if (n % 2 == 0)/*white*/BoardMap[step[n].x][step[n].y] = 2;
			}
			N1 = n;
			//system("cls");
			print_board(BoardMap);
			printf("step[%d]=%d,%d\n", n, step[n].x, step[n].y);
			replaycourse(p, N);
		}
		else {
			printf("more than maximum steps,please enter again.\n");
			replaycourse(p, N);
		}
	}

	//开始复盘时，n = N1 + 1，N1 = N(最终手数)
	else if (p < 0) {
		if (N1 + p >= 1) {
			for (n = N1;n > N1 + p; n--) { //此时p < 0
				BoardMap[step[n].x][step[n].y] = 0;
			}
			N1 = n;
			if (n % 2 == 1)/*black*/BoardMap[step[n].x][step[n].y] = 1;
			if (n % 2 == 0)/*white*/BoardMap[step[n].x][step[n].y] = 2;
			//system("cls");//清屏
			print_board(BoardMap);
			printf("step[%d]=%d,%d\n", n, step[n].x, step[n].y);
			replaycourse(p, N);
		}
		else {
			printf("less than minimum steps,please enter again.\n");
			replaycourse(p, N);
		}
	}

	else {
		printf("Please do not enter 0.\n");
		replaycourse(p, N);
	}
}