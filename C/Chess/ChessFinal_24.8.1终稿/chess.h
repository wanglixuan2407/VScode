#ifndef CHESS_H
#define CHESS_H

/*----------Macro Definition------*/
/*----------BoardSize-------------*/
#define ROW 9 /*a-h、边框*/
#define COL 9 /*1-8、边框*/
/*---------------MAX--------------*/
#define MAXIPT 25    /*最多允许输入*/
#define MAXMOV 1000  /*单局最多允许步数*/
#define MAXRND 100   /*最多允许局数*/
/*--------------Edge--------------*/
#define W_PCE_NUM_LO 1  /*白子编号1-16*/
#define W_PCE_NUM_HI 16 

#define W_P_NUM_LO 9  /*白兵编号9-16*/
#define W_P_NUM_HI 16

#define B_PCE_NUM_LO 17 /*黑子编号17-32*/
#define B_PCE_NUM_HI 32

#define B_P_NUM_LO 17 /*黑兵编号17-24*/
#define B_P_NUM_HI 24 

/*-------------choRchSt--------------*/
#define SPR 0  /*空闲*/
#define CHO 1  /*选择*/
#define RCH 2  /*移动到达*/

#define W_K_SFE 11 /*白王不被将*/
#define B_K_SFE 12 /*黑王不被将*/
#define W_K_CKD 111 /*白王被将*/
#define W_K_CCKKDD 113/*白王被多个黑方棋子同时将军*/
#define W_K_OCPD 115 /*白王被己方棋子占据，不合规移动*/
#define B_K_CKD 112 /*黑王被将*/
#define B_K_CCKKDD 114 //黑王被白方多个棋子同时将军
#define B_K_OCPD 116 /*黑王被己方棋子占据，不合规移动*/

#define W_TRN 301 /*轮白下*/
#define B_TRN 300 /*轮黑下*/
/*----------Legal Check-----------*/
#define CRD_LEG 500 /*输入坐标合规*/
#define CRD_ILL 501 /*输入坐标违规*/
#define CHO_LEG 100 /*选择合规*/
#define CHO_ILL 101 /*选择违规*/
#define MOV_LEG 502 /*移动合规*/
#define MOV_ILL 0   /*移动违规*/

/*-----------Castling-------------*/
#define W_ST_CST 151 /*白王短易位*/
#define B_ST_CST 150 /*黑王短易位*/
#define W_LG_CST 149 /*白王长易位*/
#define B_LG_CST 148 /*黑王长易位*/

#define W_ST_CST_OK 155 /*下一步白王可以短易位*/
#define B_ST_CST_OK 154 /*下一步黑王可以长易位*/
#define W_LG_CST_OK 153 /*下一步白王可以短易位*/
#define B_LG_CST_OK 152 /*下一步黑王可以长易位*/

#define W_CSTS_OK 157 /*下一步白王可以两侧易位*/
#define B_CSTS_OK 156 /*下一步黑王可以两侧易位*/

/*-----------EN_Passant-----------*/
enum EN_PASNT_WRN{
                        NO_W_EN_PASNT_WRN = 0,NO_B_EN_PASNT_WRN = 0,
                        W_EN_PASNT_WRN_A = 1,B_EN_PASNT_WRN_A = 1,
                        W_EN_PASNT_WRN_B = 2,B_EN_PASNT_WRN_B = 2,
                        W_EN_PASNT_WRN_C = 3,B_EN_PASNT_WRN_C = 3,
                        W_EN_PASNT_WRN_D = 4,B_EN_PASNT_WRN_D = 4,
                        W_EN_PASNT_WRN_E = 5,B_EN_PASNT_WRN_E = 5,
                        W_EN_PASNT_WRN_F = 6,B_EN_PASNT_WRN_F = 6,
                        W_EN_PASNT_WRN_G = 7,B_EN_PASNT_WRN_G = 7,
                        W_EN_PASNT_WRN_H = 8,B_EN_PASNT_WRN_H = 8
                    };
