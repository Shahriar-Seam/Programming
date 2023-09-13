#include <stdio.h>

int main()
{
    int n, a, b, c, count = 0;
    int i, j, k;
    
    scanf("%d %d %d %d", &n, &a, &b, &c);

    if (a > b) {
        int temp = b;
        b = a;
        a = temp;
    }
    if (b > c) {
        int temp = b;
        b = c;
        c = temp;
    }
    
    if (a > b) {
        int temp = b;
        b = a;
        a = temp;
    }

    if (n % a == 0) {
        count += n / a;
        n = 0;
    }
    else {
        k = n / c;
        n = n - (n / c) * c;

        j = n / b;
        n = n - (n / b) * b;

        i = n / a;

        count += i + j + k;
    }

    printf("%d", count);

    return 0;
}