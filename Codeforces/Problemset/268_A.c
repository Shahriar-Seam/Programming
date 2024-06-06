#include <stdio.h>

int main()
{
    int t, i, j, count = 0;

    scanf("%d", &t);

    int arr1[t], arr2[t];

    for (i = 0; i < t; i++) {
        scanf("%d %d", &arr1[i], &arr2[i]);
    }

    for (i = 0; i < t; i++) {
        for (j = 0; j < t; j++) {
            if (arr1[i] == arr2[j]) {
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}