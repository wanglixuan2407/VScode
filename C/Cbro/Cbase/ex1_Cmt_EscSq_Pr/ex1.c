#include<stdio.h>
int main()
{
    // Comment (// /**/)
    //This is a comment
    /*
    This 
    is
    a
    multi-line
    comment
    */

    /*escape sequence(zhuanyixulie) = character combination consisting of a backslash \       
      followed by a letter or a combination of digits
      They specify actions within a line or string of text  
      \t = Tab
      \n = newline
      \\ = \
      \" = "
      \' = '
    */ 
    int a = 1;
    printf("a = %d\n",a);
    printf("1\t2\t3\t4\t5\n");
    printf("\"I like pizza.\" - Abraham Lincoln probably.\n ");
    printf("\\\n");// only a '\'
    return 0;
}