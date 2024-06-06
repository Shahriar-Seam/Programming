#include <stdio.h>

int main()
{
    int i, j;

    int A[3] = {3, 10, 5}, B[3] = {9, 0, 2};

    printf("{");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("{%d, %d}", A[i], B[j]);

            if (i == 2 && j == 2) {
                break;
            }

            printf(", ");
        }
    }
    printf("}");

    return 0;
}