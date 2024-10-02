#include <stdio.h>

void swp(int a, int b)
{
    // write function here
}

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);

    swp((int)&a, (int)&b);

    printf("%d %d\n", a, b);

    return 0;
}