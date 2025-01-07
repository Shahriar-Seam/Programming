#include <stdio.h>
#include <stdint.h>

#define int long long
int sums[1000000] = {};

int max(int a, int b)
{
    return a > b ? a : b;
}

void knapsack(int n, int w, int *w_arr, int *v_arr, int i, int weight, int value, int *sums, int *index)
{
    if (i == n) {
        sums[*index] = value;

        *index += 1;

        return;
    }

    if (weight + w_arr[i] <= w) {
        knapsack(n, w, w_arr, v_arr, i + 1, weight + w_arr[i], value + v_arr[i], sums, index);
    }

    knapsack(n, w, w_arr, v_arr, i + 1, weight, value, sums, index);
}

int32_t main()
{
    int n, w, i, index = 0;
    int max_val = 0;

    scanf("%lld %lld", &n, &w);
    
    int w_arr[n], v_arr[n];

    for (i = 0; i < n; i++) {
        scanf("%lld %lld", w_arr + i, v_arr + i);
    }

    knapsack(n, w, w_arr, v_arr, 0, 0, 0, sums, &index);

    for (i = 0; i < index; i++) {
        max_val = max(max_val, sums[i]);
    }

    printf("%lld\n", max_val);

    return 0;
}