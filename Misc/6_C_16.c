#include <stdio.h>

int main()
{
    int arr[10];
    int n, count = 0, i;

    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &n);

    for (i = 0; i < 10; i++) {
        if (arr[i] == n) {
            count++;
        }
    }

    if (count > 0) {
        printf("YES, %d\n", count);
    }
    else {
        printf("NO\n");
    }

    return 0;
}