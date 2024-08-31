#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "module.h"

void choose_and_play()
{
	int q = 0;
	printf("Choose:Person VS Person:1,Person black:2,Person white:3,Machine VS Machine:4\n");
	scanf_s("%d", &q);
	switch (q) {
	case 1:
		fprintf(f, "1:Person VS Person\n");
		play1();
		break;
	case 2:
		fprintf(f, "2:Person black\n");
		play2();
		break;
	case 3:
		fprintf(f, "3,Person white\n");
		play3();
		break;
	case 4:
		fprintf(f, "4:Machine\n");
		play4();
		break;
	default:
		choose_and_play();
		break;
	}
}
void play1()
{
	int num = 0;
	printf("Please enter coordinates,such as:7 7,at least 1 blank is needed between 2 numbers.\n");
	print_board(BoardMap);
	for (num = 0; num <= ROW * COLUMN; num++) {
		black_turn(n);
		n++;
		white_back();
		check();
		white_turn(n);
		n++;
		black_back();
		check();
	}
}
void play2()
{
	int num = 0;
	printf("Please enter coordinates,such as:7 7,at least 1 blank is needed between 2 numbers.\n");
	print_board(BoardMap);
	for (num = 0; num <= ROW * COLUMN; num++) {
		black_turn(n);
		n++;
		check();
		whitebot();
		n++;
		black_back();
		check();
	}
}
void play3()
{
	int num = 0;
	printf("Please enter coordinates,such as:7 7,at least 1 blank is needed between 2 numbers.\n");
	for (num = 0; num <= ROW * COLUMN; num++) {
		blackbot();
		n++;
		white_back();
		check();
		white_turn(n);
		n++;
		check();
	}
}
void play4()
{
	int num = 0;
	for (num = 0; num <= ROW * COLUMN; num++) {
		blackbot();
		n++;
		check();
		whitebot();
		n++;
		check();
	}
}