/*------Digital Code for Piece----*/
enum CHESSPCE{
               W_K = 1, W_Q = 2, 
               W_R_A = 3, W_R_H = 4,
               W_B_B = 5,W_B_W = 6,  
               W_N = 7, W_R_PRM = 8,
               W_P_E = 9, W_P_D = 10,
               W_P_F = 11, W_P_C = 12, W_P_G = 13,
               W_P_B = 14, W_P_H = 15, W_P_A = 16,
               B_K = 32, B_Q = 31, 
               B_R_H = 29,B_R_A = 30,
               B_B_B = 27, B_B_W = 28,
               B_R_PRM = 25, B_N = 26,
               B_P_E = 24, B_P_D = 23, 
               B_P_F = 22, B_P_C = 21, B_P_G = 20,
               B_P_B = 19, B_P_H = 18, B_P_A =17,
               BLK = 0, 
               };
/*-----------Result Judge---------*/
#define W_WIN 750 /*白胜*/
#define CONTI 701 /*继续*/
#define B_WIN 650 /*黑胜*/
#define DRAW 700  /*和棋*/

/*-------------resign--------------*/
#define W_RSN 401
#define B_RSN 400
#define NO_RSN 399

/*-----------True or false--------*/
#define true 1
#define false 0
/*---------------ERR--------------*/
#define ERR -1  /*错误返回值:-1*/

/*--------Variable Declaraion-----*/
extern char board[MAXRND][MAXMOV][COL][ROW];

extern int recBoard[MAXRND][MAXMOV][COL][ROW];
extern int iniRecBoard[COL][ROW]; 

extern int whtThrBoard[MAXRND][MAXMOV][COL][ROW];
extern int blkThrBoard[MAXRND][MAXMOV][COL][ROW];
extern int iniThrBoard[COL][ROW];
/*----------Step/Round-------------*/
extern int step;
extern int rnd;
/*----------Play Again-----------*/
extern char whtResp;
extern char blkResp;
/*-------Buffer for scanf--------*/
extern char buf;
/*-----------WhoseMov------------*/
extern int whosMov;
/*-----------Coordinates---------*/
extern char rowLtr[MAXIPT];
extern char colIdx[MAXIPT];
/*-------Choose Reach State------*/
extern int choRchSt;

extern int choTryNum;
extern int rchTryNum;
/*----------Castling Judge-------*/
extern int isWht_K_Ckd;
extern int isBlk_K_Ckd;

extern int wht_K_MovNum;
extern int wht_R_H_MovNum;
extern int wht_R_A_MovNum;

extern int blk_K_MovNum;
extern int blk_R_H_MovNum;
extern int blk_R_A_MovNum;

/*---------EN_PASSANT Judge------*/
extern int whtEnPasntWrn;
extern int blkEnPasntWrn;
/*Record the Previous Legal Move */
extern int tmpCho; 
extern int tmpChoRow;
extern int tmpChoCol;

extern int tmpRch;
extern int tmpRchRow;
extern int tmpRchCol;

extern char tmpChoRowLtr;
extern char tmpRchRowLtr;
/*-----50-Round-Draw Judge--------*/
extern int is_P_Mov;
extern int is_pceTkn;
extern int pceNum;
extern int drawStpCnt;

/*----3-repetition-Draw Judge-----*/
extern int enPstRec[MAXRND][MAXMOV];
extern int cstlRec[MAXRND][MAXMOV];
extern int reptRec[MAXRND][MAXMOV];

/*------Function declaration------*/

/*---------main welcome-----------*/
/*b1*/void welcome_interface();

/*----------play_again------------*/
/*b2*/void play_again();

/*b13*/ void inf_ipt();

/*-------------reset--------------*/
/*b10*/void reset();
/*b9*/void int_board_reset(int chessBoard[MAXRND][MAXMOV][COL][ROW],int iniChessBoard[COL][ROW]);
//数组棋盘(rec/Threat)复原

/*-------recBoard---charBoard-----*/
/*b5*/void char_board_set();
/*b4*/void c_r_crsp(int i,int j);

/*-------printBoard---------------*/
/*b6*/void print_char_board();
/*b3*/void print_int_board(int chessBoard[MAXRND][MAXMOV][COL][ROW]);
//打印当前轮次、步数的数组棋盘(rec/Threat) 

/*--------update temporarily------*/
/*b7*/void update_board(); 
// char + rec + b/w threat
/*b11*/void int_board_set_init(int chessBoard[MAXRND][MAXMOV][COL][ROW]);
/*b12*/int pce_cnt(); 

