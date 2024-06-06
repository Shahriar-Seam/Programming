#include <stdio.h>

long long int count(int last)
{
    long long int arr[last + 1][last + 1];
    int i, j;

    for (i = 0; i <= last; i++) {
        arr[i][0] = 1;
    }
    
    for (i = 0; i <= last; i++) {
        arr[0][i] = 1;
    }

    for (i = 1; i <= last; i++) {
        for (j = 1; j <= last; j++) {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }

    return arr[last][last];
}

int main()
{

    printf("%lld\n", count(20));

    return 0;
}