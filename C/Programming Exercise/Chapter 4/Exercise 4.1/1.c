#include <stdio.h>

int main()
{
    int num[10];
    int i;

    for (i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }

    for (i = 9; i >= 0; i--) {
        printf("%d ", num[i]);
    }

    printf("\n");
    
    return 0;
}