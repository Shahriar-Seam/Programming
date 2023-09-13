#include <stdio.h>

int sum = 0;

int SUM(int n)
{
    // Base case
    if (n <= 0) {
        return 0;
    }

    // Recursive case
    return sum = n + SUM(n - 1);
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("Sum = %d\n", SUM(n));

    return 0;
}