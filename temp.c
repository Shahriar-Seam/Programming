#include <stdio.h>

int bla(int a, int b)
{
    return b;
}

int main()
{
    printf("%d %d\n", bla(2, 4), bla(2, 3));

    return 0;
}