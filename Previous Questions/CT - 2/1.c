#include <stdio.h>

int main()
{
    int arr1[100][100], arr2[100][100], sum1 = 0, sum2 = 0;
    int i, j, n = 100;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        sum1 += arr1[0][i] + arr1[n - 1][i];
    }
    
    for (i = 0; i < n; i++) {
        sum2 += arr2[i][0] + arr2[i][n - 1];
    }

    if (sum1 > sum2) {
        printf("Sum of elements at the boundary rows of A is greater than the summation of the elements at the boundary columns of B.\n");
    }
    else {
        printf("Sum of elements at the boundary rows of A is not greater than the summation of the elements at the boundary columns of B.\n");
    }

    return 0;
}