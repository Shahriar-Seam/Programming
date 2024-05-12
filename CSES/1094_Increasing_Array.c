#include <stdio.h>

int main()
{
    int n, i;
    long long int count = 0, last;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    last = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] < last) {
            count += last - 1LL * arr[i];
        }
        else {
            last = arr[i];
        }
    }

    printf("%lld\n", count);

    return 0;
}