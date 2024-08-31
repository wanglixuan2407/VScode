#ifndef RPN_H
#define RPN_H

#define NUMBER '0'
#define MAXOP 100
int getch(void);
void ungetch(int c);
void push(double f);
double pop(void);
int getop(char s[]);

#endif
