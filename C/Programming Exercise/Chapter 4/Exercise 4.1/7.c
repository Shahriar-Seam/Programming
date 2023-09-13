#include <stdio.h>

int main()
{
    int n, i, j, temp;

    scanf("%d", &n);

    int num[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    for (j = n - 1; j > 0; j--) {
        for (i = 0; i < j; i++) {
            if (num[i] > num[i + 1]) {
                temp = num[i];
                num[i] = num[i + 1];
                num[i + 1] = temp;
            }
        }        
    }

    for (i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }

    printf("\n");

    return 0;
}