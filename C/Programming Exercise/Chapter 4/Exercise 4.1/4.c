#include <stdio.h>

int main()
{
    int i, j, temp;
    int age[10];

    for (i = 0; i < 10; i++) {
        scanf("%d", &age[i]);
    }

    for (j = 9; j > 0; j--) {
        for (i = 0; i < j; i++) {
            if (age[i] > age[i + 1]) {
                temp = age[i];
                age[i] = age[i + 1];
                age[i + 1] = temp;
            }
        }
    }

    printf("Oldest: %d\n2nd Oldest: %d\n", age[9], age[8]);

    return 0;
}