#include <stdio.h>

int func(int *c)
{
    int a = 10;
    static int b = (char) 0;

    a--;
    b++;

    *c = b;

    return a;
}

int main()
{
    int a, b = 100;

    a = printf("I am seam\n");

    while (a--) {
        printf("%d %d\n", func(&b), b);
    }

    return 0;
}