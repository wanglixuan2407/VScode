#include<stdio.h>
#include<ctype.h>

int main()
{
    char questions[][100] = {"1. What year did the C language debut?:",
                             "2. Who is credited with creating C?:",
                             "3. What is the predecessor of C?:"
                            };
    char options [][100] = {"A.1969","B.1972","C,1975","D.1999",
                            "A.Dennis Ritchie","B. Nikola Tesla","C. John Carmark","D. Doc Brown",
                            "A. Obejective C","B. B","C. C++","D. C#"
                           };
    char answers[3] = {'B','A','B'};
    int Qnum = sizeof(questions)/sizeof(questions[0]);

    char guess;
    char buffer;
    int score;

    printf("QUIZ GAME\n");
    for (int i = 0; i < Qnum; i++)
    {
        printf("%s\n",questions[i]);

        for (int j = (i*4); j < (i*4)+4; j++)
        {
            printf("%s\n",options[j]);
        }

        printf("guess:");
        scanf("%c",&guess);
        scanf("%c",&buffer);

        guess = toupper(guess);

        if (guess == answers[i])
        {
            printf("CORRECT!\n");
            score++;
        }
        else
        {
            printf("WRONG!The correct answer is %c\n",answers[i]);
        }
        
    }
    
    printf("FINAL SCORE: %d/%d\n",score,Qnum);

    return 0;
}