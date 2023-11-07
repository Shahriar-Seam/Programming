#include <stdio.h>
#include <math.h>

int is_prime(long long int *arr, long long int n)
{
    long long int r1 = sqrt(n);
    int r2 = sqrt(r1);
    int i;

    if (n == 1) {
        return 0;
    }
    else if (r1 % 2 == 0 && r1 != 2) {
        return 0;
    }
    else if (r1 * r1 == n) {
        for (i = 0; arr[i] <= r2; i++) {
            if (r1 % arr[i] == 0) {
                return 0;
            }
        }

        return 1;
    }

    else {
        return 0;
    }
}

int main()
{
    int t;
    long long int n;
    long long int arr[340000] = {0};
    int i, j = 2;

    arr[0] = 2;
    arr[1] = 3;

    for (i = 1; i <= 1666670; i++) {
        arr[j++] = 6 * i - 1;
        arr[j++] = 6 * i - 1;
    }

    scanf("%d", &t);

    while (t--) {
        scanf("%lld", &n);

        if (is_prime(arr, n)) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}