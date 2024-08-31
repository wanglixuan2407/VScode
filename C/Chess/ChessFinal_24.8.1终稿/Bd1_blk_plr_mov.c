#include <stdio.h>
#include <string.h>
#include "chess.h"

void blk_plr_mov()
{
    /*上一步结尾全盘剩余子数*/
    int tmpPceNum = pceNum;

    /*步数 +1，进入此步的初始局面*/
    step ++;
    printf("step %d:\n",step);
    int_board_set_init(recBoard);
    /*配套的update_board在第一层循环*/

do
    {
        /*本步成功选择本方棋子，但不合规的移动，棋子复位*/
        if (rchTryNum >0) 
        {
            recBoard[rnd][step][tmpRchCol][tmpRchRow] = tmpRch;
            recBoard[rnd][step][tmpChoCol][tmpChoRow] = tmpCho; 
        }
        else
        {
            ;
        }
        /*本步起始图*/
        update_board();//recBoard已实时更新，此时更新(char)Board和threatmap
        print_char_board();

        printf("%s",(isBlk_K_Ckd == B_K_CKD || isBlk_K_Ckd == B_K_CCKKDD)?"Black king is checked!\n":"\0");
        
        /*必须是重新选子，否则可能陷入一个子没有合规移动的死循环*/
        printf("%s",(rchTryNum >0)?"Your previous move is ILLEGAL! Try again!\n":"Please choose a black piece\n");

        /*blackchoose*/
        do
        {
            printf("%s",(choTryNum >0)?"You did not choose a black piece, please choose again!\n":(rchTryNum >0)?"Please choose a black piece\n":"\0");
            blk_plr_cho();
        } while (!(is_blk_cho_leg(colIdx,rowLtr) >= B_PCE_NUM_LO && is_blk_cho_leg(colIdx,rowLtr) <= B_PCE_NUM_HI));

        /*选择成功后*/
        tmpCho = is_blk_cho_leg(colIdx,rowLtr);
        tmpChoRowLtr = rowLtr[0];
        tmpChoRow = rowltr_cvt(rowLtr);
        tmpChoCol = colidx_cvt(colIdx);

        /*选择处清空*/ 
        recBoard[rnd][step][tmpChoCol][tmpChoRow] = BLK;

        choTryNum = 0;
        choRchSt = SPR;
    
        /*blackreach*/
        do
        {
            printf("BlackPlayer,please enter the location to reach.\n");
            printf("x(a-h):");
            fgets(rowLtr,MAXIPT,stdin);
            strlwr(rowLtr);
        } while (is_rowltr_leg(rowLtr) != CRD_LEG);
    
        do
        {
            printf("y(1-8):");
            fgets(colIdx,MAXIPT,stdin);

        } while (is_colidx_leg(colIdx) != CRD_LEG);
    
        /*reach 坐标合规之后*/
        tmpRchRow = rowltr_cvt(rowLtr);
        tmpRchRowLtr = rowLtr[0];
        tmpRchCol = colidx_cvt(colIdx);
        tmpRch = recBoard[rnd][step][tmpRchCol][tmpRchRow];
    
        /*兵移动后，移到哪线，就跟着赋哪线的值，其余子不变*/
        if (tmpCho <= B_P_NUM_HI && tmpCho >= B_P_NUM_LO)
        {
            switch (tmpRchRow)
            {
            case 1:
            recBoard[rnd][step][tmpRchCol][tmpRchRow] = B_P_A;
            break;

            case 2:
            recBoard[rnd][step][tmpRchCol][tmpRchRow] = B_P_B;
            break;

            case 3:
            recBoard[rnd][step][tmpRchCol][tmpRchRow] = B_P_C;
            break;

            case 4:
            recBoard[rnd][step][tmpRchCol][tmpRchRow] = B_P_D;
            break;

            case 5:
            recBoard[rnd][step][tmpRchCol][tmpRchRow] = B_P_E;
            break;

            case 6:
            recBoard[rnd][step][tmpRchCol][tmpRchRow] = B_P_F;
            break;

            case 7:
            recBoard[rnd][step][tmpRchCol][tmpRchRow] = B_P_G;
            break;

            case 8:
            recBoard[rnd][step][tmpRchCol][tmpRchRow] = B_P_H;
            break;

            default:
            break;
            }
        }
        /*其他子移动*/
        else
        {
            recBoard[rnd][step][tmpRchCol][tmpRchRow] = tmpCho;
        }

        update_board();

        choRchSt = RCH;
        rchTryNum ++;
    
    } while (is_blk_mov_leg() != MOV_LEG);   
    
    printf("step[%d]:%c%d-%c%d\n",step,tmpChoRowLtr,tmpChoCol,tmpRchRowLtr,tmpRchCol);
    fprintf(tmp_file,"step[%d]:%c%d-%c%d\n",step,tmpChoRowLtr,tmpChoCol,tmpRchRowLtr,tmpRchCol);
    fprintf(file,"step[%d]:%c%d-%c%d\n",step,tmpChoRowLtr,tmpChoCol,tmpRchRowLtr,tmpRchCol);

    rchTryNum = 0;
    choRchSt = SPR;

    /*无论吃与否，下一步如果黑不送过路兵，则无法再吃*/
    whtEnPasntWrn = NO_W_EN_PASNT_WRN;

    /*实时更新(char)board和threatBoard*/
    update_board();
    
    pceNum = pce_cnt();

    /*100步规则和 相关变量更新*/
    if (tmpCho <= B_P_NUM_HI && tmpCho >= B_P_NUM_LO)
    {
        is_P_Mov = true;
    }
    else
    {
        is_P_Mov = false;
    }
    if (pceNum == tmpPceNum - 1)
    {
        is_pceTkn = true;
    }
    else
    {
        is_pceTkn = false;
    }
    if (is_P_Mov == false && is_pceTkn == false)
    {
        drawStpCnt ++;
    }
    else
    {
        drawStpCnt = 0;
    }
}