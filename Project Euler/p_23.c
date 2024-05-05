#include <stdio.h>

int div_sum(int n)
{
    int i, sum = 0;

    for (i = n / 2; i >= 1; i--) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return sum;
}

int main()
{
    const int limit = 28123;
    int i, j, sum = 0;
    int arr[6965] = {};
    int arr2[28123] = {};

    for (i = 0, j = 0; i <= limit; i++) {
        if (div_sum(i) > i) {
            arr[j++] = i;
        }
    }
    
    for (i = 0; i < 6965; i++) {
        for (j = i; j < 6965; j++) {
            if (arr[i] + arr[j] < limit) {
                arr2[arr[i] + arr[j]]++;
            }
        }
    }

    for (i = 0; i < limit; i++) {
        if (arr2[i] == 0) {
            sum += i;
        }
    }

    printf("%d\n", sum);

    return 0;
}