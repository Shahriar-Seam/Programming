#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, i, j = 0, x = 1, y = 1, index = 1;

    scanf("%d", &n);

    int arr[n];
    int duplicates[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        x = max(x, arr[i]);
        index = x == arr[i] ? i : index;
    }

    arr[index] = 0;

    int *divisors_of_x = (int *) calloc(x + 1, sizeof(int));

    for (i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            divisors_of_x[i]++;
            divisors_of_x[x / i]++;
        }
    }

    for (i = 0; i < n; i++) {
        if (divisors_of_x[arr[i]] != 0) {
            divisors_of_x[arr[i]] = 0;
            arr[i] = 0;
        }
    }

    for (i = 0; i < n; i++) {
        y = max(y, arr[i]);
    }

    printf("%d %d", x, y);

    return 0;
}