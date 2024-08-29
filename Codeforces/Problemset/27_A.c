#include <stdio.h>

int main()
{
    int n, i, temp;
    int counter[3005] = {};

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);

        counter[temp]++;
    }

    for (i = 1; i < 3005; i++) {
        if (counter[i] == 0) {
            break;
        }
    }

    printf("%d\n", i);
    
    return 0;
}