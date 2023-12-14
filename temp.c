#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    static int a = 5;

    printf("%d ", ++a);
    if (a == 10)
    {
        return 0;
    }
    else
        main();
}