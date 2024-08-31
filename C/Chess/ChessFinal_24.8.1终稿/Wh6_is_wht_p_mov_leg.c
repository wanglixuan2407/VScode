#include <stdio.h>
#include <string.h>
#include <math.h> 
#include "chess.h"

/*DECLARATION*/
/*The functions below is combined with legalJudge*/
/*default condition: king unchecked, the chosen piece is not placed on its initial location*/
int is_wht_p_mov_leg()
{
    char pro[MAXIPT];
    int prom_input_num = 0;

    /*row方向：0,1,-1*/
    if(abs(tmpRchRow - tmpChoRow)>= 2)
    {
        printf("Your Pawn move is illegal because its horizontal move >= 2.\n");
        return MOV_ILL;
    }
    /*横向位移正确 if确保兵只能前进1或2格*/ 
    else if((tmpRchCol - tmpChoCol) <= 0 || (tmpRchCol - tmpChoCol) >= 3) 
    {
        printf("Your pawn moved forward >3 or <= 0,this is illegal in chess.\n");
        return MOV_ILL;
    }
    /*横纵向均正确，先看直线*/ 
    else if(tmpRchRow == tmpChoRow) 
    {
        /*直行前进2格*/
        if(tmpRchCol - tmpChoCol == 2)
        {
            /*直行只允许到空格，且只许在第一步走两格，不许越子，否则违规*/ 
            if(tmpRch == BLK && tmpChoCol == 2 && recBoard[rnd][step][3][tmpChoRow] == BLK) 
            {
                    switch (tmpRchRow)
                {
                case 1:
                    if(recBoard[rnd][step][tmpRchCol][tmpRchRow + 1] == B_P_B)
                    {
                        whtEnPasntWrn = W_EN_PASNT_WRN_A; 
                    }
                    else
                    {
                        whtEnPasntWrn = NO_W_EN_PASNT_WRN;
                    }
                    return MOV_LEG;
                    break;
                case 8:
                    if(recBoard[rnd][step][tmpRchCol][tmpRchRow - 1] == B_P_G)
                    {
                        whtEnPasntWrn = W_EN_PASNT_WRN_H;
                    }
                    else
                    {
                        whtEnPasntWrn = NO_W_EN_PASNT_WRN;
                    }
                    return MOV_LEG;    
                    break;
                case 2:
                    if (recBoard[rnd][step][tmpRchCol][tmpRchRow - 1] == B_P_A || recBoard[rnd][step][tmpRchCol][tmpRchRow + 1] == B_P_C)
                    {
                        whtEnPasntWrn = W_EN_PASNT_WRN_B;
                    }
                    else
                    {
                        whtEnPasntWrn = NO_W_EN_PASNT_WRN;
                    }
                    return MOV_LEG;    
                    break;
                case 3:
                if (recBoard[rnd][step][tmpRchCol][tmpRchRow - 1] == B_P_B || recBoard[rnd][step][tmpRchCol][tmpRchRow + 1] == B_P_D)
                    {
                        whtEnPasntWrn = W_EN_PASNT_WRN_C;
                    }
                    else
                    {
                        whtEnPasntWrn = NO_W_EN_PASNT_WRN;
                    }
                    return MOV_LEG;    
                    break;
                case 4:
                if (recBoard[rnd][step][tmpRchCol][tmpRchRow - 1] == B_P_C || recBoard[rnd][step][tmpRchCol][tmpRchRow + 1] == B_P_E)
                    {
                        whtEnPasntWrn = W_EN_PASNT_WRN_D;
                    }
                    else
                    {
                        whtEnPasntWrn = NO_W_EN_PASNT_WRN;
                    }
                    return MOV_LEG;    
                    break;
                case 5:
                if (recBoard[rnd][step][tmpRchCol][tmpRchRow - 1] == B_P_D || recBoard[rnd][step][tmpRchCol][tmpRchRow + 1] == B_P_F)
                    {
                        whtEnPasntWrn = W_EN_PASNT_WRN_E;
                    }
                    else
                    {
                        whtEnPasntWrn = NO_W_EN_PASNT_WRN;
                    }
                    return MOV_LEG;    
                    break;
                case 6:
                if (recBoard[rnd][step][tmpRchCol][tmpRchRow - 1] == B_P_E || recBoard[rnd][step][tmpRchCol][tmpRchRow + 1] == B_P_G)
                    {
                        whtEnPasntWrn = W_EN_PASNT_WRN_F;
                    }
                    else
                    {
                        whtEnPasntWrn = NO_W_EN_PASNT_WRN;
                    }
                    return MOV_LEG;    
                    break;
                case 7:
                if (recBoard[rnd][step][tmpRchCol][tmpRchRow - 1] == B_P_F || recBoard[rnd][step][tmpRchCol][tmpRchRow + 1] == B_P_H)
                    {
                        whtEnPasntWrn = W_EN_PASNT_WRN_G;
                    }
                    else
                    {
                        whtEnPasntWrn = NO_W_EN_PASNT_WRN;
                    }
                    return MOV_LEG;    
                    break;
                default:
                    printf("ERR in file Wh6,please check your code!\n");
                    return MOV_ILL; 
                    break;
                }
            }
            else
            {
                printf("Your pawn moves straightforward ,but occupied other piece's location or jumped over other pieces or move forward by 2 after the first move!\n");
                return MOV_ILL;
            }
        }
        /*直行前进1格*/
        else if(tmpRchCol - tmpChoCol == 1) 
        {
            if (tmpRch == BLK)
            {
                if(tmpChoCol == 7)
                {
                    printf("Promotion! Please enter the piece you want to change to (N/R/Q/B):\n");
                    
                    do
                    {
                        printf((prom_input_num >0)?"Please enter one of the character:N,Q,R,B,regardless of uppercase or lowercase":"\0");
                        fgets(pro,MAXIPT,stdin);
                        strupr(pro);
                        prom_input_num ++;
                    } while (pro[0] != 'N'&& pro[0] != 'R'&&pro[0] != 'Q'&& pro[0] != 'B');
                    prom_input_num = 0;
                    
                    switch (pro[0])
                    {
                    case 'N':
                        recBoard[rnd][step][tmpRchCol][tmpRchRow] = W_N;
                        return MOV_LEG;
                        break;
                    case 'B':
                        recBoard[rnd][step][tmpRchCol][tmpRchRow] = (tmpRchRow %2 == 0)?W_B_B:W_B_W;
                        return MOV_LEG;
                        break;
                    case 'R':
                        recBoard[rnd][step][tmpRchCol][tmpRchRow] = W_R_PRM;
                        return MOV_LEG;
                        break;
                    case 'Q':
                        recBoard[rnd][step][tmpRchCol][tmpRchRow] = W_Q;
                        return MOV_LEG;
                        break;
                    default:
                        printf("ERR in file Wh6,please check your code!\n");
                        return MOV_ILL;
                        break;
                    }

                }
                /*未升变*/
                else 
                {
                    return MOV_LEG;
                }
            }
            else
            {
                printf("Your pawn moves straightforward ,but occupied other piece's location!This is illegal.\n");
                return MOV_ILL;
            }
        }
        else
        {
            printf("ERR in file Wh6,please check your code!\n");
            return MOV_ILL;
        }
    
    }
    /*斜向，只能吃子,且不能纵向2格*/
    else if(abs(tmpRchRow - tmpChoRow) == 1 && tmpRchCol - tmpChoCol == 1)
    {
        if (tmpRch >= B_PCE_NUM_LO && tmpRch <= B_PCE_NUM_HI)
        {
            if(tmpChoCol == 7)
            {
                printf("Promotion! Please enter the piece you want to change to (N/R/Q/B):\n");
                
                do
                {
                    printf((prom_input_num >0)?"Please enter one of the character:N,Q,R,B,regardless of uppercase or lowercase":"\0");
                    fgets(pro,MAXIPT,stdin);
                    strupr(pro);
                    prom_input_num ++;
                } while (pro[0] != 'N'&& pro[0] != 'R'&&pro[0] != 'Q'&& pro[0] != 'B');
                prom_input_num = 0;
                
                switch (pro[0])
                {
                case 'N':
                    recBoard[rnd][step][tmpRchCol][tmpRchRow] = W_N;
                    return MOV_LEG;
                    break;
                case 'B':
                    recBoard[rnd][step][tmpRchCol][tmpRchRow] = (tmpRchRow %2 == 0)?W_B_B:W_B_W;
                    return MOV_LEG;
                    break;
                case 'R':
                    recBoard[rnd][step][tmpRchCol][tmpRchRow] = W_R_PRM;
                    return MOV_LEG;
                    break;
                case 'Q':
                    recBoard[rnd][step][tmpRchCol][tmpRchRow] = W_Q;
                    return MOV_LEG;
                    break;
                default:
                    printf("ERR in file Wh6,please check your code!\n");
                    return MOV_ILL;
                    break;
                }

            }
            /*未升变*/
            else
            {
                return MOV_LEG;
            }
        }
        /*吃路过兵*/
        else if (tmpRch == BLK && blkEnPasntWrn != NO_B_EN_PASNT_WRN)
        {
            switch (blkEnPasntWrn) 
            {
            case B_EN_PASNT_WRN_A:
                if(tmpRchRow == B_EN_PASNT_WRN_A)
                {
                    recBoard[rnd][step][5][1] = BLK;
                    return MOV_LEG;
                }
                else
                {
                    if(recBoard[rnd][step][5][3] == B_P_C)
                    {
                        printf("ILLEGAL:No condition for En_Passant Pawn except A!\n");
                        return MOV_ILL;
                    }
                    else
                    {
                        printf("ILLEGAL:You moved your pawn diagonally,but didn't take any piece!\n");
                        return MOV_ILL;
                    }
                }
                break;
            case B_EN_PASNT_WRN_B:
                if(tmpRchRow == B_EN_PASNT_WRN_B)
                {
                    recBoard[rnd][step][5][2] = BLK;
                    return MOV_LEG;
                }
                else
                {
                    if(recBoard[rnd][step][5][4] == B_P_D)
                    {
                        printf("ILLEGAL:No condition for En_Passant Pawn except B!\n");
                        return MOV_ILL;
                    }
                    else
                    {
                        printf("ILLEGAL:You moved your pawn diagonally,but didn't take any piece!\n");
                        return MOV_ILL;
                    }
                }
                break;
            case B_EN_PASNT_WRN_C:
                if(tmpRchRow == B_EN_PASNT_WRN_C)
                {
                    recBoard[rnd][step][5][3] = BLK;
                    return MOV_LEG;
                }
                else
                {
                    if(recBoard[rnd][step][5][1] == B_P_A||recBoard[rnd][step][5][5] == B_P_E)
                    {
                        printf("ILLEGAL:No condition for En_Passant Pawn except C!\n");
                        return MOV_ILL;
                    }
                    else
                    {
                        printf("ILLEGAL:You moved your pawn diagonally,but didn't take any piece!\n");
                        return MOV_ILL;
                    }
                }
                break;
            case B_EN_PASNT_WRN_D:
                if(tmpRchRow == B_EN_PASNT_WRN_D)
                {
                    recBoard[rnd][step][5][4] = BLK;
                    return MOV_LEG;
                }
                else
                {
                    if(recBoard[rnd][step][5][2] == B_P_B||recBoard[rnd][step][5][6] == B_P_F)
                    {
                        printf("ILLEGAL:No condition for En_Passant Pawn except D!\n");
                        return MOV_ILL;
                    }
                    else
                    {
                        printf("ILLEGAL:You moved your pawn diagonally,but didn't take any piece!\n");
                        return MOV_ILL;
                    }
                }
                break;
            case B_EN_PASNT_WRN_E:
                if(tmpRchRow == B_EN_PASNT_WRN_E)
                {
                    recBoard[rnd][step][5][5] = BLK;
                    return MOV_LEG;
                }
                else
                {
                    if(recBoard[rnd][step][5][3] == B_P_C||recBoard[rnd][step][5][7] == B_P_G)
                    {
                        printf("ILLEGAL:No condition for En_Passant Pawn except E!\n");
                        return MOV_ILL;
                    }
                    else
                    {
                        printf("ILLEGAL:You moved your pawn diagonally,but didn't take any piece!\n");
                        return MOV_ILL;
                    }
                }
                break;
            case B_EN_PASNT_WRN_F:
                if(tmpRchRow == B_EN_PASNT_WRN_F)
                {
                    recBoard[rnd][step][5][6] = BLK;
                    return MOV_LEG;
                }
                else
                {
                    if(recBoard[rnd][step][5][4] == B_P_D||recBoard[rnd][step][5][8] == B_P_H)
                    {
                        printf("ILLEGAL:No condition for En_Passant Pawn except F!\n");
                        return MOV_ILL;
                    }
                    else
                    {
                        printf("ILLEGAL:You moved your pawn diagonally,but didn't take any piece!\n");
                        return MOV_ILL;
                    }
                }
                break;
            case B_EN_PASNT_WRN_G:
                if(tmpRchRow == B_EN_PASNT_WRN_G)
                {
                    recBoard[rnd][step][5][7] = BLK;
                    return MOV_LEG;
                }
                else
                {
                    if(recBoard[rnd][step][5][5] == B_P_E)
                    {
                        printf("ILLEGAL:No condition for En_Passant Pawn except G!\n");
                        return MOV_ILL;
                    }
                    else
                    {
                        printf("ILLEGAL:You moved your pawn diagonally,but didn't take any piece!\n");
                        return MOV_ILL;
                    }
                }
                break;
            case B_EN_PASNT_WRN_H:
                if(tmpRchRow == B_EN_PASNT_WRN_H)
                {
                    recBoard[rnd][step][5][8] = BLK;
                    return MOV_LEG;
                }
                else
                {
                    if(recBoard[rnd][step][5][6] == B_P_F)
                    {
                        printf("ILLEGAL:No condition for En_Passant Pawn except H!\n");
                        return MOV_ILL;
                    }
                    else
                    {
                        printf("ILLEGAL:You moved your pawn diagonally,but didn't take any piece!\n");
                        return MOV_ILL;
                    }
                }
                break;
            default:
                printf("ERR in file Wh6,please check your code!\n");
                return ERR;
                break;
            }
            
        }
        else
        {
            printf("ILLEGAL:You moved your pawn diagonally,but didn't take any piece!\n");
            return MOV_ILL;
        }
        
    }
    else
    {
        printf("ILLEGAL: Your pawn has moved forward like a knight.\n");
        return MOV_ILL;
    }
}