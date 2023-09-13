#include <stdio.h>

int main()
{
    // Declare variables
    int i, t;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        int odd[22], even[22];
        int i, j, N;

        scanf("%d", &N);

        even[0] = 1;
        even[1] = 1;

        if (N == 0) {
            // printf("\n");
        }

        else {
            printf("1 \n1 1 \n");

            for (i = 3; i <= N + 1; i++) {
                if (i % 2 == 0) {
                    even[0] = 1;
                    for (j = 1; j < i - 1; j++) {
                        even[j] = odd[j - 1] + odd[j];
                    }

                    even[j] = 1;
                }
                else {
                    odd[0] = 1;

                    for (j = 1; j < i - 1; j++) {
                        odd[j] = even[j - 1] + even[j];
                    }

                    odd[j] = 1;
                }
                
                for (j = 0; j < i; j++) {
                    if (i % 2 == 0) {
                        printf("%d", even[j]);
                    }
                    else {
                        printf("%d", odd[j]);
                    }
                }

                printf("\n");
            }

            printf("\n");
        }
    }

    return 0;
}

// DimikOJ Shows Wrong answer