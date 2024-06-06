#include <stdio.h>

int reversed_number(int n)
{
    int i, len = 0, num, rev_num = 0;
    num = n;

    for (i = 0; ; i++) {
        num = num / 10;
        len++;

        if (num == 0) {
            break;
        }
    }

    for (i = 0; i < len; i++) {
        rev_num *= 10;
        rev_num += n % 10;
        n /= 10;
    }

    return rev_num;
}

int main()
{
    int n, rev_n;

    while (1) {
        printf("Enter a number (Enter 0 to exit): ");
        scanf("%d", &n);

        if (n == 0) {
            break;
        }

        rev_n = reversed_number(n);

        printf("Reversed number = %d\n", rev_n);
    }

    return 0;    
}