#include <stdio.h>

int main()
{
    int arr[] = {100, 300, 500, 700, 900};
    int *p;
    p = arr;

    printf("*p : %d\n", *p);
    printf("*p + 1 : %d\n", *p + 1);
    printf("*(p + 1) : %d\n", *(p + 1));
    printf("*p + 2 : %d\n", *p + 2);
    printf("*(p + 2) : %d\n", *(p + 2));

    return 0;
}