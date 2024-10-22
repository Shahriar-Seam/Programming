#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int a, b, c, d;
    int misha, vasya;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    misha = max(3 * a / 10, a - (a / 250) * c);
    vasya = max(3 * b / 10, b - (b / 250) * d);

    if (misha > vasya) {
        puts("Misha");
    }
    else if (misha < vasya) {
        puts("Vasya");
    }
    else {
        puts("Tie");
    }

    return 0;
}