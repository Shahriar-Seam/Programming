#include <stdio.h>
#include <stdlib.h>

int _min(int *arr, int n)
{
    int i, min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

int main()
{
    int t, n, i;
    int *arr1, *arr2;
    unsigned long long int count;
    int min1, min2, n1, n2;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        arr1 = (int *) malloc(sizeof(int) * n);
        arr2 = (int *) malloc(sizeof(int) * n);

        for (i = 0; i < n; i++) {
            scanf("%d", &arr1[i]);
        }
        for (i = 0; i < n; i++) {
            scanf("%d", &arr2[i]);
        }

        count = 0;
        min1 = _min(arr1, n);
        min2 = _min(arr2, n);

        for(i = 0; i < n; i++)
        {
            n1 = 0, n2 = 0; 
                while(arr1[i] != min1)
                {
                    arr1[i]--;
                    n1++;
                }

                while(arr2[i] != min2)
                {
                    arr2[i]--;
                    n2++;
                }

                count += (n1 > n2) ? n1: n2;
        }

        free(arr1);
        free(arr2);

        printf("%llu\n", count);
    }

    return 0;
}