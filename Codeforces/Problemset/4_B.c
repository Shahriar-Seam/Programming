#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int d, sum, i, f = 1;

    scanf("%d %d", &d, &sum);

    int v[d][2];
    int *arr = (int *) calloc(d, sizeof(int));

    for (i = 0; i < d; i++) {
        scanf("%d %d", &v[i][0], &v[i][1]);
    }

    for (i = 0; i < d; i++) {
        if (sum >= v[i][0]) {
            arr[i] = v[i][0];

            sum -= v[i][0];
        }
        else {
            break;
        }
    }

    for (i = d - 1; i >= 0; i--) {
        if (sum > 0) {
            arr[i] += min(v[i][1] - v[i][0], sum);

            sum -= v[i][1] - v[i][0];
        }
        else {
            break;
        }
    }

    for (i = 0; i < d; i++) {
        if (arr[i] < v[i][0] || arr[i] > v[i][1]) {
            f = 0;

            break;
        }
    }

    if (sum > 0 || f == 0) {
        printf("NO\n");
    }
    else {
        printf("YES\n");

        for (i = 0; i < d; i++) {
            printf("%d ", arr[i]);
        }

        printf("\n");
    }

    return 0;
}