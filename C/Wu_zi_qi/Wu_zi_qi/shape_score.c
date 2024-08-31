#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "module.h"


int state_black(int BlackNum, int FrontEmptyNum, int BehindEmptyNum)
{
	if (BlackNum >= 4)return 10;//10=必胜
	else if (BlackNum == 3) {
		if (FrontEmptyNum >= 1 && BehindEmptyNum >= 1)return 9;      //落子后形成活四
		else if (FrontEmptyNum == 0 && BehindEmptyNum == 0)return 0; //此方向已无进攻能力  
		else return 7;//冲四
	}
	else if (BlackNum == 2) {
		if (Otherspace > 2) {
			if (FrontEmptyNum >= 2 && BehindEmptyNum >= 2)return 8; //活三进攻，之后2个方向都能冲四
			else if ((FrontEmptyNum >= 2 && BehindEmptyNum == 1) || (FrontEmptyNum == 1 && BehindEmptyNum >= 2))return 6;//活三进攻，但只有一个方向可以冲四
			else return 0;
		}
		else return 0;//此方向已无进攻能力
	}
	else if (BlackNum == 1) {
		if (FrontEmptyNum > 2 && BehindEmptyNum > 2)return 4;// 2个方向活二不受限
		else return 0;//此方向已无进攻能力
	}

	else if (BlackNum == 0) {
		if (Otherspace >= 7)return -1;
		else return 0;
	}
	else return 0;
}


int state_white(int WhiteNum, int FrontEmptyNum, int BehindEmptyNum)
{
	if (WhiteNum >= 4)return 10;//10=必胜
	else if (WhiteNum == 3) {
		if (FrontEmptyNum >= 1 && BehindEmptyNum >= 1)return 9;//活四
		else if (FrontEmptyNum == 0 && BehindEmptyNum == 0)return 0;//此方向已无进攻能力  //不能ififelse并列，else之和最近一个if组合
		else return 7;//只有先手冲四，但只有一个则无法连五
	}
	else if (WhiteNum == 2) {
		if (Otherspace > 2) {
			if (FrontEmptyNum >= 2 && BehindEmptyNum >= 2)return 8;//活三进攻，之后2个方向还有冲四
			else if ((FrontEmptyNum >= 2 && BehindEmptyNum == 1) || (FrontEmptyNum == 1 && BehindEmptyNum >= 2))return 6;//活三进攻，但只有一个方向可以冲四
			else return 0;
		}
		else return 0;//此方向已无进攻能力
	}
	else if (WhiteNum == 1) {
		if (FrontEmptyNum > 2 && BehindEmptyNum > 2)return 4;// 2个方向活二不受限
		else return 0;//此方向已无进攻能力
	}

	else if (WhiteNum == 0) {
		if (Otherspace >= 7)return -1;
		else return 0;
	}
	else return 0;
}

int state_jumpblack1(int black_front_jumpNum1, int black_behind_jumpNum1, int black_front_emptyNum1, int black_behind_emptyNum1)
{
	if (black_behind_jumpNum1 >= 4) return 0;//与连五、冲四或活四重复  //behind里包括待打分的空点
	else {
		if (black_front_emptyNum1 == 0 && black_behind_emptyNum1 == 0) {
			if (black_front_jumpNum1 == 3 && black_behind_jumpNum1 == 3)return 9;//分值=2倍活四（计算方式、倍数关系）
			else return 0;//跳形角度没有攻击力或与冲四重复
		}
		else if ((black_front_emptyNum1 != 0 && black_behind_emptyNum1 == 0) || (black_front_emptyNum1 == 0 && black_behind_emptyNum1 != 0)) {
			if (black_front_jumpNum1 + black_behind_jumpNum1 >= 4)return 5;//进攻能力偏弱的冲四/冲击长连， eg 010X112 / 0110X1112
			else return 0;                                                      //eg 0110X2、010X12 几乎无效
		}
		else {
			if (black_front_jumpNum1 + black_behind_jumpNum1 >= 4)return 5;
			else if ((black_front_jumpNum1 == 2 && black_behind_jumpNum1 == 1) || (black_front_jumpNum1 == 1 && black_behind_jumpNum1 == 2))return 6; //跳活3 //bfj+bbj=2或3
			else if (black_front_jumpNum1 == 1 && black_behind_jumpNum1 == 1)return 3;//等价于跳活2
			else return 0;
		}
	}
}

int state_jumpwhite1(int white_front_jumpNum1, int white_behind_jumpNum1, int white_front_emptyNum1, int white_behind_emptyNum1) {
	if (white_behind_jumpNum1 >= 4) return 0;//与连五、冲四或活四重复  //behind里包括待打分的空点
	else {
		if (white_front_emptyNum1 == 0 && white_behind_emptyNum1 == 0) {
			if (white_front_jumpNum1 == 3 && white_behind_jumpNum1 == 3)return 9;//分值=2倍活四（计算方式、倍数关系）
			else return 0;//跳形角度没有攻击力或与冲四重复
		}
		else if ((white_front_emptyNum1 != 0 && white_behind_emptyNum1 == 0) || (white_front_emptyNum1 == 0 && white_behind_emptyNum1 != 0)) {
			if (white_front_jumpNum1 + white_behind_jumpNum1 >= 4)return 5;//进攻能力偏弱的冲四/冲击长连， eg 010X112 / 0110X1112
			else return 0;                                                      //eg 0110X2、010X12 几乎无效
		}
		else {
			if (white_front_jumpNum1 + white_behind_jumpNum1 >= 4)return 5;
			else if ((white_front_jumpNum1 == 2 && white_behind_jumpNum1 == 1) || (white_front_jumpNum1 == 1 && white_behind_jumpNum1 == 2))return 6; //跳活3 //bfj+bbj=2或3
			else if (white_front_jumpNum1 == 1 && white_behind_jumpNum1 == 1)return 3;//等价于跳活2
			else return 0;
		}
	}
}

int state_jumpblack2(int black_front_jumpNum2, int black_behind_jumpNum2, int black_front_emptyNum2, int black_behind_emptyNum2) {
	if (black_behind_jumpNum2 == 2) {
		if (black_front_jumpNum2 >= 1) return 5;//稍弱于普通冲四 1011X...
		else return 0;//角上的bug
	}
		
	else if (black_behind_jumpNum2 == 1) {
		if (black_front_jumpNum2 == 2) return 5;//1101X...
		else if (black_front_jumpNum2 == 1) {
			if (black_front_emptyNum2 > 0 && black_behind_emptyNum2 > 0)return 6;//跳活三
			else if (black_front_emptyNum2 == 0 && black_behind_emptyNum2 == 0)return 0;
			else return 3; //很弱, 1手构不成威胁
		}
		else return 0;
	}
	else return 0;
}

int state_jumpwhite2(int white_front_jumpNum2, int white_behind_jumpNum2, int white_front_emptyNum2, int white_behind_emptyNum2) {
	if (white_behind_jumpNum2 == 2) {
		if (white_front_jumpNum2 >= 1) return 5;//稍弱于普通冲四 1011X...
		else return 0;//角上的bug
	}
		
	else if (white_behind_jumpNum2 == 1) {
		if (white_front_jumpNum2 == 2) return 5;//1101X...
		else if (white_front_jumpNum2 == 1) {
			if (white_front_emptyNum2 > 0 && white_behind_emptyNum2 > 0)return 6;//跳活三
			else if (white_front_emptyNum2 == 0 && white_behind_emptyNum2 == 0)return 0;
			else return 3; //很弱, 1手构不成威胁
		}
		else return 0;
	}
	else return 0;
}