/*------------ThreatMap-----------*/
/*b8*/void wht_thr_map();
/*b8*/void blk_thr_map();
/*g1*/ void w_k_thr_map(int i,int j);
/*g2*/ void w_q_thr_map(int i,int j);
/*g3*/ void w_n_thr_map(int i,int j);
/*g4*/ void w_b_thr_map(int i,int j);
/*g5*/ void w_r_thr_map(int i,int j);
/*g1*/ void b_k_thr_map(int i,int j);
/*g2*/ void b_q_thr_map(int i,int j);
/*g3*/ void b_n_thr_map(int i,int j);
/*g4*/ void b_b_thr_map(int i,int j);
/*g5*/ void b_r_thr_map(int i,int j);
/*-----------playerMove-----------*/
/*d1*/void wht_plr_mov();
/*d1*/void blk_plr_mov();
/*d2*/void wht_plr_cho();
/*d2*/void blk_plr_cho();
/*d3*/int rowltr_cvt(char rowLtr[MAXIPT]);//此处传全局变量,只为了方便理解代码
                                          //实际上没有必要传全局变量
/*d3*/int colidx_cvt(char colIdx[MAXIPT]);
/*d4*/int is_rowltr_leg(char rowLtr[MAXIPT]);
/*d4*/int is_colidx_leg(char colIdx[MAXIPT]);
/*d5*/int is_wht_cho_leg(char colIdx[MAXIPT],char rowLtr[MAXIPT]);
/*d5*/int is_blk_cho_leg(char colIdx[MAXIPT],char rowLtr[MAXIPT]);
/*d6*/int is_wht_mov_leg();
/*d6*/int is_blk_mov_leg();

/*h1*/int is_wht_k_mov_leg();
/*h2*/int is_wht_n_mov_leg();
/*h3*/int is_wht_b_mov_leg();
/*h4*/int is_wht_r_mov_leg();
/*h5*/int is_wht_q_mov_leg();
/*h6*/int is_wht_p_mov_leg();
/*h1*/int is_blk_k_mov_leg();
/*h2*/int is_blk_n_mov_leg();
/*h3*/int is_blk_b_mov_leg();
/*h4*/int is_blk_r_mov_leg();
/*h5*/int is_blk_q_mov_leg();
/*h6*/int is_blk_p_mov_leg();

/*k*/int is_wht_castling_leg();
/*k*/int is_blk_castling_leg();

/*----------resultjudge-----------*/
/*e1*/int is_wht_win();
/*e2*/int is_wht_drw();
/*e1*/int is_blk_win();
/*e2*/int is_blk_drw();
/*e3*/int is_spc_rl_drw();/*50回合规则和/3次重复局面和*/

/*f*/ int is_wht_k_ckd();
/*f*/ int is_blk_k_ckd();

/*m1*/int b_k_leg_mov_num(int i,int j);
/*m2*/int b_q_leg_mov_num(int i,int j);
/*m3*/int b_b_leg_mov_num(int i,int j);
/*m4*/int b_n_leg_mov_num(int i,int j);
/*m5*/int b_r_leg_mov_num(int i,int j);
/*m6*/int b_p_leg_mov_num(int i,int j);

/*m1*/int w_k_leg_mov_num(int i,int j);
/*m2*/int w_q_leg_mov_num(int i,int j);
/*m3*/int w_b_leg_mov_num(int i,int j);
/*m4*/int w_n_leg_mov_num(int i,int j);
/*m5*/int w_r_leg_mov_num(int i,int j);
/*m6*/int w_p_leg_mov_num(int i,int j);

/*n1*/int b_oprt();
/*n2*/int b_p_strat_num(int i,int j);
/*n3*/int b_p_diag_num(int i,int j);
/*n1*/int w_oprt();
/*n2*/int w_p_strat_num(int i,int j);
/*n3*/int w_p_diag_num(int i,int j);

/*m7*/int b_cstl_leg_mov_num(int i,int j);
/*m7*/int w_cstl_leg_mov_num(int i,int j);

/*n*/void fprint_final();

/*-------------review--------------*/
/*p*/void review();

/*-------------resign--------------*/
/*r*/int resign_quest(); 

/*------------main end-------------*/
/*b14*/ void end_interface();

extern FILE *tmp_file;
extern FILE *file;

#endif