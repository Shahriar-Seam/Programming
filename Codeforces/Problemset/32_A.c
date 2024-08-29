#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, d, i, j, count = 0;

    scanf("%d %d", &n, &d);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (abs(arr[i] - arr[j]) <= d) {
                count++;
            }
        }
    }

    printf("%d\n", count * 2);

    return 0;
}