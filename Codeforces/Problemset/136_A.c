#include<stdio.h>

int main()
{
    int n, num, i;

    scanf("%d", &n);

    int arr[n + 1];

    for(i = 1; i <= n; i++) {
        scanf("%d", &num);
        arr[num]=i;
    }
    
    for(i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}