#include <stdio.h>
#include "chess.h"

/*-----------Variables-----------*/
/*-------------Board-------------*/
char board[MAXRND][MAXMOV][COL][ROW];

int recBoard[MAXRND][MAXMOV][COL][ROW];
int iniRecBoard[COL][ROW] = 
{
{-9,-1,-2,-3,-4,-5,-6,-7,-8},
{-1,W_R_A,W_N,W_B_B,W_Q,W_K,W_B_W,W_N,W_R_H},
{-2,W_P_A,W_P_B,W_P_C,W_P_D,W_P_E,W_P_F,W_P_G,W_P_H},
{-3,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK},
{-4,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK},
{-5,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK},
{-6,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK},
{-7,B_P_A,B_P_B,B_P_C,B_P_D,B_P_E,B_P_F,B_P_G,B_P_H},
{-8,B_R_A,B_N,B_B_W,B_Q,B_K,B_B_B,B_N,B_R_H}
};

int whtThrBoard[MAXRND][MAXMOV][COL][ROW];
int blkThrBoard[MAXRND][MAXMOV][COL][ROW];
int iniThrBoard[COL][ROW] = 
{
{-9,-1,-2,-3,-4,-5,-6,-7,-8},
{-1,0,0,0,0,0,0,0,0},
{-2,0,0,0,0,0,0,0,0},
{-3,0,0,0,0,0,0,0,0},
{-4,0,0,0,0,0,0,0,0},
{-5,0,0,0,0,0,0,0,0},
{-6,0,0,0,0,0,0,0,0},
{-7,0,0,0,0,0,0,0,0},
{-8,0,0,0,0,0,0,0,0}
};

/*----------Step/Round-----------*/
int step = 0; /*步数*/
int rnd = 0; /*局数*/

/*----------Play Again-----------*/
char whtResp; /*白色回应是否再下一局(Y/N)*/
char blkResp; /*黑方回应是否再下一局(Y/N)*/

/*-------Buffer for scanf--------*/
char buf; /*接收上一个scanf函数留在缓冲区的回车符*/
          /*最开始按enter进入游戏也用此buf接收*/

/*-----------WhoseMove-----------*/
int whosMov = W_TRN; /*轮到谁下*/
                     /*指示标志，确保编码过程思路清晰，不易出错--判断胜负时用到*/ 

/*-----------Coordinates---------*/
char rowLtr[MAXIPT]; /*输入横坐标*/
char colIdx[MAXIPT]; /*输入纵坐标*/
                     /*变量为字符串而非单字符的原因:防止输入多字符导致程序出错*/

/*-------Choose Reach State------*/
int choRchSt = SPR;/*状态：选择CHO 移动(到达)RCH*/

int choTryNum = 0; /*尝试选择次数*/
int rchTryNum = 0; /*尝试移动(到达)次数*/

/*----------Castling Judge-------*/
int isWht_K_Ckd = W_K_SFE; /*指示变量：本步开始时，白王是否被将军*/
                           /*尝试移动后用局部变量指示*/
int isBlk_K_Ckd = B_K_SFE; /*指示变量：本步开始时，黑王是否被将军*/
                           /*尝试移动后用局部变量指示*/
int wht_K_MovNum = 0;  /*白王移动次数*/
int wht_R_H_MovNum = 0; /*白方原H线车移动次数*/
int wht_R_A_MovNum = 0; /*白方原A线车移动次数*/

int blk_K_MovNum = 0;  /*黑王移动次数*/
int blk_R_H_MovNum = 0; /*黑方原H线车移动次数*/
int blk_R_A_MovNum = 0; /*黑方原A线车移动次数*/

/*---------EN_PASSANT Judge------*/
int whtEnPasntWrn = NO_W_EN_PASNT_WRN; /*白方有无被吃过路兵可能*/
int blkEnPasntWrn = NO_B_EN_PASNT_WRN; /*黑方有无被吃过路兵可能*/

/*Record the Previous Legal Move */
int tmpCho = 0;    /*此步选中格子:空格 白子 黑子*/
int tmpChoRow = 0; /*此步选中1-8列*/
int tmpChoCol = 0; /*此步选中a-h行*/

int tmpRch = 0;    /*此步移动到格子:空格 黑子 白子*/
int tmpRchRow = 0; /*此步移动到a-h行*/
int tmpRchCol = 0; /*此步移动到1-8列*/

char tmpChoRowLtr = ' '; /*此步选择的a-h行*/
char tmpRchRowLtr = ' '; /*此步移动到a-h行*/

/*注：以上均为暂时存储，如果移动不合规，则利用这些变量还原数组棋盘recboard，进而还原显示的棋盘charBoard;如果移动合规，则这些变量和recBoard一起进行胜负判断。*/            

/*-----100-step-Draw Judge--------*/
int is_P_Mov = false;   /*未移动兵，一步一判断*/
int is_pceTkn = false;  /*没有吃子，一步一判断*/

int pceNum = 32;

int drawStpCnt = 0;  /*如果连续50回合(100 steps)不移动兵、不吃子，则和棋*/

/*----3-repetition-Draw Judge-----*/
int enPstRec[MAXRND][MAXMOV];/*本步结束后，对方吃路过兵权限记录*/
int cstlRec[MAXRND][MAXMOV];/*本步结束后，对方王车易位权限记录*/
int reptRec[MAXRND][MAXMOV];/*本步结束后，重复局面记录*/

