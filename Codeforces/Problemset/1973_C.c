/**
 *    author:  Anonymous_HF
 *    created: 19/05/2024 11:38:14
**/

#include <stdio.h>

void solve()
{
    int n, i, j, count1 = 0, count2 = 0, f = 0;

    scanf("%d", &n);

    int arr[n];
    int arr2[n];
    int arr3[n];
    int sum1[n];
    int sum2[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 0, j = 1; i < n; i += 2) {
        arr2[i] = j++;

        sum1[i] = arr[i] + arr2[i];
    }

    for (i = 1, j = n; i < n; i += 2) {
        arr2[i] = j--;
        
        sum1[i] = arr[i] + arr2[i];
    }

    // ulta
    for (i = n - 1, j = 1; i >= 0; i -= 2) {
        arr3[i] = j++;
        
        sum2[i] = arr[i] + arr3[i];
    }

    for (i = n - 2, j = n; i >= 0; i -= 2) {
        arr3[i] = j--;
        
        sum2[i] = arr[i] + arr3[i];
    }

    for (i = 1; i < n - 1; i++) {
        if ((sum1[i - 1] < sum1[i]) && (sum1[i] > sum1[i + 1])) {
            count1++;
        }
    }

    for (i = 1; i < n - 1; i++) {
        if ((sum2[i - 1] < sum2[i]) && (sum2[i] > sum2[i + 1])) {
            count2++;
        }
    }

    if (count1 > count2) {
        for (i = 0; i < n; i++) {
            printf("%d ", arr2[i]);
        }
    }
    else {
        for (i = 0; i < n; i++) {
            printf("%d ", arr3[i]);
        }
    }

    puts("");
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}