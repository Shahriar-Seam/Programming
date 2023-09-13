#include <stdio.h>

int main()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if (6 * a >= b + (6 * c)) {
        printf("Yes\n");
    }
    if (6 * a < b + (6 * c)) {
        printf("No\n");
    }
}