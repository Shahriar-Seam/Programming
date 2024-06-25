#include <stdio.h>
#include <stdlib.h>

int N = 1e6 + 5;
int *div_sum;

void fill_div_sum()
{
    int i, j;

    div_sum = (int *) calloc(N, sizeof(int));

    for (i = 1; i < N; i++) {
        div_sum[i] -= i;

        for (j = i; j < N; j += i) {
            div_sum[j] += i;
        }
    }
}

int main()
{
    fill_div_sum();

    int t, n, sum;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        sum = div_sum[n];

        if (sum > n) {
            puts("abundant");
        }
        else if (sum < n) {
            puts("deficient");
        }
        else {
            puts("perfect");
        }
    }

    return 0;
}