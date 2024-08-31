#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "module.h"

void score_black()
{
	int row = 0;//纵坐标，行数
	int column = 0;//横坐标，列数
	int state = 0;//BehindEmptyNum计算，0（row，line处）1101这种情况需要再引入state状态来判断
	int BlackNum = 0;//黑棋在某一方向有多少个子（每个方向判断完需清零）
	int WhiteNum = 0;//白棋在某一方向有多少个子
	int FrontEmptyNum = 0;//如果在待打分点落子，前面有多少个空点（异色子处会有截断，见代码）
	int BehindEmptyNum = 0;//如果在待打分点落子，后面有多少个空点（异色子处会有截断，见代码）
	int checkingrow = 0;//正在扫描第几行
	int checkingcolumn = 0;//正在扫描第几列
	int e = -4;//用于e*x，e*y扫描各个方向
	int black_front_jumpNum1 = 0;
	int black_behind_jumpNum1 = 0;
	int black_front_emptyNum1 = 0;
	int black_behind_emptyNum1 = 0;

	int white_front_jumpNum1 = 0;
	int white_behind_jumpNum1 = 0;
	int white_front_emptyNum1 = 0;
	int white_behind_emptyNum1 = 0;

	int black_front_jumpNum2 = 0;
	int black_behind_jumpNum2 = 0;
	int black_front_emptyNum2 = 0;
	int black_behind_emptyNum2 = 0;

	int white_front_jumpNum2 = 0;
	int white_behind_jumpNum2 = 0;
	int white_front_emptyNum2 = 0;
	int white_behind_emptyNum2 = 0;

	/*打分数组初始化：空点位置赋500，有子位置赋1、2*/

	for (row = 0; row < ROW; row++) {
		for (column = 0; column < COLUMN; column++) {
			switch (BoardMap[row][column]) {
			case 0:ScoreMap[row][column] = 500; break;
			case 1:ScoreMap[row][column] = 1; break;
			case 2:ScoreMap[row][column] = 2; break;
			default:printf("ERROR!Please check your program!\n"); break;//设计思路中BoardMap[i][j]只有0.1.2三种值
			}
		}
	}

	/*----------------为黑方下一步打分------------------*/

	for (row = 0; row < ROW; row++) {
		for (column = 0; column < COLUMN; column++) {
			if (BoardMap[row][column] != 0) {
				if (BoardMap[row][column] == 1) ScoreMap[row][column] = 1;
				if (BoardMap[row][column] == 2) ScoreMap[row][column] = 2;
			}

			else {                                //这里省略if(BoardMap[row][line] == 0)
				for (int y = -1; y <= 1; y++) {   //8个方向扫描 来回扫2次（见下方代码）
					for (int x = -1; x <= 1; x++) {
						if (x == 0 && y == 0) continue;

						else {
							/*---------------------------------黑子环境--------------------------------*/

							for (e = -1; e >= -4; e--) {
								checkingrow = row + e * y;
								checkingcolumn = column + e * x;

								if ((Bounday_judgement) && (BoardMap[checkingrow][checkingcolumn] == 1)) {
									if (state == 0)BlackNum++; //state=0连子数才可加，下方有state≠0的情况，此时无法再加
									if (state == 1) {
										BlackNum = 0;
										break;
									} //一旦出现state=1，后面再有同色子则出现跳形，不在研究范围内，各量清零，break
								}
								else if ((Bounday_judgement) && (BoardMap[checkingrow][checkingcolumn] == 0)) {
									//如果遇到空格，连子清零//循环到这个空点为【row】【line】即可弥补此情况！
									FrontEmptyNum++;
									state = 1;
								}
								else break;
							}


							state = 0;
							for (e = 1; e <= 4; e++) {
								checkingrow = row + e * y;
								checkingcolumn = column + e * x;

								if ((Bounday_judgement) && (BoardMap[checkingrow][checkingcolumn] == 1)) {
									if (state == 0)BlackNum++; //state=0连子数才可加，下方有state≠0的情况，此时无法再加
									if (state == 1) {
										BlackNum = 0;
										break;
									} //一旦出现state=1，后面再有同色子则出现跳形，不在研究范围内，各量清零，break
								}
								else if ((Bounday_judgement) && (BoardMap[checkingrow][checkingcolumn] == 0)) {
									//如果遇到空格，连子清零//循环到这个空点为【row】【line】即可弥补此情况！
									BehindEmptyNum++;
									state = 1;
								}
								else break;
							}//efor循环到此为止

							switch (state_black(BlackNum, FrontEmptyNum, BehindEmptyNum)) {
							case -1:ScoreMap[row][column] += 4; break;  //开辟新区域
							case 0: break;                              //没有进攻能力的点不加分

							case 4:ScoreMap[row][column] += 7000; break;   //活2
							case 6:ScoreMap[row][column] += 15000; break;  //连活3，但只有1方向可以正常冲4  eg2011X002
							case 7:ScoreMap[row][column] += 24000; break;  //等价于冲4  eg 102X2210
							case 8:ScoreMap[row][column] += 18000; break;  //连活3
							case 9:ScoreMap[row][column] += 8000000; break;//活4
							case 10:ScoreMap[row][column] += 100000000; break;//连5：走完黑子必胜
							default: break;
							}
							BlackNum = 0;
							FrontEmptyNum = 0;
							BehindEmptyNum = 0;
							/*----------------------------------------跳形10X/10X1------------------------------------------*/
							e = -4;      
							state = 2; 

							for (e = -4; e <= 4; e++) {
								checkingrow = row + e * y;
								checkingcolumn = column + e * x;
								if (e == 0)continue;                  //前面有else控制【row】【line】处是空格

								else {
									if (Bounday_judgement) {
										if (e == -1) {//e<0区间：e==-1终极条件！
											if (BoardMap[checkingrow][checkingcolumn] != 0) {  //空点周围非空则落子后构不成跳形
												black_front_jumpNum1 = 0;
												black_front_emptyNum1 = 0;
												break; //无论此处是黑还是白，均不满足主动跳形要求，结束这个方向顺序的for循环
											}
											else black_behind_jumpNum1 = 1;//2个frontjump数据照常保留,算0位落子本身，空位后面至少一个黑子
										}
										if (e == -2) { //-2比-1先进行
											if (BoardMap[checkingrow][checkingcolumn] == 1) black_front_jumpNum1++;//至少保证1个black_front_jumpNum1（但如果-1处不是空格，则全部清零并break）
											else { //...0(2)0X无效
												black_front_jumpNum1 = 0;
												black_front_emptyNum1 = 0;
												break;
											}
										}
										if (e < -2) {//-2处有保证，前面只剩-4、-3，易写 00 01 10 11  （-2到0对应101才有效）
											if (BoardMap[checkingrow][checkingcolumn] == 1) black_front_jumpNum1++;
											if (BoardMap[checkingrow][checkingcolumn] == 0) {
												black_front_emptyNum1++; 
												black_front_jumpNum1 = 0;
											}
											if (BoardMap[checkingrow][checkingcolumn] == 2) {
												black_front_jumpNum1 = 0;
												black_front_emptyNum1 = 0; //不能break，因为此时基本框10X可能已经形成
											}
										}

										if (e > 0) {
											if (BoardMap[checkingrow][checkingcolumn] == 2) {  //空点周围非空则落子后构不成跳形
												black_behind_jumpNum1 = 1;//-1处判断时已经加过1了！
												black_behind_emptyNum1 = 0;
												break;//e>0后出现，此时出现2则终结
											}
											else if (BoardMap[checkingrow][checkingcolumn] == 0) {
												black_behind_emptyNum1++;// black_behind_jumpNum定住了 state=3
												state = 3;   //若后面全0，behind正常加
											}
											else if (BoardMap[checkingrow][checkingcolumn] == 1) {
												if (state == 2)black_behind_jumpNum1++;
												if (state == 3)break;
											}
										}
									}//最顶层if控制边界即可
								}
							}//efor循环到此为止


							switch (state_jumpblack1(black_front_jumpNum1, black_behind_jumpNum1, black_front_emptyNum1, black_behind_emptyNum1)) {
							case 0: break;//无进攻能力
							case 3:ScoreMap[row][column] += 5500; break;//跳活2（2750*2）
							case 5:ScoreMap[row][column] += 27000; break;//冲连（13500*2）
							case 6:ScoreMap[row][column] += 20000; break;//跳活三（10000*2）  //受打分方式影响
							case 9:ScoreMap[row][column] += 16000000; break;//等价于活4(8000000*2)
							default: break;
							}
							black_front_jumpNum1 = 0;
							black_behind_jumpNum1 = 0;
							black_front_emptyNum1 = 0;
							black_behind_emptyNum1 = 0;
							/*---------------------------------------跳形101...X0------------------------------------------------*/

							e = 1;
							state = 4;
							for (e = 1; e <= 4; e++) {
								checkingrow = row + e * y;
								checkingcolumn = column + e * x;

								if (Bounday_judgement) { 
									if (BoardMap[checkingrow][checkingcolumn] != 0)break;//都不是所需跳形
									else black_behind_emptyNum2++;//0-4个
								}
							}
							e = -1;
							for (e = -1; e >= -4; e--) {
								checkingrow = row + e * y;
								checkingcolumn = column + e * x;

								if (Bounday_judgement) {
									if (e == -1) {
										if (BoardMap[checkingrow][checkingcolumn] != 1) {
											state = 4;
											black_front_jumpNum2 = 0;
											black_behind_jumpNum2 = 0;
											black_front_emptyNum2 = 0;
											black_behind_emptyNum2 = 0;
											break;  //不满足101X基本要求，参数归零，舍
										}
										else black_behind_jumpNum2++;//注意black_behind_jumpNum2未包含0处落点
									}

									if (e < -1) {
										if (BoardMap[checkingrow][checkingcolumn] == 1) {
											if (state == 4)black_behind_jumpNum2++;
											else if (state == 5) {  //只能执行一种情况，state转换，需要前面的else辅助！
												black_front_jumpNum2++;
												state = 6;
											}
											else if (state == 6) {
												black_front_jumpNum2++;
											}
										}


										else if (BoardMap[checkingrow][checkingcolumn] == 0) {
											if (state == 4)state = 5;
											else if (state == 5) {   // 必须else，否则直接执行下一语句，state=5对上了
												state = 4;
												black_front_jumpNum2 = 0;
												black_behind_jumpNum2 = 0;
												black_front_emptyNum2 = 0;
												black_behind_emptyNum2 = 0;
												break;  //不满足101X基本要求，参数归零，舍
											}
											else if (state == 6)black_front_emptyNum2++;
										}
										else {
											if (state == 4 || state == 5) {
												state = 4;
												black_front_jumpNum2 = 0;
												black_behind_jumpNum2 = 0;
												black_front_emptyNum2 = 0;
												black_behind_emptyNum2 = 0;
												break;  //不满足101X基本要求，参数归零，舍
											}
											if (state == 6) break;
											//只扫-4到-2，最多到state=6
										}
									}
								}
							}

							e = -1;
							state = 4;//state复原


							switch (state_jumpblack2(black_front_jumpNum2, black_behind_jumpNum2, black_front_emptyNum2, black_behind_emptyNum2)) {
							case 0:break;
							case 3:ScoreMap[row][column] += 30; break;
							case 5:ScoreMap[row][column] += 16000; break;//冲4
							case 6:ScoreMap[row][column] += 19000; break;//跳活三
							default:break;
							}/*统计黑子得分*/
							black_front_jumpNum2 = 0;
							black_behind_jumpNum2 = 0;
							black_front_emptyNum2 = 0;
							black_behind_emptyNum2 = 0;
							e = -1;//e也复原
							state = 0;//state复原到0（不是2），下面对white环境打分

							/*--------------------------白子环境----------------------------*/

							for (e = -1; e >= -4; e--) {
								checkingrow = row + e * y;
								checkingcolumn = column + e * x;

								if ((Bounday_judgement) && (BoardMap[checkingrow][checkingcolumn] == 2)) {
									if (state == 0)WhiteNum++; //state=0连子数才可加，下方有state≠0的情况，此时无法再加
									if (state == 1) {
										WhiteNum = 0;
										break;
									} //一旦出现state=1，后面再有同色子则出现跳形，不在研究范围内，各量清零，break
								}
								else if ((Bounday_judgement) && (BoardMap[checkingrow][checkingcolumn] == 0)) {
									//如果遇到空格，连子清零//循环到这个空点为【row】【line】即可弥补此情况！
									FrontEmptyNum++;
									state = 1;
								}
								else break;
							}

							e = 1;
							state = 0;
							for (e = 1; e <= 4; e++) {
								checkingrow = row + e * y;
								checkingcolumn = column + e * x;

								if ((Bounday_judgement) && (BoardMap[checkingrow][checkingcolumn] == 2)) {
									if (state == 0)WhiteNum++; //state=0连子数才可加，下方有state≠0的情况，此时无法再加
									if (state == 1) {
										WhiteNum = 0;
										break;
									} //一旦出现state=1，后面再有同色子则出现跳形，不在研究范围内，各量清零，break
								}
								else if ((Bounday_judgement) && (BoardMap[checkingrow][checkingcolumn] == 0)) {
									//如果遇到空格，连子清零//循环到这个空点为【row】【line】即可弥补此情况！
									BehindEmptyNum++;
									state = 1;
								}
								else break;
							}//efor循环到此为止


							switch (state_white(WhiteNum, FrontEmptyNum, BehindEmptyNum)) {
							case -1:ScoreMap[row][column] += 4; break;
							case 0: break;// 无效
							case 4:ScoreMap[row][column] += 2000; break;//活2
							case 6:ScoreMap[row][column] += 15500; break;//连活3，但只有1方向可以正常冲4  eg001X102
							case 7:ScoreMap[row][column] += 21600; break;//冲4 
							case 8:ScoreMap[row][column] += 16200; break;//连活3
							case 9:ScoreMap[row][column] += 7000000; break;//活4
							case 10:ScoreMap[row][column] += 80000000; break;//白子走完必胜
							default:break;
							}
							WhiteNum = 0;
							FrontEmptyNum = 0;//要么记黑，要么记白，直接计空则break，此时Emptynum=2，待复原
							BehindEmptyNum = 0;

							e = -4;
							state = 2;
							/*---------------------------------------跳形10X,10X1--------------------------------------------*/

							for (e = -4; e <= 4; e++) {
								checkingrow = row + e * y;
								checkingcolumn = column + e * x;
								if (e == 0)continue;                  //前面有else控制【row】【line】处是空格

								else {
									if (Bounday_judgement) {
										if (e == -1) {//e<0区间：e==-1终极条件！
											if (BoardMap[checkingrow][checkingcolumn] != 0) {  //空点周围非空则落子后构不成跳形
												white_front_jumpNum1 = 0;
												white_front_emptyNum1 = 0;
												break; //无论此处是黑还是白，均不满足主动跳形要求，结束这个方向顺序的for循环
											}
											else white_behind_jumpNum1 = 1;//2个frontjump数据照常保留,算0位落子本身，空位后面至少一个白子
										}
										if (e == -2) { //-2比-1先进行
											if (BoardMap[checkingrow][checkingcolumn] == 2) white_front_jumpNum1++;
											else { //...0(1)0X无效
												white_front_jumpNum1 = 0;
												white_front_emptyNum1 = 0;
												break;
											}
										}
										if (e < -2) {
											if (BoardMap[checkingrow][checkingcolumn] == 2) white_front_jumpNum1++;
											if (BoardMap[checkingrow][checkingcolumn] == 0) {
												white_front_emptyNum1++; 
												white_front_jumpNum1 = 0;
											}
											if (BoardMap[checkingrow][checkingcolumn] == 1) {
												white_front_jumpNum1 = 0;
												white_front_emptyNum1 = 0; //不能break
											}
										}

										if (e > 0) {
											if (BoardMap[checkingrow][checkingcolumn] == 1) {  //空点周围非空则落子后构不成跳形
												white_behind_jumpNum1 = 1;//-1处判断时已经加过1了！
												white_behind_emptyNum1 = 0;
												break;//e>0后出现1则终结
											}
											else if (BoardMap[checkingrow][checkingcolumn] == 0) {
												white_behind_emptyNum1++;// black_behind_jumpNum定住了 state=3
												state = 3;   //若后面全0，behind正常加
											}
											else if (BoardMap[checkingrow][checkingcolumn] == 2) { 
												if (state == 2)white_behind_jumpNum1++;
												if (state == 3)break;
											}
										}
									}//最顶层if控制边界即可
								}
							}//efor循环到此为止

							switch (state_jumpwhite1(white_front_jumpNum1, white_behind_jumpNum1, white_front_emptyNum1, white_behind_emptyNum1)) {
							case 0: break;//无进攻能力
							case 3:ScoreMap[row][column] += 5000; break;//跳活2
							case 5:ScoreMap[row][column] += 16000; break;//冲连
							case 6:ScoreMap[row][column] += 19000; break;//跳活三  //受打分方式影响
							case 9:ScoreMap[row][column] += 14000000; break;//等价于活4(7000000*2)
							default: break;
							}
							white_front_jumpNum1 = 0;
							white_behind_jumpNum1 = 0;
							white_front_emptyNum1 = 0;
							white_behind_emptyNum1 = 0;
							/*---------------------------------------跳形101X------------------------------------------------*/
							e = 1;
							state = 4;
							for (e = 1; e <= 4; e++) {
								checkingrow = row + e * y;
								checkingcolumn = column + e * x;

								if (Bounday_judgement) { 
									if (BoardMap[checkingrow][checkingcolumn] != 0)break;
									else white_behind_emptyNum2++;//0-4个
								}
							}
							e = -1;
							for (e = -1; e >= -4; e--) {
								checkingrow = row + e * y;
								checkingcolumn = column + e * x;

								if (Bounday_judgement) {
									if (e == -1) {
										if (BoardMap[checkingrow][checkingcolumn] != 2) {
											state = 4;
											white_front_jumpNum2 = 0;
											white_behind_jumpNum2 = 0;
											white_front_emptyNum2 = 0;
											white_behind_emptyNum2 = 0;
											break;
										}
										else white_behind_jumpNum2++;
									}

									if (e < -1) {
										if (BoardMap[checkingrow][checkingcolumn] == 2) {
											if (state == 4)white_behind_jumpNum2++;
											else if (state == 5) {
												white_front_jumpNum2++;
												state = 6;
											}
											else if (state == 6) {
												white_front_jumpNum2++;
											}
										}


										else if (BoardMap[checkingrow][checkingcolumn] == 0) {
											if (state == 4)state = 5;
											else if (state == 5) {   // 必须else，否则直接执行下一语句，state=5
												state = 4;
												white_front_jumpNum2 = 0;
												white_behind_jumpNum2 = 0;
												white_front_emptyNum2 = 0;
												white_behind_emptyNum2 = 0;
												break;  //不满足101X基本要求，参数归零，舍
											}
											else if (state == 6)white_front_emptyNum2++;
										}
										else {
											if (state == 4 || state == 5) {
												state = 4;
												white_front_jumpNum2 = 0;
												white_behind_jumpNum2 = 0;
												white_front_emptyNum2 = 0;
												white_behind_emptyNum2 = 0;
												break;  //不满足101X基本要求，参数归零，舍
											}
											if (state == 6) break;
											//只扫-4到-2，最多到state=6
										}
									}
								}
							}

							e = -1;
							state = 4;//state复原

							switch (state_jumpwhite2(white_front_jumpNum2, white_behind_jumpNum2, white_front_emptyNum2, white_behind_emptyNum2)) {
							case 0:break;
							case 3:ScoreMap[row][column] += 30; break;//进攻能力弱
							case 5:ScoreMap[row][column] += 14000; break;//冲四
							case 6:ScoreMap[row][column] += 17000; break;//跳活三
							default:break;
							}/*统计白子得分*/

							white_front_jumpNum2 = 0;
							white_behind_jumpNum2 = 0;
							white_front_emptyNum2 = 0;
							white_behind_emptyNum2 = 0;
							e = -4;//e也复原
							state = 0;//state复原到0（不是2）
						}
					}
				}
			}
			/*--------------------------------打分结束---------------------------------*/
			if (column == COLUMN - 1) {
				printf("%d\n", ScoreMap[row][column]);
			}
			else {
				printf("%d\t", ScoreMap[row][column]);
			}
			if (BoardMap[row][column] == 0) {
				if (ScoreMap[row][column] >= max) {
					max = ScoreMap[row][column];
					c = row;
					d = column;
				}
			}
		}
	}
}


