#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "module.h"

void replay()
{
	int q = 0;

	N = n - 1;// 之前的函数里有n++，所以这里N=n-1
	N1 = N;  //提前赋值
	// printf("N = %d,N1 = %d,n = %d",N,N1,n); //此时:n = N1 + 1,N1 = N(最终手数)
	
	printf("Game saved, review? Yes:1,No:Other numbers.");
	scanf_s("%d", &q);
	if (q == 1) {
		//system("cls");
		print_board(BoardMap);
		printf("Review starts.Please enter step change. Positive:forward/Negative:back.\n");
		replaycourse(p, N); //此时:n = N1 + 1,N1 = N(最终手数)
	}

	else exit(0);// exit(0) 退出程序
}