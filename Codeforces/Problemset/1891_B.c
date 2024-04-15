#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_present(int *arr, int key, int index)
{
    int i;

    for (i = 0; i < index; i++) {
        if (arr[i] == key) {
            return true;
        }
    }

    return false;
}

void solve()
{
    int n, q, i, j, k, temp;
    int brr[31] = {};

    scanf("%d %d", &n, &q);

    int arr[n];
    int new_arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        new_arr[i] = arr[i];
    }

    for (i = 0, j = 0; i < q; i++) {
        scanf("%d", &temp);

        if (is_present(brr, temp, j) == false) {
            brr[j++] = temp;
        }
    }

    for (k = 0; k < j; k++) {
        temp = (1 << brr[k]);
        
        for (i = 0; i < n; i++) {
            if (new_arr[i] % temp == 0) {
                new_arr[i] += (temp >> 1);
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", new_arr[i]);
    }

    printf("\n");
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