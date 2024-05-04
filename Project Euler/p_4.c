#include <stdio.h>
#include <stdbool.h>

int is_palindrome(int n)
{
    int temp = n, rev = 0;

    while (temp > 0) {
        rev *= 10;
        rev += temp % 10;

        temp /= 10;
    }

    return rev == n;
}

int __max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
    int i, j, max;

    for (i = 100; i < 1000; i++) {
        for (j = i; j < 1000; j++) {
            if (is_palindrome(i * j) == true) {
                max = __max(max, i * j);
            }
        }
    }

    printf("%d\n", max);

    return 0;
}