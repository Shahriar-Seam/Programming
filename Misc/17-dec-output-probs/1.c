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
    int a, b = 45, count = 0;
    int *p = &count;

    a = printf("I am seam\n");

    while (a--) {
        printf("%d %d\n", func(&b), b);
        count++;
    }

    printf("count = %d", *p);

    return 0;
}