FILE *tmp_file;
FILE *file; 

/*-------------main---------------*/
int main()
{
    int nglb_Is_Wht_Win;/*局部变量，记录is_wht_win()返回值 CONTI  W_WIN*/
    int nglb_Is_Wht_Drw;/*局部变量，记录is_wht_drw()返回值 CONTI  DRAW */
    int nglb_Is_Blk_Win;/*局部变量，记录is_blk_win()返回值 CONTI  B_WIN*/
    int nglb_Is_Blk_Drw;/*局部变量，记录is_blk_drw()返回值 CONTI  DRAW */
        
    /*打开记录文件*/
    tmp_file = fopen("Chess_temp.txt","w");
    file = fopen("D:\\Computer_2Code\\VScode\\C\\Chess_Graduation_Design\\ChessRecord\\Chess_record_formal_use\\Chess_record_use1.txt","a");
    /*测试版Chess_record.txt已结束，以后从Chess_record_use文件夹开始正式使用*/
    /*文件名可以随时改动*/
    
    /*开始界面*/
    welcome_interface();

    /*进入主循环(循环1)：*/
    do
    {
        /*开始新一局：Round更新*/
        scanf("%c",&buf);
        
        /*输入对局信息:比赛名称，对局双方，比赛时间*/
        inf_ipt();

        rnd ++;   
        printf("Round %d\n",rnd);
        fprintf(tmp_file,"Round %d\n",rnd);
        fprintf(file,"Round %d\n",rnd);

        /*所有参数复原*/
        reset(); 

        /*至此正式开始新一局*/
        /*一盘棋，白黑交替下棋，循环2开始*/
        do
        {
            /*轮到白方*/
            /*落棋前先确认白方是否认输*/
            if (resign_quest() == W_RSN)
            {
                goto play_again_label;
            }
            else
            {
                ;
            }

            wht_plr_mov();
            
            /*判断是否出现50回合规则和/3次重复局面和*/
            if (is_spc_rl_drw() == DRAW)
            {
                goto play_again_label;
            }
            else
            {
                ;
            }
            whosMov = B_TRN;
            /*黑选择前，判断是否被将军。后续胜负判断需要以此为条件展开*/
            isBlk_K_Ckd = is_blk_k_ckd();

            /*胜负判断，如果白胜/白方主动逼和/3次重复局面和/50回合规则和，则结束，反之本局继续，轮黑方下棋*/
            nglb_Is_Wht_Win = is_wht_win();
            nglb_Is_Wht_Drw = is_wht_drw();
            if (nglb_Is_Wht_Win == CONTI && nglb_Is_Wht_Drw == CONTI)
            {
                /*轮到黑方*/
                /*落棋前先确认黑方是否认输*/
                if (resign_quest() == B_RSN)
                {
                    goto play_again_label;
                }
                else
                {
                    ;
                }

                blk_plr_mov();

                /*判断是否出现50回合规则和/3次重复局面和*/
                if (is_spc_rl_drw() == DRAW)
                {
                    goto play_again_label;
                }
                else
                {
                    ;
                }   
                whosMov = W_TRN;
                /*白方选择前，判断是否被将军。后续胜负判断需要以此为条件展开*/
                isWht_K_Ckd = is_wht_k_ckd(); 
            }
            else if (nglb_Is_Wht_Win == W_WIN)
            {
                print_char_board();
                printf("White won!\n");
                fprintf(tmp_file,"\nResult:1 - 0\n");
                fprintf(file,"\nResult:1 - 0\n");
                goto play_again_label;
            }
            else if (nglb_Is_Wht_Drw == DRAW)
            {
                print_char_board();
                printf("White---Draw---black!\n");
                fprintf(tmp_file,"\nResult:1/2 - 1/2\n");
                fprintf(file,"\nResult:1/2 - 1/2\n");
                goto play_again_label;
            }
            else 
            {
                printf("ERR---file a,please check your code!\n");
                break;
            }
            /*胜负判断，如果黑胜/黑方主动逼和/3次重复局面和/50回合规则和，则结束，反之本局继续，轮白方下棋*/
            nglb_Is_Blk_Win = is_blk_win();
            nglb_Is_Blk_Drw = is_blk_drw();
        } while (nglb_Is_Blk_Win == CONTI && nglb_Is_Blk_Drw == CONTI);
        
        if (nglb_Is_Blk_Drw == DRAW) 
        {
            print_char_board();
            printf( "black---Draw---white!\n"); 
            fprintf(tmp_file,"\nResult:1/2 - 1/2\n");
            fprintf(file,"\nResult:1/2 - 1/2\n");
        }
        else if(nglb_Is_Blk_Win == B_WIN)
        {
            print_char_board();
            printf("Black won!\n"); 
            fprintf(tmp_file,"\nResult:0 - 1\n");
            fprintf(file,"\nResult:0 - 1\n");
        }
        else
        {
            printf("ERR---file a,please check your code!\n");
        }

        /*一局结束，打印终局场面，询问是否重新开始*/
        play_again_label:
        fprint_final();

        review();

        play_again();

    /*如果白黑均同意(输入Y)，则回到循环1开头，重新开始*/
    } while (whtResp == 'Y' && blkResp == 'Y');

    /*如果白黑至少一方不同意(输入非Y字符)，则退出程序*/
    end_interface();
    
    /*关闭文件*/
    fclose(tmp_file);
    fclose(file);

    return 0;
}