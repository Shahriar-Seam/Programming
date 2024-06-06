#include <stdio.h>

int medium(int a, int b, int c)
{
    int temp;

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    return b;
}

int main()
{
    int t, a, b, c, m;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &a, &b, &c);

        m = medium(a, b, c);

        printf("%d\n", m);
    }

    return 0;
}