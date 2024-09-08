#include <stdio.h>

#define print(n) printf("%d\n", ((n)))

int main()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if (a > b) {
        if (b > c) {
            print(c);
        }
        else {
            print(b);
        }
    }
    else {
        if (a > c) {
            print(c);
        }
        else {
            print(a);
        }
    }

    return 0;
}