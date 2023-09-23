#include <stdio.h>

int main()
{
    int n, k, i, count = 0;

    scanf("%d %d", &n, &k);

    int arr[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    k = k - 1;

    for (i = 0; i < n; i++)
    {

        if (arr[i] >= arr[k] && arr[i] > 0)
        {
            count++;
        }
    }
    
    printf("%d\n", count);

    return 0;
}