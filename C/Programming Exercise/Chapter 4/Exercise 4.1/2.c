#include <stdio.h>

int main()
{
    int n, i, count = 0;

    printf("Enter number of vases: ");
    scanf("%d", &n);

    int vase[n];

    printf("Enter number of flowers in each vase:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &vase[i]);
    }

    if (n % 2 == 0) {
        for (i = 0; i < n / 2; i++) {
            if (vase[i] == vase[n - i - 1]) {
                count++;
            }
        }
    }

    else {
        for (i = 0; i < n / 2; i++) {
            if (vase[i] == vase[n - i - 1]) {
                count++;
            }
        }
    }

    if (count == n / 2) {
        printf("Symmetric.\n");
    }

    else {
        printf("Asymmetric.\n");
    }

    return 0;
}