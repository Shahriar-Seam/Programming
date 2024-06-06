#include <stdio.h>

int sum_of_digits(int n)
{
    int i, len = 0, num, sum = 0;
    num = n;

    for (i = 0; ; i++) {
        num /= 10;
        len++;
        if (num == 0) {
            break;
        }
    }

    for (i = 0; i < len; i++) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int reversed_number(int n)
{
    int i, len = 0, num, rev_num = 0;
    num = n;

    for (i = 0; ; i++) {
        num /= 10;
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
    int n, sum, rev_num;

    scanf("%d", &n);

    sum = sum_of_digits(n);

    rev_num = reversed_number(n);

    printf("Sum of digits = %d\n", sum);
    printf("Reversed Number = %d\n", rev_num);

    return 0;
}