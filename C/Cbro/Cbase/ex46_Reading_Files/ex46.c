#include<stdio.h>

int main()
{
    FILE *pf = fopen("D:\\Computer_2Code\\VScode\\C\\Cbro\\Cbase\\ex45_Writing_Files\\test.txt","r");
    char buffer[255];

    if (pf == NULL)
    {
        printf("Cannot open this file!\n");
    }
    else
    {
        while (fgets(buffer,255,pf) != NULL)
        {
            printf("%s",buffer);
        }
        
    }
    
    return 0;
}