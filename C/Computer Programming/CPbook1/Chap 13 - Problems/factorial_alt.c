#include <stdio.h>
#include <math.h>

int main()
{
    // prime numbers until 100:
    int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int n;
    int i, j;
    int count[25] = {0};

    printf("Enter a number: ");
    scanf("%d", &n);

    for (i = 0; i < 25; i++) {
        for (j = 1; j <= 7; j++) {
            count[i] += n / pow(prime[i], j);

            if (n / pow(prime[i], j) == 0) {
                break;
            }
        }
    }

    for (i = 0; i < 25; i++) {
        printf("Number of %2d in %d! as factor is: %2d\n", prime[i], n, count[i]);
    }

    return 0;
}