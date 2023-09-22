#include "stdio.h"

int inputandchecker(int input)
{
    printf("please input your desired nunber= ");
    scanf("%d", &input);
    if (input == 0)
    {
        printf("it is just zero");
        return 1;
    }
    else if (input < 0)
    {
        printf("input is less than zero, invalid input");
        return 0;
    }
}
// printf("");
// scanf("%",&);
int main()
{
    int input = 0, c;

    c = inputandchecker(input);
    if (c)
        printf("\n%d", input);
    else
    {
        printf("\nProgram terminated");
        return 0;
    }
}