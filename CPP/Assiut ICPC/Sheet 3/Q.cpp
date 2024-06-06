#include <bits/stdc++.h>

using namespace std;

void solve();
int check(int *arr, int n);

int main()
{
    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

void solve()
{
    int size, *arr, *sub_arr, i, j, k, l, cnt = 0;

    cin >> size;

    arr = (int *) malloc(sizeof(int) * size);
    sub_arr = (int *) calloc(size, sizeof(int));

    for (i = 0; i < size; i++) {
        cin >> arr[i];
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j <= i; j++) {
            l = 0;

            for (k = j; k <= i; k++) {
                sub_arr[l++] = arr[k];
            }

            if (check(sub_arr, l) == 1) {
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
}

int check(int *arr, int n)
{
    int i;

    for (i = 0; i < n - 1; i++) {
        if (arr[i] >= arr[i + 1]) {
            return 0;
        }
    }

    return 1;
}