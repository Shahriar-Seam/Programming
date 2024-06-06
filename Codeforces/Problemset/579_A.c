#include <stdio.h>

int _count(int n)
{
    int r, count = 0;

    while (n != 0) {
        r = n % 2;
        n /= 2;
        
        if (r == 1) {
            count++;
        }
    }

    return count;
}

int main()
{
    int n;

    scanf("%d", &n);

    if (n && !(n & (n - 1))) {
        printf("1");
    }

    else {
        printf("%d", _count(n));
    }

    return 0;
}