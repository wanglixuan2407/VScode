#include <stdio.h>
#include <string.h>
#include <math.h> 
#include "chess.h"

/*DECLARATION*/
/*The functions below is combined with legalJudge*/
/*default condition: king unchecked, the chosen piece is not placed on its initial location*/
int is_blk_p_mov_leg()
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
    else if((tmpRchCol - tmpChoCol) >= 0 || (tmpRchCol - tmpChoCol) <= -3)
    {
        printf("Your pawn moved forward >3 or <= 0,this is illegal in chess.\n");
        return MOV_ILL;
    }
    /*横纵向均正确，先看直线*/ 
    else if(tmpRchRow == tmpChoRow) 
    {
        /*直行前进2格*/
        if(tmpRchCol - tmpChoCol == -2)
        {
            /*直行只允许到空格，且只许在第一步走两格，不许越子，否则违规*/ 
            if(tmpRch == BLK && tmpChoCol == 7 && recBoard[rnd][step][6][tmpChoRow] == BLK) 
            {
                    switch (tmpRchRow)
                {
                case 1:
                    if(recBoard[rnd][step][tmpRchCol][tmpRchRow + 1] == W_P_B)
                    {
                        blkEnPasntWrn = B_EN_PASNT_WRN_A; 
                    }
                    else
                    {
                        blkEnPasntWrn = NO_B_EN_PASNT_WRN;
                    }
                    return MOV_LEG;
                    break;
                case 8:
                    if(recBoard[rnd][step][tmpRchCol][tmpRchRow - 1] == W_P_G)
                    {
                        blkEnPasntWrn = B_EN_PASNT_WRN_H;
                    }
                    else
                    {
                        blkEnPasntWrn = NO_B_EN_PASNT_WRN;
                    }
                    return MOV_LEG;    
                    break;
                case 2:
                    if (recBoard[rnd][step][tmpRchCol][tmpRchRow - 1] == W_P_A || recBoard[rnd][step][tmpRchCol][tmpRchRow + 1] == W_P_C)
                    {
                        blkEnPasntWrn = B_EN_PASNT_WRN_B;
                    }
                    else
                    {
                        blkEnPasntWrn = NO_B_EN_PASNT_WRN;
                    }
                    return MOV_LEG;    
                    break;
                case 3:
                if (recBoard[rnd][step][tmpRchCol][tmpRchRow - 1] == W_P_B || recBoard[rnd][step][tmpRchCol][tmpRchRow + 1] == W_P_D)
                    {
                        blkEnPasntWrn = B_EN_PASNT_WRN_C;
                    }
                    else
                    {
                        blkEnPasntWrn = NO_B_EN_PASNT_WRN;
                    }
                    return MOV_LEG;    
                    break;
                case 4:
                if (recBoard[rnd][step][tmpRchCol][tmpRchRow - 1] == W_P_C || recBoard[rnd][step][tmpRchCol][tmpRchRow + 1] == W_P_E)
                    {
                        blkEnPasntWrn = B_EN_PASNT_WRN_D;
                    }
                    else
                    {
                        blkEnPasntWrn = NO_B_EN_PASNT_WRN;
                    }
                    return MOV_LEG;    
                    break;
                case 5:
                if (recBoard[rnd][step][tmpRchCol][tmpRchRow - 1] == W_P_D || recBoard[rnd][step][tmpRchCol][tmpRchRow + 1] == W_P_F)
                    {
                        blkEnPasntWrn = B_EN_PASNT_WRN_E;
                    }
                    else
                    {
                        blkEnPasntWrn = NO_B_EN_PASNT_WRN;
                    }
                    return MOV_LEG;    
                    break;
                case 6:
                if (recBoard[rnd][step][tmpRchCol][tmpRchRow - 1] == W_P_E || recBoard[rnd][step][tmpRchCol][tmpRchRow + 1] == W_P_G)
                    {
                        blkEnPasntWrn = B_EN_PASNT_WRN_F;
                    }
                    else
                    {
                        blkEnPasntWrn = NO_B_EN_PASNT_WRN;
                    }
                    return MOV_LEG;    
                    break;
                case 7:
                if (recBoard[rnd][step][tmpRchCol][tmpRchRow - 1] == W_P_F || recBoard[rnd][step][tmpRchCol][tmpRchRow + 1] == W_P_H)
                    {
                        blkEnPasntWrn = B_EN_PASNT_WRN_G;
                    }
                    else
                    {
                        blkEnPasntWrn = NO_B_EN_PASNT_WRN;
                    }
                    return MOV_LEG;    
                    break;
                default:
                    printf("ERR in file Bh6,please check your code!\n");
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
        else if(tmpRchCol - tmpChoCol == -1) 
        {
            if (tmpRch == BLK)
            {
                if(tmpChoCol == 2)
                {
                    printf("Promotion! Please enter the piece you want to change to (n/r/q/b):\n");
                    
                    do
                    {
                        printf((prom_input_num >0)?"Please enter one of the character:n,q,r,b,regardless of uppercase or lowercase":"\0");
                        fgets(pro,MAXIPT,stdin);
                        strlwr(pro);
                        prom_input_num ++;
                    } while (pro[0] != 'n'&& pro[0] != 'r'&&pro[0] != 'q'&& pro[0] != 'b');
                    prom_input_num = 0;
                    
                    switch (pro[0])
                    {
                    case 'n':
                        recBoard[rnd][step][tmpRchCol][tmpRchRow] = B_N;
                        return MOV_LEG;
                        break;
                    case 'b':
                        recBoard[rnd][step][tmpRchCol][tmpRchRow] = (tmpRchRow %2 == 0)?B_B_W:B_B_B;
                        return MOV_LEG;
                        break;
                    case 'r':
                        recBoard[rnd][step][tmpRchCol][tmpRchRow] = B_R_PRM;
                        return MOV_LEG;
                        break;
                    case 'q':
                        recBoard[rnd][step][tmpRchCol][tmpRchRow] = B_Q;
                        return MOV_LEG;
                        break;
                    default:
                        printf("ERR in file Bh6,please check your code!\n");
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
                printf("Your pawn moves straightforward ,but occupied other piece's location!\n");
                return MOV_ILL;
            }
        }
        else
        {
            printf("ERR in file Bh6,please check your code!\n");
            return MOV_ILL;
        }
    
    }
    /*斜向，只能吃子,且不能纵向2格*/
    else if(abs(tmpRchRow - tmpChoRow) == 1 && tmpRchCol - tmpChoCol == -1)
    {
        if (tmpRch >= W_PCE_NUM_LO && tmpRch <= W_PCE_NUM_HI)
        {
            if(tmpChoCol == 2)
            {
                printf("Promotion! Please enter the piece you want to change to (n/r/q/b):\n");           
                do
                {
                    printf((prom_input_num >0)?"Please enter one of the character:n,q,r,b,regardless of uppercase or lowercase":"\0");
                    fgets(pro,MAXIPT,stdin);
                    strlwr(pro);
                    prom_input_num ++;
                } while (pro[0] != 'n'&& pro[0] != 'r'&& pro[0] != 'q'&& pro[0] != 'b');
                prom_input_num = 0;
                
                switch (pro[0])
                {
                case 'n':
                    recBoard[rnd][step][tmpRchCol][tmpRchRow] = B_N;
                    return MOV_LEG;
                    break;
                case 'b':
                    recBoard[rnd][step][tmpRchCol][tmpRchRow] = (tmpRchRow %2 == 0)?B_B_W:B_B_B;
                    return MOV_LEG;
                    break;
                case 'r':
                    recBoard[rnd][step][tmpRchCol][tmpRchRow] = B_R_PRM;
                    return MOV_LEG;
                    break;
                case 'q':
                    recBoard[rnd][step][tmpRchCol][tmpRchRow] = B_Q;
                    return MOV_LEG;
                    break;
                default:
                    printf("ERR in file Bh6,please check your code!\n");
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
        else if (tmpRch == BLK && whtEnPasntWrn != NO_W_EN_PASNT_WRN)
        {
            switch (whtEnPasntWrn) 
            {
            case W_EN_PASNT_WRN_A:
                if(tmpRchRow == W_EN_PASNT_WRN_A)
                {
                    recBoard[rnd][step][4][1] = BLK;
                    return MOV_LEG;
                }
                else
                {
                    if(recBoard[rnd][step][4][3] == W_P_C)
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
            case W_EN_PASNT_WRN_B:
                if(tmpRchRow == W_EN_PASNT_WRN_B)
                {
                    recBoard[rnd][step][4][2] = BLK;
                    return MOV_LEG;
                }
                else
                {
                    if(recBoard[rnd][step][4][4] == W_P_D)
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
            case W_EN_PASNT_WRN_C:
                if(tmpRchRow == W_EN_PASNT_WRN_C)
                {
                    recBoard[rnd][step][4][3] = BLK;
                    return MOV_LEG;
                }
                else
                {
                    if(recBoard[rnd][step][4][1] == W_P_A||recBoard[rnd][step][4][5] == W_P_E)
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
            case W_EN_PASNT_WRN_D:
                if(tmpRchRow == W_EN_PASNT_WRN_D)
                {
                    recBoard[rnd][step][4][4] = BLK;
                    return MOV_LEG;
                }
                else
                {
                    if(recBoard[rnd][step][4][2] == W_P_B||recBoard[rnd][step][4][6] == W_P_F)
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
            case W_EN_PASNT_WRN_E:
                if(tmpRchRow == W_EN_PASNT_WRN_E)
                {
                    recBoard[rnd][step][4][5] = BLK;
                    return MOV_LEG;
                }
                else
                {
                    if(recBoard[rnd][step][4][3] == W_P_C||recBoard[rnd][step][4][7] == W_P_G)
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
            case W_EN_PASNT_WRN_F:
                if(tmpRchRow == W_EN_PASNT_WRN_F)
                {
                    recBoard[rnd][step][4][6] = BLK;
                    return MOV_LEG;
                }
                else
                {
                    if(recBoard[rnd][step][4][4] == W_P_D||recBoard[rnd][step][4][8] == W_P_H)
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
            case W_EN_PASNT_WRN_G:
                if(tmpRchRow == W_EN_PASNT_WRN_G)
                {
                    recBoard[rnd][step][4][7] = BLK;
                    return MOV_LEG;
                }
                else
                {
                    if(recBoard[rnd][step][4][5] == W_P_E)
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
            case W_EN_PASNT_WRN_H:
                if(tmpRchRow == W_EN_PASNT_WRN_H)
                {
                    recBoard[rnd][step][4][8] = BLK;
                    return MOV_LEG;
                }
                else
                {
                    if(recBoard[rnd][step][4][6] == W_P_F)
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
                printf("ERR in file Bh6,please check your code!\n");
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
    /*前2左1or前2右1*/
    else 
    {
        printf("ILLEGAL: Your pawn has moved forward like a knight.\n");
        return MOV_ILL;
    }
}