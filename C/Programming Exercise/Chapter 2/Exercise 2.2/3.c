#include <stdio.h>

int main()
{
    int marks, pass_mark;

    scanf("%d %d", &marks, &pass_mark);

    if (marks >= pass_mark) {
        printf("Passed\n");
    }
    if (marks < pass_mark) {
        printf("Failed\n");
    }

    return 0;
}