#include <stdio.h>

int main()
{
    int k, n, w;
    int money_needed, money_borrowed;

    scanf("%d %d %d", &k, &n, &w);

    money_needed = k * (w * (w + 1) / 2);
    money_borrowed = money_needed - n;

    if (money_borrowed > 0) {
        printf("%d", money_borrowed);
    }
    else {
        printf("0");
    }

    return 0;
}