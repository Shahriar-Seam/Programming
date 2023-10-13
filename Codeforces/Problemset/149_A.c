#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (* (int *) b - * (int *) a);
}

int main()
{
    int k, i, sum = 0, f = 0;
    int arr[12];

    scanf("%d", &k);

    for (i = 0; i < 12; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, 12, sizeof(int), compare);

    for (i = 0; i < 12; i++) {
        if (sum >= k) {
            f = 1;
            break;
        }
        
        sum += arr[i];
    }
    
    f ? printf("%d", i) : printf("-1");

    return 0;
}